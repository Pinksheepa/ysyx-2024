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
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

// 在文件顶部添加
word_t paddr_read(paddr_t addr, int len);

enum
{
  TK_NOTYPE = 256,
  TK_EQ,

  /* TODO: Add more token types */
  TK_NEQ,   // !=
  TK_AND,   // &&
  TK_OR,    // ||
  TK_DEC,   // decimal number
  TK_HEX,   // hexadecimal number
  TK_REG,   // register
  TK_GE,    // >= 添加这一行
  TK_LE,    // <= 添加这一行
  TK_DEREF, // pointer dereference

};

static struct rule
{
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE}, // spaces

    /****************addition ***************** */
    {"\\+", '+'}, // plus
    {"-", '-'},   // subtraction
    {"\\*", '*'}, // multiplication or dereference
    {"/", '/'},   // division

    /* Parentheses */
    {"\\(", '('}, // left parenthesis
    {"\\)", ')'}, // right parenthesis

    /* Logical operators */
    {"==", TK_EQ},     // equal
    {"!=", TK_NEQ},    // not equal
    {"&&", TK_AND},    // logical AND
    {"\\|\\|", TK_OR}, // logical OR
    {">=", TK_GE},     // greater than or equal -
    {"<=", TK_LE},     // less than or equal -
    {">", '>'},        // greater than
    {"<", '<'},        // less than

    /* Numbers */
    {"0[xX][0-9a-fA-F]+", TK_HEX}, // hexadecimal number
    {"[0-9]+", TK_DEC},            // decimal number

    /* Registers */
    {"\\$[a-zA-Z0-9]+", TK_REG}, // register reference

    /* Pointer dereference*/
    // {"\\*", '*'}, // multiplication or dereference

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/******************************************************************************************** */
/* 初始化 - 编译所有正则表达式 */

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex()
{
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++)
  {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0)
    {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}
/******************************************************************************************** */

/* 词法分析 - 将输入字符串分解为token序列  */
typedef struct token
{
  int type;
  char str[64]; // 增大单个token的最大长度
} Token;

