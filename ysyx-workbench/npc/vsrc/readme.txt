vsrc/
├── include/
│   └── defines.v        # 全局定义和参数
├── core/
│   ├── idu.v            # 指令译码单元
│   ├── alu.v            # 算术逻辑单元
│   ├── gpr.v            # 通用寄存器模块
│   ├── imm_gen.v        # 立即数生成模块
│   ├── csr.v            # 控制状态寄存器模块
│   └── pc_reg.v         # 程序计数器模块
├── memory/
│   ├── inst_mem.v       # 指令存储器
│   └── data_mem.v       # 数据存储器
├── utils/
│   └── multiplexer.v    # 复用器模块
└── top.v                # 顶层连接模块