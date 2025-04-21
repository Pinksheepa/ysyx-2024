// 处理器顶层模块
module top (
        input wire clk,            // 时钟信号
        input wire rst,            // 复位信号

        // 指令内存接口
        output wire [31:0] imem_addr,    // 指令地址
        input  wire [31:0] imem_rdata,   // 读取的指令数据
        output wire        imem_valid,   // 指令访问有效信号

        // 数据内存接口
        output wire [31:0] dmem_addr,    // 数据地址
        input  wire [31:0] dmem_rdata,   // 读取的数据
        output wire [31:0] dmem_wdata,   // 写入的数据
        output wire        dmem_valid,   // 数据访问有效信号
        output wire [3:0]  dmem_wen      // 写使能信号，按字节控制
    );

    // 内存基地址常量定义
    // parameter IMEM_BASE = 32'h8000_0000;  // 指令内存基地址
    parameter DMEM_BASE = 32'h8010_0000;  // 数据内存基地址

    // PC寄存器信号
    wire [31:0] pc;           // 当前PC值
    wire [31:0] next_pc;      // 下一条指令地址
    wire        pc_wen;       // PC写使能

    // 指令相关信号
    wire [31:0] inst;         // 当前指令
    wire [2:0]  funct3;       // 添加funct3信号

    // 控制信号
    wire        reg_wen;      // 寄存器写使能
    wire        mem_wen;      // 内存写使能
    wire        mem_ren;      // 内存读使能
    wire [3:0]  alu_op;       // ALU操作码
    wire        use_imm;      // 使用立即数标志
    wire        branch;       // 分支指令标志
    wire        jump;         // 跳转指令标志

    // 数据信号
    wire [4:0]  rs1;          // 源寄存器1
    wire [4:0]  rs2;          // 源寄存器2
    wire [4:0]  rd;           // 目标寄存器
    wire [31:0] rs1_data;     // 源寄存器1数据
    wire [31:0] rs2_data;     // 源寄存器2数据
    wire [31:0] imm;          // 立即数
    wire [31:0] alu_src1;     // ALU源操作数1
    wire [31:0] alu_src2;     // ALU源操作数2
    wire [31:0] alu_result;   // ALU结果
    wire [31:0] wb_data;      // 写回数据
    wire        branch_taken; // 分支是否跳转
    // wire is_jal;         // 是否为jal指令
    wire is_jalr;        // 是否为jalr指令

    // 调试信号
    wire [31:0] reg_x1;       // x1寄存器值(ra)
    wire [31:0] reg_x2;       // x2寄存器值(sp)
    wire [31:0] reg_a0;       // a0寄存器值(x10)

    // 从指令中提取funct3字段
    assign funct3 = inst[14:12];

    // 指令取指模块实例化
    IFU ifu (
            .clk        (clk),
            .rst        (rst),
            .pc         (pc),
            .imem_addr  (imem_addr),
            .imem_rdata (imem_rdata),
            .imem_valid (imem_valid),
            .inst       (inst)
        );

    // 指令译码模块实例化
    IDU idu (
            .clk        (clk),
            .rst        (rst),
            .inst       (inst),
            .rs1_data   (rs1_data),
            .rs2_data   (rs2_data),
            .rs1        (rs1),
            .rs2        (rs2),
            .rd         (rd),
            .imm        (imm),
            .reg_wen    (reg_wen),
            .mem_wen    (mem_wen),
            .mem_ren    (mem_ren),
            .alu_op     (alu_op),
            .use_imm    (use_imm),
            .branch     (branch),
            .jump       (jump),
            // .is_jal     (is_jal),
            .is_jalr    (is_jalr)
        );

    // 执行单元实例化 - 添加DMEM_BASE参数
    EXU exu (
            .clk         (clk),
            .rst         (rst),
            .rs1_data    (rs1_data),
            .rs2_data    (rs2_data),
            .rs1         (rs1),
            .rs2         (rs2),
            .rd          (rd),
            .imm         (imm),
            .pc          (pc),
            .reg_wen     (reg_wen),
            .mem_wen     (mem_wen),
            .mem_ren     (mem_ren),
            .alu_op      (alu_op),
            .use_imm     (use_imm),
            .branch      (branch),
            .jump        (jump),
            .funct3      (funct3),    // 添加funct3连接
            .inst        (inst),      // 添加inst连接，用于EBREAK检测
            .wb_data     (wb_data),
            .alu_result  (alu_result),
            .branch_taken(branch_taken),
            .dmem_addr   (dmem_addr),
            .dmem_rdata  (dmem_rdata),
            .dmem_wdata  (dmem_wdata),
            .dmem_valid  (dmem_valid),
            .dmem_wen    (dmem_wen),
            .DMEM_BASE   (DMEM_BASE),  // 传递数据内存基地址
            // .reg_x1      (reg_x1),    // 连接调试接口信号
            // .reg_x2      (reg_x2),    // 连接调试接口信号
            // .reg_a0      (reg_a0)     // 连接调试接口信号
            // .is_jal     (is_jal),
            .is_jalr    (is_jalr)
        );

    // PC寄存器实例化
    PC_Reg pc_reg (
               .clk         (clk),
               .rst         (rst),
               .next_pc     (next_pc),
               .pc          (pc),
               .pc_wen      (1'b1)  // PC始终更新
           );

    // 下一条PC的计算
    assign next_pc = branch_taken ? alu_result : (pc + 4);

endmodule
