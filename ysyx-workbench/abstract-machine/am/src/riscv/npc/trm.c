#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch)
{
}

void halt(int code)
{
  // 设置返回码到 a0 寄存器
  register int a0 asm("a0") = code;

  // 执行 ebreak 指令
  asm volatile("ebreak" ::"r"(a0));

  // 以下不应该被执行到
  while (1)
    ;
}

void _trm_init()
{
  // 使用我们定义的mainargs变量，而不是__am_mainargs
  const char *args = mainargs;

  int ret = main(args);
  halt(ret);
}
