#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "Vtop___024root.h"

#define MAX_SIM_TIME 20 // 最大仿真时钟周期
vluint64_t sim_time = 0; // 实际仿真周期

int main(int argc, char** argv, char** env) {
    Vtop *dut = new Vtop; // 例化一个top模块

    // 下面4行为开启跟踪固定代码
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
        int a = rand() & 1; // 随机生成a
        int b = rand() & 1; // 随机生成b
        dut->a = a; // 将a赋值给例化模块的a
        dut->b = b; // 将b赋值给例化模块的b
        dut->eval(); // 更新电路状态！！！切记要在while中添加，非常重要，一定不能少
        m_trace->dump(sim_time); // 将当前状态记录到trace中，后续输出波形要用
        sim_time++; // 仿真周期增加
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
