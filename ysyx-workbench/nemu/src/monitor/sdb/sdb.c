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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

word_t paddr_read(paddr_t addr, int len);

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
{
  static char *line_read = NULL;

  if (line_read)
  {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read)
  {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args)
{
  cpu_exec(-1);
  return 0;
}

/********************* addition ****************************/
static int cmd_q(char *args)
{
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args)
{
  char *arg = strtok(NULL, " ");
  int N = 1;
  if (arg != NULL)
  {
    sscanf(arg, "%d", &N);
  }
  cpu_exec(N);
  return 0;
}

static int cmd_info(char *args)
{
  char *arg = strtok(NULL, " ");

  if (arg == NULL)
  {
    printf("info r: Print registers\n");
    printf("info w: Print watchpoints\n");
    return 0;
  }
  if (strcmp(arg, "r") == 0)
  {
    isa_reg_display();
  }
  else if (strcmp(arg, "w") == 0)
  {
    print_wp();
  }
  else
  {
    printf("Unknown command info %s\n", arg);
  }
  return 0;
}

static int cmd_x(char *args)
{
  if (args == NULL)
  {
    printf("Usage: x N EXPR - Scan N 4-byte memory units at address EXPR\n");
    return 0;
  }

  char *arg1 = strtok(NULL, " "); // N
  if (arg1 == NULL)
  {
    printf("Error: Missing number of memory units to display\n");
    return 0;
  }

  int n;
  if (sscanf(arg1, "%d", &n) != 1 || n <= 0)
  {
    printf("Error: Invalid number '%s'\n", arg1);
    return 0;
  }

  // 获取EXPR部分，需要处理剩余所有参数，因为表达式可能包含空格
  char *expr_str = strtok(NULL, "");
  if (expr_str == NULL)
  {
    printf("Error: Missing address expression\n");
    return 0;
  }

  // 使用expr()函数计算表达式的值
  bool success = true;
  word_t addr = expr(expr_str, &success);

  if (!success)
  {
    printf("Error: Invalid expression '%s'\n", expr_str);
    return 0;
  }

  // 扫描并打印内存内容
  printf("Memory content at 0x%08x:\n", addr);
  for (int i = 0; i < n; i++)
  {
    // 读取一个字(4字节)的内存
    word_t value = paddr_read(addr + i * sizeof(word_t), sizeof(word_t));

    // 打印地址和值
    printf("0x%08lx: 0x%08x\n", addr + i * sizeof(word_t), value);

    // 每4个单元换行以提高可读性
    if ((i + 1) % 4 == 0 && i + 1 < n)
    {
      printf("\n");
    }
  }

  return 0;
}

static int cmd_w(char *args)
{
  if (args == NULL)
  {
    printf("Usage: w EXPR - Set a watchpoint for expression EXPR\n");
    return 0;
  }

  // 创建监视点
  WP *wp = new_wp(args);
  if (wp == NULL)
  {
    printf("Error: Failed to create watchpoint\n");
    return 0;
  }
  else
  {
    printf("Watchpoint %d: %s = 0x%08x\n", wp->NO, args, wp->old_val);
  }
  return 0;
}

static int cmd_d(char *args)
{
  if (args == NULL)
  {
    printf("Usage: d N - Delete watchpoint N\n");
    return 0;
  }

  int N;
  if (sscanf(args, "%d", &N) != 1)
  {
    printf("Error: Invalid watchpoint number '%s'\n", args);
    return 0;
  }
  else
  {
    free_wp(N);
  }
  return 0;
}

static int cmd_p(char *args)
{
  if (args == NULL)
  {
    printf("Usage: p EXPR - Evaluate expression EXPR\n");
    return 0;
  }

  // 使用expr()函数计算表达式的值
  bool success = true;
  word_t result = expr(args, &success);

  if (success)
  {
    printf("Result: 0x%08x\n", result);
  }
  else
  {
    printf("Error: Invalid expression '%s'\n", args);
  }

  return 0;
}

/***********************************************/

static int cmd_help(char *args);

static struct
{
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},

    /* TODO: Add more commands */
    {"si", "Step one instruction", cmd_si},
    {"info", "Print program state", cmd_info},
    {"x", "Scan memory", cmd_x},
    {"w", "set watchpoint", cmd_w},
    {"d", "delete watchpoint", cmd_d},
    {"p", "print value of expression", cmd_p},

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL)
  {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++)
    {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else
  {
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(arg, cmd_table[i].name) == 0)
      {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode()
{
  is_batch_mode = true;
}

void sdb_mainloop()
{
  if (is_batch_mode)
  {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;)
  {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL)
    {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end)
    {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(cmd, cmd_table[i].name) == 0)
      {
        if (cmd_table[i].handler(args) < 0)
        {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD)
    {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb()
{
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
