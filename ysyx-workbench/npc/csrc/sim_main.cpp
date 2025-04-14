#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop__Dpi.h"
#include <verilated_dpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

// 模拟器参数定义
#define MAX_SIM_TIME 100000               // 最大模拟周期
#define MEMORY_SIZE (256 * 1024 * 1024) // 256MB
#define PMEM_BASE 0x80000000            // 物理内存起始地址

// 全局变量
static bool simulation_finished = false;
static uint8_t *pmem = NULL;
static bool wave_enable = true;

// 内存映射函数
static inline bool in_pmem_range(uint32_t addr)
{
  return addr >= PMEM_BASE && addr < PMEM_BASE + MEMORY_SIZE;
}

static inline uint8_t *guest_to_host(uint32_t paddr)
{
  // 检查地址是否有效
  assert(in_pmem_range(paddr));
  // 计算主机内存偏移
  return pmem + (paddr - PMEM_BASE);
}

// DPI-C函数实现
extern "C"
{
  // 模拟退出
  void sim_exit(int exit_code)
  {
    if (exit_code == 0)
    {
      printf("\033[1;32m[NPC] HIT GOOD TRAP at ebreak, exit code = %d\033[0m\n", exit_code);
    }
    else
    {
      printf("\033[1;31m[NPC] HIT BAD TRAP at ebreak, exit code = %d\033[0m\n", exit_code);
    }
    simulation_finished = true;
  }

  // 内存读取
  int pmem_read(int addr, int len)
  {
    // 特殊处理0地址 - 这通常发生在复位后第一次取指
    if (addr == 0)
    {
      printf("\033[1;33m[NPC] Memory read from address 0, returning jump to PMEM_BASE\033[0m\n");
      return 0x7001B7; // JAL指令 - 跳转到0x80000000
    }

    // 检查地址是否在有效范围内
    if (!in_pmem_range(addr))
    {
      printf("\033[1;31m[NPC] Memory read out of bounds: 0x%08x\033[0m\n", addr);
      return 0x00000013; // 返回NOP指令(addi x0, x0, 0)而不是0
    }

    uint8_t *haddr = guest_to_host(addr);
    int rdata = 0;

    switch (len)
    {
    case 1:
      rdata = *(uint8_t *)haddr;
      break;
    case 2:
      rdata = *(uint16_t *)haddr;
      break;
    case 4:
      rdata = *(uint32_t *)haddr;
      break;
    default:
      printf("\033[1;31m[NPC] Unsupported read width: %d\033[0m\n", len);
      assert(0);
    }

    return rdata;
  }

  // 内存写入
  void pmem_write(int addr, int data, int len)
  {
    // 检查地址是否在有效范围内
    if (!in_pmem_range(addr))
    {
      printf("\033[1;31m[NPC] Memory write out of bounds: 0x%08x\033[0m\n", addr);
      return;
    }

    uint8_t *haddr = guest_to_host(addr);

    switch (len)
    {
    case 1:
      *(uint8_t *)haddr = data & 0xFF;
      break;
    case 2:
      *(uint16_t *)haddr = data & 0xFFFF;
      break;
    case 4:
      *(uint32_t *)haddr = data;
      break;
    default:
      printf("\033[1;31m[NPC] Unsupported write width: %d\033[0m\n", len);
      assert(0);
    }
  }

  // 添加DPI-C函数用于字符输出
  void npc_putchar(char ch)
  {
    putchar(ch);
    fflush(stdout); // 确保立即输出
  }
}

// 显示使用说明
static void show_usage(const char *prog_name)
{
  printf("Usage: %s [options] [binary_file]\n", prog_name);
  printf("Options:\n");
  printf("  -h, --help         Show this help message\n");
  printf("  -t, --time <n>     Set maximum simulation time (cycles)\n");
  printf("  -w, --wave         Enable waveform dump\n");
  printf("\n");
  printf("Examples:\n");
  printf("  %s program.bin     Load and run program.bin\n", prog_name);
  printf("  %s -w program.bin  Run program.bin with waveform dump enabled\n", prog_name);
  printf("\n");
  printf("Program file is loaded to memory at 0x%08x\n", PMEM_BASE);
}

