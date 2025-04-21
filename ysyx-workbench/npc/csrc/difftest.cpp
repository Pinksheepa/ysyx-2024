#include "difftest.h"
#include "log.h"
#include <stdio.h>

// 声明get_gpr函数，该函数在sim_main.cpp中定义
extern "C" int get_gpr(int index);

// DiffTest相关函数指针
static difftest_memcpy_t ref_difftest_memcpy = NULL;
static difftest_regcpy_t ref_difftest_regcpy = NULL;
static difftest_exec_t ref_difftest_exec = NULL;
static difftest_raise_intr_t ref_difftest_raise_intr = NULL;
static difftest_init_t ref_difftest_init = NULL;

// 动态库句柄
static void *handle = NULL;

// DiffTest是否启用标志
static bool is_difftest_enabled = false;

// 是否跳过REF的比较标志
static bool skip_ref_once = false;

// 初始化DiffTest
void difftest_init(const char *ref_so_file, long img_size)
{
    assert(ref_so_file != NULL);

    // 打开动态库
    handle = dlopen(ref_so_file, RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Failed to open %s: %s\n", ref_so_file, dlerror());
        assert(0);
        return;
    }

    // 获取动态库中的函数指针
    ref_difftest_memcpy = (difftest_memcpy_t)dlsym(handle, "difftest_memcpy");
    assert(ref_difftest_memcpy);

    ref_difftest_regcpy = (difftest_regcpy_t)dlsym(handle, "difftest_regcpy");
    assert(ref_difftest_regcpy);

    ref_difftest_exec = (difftest_exec_t)dlsym(handle, "difftest_exec");
    assert(ref_difftest_exec);

    ref_difftest_raise_intr = (difftest_raise_intr_t)dlsym(handle, "difftest_raise_intr");
    assert(ref_difftest_raise_intr);

    ref_difftest_init = (difftest_init_t)dlsym(handle, "difftest_init");
    assert(ref_difftest_init);

    // 初始化REF
    ref_difftest_init(0);

    // 设置标志位
    is_difftest_enabled = true;

    printf("DiffTest模式已启用: %s\n", ref_so_file);
}

// 关闭DiffTest
void difftest_close()
{
    if (handle)
    {
        dlclose(handle);
        handle = NULL;
    }
    is_difftest_enabled = false;
}

// 从REF复制寄存器到DUT
void difftest_regcpy_from_ref(CPU_state *dut)
{
    if (!is_difftest_enabled)
        return;
    ref_difftest_regcpy(dut, DIFFTEST_TO_DUT);
}

// 从DUT复制寄存器到REF
void difftest_regcpy_to_ref(CPU_state *dut)
{
    if (!is_difftest_enabled)
        return;
    ref_difftest_regcpy(dut, DIFFTEST_TO_REF);
}

// 复制内存到REF
void difftest_memcpy_to_ref(uint32_t addr, void *buf, size_t n)
{
    if (!is_difftest_enabled)
        return;
    ref_difftest_memcpy(addr, buf, n, DIFFTEST_TO_REF);
}

// 跳过REF的比较
void difftest_skip_ref()
{
    skip_ref_once = true;
}

// DiffTest的单步执行比较
void difftest_step(uint32_t pc)
{
    if (!is_difftest_enabled)
        return;

    // 如果需要跳过，则直接同步寄存器状态而不做比较
    if (skip_ref_once)
    {
        CPU_state dut;
        // 从全局函数获取当前DUT的寄存器状态
        for (int i = 0; i < 32; i++)
        {
            dut.gpr[i] = get_gpr(i);
        }
        dut.pc = pc;

        // 把当前寄存器状态同步到REF
        ref_difftest_regcpy(&dut, DIFFTEST_TO_REF);
        skip_ref_once = false;
        return;
    }

    // 让REF执行一步
    ref_difftest_exec(1);

    // 获取REF执行后的寄存器状态
    CPU_state ref;
    ref_difftest_regcpy(&ref, DIFFTEST_TO_DUT);

    // 获取DUT执行后的寄存器状态
    CPU_state dut;
    // 填充DUT的寄存器值
    for (int i = 0; i < 32; i++)
    {
        dut.gpr[i] = get_gpr(i);
    }
    dut.pc = pc;

    // 比较寄存器状态
    bool is_same = true;
    for (int i = 0; i < 32; i++)
    {
        if (ref.gpr[i] != dut.gpr[i])
        {
            printf("DiffTest失败: r%d 不匹配, REF = 0x%08x, DUT = 0x%08x, PC = 0x%08x\n",
                   i, ref.gpr[i], dut.gpr[i], pc);
            is_same = false;
        }
    }

    if (ref.pc != pc)
    {
        printf("DiffTest失败: PC 不匹配, REF = 0x%08x, DUT = 0x%08x\n", ref.pc, pc);
        is_same = false;
    }

    // 如果比较失败，可以根据需要采取行动
    if (!is_same)
    {
        // 例如停止模拟
        // assert(0);
    }
}