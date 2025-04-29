#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "verilated_dpi.h"
#include "Vtop.h"
// 添加Vtop___024root.h头文件，使用正确的相对路径
#include "../obj_dir/Vtop___024root.h"
#include "log.h"
#include "sdb.h"      // 添加SDB头文件
#include "difftest.h" // 添加DiffTest头文件

// 添加全局变量用于控制仿真结束
static bool ebreak_triggered = false;
static int trap_code = 0; // 用于存储退出代码，0表示GOOD TRAP，其他值表示BAD TRAP

// 添加指向顶层模块的全局指针
static Vtop *top_module = nullptr;

// DPI-C export implementation
extern "C" int get_gpr(int index)
{
  if (top_module && index >= 0 && index < 32)
  {
    // 修改寄存器访问路径，与Verilog代码结构匹配
    // 寄存器文件位于顶层模块中，而不是EXU模块内
    return top_module->rootp->top__DOT__regfile__DOT__registers[index];
  }
  return 0;
}

// DPI-C - 处理ECALL指令，实现系统调用
extern "C" void npc_ecall(int a0_value)
{
  // 简单的ECALL处理，检查a0寄存器值确定系统调用类型
  printf("\n\033[1;34m[npc] ECALL instruction executed with a0 = %d\033[0m\n", a0_value);

  // 根据a0值处理不同的系统调用（符合RISC-V约定）
  switch (a0_value)
  {
  case 0: // SYS_exit
    printf("\033[1;34m[npc] System call: exit(0)\033[0m\n");
    trap_code = 0;
    ebreak_triggered = true; // 也使用ebreak_triggered终止仿真
    break;

  case 1:                                                                                    // SYS_exit with error code
    printf("\033[1;31m[npc] System call: exit(%d) - with error code\033[0m\n", get_gpr(11)); // a1寄存器
    trap_code = get_gpr(11);                                                                 // 使用a1作为退出码
    ebreak_triggered = true;
    break;

  // 可以根据需要添加更多系统调用
  default:
    printf("\033[1;33m[npc] Unhandled system call: %d\033[0m\n", a0_value);
    break;
  }
}

// DPI-C - 在Verilog中通过npc_ebreak()调用，a0_value是从Verilog传递过来的a0寄存器值
extern "C" void npc_ebreak(int a0_value)
{
  // 直接使用传入的a0寄存器值
  trap_code = a0_value;
  printf("\n\033[1;32m[npc] EBREAK instruction executed\033[0m\n");
  if (trap_code == 0)
  {
    printf("\033[1;32m[npc] HIT GOOD TRAP\033[0m\n");
  }
  else
  {
    printf("\033[1;31m[npc] HIT BAD TRAP, exit code = %d\033[0m\n", trap_code);
  }
  ebreak_triggered = true;
}

// 内存大小定义
#define MEM_SIZE (1024 * 1024) // 1MB 内存
#define IMEM_BASE 0x80000000   // 指令内存基地址
#define DMEM_BASE 0x80100000   // 数据内存基地址

// DiffTest相关路径
#define NEMU_SO_PATH "../nemu/build/riscv32-nemu-interpreter-so"

// 存储器类，用于模拟物理内存
class Memory
{
private:
  uint8_t *mem;
  size_t size;

public:
  Memory(size_t size) : size(size)
  {
    mem = new uint8_t[size](); // 分配并初始化为0
    printf("[npc] Memory initialized, size = %zu bytes\n", size);
  }

  ~Memory()
  {
    delete[] mem;
    printf("[npc] Memory freed\n");
  }

  // 按字节读取
  uint8_t readByte(uint32_t addr)
  {
    if (addr >= size)
    {
      Log_Error("Memory read out of bounds at 0x%08x", addr);
      return 0;
    }
    return mem[addr];
  }

