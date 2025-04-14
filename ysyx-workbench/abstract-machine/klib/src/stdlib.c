#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;
static void *addr = NULL; // 维护上次分配内存位置的变量

int rand(void)
{
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed)
{
  next = seed;
}

int abs(int x)
{
  return (x < 0 ? -x : x);
}

int atoi(const char *nptr)
{
  int x = 0;
  while (*nptr == ' ')
  {
    nptr++;
  }
  while (*nptr >= '0' && *nptr <= '9')
  {
    x = x * 10 + *nptr - '0';
    nptr++;
  }
  return x;
}

void *malloc(size_t size)
{
  // 如果addr为NULL，初始化为堆区起始位置
  if (addr == NULL)
  {
    addr = heap.start;
  }

  // 对齐地址到8字节边界 (满足内存对齐要求)
  size_t aligned_size = (size + 7) & ~7;

  // 检查是否超出堆区范围
  if ((uintptr_t)addr + aligned_size > (uintptr_t)heap.end)
  {
    panic("Malloc: Out of memory");
    return NULL;
  }

  void *old_addr = addr;
  addr = (void *)((uintptr_t)addr + aligned_size);

  return old_addr;
}

void free(void *ptr)
{
  // 不做任何事，表示只分配不释放
}

#endif
