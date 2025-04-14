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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

extern const char *regs[];

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  bool is_same = true;
  
  // 检查所有通用寄存器(x0-x31)
  for (int i = 0; i < 32; i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf("difftest: reg %s (x%d) mismatch, ref=0x%08x, dut=0x%08x\n",
             regs[i], i, ref_r->gpr[i], cpu.gpr[i]);
      is_same = false;
    }
  }

  // 检查PC寄存器
  // if (ref_r->pc != pc) {
  //   printf("difftest: PC mismatch, ref=0x%08x, dut=0x%08x\n", ref_r->pc, pc);
  //   is_same = false;
  // }

  // 检查CSR寄存器(可选)
  #ifdef CONFIG_RV_CSR
  if (ref_r->csr != cpu.csr) {
    printf("difftest: CSR mismatch, ref=0x%08x, dut=0x%08x\n", ref_r->csr, cpu.csr);
    is_same = false;
  }
  #endif

  return is_same;
}

void isa_difftest_attach()
{
}