  // 按字（32位）读取
  uint32_t readWord(uint32_t addr)
  {
    if (addr + 3 >= size)
    {
      Log_Error("Memory read out of bounds at 0x%08x", addr);
      return 0;
    }
    return (uint32_t)readByte(addr) |
           ((uint32_t)readByte(addr + 1) << 8) |
           ((uint32_t)readByte(addr + 2) << 16) |
           ((uint32_t)readByte(addr + 3) << 24);
  }

  // 按字节写入
  void writeByte(uint32_t addr, uint8_t data)
  {
    if (addr >= size)
    {
      Log_Error("Memory write out of bounds at 0x%08x", addr);
      return;
    }
    mem[addr] = data;
  }

  // 按字（32位）写入
  void writeWord(uint32_t addr, uint32_t data)
  {
    if (addr + 3 >= size)
    {
      Log_Error("Memory write out of bounds at 0x%08x", addr);
      return;
    }
    writeByte(addr, data & 0xFF);
    writeByte(addr + 1, (data >> 8) & 0xFF);
    writeByte(addr + 2, (data >> 16) & 0xFF);
    writeByte(addr + 3, (data >> 24) & 0xFF);
  }

  // 获取内存指针，用于DiffTest复制内存
  uint8_t *getMemPtr()
  {
    return mem;
  }

  // 加载ELF文件或二进制文件（简化实现）
  bool loadBinary(const char *filename, uint32_t offset = 0)
  {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
      Log_Error("Cannot open file %s", filename);
      return false;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (offset + fileSize > size)
    {
      Log_Error("File too large to fit in memory");
      fclose(fp);
      return false;
    }

    size_t result = fread(mem + offset, 1, fileSize, fp);
    if (result != (size_t)fileSize)
    {
      Log_Error("Failed to read file");
      fclose(fp);
      return false;
    }

    fclose(fp);
    printf("[npc] Loaded %ld bytes from %s to memory at offset 0x%08x\n", fileSize, filename, offset);
    return true;
  }

  // 打印内存内容（调试用）
  void dump(uint32_t start, uint32_t length)
  {
    printf("[npc] Memory dump from 0x%08x, length %d bytes:\n", start, length);
    for (uint32_t i = 0; i < length; i += 4)
    {
      if (i % 16 == 0)
      {
        printf("\n0x%08x: ", start + i);
      }
      printf("%08x ", readWord(start + i));
    }
    printf("\n");
  }
};

// 处理器仿真器类
class Simulator
{
private:
  std::unique_ptr<VerilatedContext> contextp;
  std::unique_ptr<Vtop> top;
  std::unique_ptr<VerilatedVcdC> tfp; // 波形追踪
  std::unique_ptr<Memory> memory;
  std::unique_ptr<SDB> sdb; // 添加SDB调试器

  vluint64_t main_time;
  bool is_batch_mode;   // 批处理模式标志
  bool enable_difftest; // DiffTest使能标志

public:
  Simulator(bool batch_mode = false, bool diff_test = false)
      : main_time(0), is_batch_mode(batch_mode), enable_difftest(diff_test)
  {
    // 初始化仿真环境
    contextp = std::make_unique<VerilatedContext>();
    top = std::make_unique<Vtop>(contextp.get());

    // 设置全局指针
    top_module = top.get();

    // 初始化波形追踪
    Verilated::traceEverOn(true);
    tfp = std::make_unique<VerilatedVcdC>();
    top->trace(tfp.get(), 99);
    tfp->open("wave.vcd");

    // 初始化内存
    memory = std::make_unique<Memory>(MEM_SIZE);

    // 初始信号
    top->clk = 0;
    top->rst = 1; // 初始复位

    // 初始化SDB调试器
    sdb = std::make_unique<SDB>(this, batch_mode);
    sdb->init_sdb();

    printf("[npc] Simulator initialized\n");
  }

  ~Simulator()
  {
    tfp->close();
    printf("[npc] Simulator finished\n");

    // 关闭DiffTest
    if (enable_difftest)
    {
      difftest_close();
    }
  }

