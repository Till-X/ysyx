/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
   bool ret = true;
  for (int i = 0; i < 32; i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      ret = false;
    }
  }
  if (ref_r->pc != cpu.pc) {
    printf("pc,err!!");
    ret = false;
  }

  if (ret != true) {
    printf("---------------------------dut------------------------------\n");
    for (size_t i = 0; i < 16; i++) {
      printf("%s:%16d\t\t%s:%16d\n", reg_name(i), cpu.gpr[i], reg_name(i + 16), cpu.gpr[i + 16]);
    }
    printf("\tpc:%08x\n", cpu.pc);
    printf("---------------------------ref------------------------------\n");
    for (size_t i = 0; i < 16; i++) {
      printf("%s:%16d\t\t%s:%16d\n", reg_name(i), ref_r->gpr[i], reg_name(i + 16), ref_r->gpr[i + 16]);
    }
    printf("\tpc:%08x\n", ref_r->pc);
    printf("------------------------------------------------------------\n");
  }

  return ret;

  // for (int i = 0; i < 32; i++) {
  //   /* 打印寄存器名称和内容 */
  //   printf("%d:%s\t%lx\n", i, reg_name(i, 64), gpr(i));
  // }
  // /* pc 寄存器 */
  // printf("%d:%s\t%lx\n", 33, "pc", cpu.pc);
}

void isa_difftest_attach() {
}
