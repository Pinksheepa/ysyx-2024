#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <dlfcn.h>

// 定义REF寄存器结构体，仿照NEMU中的结构
typedef struct
{
    uint32_t gpr[32];
    uint32_t pc;
} CPU_state;

// DiffTest导出函数原型
typedef void (*difftest_memcpy_t)(uint32_t addr, void *buf, size_t n, bool direction);
typedef void (*difftest_regcpy_t)(void *dut, bool direction);
typedef void (*difftest_exec_t)(uint64_t n);
typedef void (*difftest_raise_intr_t)(uint64_t NO);
typedef void (*difftest_init_t)(int port);

// DiffTest方向
enum
{
    DIFFTEST_TO_DUT,
    DIFFTEST_TO_REF
};

// 打开DiffTest功能
void difftest_init(const char *ref_so_file, long img_size);

// 执行一步DiffTest
void difftest_step(uint32_t pc);

// 关闭DiffTest功能
void difftest_close();

// 从REF复制寄存器到DUT
void difftest_regcpy_from_ref(CPU_state *dut);

// 从DUT复制寄存器到REF
void difftest_regcpy_to_ref(CPU_state *dut);

// 复制内存到REF
void difftest_memcpy_to_ref(uint32_t addr, void *buf, size_t n);

// 让REF跳过一步比较
void difftest_skip_ref();

#endif // __DIFFTEST_H__