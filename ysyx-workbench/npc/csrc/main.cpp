#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "Vtop___024root.h"
// dpi-c
#include "Vtop__Dpi.h"
#include <verilated_dpi.h>
// glibc
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Difftest
#include <dlfcn.h>
// readline
#include <readline/readline.h>
#include <readline/history.h>
// system time
#include <sys/time.h>

// 用于DPI-C通信的标志
static bool simulation_finished = false;

#ifdef __cplusplus
extern "C"
{
#endif

void sim_exit()
{
  printf("\033[1;32m[NPC] EBREAK instruction executed, simulation terminated\033[0m\n");
simulation_finished = true;  // 设置标志而不是直接退出
      // 不使用exit(0)以允许正常清理资源
  }

#ifdef __cplusplus
}
#endif

// 单步执行的最大周期数
#define MAX_SIM_TIME 1000
// 波形文件路径
#define WAVE_FILE "waveform.vcd"
// 是否启用波形追踪
bool wave_enable = true;

int main(int argc, char *argv[])
{
  // 初始化上下文
  Verilated::commandArgs(argc, argv);
  Vtop *top = new Vtop;

  // 设置波形跟踪
  VerilatedVcdC *tfp = nullptr;

  if (wave_enable)
  {
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99); // 跟踪99级信号深度
    tfp->open(WAVE_FILE);
    printf("波形记录已启用，文件路径: %s\n", WAVE_FILE);
  }

  // 仿真时间和时钟初始化
  uint64_t sim_time = 0;
  bool clk = 0;

  // 主仿真循环 - 检查simulation_finished标志
  while (!simulation_finished && sim_time < MAX_SIM_TIME)
  {
    // 设置时钟信号
    top->clk = clk;

    // 设置复位信号（前10个时钟周期保持复位）
    top->rst = (sim_time < 10) ? 1 : 0;

    // 评估模型状态
    top->eval();

    // 记录波形
    if (tfp)
    {
      tfp->dump(sim_time);
    }

    // 如果是时钟上升沿，打印调试信息
    if (clk && sim_time >= 10)
    {
      printf("Simulation time: %ld\n", sim_time);
    }

    // 翻转时钟
    clk = !clk;
    sim_time++;
  }

  // 完成仿真
  if (sim_time >= MAX_SIM_TIME)
  {
    printf("仿真达到最大周期数 %d，退出\n", MAX_SIM_TIME);
  }

  // 关闭波形文件
  if (tfp)
  {
    tfp->close();
    delete tfp;
  }

  // 清理对象
  delete top;

  return 0;
}
