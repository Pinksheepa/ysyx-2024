all: sim

VSRCS = $(shell find ./vsrc -name "*.v")
INCLUDE = ./vsrc
CSRCS = ./csrc/sim_main.cpp

sim:
	@echo "Compiling NPC simulator..."
	@echo "Found Verilog sources: $(VSRCS)"
	verilator -Wall --Wno-DECLFILENAME --Wno-UNUSEDSIGNAL --Wno-WIDTHEXPAND \
	--Wno-CASEINCOMPLETE --trace -cc --exe --build \
	--Wno-SYNCASYNCNET	\
	--top-module top \
	-I$(INCLUDE) $(CSRCS) $(VSRCS) \
	--timing \
	-LDFLAGS "-lreadline"
	@echo "NPC simulator build complete"
	@ls -l obj_dir/Vtop || echo "ERROR: Vtop not built successfully!"

# 直接运行不带参数时，执行默认测试
run: sim
	./obj_dir/Vtop

# 查看波形
wave: run
	gtkwave waveform.vcd

# 运行指定的程序文件
run-bin: sim
	@if [ -n "$(BIN)" ]; then \
		./obj_dir/Vtop $(BIN); \
	else \
		echo "Please specify BIN=<binary file>"; \
		exit 1; \
	fi

# 清理生成的文件
clean:
	rm -rf obj_dir
	rm -f waveform.vcd
	
.PHONY: all sim run wave run-bin clean

include ../Makefile
