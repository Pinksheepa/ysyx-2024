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
    // 从DUT复制到REF (NEMU)
    memcpy(guest_to_host(addr), buf, n);
  }
  else
  {
    // 从REF复制到DUT
    memcpy(buf, guest_to_host(addr), n);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction)
{
  // 根据direction复制寄存器
  if (direction == DIFFTEST_TO_REF)
  {
    // 从DUT复制到REF (NEMU)
    memcpy(&cpu, dut, DIFFTEST_REG_SIZE);
  }
  else
  {
    // 从REF复制到DUT
    memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
  }
}

__EXPORT void difftest_exec(uint64_t n)
{
  // 执行N条指令
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO)
{
  // 暂时不实现，用于中断支持
}

__EXPORT void difftest_init(int port)
{
  void init_mem();
  init_mem();

  // 执行ISA相关的初始化
  init_isa();
}
