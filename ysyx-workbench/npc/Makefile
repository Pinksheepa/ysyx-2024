all:
	@echo "Write this Makefile by your self."

VSRCS = $(shell find $(./vsrc ) -name "*.v")
INCLUDE = ./vsrc/include


sim:
	@echo $(VSRCS)	

	verilator -Wall --Wno-UNUSEDPARAM --trace -cc --exe --build \
	--top-module top \
	-I$(INCLUDE) ./csrc/main.cpp $(VSRCS) \
	--timing \
	-LDFLAGS "-lreadline"

	@echo "Write this Makefile by your self."
	
wave: sim
	./obj_dir/Vtop
	gtkwave waveform.vcd



# 清理生成的文件
clean:
	rm -rf obj_dir
	rm waveform.vcd
	
.PHONY: sim clean


include ../Makefile
