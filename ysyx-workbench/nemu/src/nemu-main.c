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

#include <common.h>
#include <stdio.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

// // 声明expr相关函数
// void init_regex();
// word_t expr(char *e, bool *success);

// /********************************** */
// // 测试表达式求值功能
// static void test_expr()
// {
//   FILE *fp = fopen("./tools/gen-expr/input", "r");
//   if (fp == NULL)
//   {
//     printf("无法打开测试文件\n");
//     return;
//   }

//   char line[1024];
//   int pass_count = 0;
//   int total_count = 0;

//   printf("开始测试表达式求值...\n");

//   while (fgets(line, sizeof(line), fp) != NULL)
//   {
//     // 解析每行数据：预期结果和表达式
//     word_t expected;
//     char expression[1024];

//     if (sscanf(line, "%u %[^\n]", &expected, expression) == 2)
//     {
//       total_count++;

//       // 计算表达式的值
//       bool success = true;
//       word_t result = expr(expression, &success);

//       // 检查结果
//       if (success)
//       {
//         if (result == expected)
//         {
//           pass_count++;
//           printf("测试 %d: 通过 - %s = %u\n", total_count, expression, result);
//         }
//         else
//         {
//           printf("测试 %d: 失败 - %s\n  预期: %u, 实际: %u\n",
//                  total_count, expression, expected, result);
//         }
//       }
//       else
//       {
//         printf("测试 %d: 表达式求值失败 - %s\n", total_count, expression);
//       }
//     }
//   }

//   fclose(fp);

//   printf("\n测试完成: %d/%d 通过 (%.2f%%)\n",
//          pass_count, total_count,
//          total_count > 0 ? (pass_count * 100.0 / total_count) : 0);
// }
/********************************** */

int main(int argc, char *argv[])
{

  /********************************** */
  // 初始化正则表达式引擎
  //init_regex();

  // 执行表达式测试
  //test_expr();
  /********************************* */

  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
