# Makefile for verilator & generating tb_top.cpp in ./obj_dir

# 设置源文件路径
VSRC_DIR = ./vsrc
OBJ_DIR = ./obj_dir
TB_FILE = $(OBJ_DIR)/tb_top.cpp

# 仿真最大周期
MAX_SIM_TIME = 20

# 仿真目标
sim: 
# 1. 使用 Verilator 编译 Verilog 源文件并生成 C++ 模型
	verilator -Wall --trace -cc ./vsrc/top.v --exe tb_top.cpp

# 生成 tb_top.cpp 文件
	touch $(TB_FILE)
	@echo '#include <verilated.h>' > $(TB_FILE)
	@echo '#include <verilated_vcd_c.h>' >> $(TB_FILE)
	@echo '#include "Vtop.h"' >> $(TB_FILE)
	@echo '#include "Vtop___024root.h"' >> $(TB_FILE)
	@echo '' >> $(TB_FILE)
	@echo '#define MAX_SIM_TIME $(MAX_SIM_TIME) // 最大仿真时钟周期' >> $(TB_FILE)
	@echo 'vluint64_t sim_time = 0; // 实际仿真周期' >> $(TB_FILE)
	@echo '' >> $(TB_FILE)
	@echo 'int main(int argc, char** argv, char** env) {' >> $(TB_FILE)
	@echo '    Vtop *dut = new Vtop; // 例化一个top模块' >> $(TB_FILE)
	@echo '' >> $(TB_FILE)
	@echo '    // 下面4行为开启跟踪固定代码' >> $(TB_FILE)
	@echo '    Verilated::traceEverOn(true);' >> $(TB_FILE)
	@echo '    VerilatedVcdC *m_trace = new VerilatedVcdC;' >> $(TB_FILE)
	@echo '    dut->trace(m_trace, 5);' >> $(TB_FILE)
	@echo '    m_trace->open("waveform.vcd");' >> $(TB_FILE)
	@echo '' >> $(TB_FILE)
	@echo '    while (sim_time < MAX_SIM_TIME) {' >> $(TB_FILE)
	@echo '        int a = rand() & 1; // 随机生成a' >> $(TB_FILE)
	@echo '        int b = rand() & 1; // 随机生成b' >> $(TB_FILE)
	@echo '        dut->a = a; // 将a赋值给例化模块的a' >> $(TB_FILE)
	@echo '        dut->b = b; // 将b赋值给例化模块的b' >> $(TB_FILE)
	@echo '        dut->eval(); // 更新电路状态！！！切记要在while中添加，非常重要，一定不能少' >> $(TB_FILE)
	@echo '        m_trace->dump(sim_time); // 将当前状态记录到trace中，后续输出波形要用' >> $(TB_FILE)
	@echo '        sim_time++; // 仿真周期增加' >> $(TB_FILE)
	@echo '    }' >> $(TB_FILE)
	@echo '' >> $(TB_FILE)
	@echo '    m_trace->close();' >> $(TB_FILE)
	@echo '    delete dut;' >> $(TB_FILE)
	@echo '    exit(EXIT_SUCCESS);' >> $(TB_FILE)
	@echo '}' >> $(TB_FILE)

# 2. 使用生成的 Vtop.mk 文件编译 C++ 模型并生成可执行文件
	make -C $(OBJ_DIR) -f Vtop.mk Vtop

# 3. 运行生成的 Vtop 可执行文件
	./$(OBJ_DIR)/Vtop



# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR)

.PHONY: sim clean



