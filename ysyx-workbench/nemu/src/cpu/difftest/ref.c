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
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
  if (direction == DIFFTEST_TO_REF)
  {
    // 从DUT复制到NEMU（参考模型）
    memcpy(guest_to_host(addr), buf, n);
  }
  else
  {
    // 从NEMU复制到DUT
    memcpy(buf, guest_to_host(addr), n);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction)
{
  if (direction == DIFFTEST_TO_REF)
  {
    // 从DUT复制到参考模型NEMU
    memcpy(&cpu, dut, DIFFTEST_REG_SIZE);
  }
  else
  {
    // 从参考模型NEMU复制到DUT
    memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
  }
}

__EXPORT void difftest_exec(uint64_t n)
{
  // 执行n条指令
  for (uint64_t i = 0; i < n; i++)
  {
    // 执行一条指令
    cpu_exec(1);
  }
}

__EXPORT void difftest_raise_intr(word_t NO)
{
  // 按照要求，目前暂不使用
  assert(0);
}

__EXPORT void difftest_init(int port)
{
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