  // 加载指令到内存
  bool loadProgram(const char *filename)
  {
    bool result = memory->loadBinary(filename, IMEM_BASE - IMEM_BASE);

    // 如果启用了DiffTest，则初始化DiffTest
    if (result && enable_difftest)
    {
      // 获取文件大小
      FILE *fp = fopen(filename, "rb");
      if (fp == NULL)
      {
        return false;
      }
      fseek(fp, 0, SEEK_END);
      long img_size = ftell(fp);
      fclose(fp);

      // 初始化DiffTest
      difftest_init(NEMU_SO_PATH, img_size);

      // 复制镜像到REF
      difftest_memcpy_to_ref(IMEM_BASE, memory->getMemPtr(), img_size);

      // 初始化REF的CPU状态
      CPU_state init_state;
      memset(&init_state, 0, sizeof(init_state));
      init_state.pc = IMEM_BASE; // 设置初始PC
      difftest_regcpy_to_ref(&init_state);

      printf("[npc] DiffTest initialized with %s\n", NEMU_SO_PATH);
    }

    return result;
  }

  void loadInstructions()
  {
    // 计算物理内存偏移 - 从IMEM_BASE的物理内存位置开始存储指令
    uint32_t physOffset = 0; // 物理内存从0开始，对应逻辑地址IMEM_BASE (0x80000000)

    // addi x1, x0, 10
    memory->writeWord(physOffset, 0x00A00093);
    physOffset += 4;

    // addi x2, x0, 20
    memory->writeWord(physOffset, 0x01400113);
    physOffset += 4;
 
    // add x3, x1, x2
    memory->writeWord(physOffset, 0x002081B3);
    physOffset += 4;

    memory->writeWord(physOffset, 0x00100073);
    physOffset += 8;

    printf("[npc] Instructions loaded to memory starting at physical offset 0x%08x (maps to 0x%08x)\n",
           0, IMEM_BASE);

    // 调试信息 - 打印加载的指令
    printf("[npc] Loaded instructions:\n");
    for (uint32_t i = 0; i < 4; i++)
    {
      printf("  0x%08x: 0x%08x\n", IMEM_BASE + i * 4, memory->readWord(i * 4));
    }

    // 如果启用了DiffTest，则初始化DiffTest
    if (enable_difftest)
    {
      // 初始化DiffTest
      difftest_init(NEMU_SO_PATH, 4 * 4); // 4条指令，每条4字节

      // 复制指令到REF
      difftest_memcpy_to_ref(IMEM_BASE, memory->getMemPtr(), 4 * 4);

      // 初始化REF的CPU状态
      CPU_state init_state;
      memset(&init_state, 0, sizeof(init_state));
      init_state.pc = IMEM_BASE; // 设置初始PC
      difftest_regcpy_to_ref(&init_state);

      printf("[npc] DiffTest initialized with %s\n", NEMU_SO_PATH);
    }
  }