// 加载程序到内存
static long load_program(const char *filename)
{
  if (filename == NULL)
  {
    printf("\033[1;31m[NPC] No program file specified\033[0m\n");
    return -1;
  }

  printf("\033[1;32m[NPC] Attempting to load program: %s\033[0m\n", filename);

  // 检查文件信息
  struct stat file_stat;
  if (stat(filename, &file_stat) != 0)
  {
    printf("\033[1;31m[NPC] Cannot stat file '%s': %s (errno=%d)\033[0m\n",
           filename, strerror(errno), errno);
    return -1;
  }

  printf("\033[1;32m[NPC] File exists, size: %ld bytes, permissions: %o\033[0m\n",
         file_stat.st_size, file_stat.st_mode & 0777);

  // 打开文件
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL)
  {
    printf("\033[1;31m[NPC] Cannot open '%s': %s (errno=%d)\033[0m\n",
           filename, strerror(errno), errno);
    return -1;
  }

  // 检查程序大小是否超出内存范围
  if (file_stat.st_size > MEMORY_SIZE)
  {
    printf("\033[1;31m[NPC] Program too large: %ld bytes > %d bytes\033[0m\n",
           file_stat.st_size, MEMORY_SIZE);
    fclose(fp);
    return -1;
  }

  // 读取文件内容到内存，直接使用内存映射
  uint8_t *prog_start = guest_to_host(PMEM_BASE);
  size_t bytes_read = fread(prog_start, 1, file_stat.st_size, fp);
  if (bytes_read != (size_t)file_stat.st_size)
  {
    printf("\033[1;31m[NPC] Error reading '%s': read %ld of %ld bytes: %s\033[0m\n",
           filename, bytes_read, (long)file_stat.st_size,
           ferror(fp) ? strerror(errno) : "Incomplete read");
    fclose(fp);
    return -1;
  }

  fclose(fp);
  printf("\033[1;32m[NPC] Program '%s' loaded successfully, size: %ld bytes\033[0m\n",
         filename, (long)file_stat.st_size);

  // 打印加载的前16个字节，用于调试
  printf("\033[1;32m[NPC] Program header (first 16 bytes):\033[0m ");
  for (int i = 0; i < 16 && i < file_stat.st_size; i++)
  {
    printf("%02x ", prog_start[i]);
  }
  printf("\n");
  printf("\033[1;32m[NPC] Program loaded at address 0x%08x\033[0m\n", PMEM_BASE);

  return file_stat.st_size;
}

// 主函数
int main(int argc, char *argv[])
{
  // 初始化上下文
  Verilated::commandArgs(argc, argv);

  // 解析命令行参数
  const char *program_file = NULL;
  uint64_t max_sim_time = MAX_SIM_TIME;

  printf("[NPC] Command line arguments: ");
  for (int i = 0; i < argc; i++)
  {
    printf("%s ", argv[i]);
  }
  printf("\n");

  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
    {
      show_usage(argv[0]);
      return 0;
    }
    else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--wave") == 0)
    {
      wave_enable = true;
    }
    else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--time") == 0)
    {
      if (i + 1 < argc)
      {
        max_sim_time = atoll(argv[i + 1]);
        i++;
      }
    }
    else if (argv[i][0] != '-')
    {
      program_file = argv[i];
    }
    else
    {
      printf("\033[1;33m[NPC] Unknown option: %s\033[0m\n", argv[i]);
    }
  }

  printf("[NPC] Program file: %s\n", program_file ? program_file : "None");
  if (program_file == NULL)
  {
    printf("\033[1;31m[NPC] Error: No program file specified\033[0m\n");
    show_usage(argv[0]);
    return -1;
  }

  // 初始化模拟内存
  pmem = (uint8_t *)malloc(MEMORY_SIZE);
  if (pmem == NULL)
  {
    printf("\033[1;31m[NPC] Failed to allocate memory: %s\033[0m\n", strerror(errno));
    return -1;
  }

  // 清零内存
  memset(pmem, 0, MEMORY_SIZE);
  printf("\033[1;32m[NPC] Allocated %d MB memory at %p\033[0m\n", MEMORY_SIZE / 1024 / 1024, pmem);
  printf("\033[1;32m[NPC] Memory mapped from 0x%08x to 0x%08x\033[0m\n",
         PMEM_BASE, PMEM_BASE + MEMORY_SIZE - 1);

  // 加载程序
  if (program_file != NULL)
  {
    if (load_program(program_file) < 0)
    {
      printf("\033[1;31m[NPC] Failed to load program, exiting\033[0m\n");
      free(pmem);
      return -1;
    }
  }
  else
  {
    printf("\033[1;33m[NPC] No program specified, simulation will start with empty memory\033[0m\n");
  }

  // 初始化Verilator模型
  Vtop *top = new Vtop;

  // 设置波形跟踪
  VerilatedVcdC *tfp = NULL;
  if (wave_enable)
  {
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");
  }

  // 仿真时间和时钟初始化
  uint64_t sim_time = 0;
  bool clk = 0;

  // 主仿真循环
  while (!simulation_finished && sim_time < max_sim_time)
  {
    // 设置信号
    top->clk = clk;
    top->rst = (sim_time < 10) ? 1 : 0;

    // 评估模型
    top->eval();

    // 更新波形
    if (wave_enable)
    {
      tfp->dump(sim_time);
    }

    // 翻转时钟
    clk = !clk;
    sim_time++;

    // 每1000个周期输出一次进度
    if (sim_time % 1000 == 0)
    {
      printf("\r[NPC] Simulation time: %ld cycles", sim_time);
      fflush(stdout);
    }
  }

  // 仿真结束
  printf("\n[NPC] Simulation finished after %ld cycles\n", sim_time);

  // 清理资源
  if (wave_enable)
  {
    tfp->close();
    delete tfp;
  }

  delete top;
  free(pmem);

  return 0;
}
