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

#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

// Forward declaration of watchpoint structure
typedef struct watchpoint
{
    int NO;                  // watchpoint number
    struct watchpoint *next; // next watchpoint

    /* TODO: Add more members if necessary */
    char expr[128];
    word_t old_val;
    bool enabled;
} WP;

word_t expr(char *e, bool *success);

WP *new_wp(char *expr);
void free_wp(int wp_no);
void print_wp();
WP *check_wp();

#endif