  // 运行一个时钟周期
  void step()
  {
    // 时钟信号翻转
    top->clk = !top->clk;

    // 在时钟上升沿之前处理存储器访问
    if (top->clk == 1)
    {
      // 处理指令内存访问
      if (top->imem_valid)
      {
        // 计算物理内存偏移
        uint32_t physAddr = 0;
        if (top->imem_addr >= IMEM_BASE)
        {
          physAddr = top->imem_addr - IMEM_BASE;
          if (physAddr < MEM_SIZE)
          {
            uint32_t data = memory->readWord(physAddr);
            top->imem_rdata = data;
            // printf("IMEM read: addr=0x%08x, physAddr=0x%08x, data=0x%08x\n",
            //       top->imem_addr, physAddr, data);
          }
          else
          {
            Log_Warning("Physical address 0x%08x out of range", physAddr);
            top->imem_rdata = 0; // 读取无效数据返回0
          }
        }
        else
        {
          if (top->rst != 1)
          {
            Log_Warning("Invalid instruction address 0x%08x", top->imem_addr);
            top->imem_rdata = 0; // 无效地址返回0指令
          }
        }
      }

      // 处理数据内存访问
      if (top->dmem_valid)
      {
        // 直接使用传入的dmem_addr，因为地址计算已在Verilog中完成
        uint32_t addr = top->dmem_addr;
        uint32_t physAddr = 0;

        // 根据地址范围确定物理地址映射
        if (addr >= IMEM_BASE && addr < DMEM_BASE)
        {
          physAddr = addr - IMEM_BASE;
        }
        else if (addr >= DMEM_BASE)
        {
          physAddr = addr - DMEM_BASE;
        }
        else
        {
          Log_Warning("Invalid data address111 0x%08x", addr);
          if (!top->dmem_wen)
          {
            top->dmem_rdata = 0;
          }
          return;
        }

        if (physAddr < MEM_SIZE)
        {
          if (top->dmem_wen)
          { // 写操作
            memory->writeWord(physAddr, top->dmem_wdata);

            // DiffTest：同步内存写操作
            if (enable_difftest)
            {
              difftest_memcpy_to_ref(addr, &top->dmem_wdata, 4);
            }
          }
          else
          { // 读操作
            uint32_t data = memory->readWord(physAddr);
            top->dmem_rdata = data;
          }
        }
        else
        {
          Log_Warning("Physical address 0x%08x out of range", physAddr);
          if (!top->dmem_wen)
          {
            top->dmem_rdata = 0;
          }
        }
      }
    }

    // 求值并推进仿真时间
    top->eval();
    tfp->dump(main_time);
    main_time++;

    // 在复位后的第一个时钟周期取消复位
    if (main_time == 3)
    {
      top->rst = 0;
    }

    // 执行DiffTest
    static uint32_t lastPC = 0;
    static bool instrCompleted = false;

    // 在时钟下降沿检查是否完成一条指令
    if (top->clk == 0)
    {
      uint32_t currentPC = getPC();

      // 如果PC发生变化，说明完成了一条指令
      if (currentPC != lastPC && lastPC != 0)
      {
        instrCompleted = true;
      }

      lastPC = currentPC;

      // 如果完成了一条指令且启用了DiffTest，进行DiffTest检查
      if (instrCompleted && enable_difftest)
      {
        // 构造当前CPU状态
        CPU_state dut_state;
        memset(&dut_state, 0, sizeof(dut_state));

        // 获取通用寄存器
        for (int i = 0; i < 32; i++)
        {
          dut_state.gpr[i] = get_gpr(i);
        }

        // 获取PC（这里用的是当前PC，因为PC已经更新到下一条指令）
        dut_state.pc = currentPC;

        // 执行DiffTest
        difftest_step(currentPC);

        instrCompleted = false;
      }
    }
  }

  // 连续运行多个周期
  void run(int cycles)
  {
    for (int i = 0; i < cycles * 2; i++)
    {
      step();
    }
  }

  // 持续运行直到达到某个条件
  void runUntil(std::function<bool(Vtop *)> stopCondition, int maxCycles = 1000000)
  {
    int cycles = 0;
    while (!stopCondition(top.get()) && cycles < maxCycles && !ebreak_triggered)
    {
      step();
      if (top->clk == 0)
      { // 只在下降沿计数
        cycles++;
      }
    }

    if (cycles >= maxCycles)
    {
      Log_Warning("Reached maximum cycle count (%d)", maxCycles);
    }
    else if (ebreak_triggered)
    {
      printf("\033[1;32m[npc] ----- ebreak at 0x%08x -----\033[0m\n", getPC());
      if (trap_code == 0)
      {
        printf("\033[1;32m[npc] GOOD TRAP\033[0m\n");
      }
      else
      {
        printf("\033[1;31m[npc] BAD TRAP, code = %d\033[0m\n", trap_code);
      }
    }
    else
    {
      printf("[npc] Simulation stopped after %d cycles\n", cycles);
    }
  }

  // 获取当前PC值
  uint32_t getPC()
  {
    // 使用公开的 imem_addr 接口代替内部 PC 访问
    return top->imem_addr;
  }

