/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */
  TK_NEQ,       // !=
  TK_AND,       // &&
  TK_OR,        // ||
  TK_DEC,       // 十进制数
  TK_HEX,       // 十六进制数
  TK_REG,       // 寄存器
  // TK_DEREF,     // 解引用(*)
  // TK_NEG,       // 负号
  

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces

  /****************addition ***************** */
  {"\\+", '+'},         // plus
  {"-", '-'},           // 减法
  {"\\*", '*'},         // 乘法或解引用
  {"/", '/'},           // 除法

    /* 括号 */
  {"\\(", '('},         // 左括号
  {"\\)", ')'},         // 右括号

   /* 逻辑运算符 */
  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},       // 不等于
  {"&&", TK_AND},       // 逻辑与
  {"\\|\\|", TK_OR},    // 逻辑或
  {">=", '>=' },        // 大于等于
  {"<=", '<=' },        // 小于等于
  {">", '>' },          // 大于
  {"<", '<' },          // 小于

  /* 数值 */
  {"0[xX][0-9a-fA-F]+", TK_HEX},           // 十六进制数
  {"[0-9]+", TK_DEC},                      // 十进制数
  
  /* 寄存器 */
  {"\\$[a-zA-Z0-9]+", TK_REG},             // 寄存器引用
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE: break;

          default: 
            // check overflow
            if(nr_token >= 32) {
              printf("Too many tokens\n");
              return false;
            }
            // record token type
            tokens[nr_token].type = rules[i].token_type;
            
            // record token string
            if(substr_len > 32) {
              substr_len = 31;
            }
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';

            nr_token++;
            break;
        }
        
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

/* function for evaluation */
// 检查表达式是否被一对匹配的括号完全包围
static bool check_parentheses(int p, int q) {
  if (tokens[p].type != '(' || tokens[q].type != ')')
    return false;
  
  int balance = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(')
      balance++;
    else if (tokens[i].type == ')')
      balance--;
    
    // 如果在到达右端前括号已经匹配完，说明这不是一对包围整个表达式的括号
    if (balance == 0 && i < q)
      return false;
  }
  return balance == 0; // 确保括号完全匹配
}

// 获取运算符优先级，数值越小优先级越低
static int get_priority(int op_type) {
  switch (op_type) {
    case TK_OR:       return 1;  // 逻辑或
    case TK_AND:      return 2;  // 逻辑与
    case TK_EQ:
    case TK_NEQ:
    case '>':
    case '<':
    case '>=':
    case '<=':        return 3;  // 比较运算符
    case '+':
    case '-':         return 4;  // 加减
    case '*':
    case '/':         return 5;  // 乘除
    default:          return 0;  // 非运算符
  }
}

// 查找主运算符（最外层且优先级最低的运算符）
static int find_main_operator(int p, int q) {
  int op_position = -1;
  int min_priority = 10;  // 一个较大的初始值
  int parentheses = 0;
  
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') {
      parentheses++;
      continue;
    }
    if (tokens[i].type == ')') {
      parentheses--;
      continue;
    }
    
    // 只在未被括号包围的部分寻找运算符
    if (parentheses != 0)
      continue;
    
    int priority = get_priority(tokens[i].type);
    // 选择优先级最低的，若相同则选最右边的
    if (priority > 0 && priority <= min_priority) {
      min_priority = priority;
      op_position = i;
    }
  }
  
  return op_position;
}

// 表达式求值递归函数
static word_t eval(int p, int q, bool *success) {
  if (p > q) {
    // 处理错误情况：空表达式
    *success = false;
    return 0;
  }
  else if (p == q) {
    // 单个token，必须是数字或寄存器
    word_t val = 0;
    if (tokens[p].type == TK_DEC) {
      sscanf(tokens[p].str, "%u", &val);
    }
    else if (tokens[p].type == TK_HEX) {
      sscanf(tokens[p].str + 2, "%x", &val); // 跳过"0x"前缀
    }
    else if (tokens[p].type == TK_REG) {
      bool reg_success = true;
      val = isa_reg_str2val(tokens[p].str + 1, &reg_success); // 跳过"$"前缀
      if (!reg_success) {
        printf("Invalid register: %s\n", tokens[p].str);
        *success = false;
        return 0;
      }
    }
    else {
      printf("Unexpected token type %d at position %d\n", tokens[p].type, p);
      *success = false;
      return 0;
    }
    return val;
  }
  else if (check_parentheses(p, q) == true) {
    // 表达式被一对括号包围，去掉括号递归求值
    return eval(p + 1, q - 1, success);
  }
  else {
    // 寻找主运算符并分割表达式
    int op = find_main_operator(p, q);
    if (op == -1) {
      printf("No valid operator found in expression\n");
      *success = false;
      return 0;
    }
    
    // 递归求解左右子表达式
    word_t val1 = eval(p, op - 1, success);
    if (!*success) return 0;
    
    word_t val2 = eval(op + 1, q, success);
    if (!*success) return 0;
    
    // 根据运算符执行相应操作
    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': 
        if (val2 == 0) {
          printf("Division by zero\n");
          *success = false;
          return 0;
        }
        return val1 / val2;
      case TK_EQ:  return val1 == val2;
      case TK_NEQ: return val1 != val2;
      case '>':    return val1 > val2;
      case '<':    return val1 < val2;
      case '>=':   return val1 >= val2;
      case '<=':   return val1 <= val2;
      case TK_AND: return val1 && val2;
      case TK_OR:  return val1 || val2;
      default:
        printf("Unsupported operator: %d\n", tokens[op].type);
        *success = false;
        return 0;
    }
  }
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  *success = true;
  return eval(0, nr_token - 1, success);

}
