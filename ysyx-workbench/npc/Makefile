all: sim

VSRCS = $(shell find ./vsrc -name "*.v")
INCLUDE = ./vsrc
CSRCS = ./csrc/sim_main.cpp ./csrc/sdb.cpp ./csrc/difftest.cpp

sim:
	@echo "Compiling NPC simulator..."
	@echo "Found Verilog sources: $(VSRCS)"
	verilator -Wall --Wno-DECLFILENAME --Wno-UNUSEDSIGNAL --Wno-WIDTHEXPAND \
	--Wno-CASEINCOMPLETE --trace -cc --exe --build \
	--Wno-SYNCASYNCNET	\
	--Wno-PINCONNECTEMPTY \
	--top-module top \
	-I$(INCLUDE) $(CSRCS) $(VSRCS) \
	--timing \
	-LDFLAGS "-lreadline -ldl"
	@echo "NPC simulator build complete"
	@ls -l obj_dir/Vtop || echo "ERROR: Vtop not built successfully!"

# 直接运行不带参数时，执行默认测试
run: sim
	./obj_dir/Vtop --diff

# # 运行指定的二进制文件
# run-bin: sim
# 	@if [ -z "$(BIN)" ]; then \
# 		echo "Specify .bin file! ----> make run-bin BIN=path/to/file.bin"; \
# 		exit 1; \
# 	fi
# 	@echo "运行二进制文件: $(BIN)"
# 	./obj_dir/Vtop $(BIN)

# 查看波形
wave: run
	gtkwave wave.vcd

# 清理生成的文件
clean:
	rm -rf obj_dir
	rm -f wave.vcd
	
.PHONY: all sim run wave run-bin clean

include ../Makefile