#define TOKENS_SIZE 1024 // 增大到足够存储长表达式
static Token tokens[TOKENS_SIZE] = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e)
{
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0')
  {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++)
    {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
      {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type)
        {
        case TK_NOTYPE:
          break;

        default:
          // check overflow
          if (nr_token >= 32)
          {
            printf("Too many tokens\n");
            return false;
          }
          // record token type
          tokens[nr_token].type = rules[i].token_type;

          // record token string
          if (substr_len > 32)
          {
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

    if (i == NR_REGEX)
    {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  // 处理完词法分析后，遍历tokens识别解引用符号
  for (int i = 0; i < nr_token; i++)
  {
    if (tokens[i].type == '*')
    {
      // 如果 '*' 在表达式开头，或者前面是运算符或左括号，它是解引用操作符
      if (i == 0 || (tokens[i - 1].type != TK_DEC &&
                     tokens[i - 1].type != TK_HEX &&
                     tokens[i - 1].type != TK_REG &&
                     tokens[i - 1].type != ')'))
      {
        tokens[i].type = TK_DEREF;
      }
    }
  }

  return true;
}

/******************************************************************************************** */

/* function for evaluation */
// Check if the expression is completely surrounded by a matched pair of parentheses
static bool check_parentheses(int p, int q)
{
  if (tokens[p].type != '(' || tokens[q].type != ')')
    return false;

  int balance = 0;
  for (int i = p; i <= q; i++)
  {
    if (tokens[i].type == '(')
      balance++;
    else if (tokens[i].type == ')')
      balance--;

    // If the parentheses are matched before reaching the right end, it means this is not a pair of parentheses surrounding the entire expression
    if (balance == 0 && i < q)
      return false;
  }
  return balance == 0; // Ensure the parentheses are completely matched
}

// Get operator priority, the smaller the value, the lower the priority
static int get_priority(int op_type)
{
  switch (op_type)
  {
  case TK_OR:
    return 1; // Logical OR
  case TK_AND:
    return 2;  // Logical AND
  case TK_EQ:  // ==
  case TK_NEQ: // !=
  case '>':
  case '<':
  case TK_GE: // >=
  case TK_LE: // <=
    return 3; // Comparison operators
  case '+':
  case '-':
    return 4; // Addition and subtraction
  case '*':
  case '/':
    return 5; // Multiplication and division
  case TK_DEREF:
    return 6; // 指针解引用优先级最高
  default:
    return 0; // Non-operator
  }
}

// Find the main operator (outermost and lowest priority operator)
static int find_main_operator(int p, int q)
{
  int op_position = -1;
  int min_priority = 10; // A relatively large initial value
  int parentheses = 0;

  for (int i = p; i <= q; i++)
  {
    if (tokens[i].type == '(')
    {
      parentheses++;
      continue;
    }
    if (tokens[i].type == ')')
    {
      parentheses--;
      continue;
    }

    // Only look for operators in the part not surrounded by parentheses
    if (parentheses != 0)
      continue;

    int priority = get_priority(tokens[i].type);
    // Choose the lowest priority, if the same, choose the rightmost one
    if (priority > 0 && priority <= min_priority)
    {
      min_priority = priority;
      op_position = i;
    }
  }

  return op_position;
}

/******************************************************************************************** */
/* 递归求值 */

// Recursive function for expression evaluation
static word_t eval(int p, int q, bool *success)
{
  if (p > q)
  {
    // Handle error case: empty expression
    *success = false;
    return 0;
  }
  else if (p == q)
  {
    // Single token, must be a number or register
    word_t val = 0;
    if (tokens[p].type == TK_DEC)
    {
      sscanf(tokens[p].str, "%u", &val);
    }
    else if (tokens[p].type == TK_HEX)
    {
      sscanf(tokens[p].str + 2, "%x", &val); // Skip "0x" prefix
    }
    else if (tokens[p].type == TK_REG)
    {
      bool reg_success = true;
      val = isa_reg_str2val(tokens[p].str + 1, &reg_success); // Skip "$" prefix
      if (!reg_success)
      {
        printf("Invalid register: %s\n", tokens[p].str);
        *success = false;
        return 0;
      }
    }
    else
    {
      printf("Unexpected token type %d at position %d\n", tokens[p].type, p);
      *success = false;
      return 0;
    }
    return val;
  }
  else if (check_parentheses(p, q) == true)
  {
    // Expression surrounded by parentheses, remove them and evaluate recursively
    return eval(p + 1, q - 1, success);
  }
  else
  {
    // 检查是否是解引用操作
    if (tokens[p].type == TK_DEREF && p + 1 <= q)
    {
      // 解引用操作符后面的表达式
      word_t addr = eval(p + 1, q, success);
      if (!*success)
        return 0;

      // 读取指针指向的内存数据
      if (addr == 0)
      {
        printf("Error: 尝试解引用空指针\n");
        *success = false;
        return 0;
      }

      word_t value;
      // 使用ISA相关的内存读取函数，根据NEMU实现可能需要调整
      value = paddr_read(addr, sizeof(word_t));
      return value;
    }

    // 处理二元运算符
    int op = find_main_operator(p, q);
    if (op == -1)
    {
      printf("No valid operator found in expression\n");
      *success = false;
      return 0;
    }

    // Recursively evaluate left and right subexpressions
    word_t val1 = eval(p, op - 1, success);
    if (!*success)
      return 0;

    word_t val2 = eval(op + 1, q, success);
    if (!*success)
      return 0;

    // Perform operation according to the operator
    switch (tokens[op].type)
    {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 * val2;
    case '/':
      if (val2 == 0)
      {
        printf("Division by zero\n");
        *success = false;
        return 0;
      }
      return val1 / val2;
    case TK_EQ:
      return val1 == val2;
    case TK_NEQ:
      return val1 != val2;
    case '>':
      return val1 > val2;
    case '<':
      return val1 < val2;
    case TK_GE: //
      return val1 >= val2;
    case TK_LE: //
      return val1 <= val2;
    case TK_AND:
      return val1 && val2;
    case TK_OR:
      return val1 || val2;
    default:
      printf("Unsupported operator: %d\n", tokens[op].type);
      *success = false;
      return 0;
    }
  }
}

/******************************************************************************************** */
/* 对外接口 - 供其他模块调用的函数 */

word_t expr(char *e, bool *success)
{
  if (!make_token(e))
  {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  *success = true;
  return eval(0, nr_token - 1, success);
}
