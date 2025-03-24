#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
    "#include <stdio.h>\n"
    "int main() { "
    "  unsigned result = %s; "
    "  printf(\"%%u\", result); "
    "  return 0; "
    "}";

static int choose(int n)
{
  return rand() % n;
}

#define MAX_DEPTH 6

static void gen_expr(int depth)
{
  if (depth >= MAX_DEPTH)
  {
    return;
  }

  switch (choose(3))
  {
  case 0: // number  0-100
    sprintf(buf + strlen(buf), "%u", choose(100));

    break;
    // case 1: // one pair parentheses
    // {
    //   size_t len = strlen(buf);

    //   // 确保空间足够
    //   if (len + 2 < sizeof(buf))
    //   {
    //     // 先将现有内容右移一位，为左括号腾出空间
    //     memmove(buf + 1, buf, len + 1); // +1 for null terminator

    //     // 添加左右括号
    //     buf[0] = '(';
    //     buf[len + 1] = ')';
    //     buf[len + 2] = '\0';
    //   }
    // }
    break;
  case 1: // one operator
    // char op1[4] = {'+', '-', '*', '/'};
    // sprintf(buf + strlen(buf), "%c", op1[choose(4)]);
    // gen_expr(depth + 1);

    // break;

    // 生成带括号的表达式
    strcat(buf, "(");
    gen_expr(depth + 1);
    strcat(buf, ")");
    break;
    // case 2: // left/right parenthesis
    //   sprintf(buf + strlen(buf), "%s", choose(2) ? "(" : ")");
    //   gen_expr(depth + 1);
    //   break;

  case 2: // binary operation
    strcat(buf, "(");

    // sprintf(buf + strlen(buf), "%u", choose(100));
    // 生成左子表达式
    gen_expr(depth + 1);

    char ops[4] = {'+', '-', '*', '/'};
    char op2 = ops[choose(4)];
    sprintf(buf + strlen(buf), "%c", op2);
    if (op2 == '/')
    {
      sprintf(buf + strlen(buf), "%u", choose(100) + 1);
    }
    else
    {
      gen_expr(depth + 1);
    }
    strcat(buf, ")");
    break;
  }
}

static void gen_rand_expr()
{
  buf[0] = '\0';
  gen_expr(0);
}

int main(int argc, char *argv[])
{
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1)
  {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i++)
  {
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0)
      continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