  // 打印处理器状态
  void printStatus()
  {
    printf("[npc] Current PC: 0x%08x\n", getPC());
    printf("[npc] Current Instruction: 0x%08x\n", top->imem_rdata);
  }

  // 读取内存的方法（供SDB使用）
  uint32_t readMemory(uint32_t addr)
  {
    // 计算物理地址
    uint32_t physAddr;
    if (addr >= IMEM_BASE && addr < DMEM_BASE)
    {
      physAddr = addr - IMEM_BASE;
    }
    else if (addr >= DMEM_BASE)
    {
      physAddr = addr - DMEM_BASE;
    }
    else
    {
      // 无效地址
      Log_Warning("Invalid memory address 0x%08x", addr);
      return 0;
    }

    if (physAddr >= MEM_SIZE)
    {
      Log_Warning("Memory address 0x%08x out of range", addr);
      return 0;
    }

    return memory->readWord(physAddr);
  }

  // 开始交互式调试会话
  void startDebugSession()
  {
    if (!is_batch_mode)
    {
      printf("[npc] Starting debug session. Type 'help' for commands.\n");
      sdb->sdb_mainloop();
    }
  }

  // 设置DiffTest模式
  void setDiffTest(bool enable)
  {
    enable_difftest = enable;
  }

  // 获取DiffTest模式状态
  bool isDiffTestEnabled() const
  {
    return enable_difftest;
  }
};

// 为SDB提供的辅助函数
uint32_t get_pc(Simulator *sim)
{
  return sim->getPC();
}

uint32_t read_memory(Simulator *sim, uint32_t addr)
{
  return sim->readMemory(addr);
}

void execute_n_cycles(Simulator *sim, int n)
{
  // 执行n条指令（近似值，实际上是执行2*n个周期）
  sim->run(n);
}

// 为SDB提供的辅助函数，用于持续运行至结束或中断
void run_until_end(Simulator *sim, int maxCycles = 10000000)
{
  sim->runUntil([](Vtop *top)
                {
                  return false; // 返回false让仿真持续运行，直到ebreak触发或达到最大周期
                },
                maxCycles);
}

// 程序入口
int main(int argc, char **argv)
{
  // 分析命令行参数
  bool batch_mode = false;
  bool diff_test = false; // 新增DiffTest参数

  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "--batch") == 0)
    {
      batch_mode = true;
    }
    else if (strcmp(argv[i], "--diff") == 0)
    {
      diff_test = true; // 开启DiffTest模式
    }
  }

  // 初始化Verilator
  Verilated::commandArgs(argc, argv);

  // 创建仿真器，传入DiffTest模式标志
  Simulator sim(batch_mode, diff_test);

  // 检查是否提供了二进制文件路径
  const char *progFile = nullptr;
  for (int i = 1; i < argc; i++)
  {
    if (strncmp(argv[i], "--", 2) != 0)
    {
      // 不是选项参数，认为是程序文件
      progFile = argv[i];
      break;
    }
  }

  if (progFile)
  {
    if (!sim.loadProgram(progFile))
    {
      Log_Error("Can't load program! %s", progFile);
      return 1;
    }
    printf("[npc] Loading: %s\n", progFile);
  }
  else
  {
    printf("[npc] No program provided!\n");
    sim.loadInstructions();
  }

  printf("[npc] Starting simulation...\n");

  if (batch_mode)
  {
    // 批处理模式：直接运行到结束
    sim.runUntil([](Vtop *top)
                 {
                   return false; // 返回false让仿真继续，直到ebreak触发或达到最大周期
                 },
                 1000000);
    printf("[npc] Simulation completed\n");
  }
  else
  {
    // 交互模式：启动调试会话
    sim.startDebugSession();
  }

  // 如果是DiffTest模式且执行成功，打印成功信息
  if (diff_test && trap_code == 0)
  {
    printf("\033[1;32m[npc] DiffTest 通过！\033[0m\n");
  }

  return trap_code;
}