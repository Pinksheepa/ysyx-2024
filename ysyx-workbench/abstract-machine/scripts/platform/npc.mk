AM_SRCS := riscv/npc/start.S \
	       riscv/npc/trm.c \
	       riscv/npc/ioe.c \
	       riscv/npc/timer.c \
	       riscv/npc/input.c \
	       riscv/npc/cte.c \
	       riscv/npc/trap.S \
	       platform/dummy/vme.c \
	       platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start

# 根据ARCH设置额外的编译参数
ifeq ($(findstring riscv32e,$(ARCH)),riscv32e)
CFLAGS += -march=rv32e -mabi=ilp32e
else
CFLAGS += -march=rv32i -mabi=ilp32
endif

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python3 $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

# NPC运行选项
NPC_HOME ?= $(shell dirname $(AM_HOME))/npc
NPCFLAGS += -t 100000  # 默认最大仿真周期数

# 如果是riscv32e架构，添加对应标志
ifeq ($(findstring riscv32e,$(ARCH)),riscv32e)
NPCFLAGS += --arch=riscv32e
endif

# 改进后的run目标，支持riscv32e-npc架构
run: insert-arg
	@echo "Running program [$(IMAGE_REL)] on NPC with ARCH=$(ARCH)..."
	@echo "Full path to binary: $(IMAGE).bin"
	@ls -l $(IMAGE).bin || echo "Error: Binary file not found!"
	@if [ ! -d "$(NPC_HOME)" ]; then echo "Error: NPC_HOME directory does not exist!"; exit 1; fi
	@echo "Building NPC simulator..."
	$(MAKE) -C $(NPC_HOME) sim
	@echo "Copying binary to local directory to avoid shared filesystem issues..."
	cp -f $(IMAGE).bin /tmp/npc_program.bin
	@echo "File copied to /tmp/npc_program.bin"
	@ls -l /tmp/npc_program.bin
	@echo "Executing NPC with local copy of binary..."
	cd $(NPC_HOME) && ./obj_dir/Vtop $(NPCFLAGS) /tmp/npc_program.bin

.PHONY: insert-arg
