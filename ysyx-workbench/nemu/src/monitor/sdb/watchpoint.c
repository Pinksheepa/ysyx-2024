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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
  int i;
  for (i = 0; i < NR_WP; i++)
  {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP *new_wp(char *expr_str)
{
  if (free_ == NULL)
  {
    printf("No more watchpoints available\n");
    return NULL;
  }

  // Get a new watchpoint from the free list
  WP *wp = free_;
  free_ = free_->next;

  // 初始化监视点
  wp->next = NULL;
  strncpy(wp->expr, expr_str, sizeof(wp->expr) - 1);
  wp->expr[sizeof(wp->expr) - 1] = '\0'; // 确保字符串以null结尾
  wp->enabled = true;

  // 计算初始值
  bool success = true;
  wp->old_val = expr(wp->expr, &success);
  if (!success)
  {
    // 计算失败，将节点放回free_链表
    wp->next = free_;
    free_ = wp;
    return NULL;
  }

  if (head == NULL)
  {
    head = wp;
  }
  else
  {
    wp->next = head;
    head = wp;
  }

  return wp;
}

void free_wp(int wp_no)
{
  if (head == NULL)
  {
    printf("Error: No watchpoints to delete\n");
    return;
  }

  WP *prev = NULL;
  WP *curr = head;

  while (curr != NULL && curr->NO != wp_no)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL)
  {
    printf("Error: Cannot find watchpoint number %d\n", wp_no);
    return;
  }

  // Remove from the watchpoint list
  if (prev == NULL)
  {
    head = curr->next;
  }
  else
  {
    prev->next = curr->next;
  }

  // Add back to free list
  curr->next = free_;
  free_ = curr;

  printf("Deleted watchpoint %d: %s\n", wp_no, curr->expr);
  curr->expr[0] = '\0'; // 清空表达式
}

void print_wp()
{
  if (head == NULL)
  {
    printf("No watchpoints\n");
    return;
  }

  WP *current = head;
  printf("Num\tExpr\tValue\n");
  printf("---\t----\t-----\n");
  while (current != NULL)
  {
    printf("%d\t%s\t0x%08x\n", current->NO, current->expr, current->old_val);
    current = current->next;
  }
}

// Check if any watchpoint is triggered
WP *check_wp()
{
  if (head == NULL)
  {
    return NULL;
  }

  WP *current = head;
  while (current != NULL)
  {
    bool success = true;
    word_t new_val = expr(current->expr, &success);
    if (!success)
    {
      printf("Invalid expression: %s\n", current->expr);
      return NULL;
    }

    if (new_val != current->old_val)
    {
      printf("Watchpoint %d: %s\n", current->NO, current->expr);
      printf("Old value: 0x%08x\n", current->old_val);
      printf("New value: 0x%08x\n", new_val);
      current->old_val = new_val;
      return current;
    }

    current = current->next;
  }

  return NULL;
}