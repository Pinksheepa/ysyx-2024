// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\PipeRegIDEX.v
// ID/EX流水线寄存器模块
module PipeRegIDEX (
        input  wire        clk,          // 时钟信号
        input  wire        rst,          // 复位信号
        input  wire        stall,        // 暂停信号
        input  wire        flush,        // 冲刷信号

        // 增加bubble信号，用于指示需要插入气泡
        input  wire        bubble,       // 插入气泡信号

        // ID阶段传递的数据
        input  wire [31:0] id_pc,        // ID阶段的PC值
        input  wire [31:0] id_instr,     // ID阶段的指令
        input  wire [31:0] id_rs1_data,  // 源寄存器1数据
        input  wire [31:0] id_rs2_data,  // 源寄存器2数据
        input  wire [4:0]  id_rs1,       // 源寄存器1地址
        input  wire [4:0]  id_rs2,       // 源寄存器2地址
        input  wire [4:0]  id_rd,        // 目标寄存器地址
        input  wire [31:0] id_imm,       // 立即数

        // ID阶段传递的基本控制信号
        input  wire        id_reg_wen,   // 寄存器写使能
        input  wire        id_mem_wen,   // 内存写使能
        input  wire        id_mem_ren,   // 内存读使能
        input  wire [3:0]  id_alu_op,    // ALU操作码
        input  wire        id_use_imm,   // 使用立即数标志
        input  wire        id_branch,    // 分支指令标志
        input  wire        id_jump,      // 跳转指令标志
        input  wire        id_is_jalr,   // JALR指令标志

        // ID阶段传递的扩展控制信号
        input  wire [2:0]  id_mem_type,     // 内存访问类型 (00:字节, 01:半字, 10:字)
        input  wire        id_mem_unsigned,  // 内存无符号加载
        input  wire [1:0]  id_wb_sel,        // 写回数据选择 (00:ALU, 01:MEM, 10:PC+4, 11:CSR)
        input  wire        id_csr_ren,       // CSR读使能
        input  wire        id_csr_wen,       // CSR写使能
        input  wire [11:0] id_csr_addr,      // CSR地址
        input  wire [1:0]  id_csr_op,        // CSR操作类型
        input  wire        id_csr_imm,       // CSR立即数操作
        input  wire        id_illegal_instr, // 非法指令标志

        // EX阶段接收的数据
        output reg  [31:0] ex_pc,        // EX阶段的PC值
        output reg  [31:0] ex_instr,     // EX阶段的指令
        output reg  [31:0] ex_rs1_data,  // 源寄存器1数据
        output reg  [31:0] ex_rs2_data,  // 源寄存器2数据
        output reg  [4:0]  ex_rs1,       // 源寄存器1地址
        output reg  [4:0]  ex_rs2,       // 源寄存器2地址
        output reg  [4:0]  ex_rd,        // 目标寄存器地址
        output reg  [31:0] ex_imm,       // 立即数

        // EX阶段接收的基本控制信号
        output reg         ex_reg_wen,   // 寄存器写使能
        output reg         ex_mem_wen,   // 内存写使能
        output reg         ex_mem_ren,   // 内存读使能
        output reg  [3:0]  ex_alu_op,    // ALU操作码
        output reg         ex_use_imm,   // 使用立即数标志
        output reg         ex_branch,    // 分支指令标志
        output reg         ex_jump,      // 跳转指令标志
        output reg         ex_is_jalr,   // JALR指令标志

        // EX阶段接收的扩展控制信号
        output reg  [2:0]  ex_mem_type,     // 内存访问类型 (00:字节, 01:半字, 10:字)
        output reg         ex_mem_unsigned,  // 内存无符号加载
        output reg  [1:0]  ex_wb_sel,        // 写回数据选择 (00:ALU, 01:MEM, 10:PC+4, 11:CSR)
        output reg         ex_csr_ren,       // CSR读使能
        output reg         ex_csr_wen,       // CSR写使能
        output reg  [11:0] ex_csr_addr,      // CSR地址
        output reg  [1:0]  ex_csr_op,        // CSR操作类型
        output reg         ex_csr_imm,       // CSR立即数操作
        output reg         ex_illegal_instr  // 非法指令标志
    );

    // 流水线寄存器更新逻辑
    always @(posedge clk) begin
        if (rst || flush || bubble) begin
            // 复位、冲刷或插入气泡时清零所有控制信号和数据
            ex_pc           <= 32'b0;
            ex_instr        <= 32'b0;
            ex_rs1_data     <= 32'b0;
            ex_rs2_data     <= 32'b0;
            ex_rs1          <= 5'b0;
            ex_rs2          <= 5'b0;
            ex_rd           <= 5'b0;
            ex_imm          <= 32'b0;
            ex_reg_wen      <= 1'b0;
            ex_mem_wen      <= 1'b0;
            ex_mem_ren      <= 1'b0;
            ex_alu_op       <= 4'b0;
            ex_use_imm      <= 1'b0;
            ex_branch       <= 1'b0;
            ex_jump         <= 1'b0;
            ex_is_jalr      <= 1'b0;

            // 扩展的控制信号清零
            ex_mem_type     <= 3'b0;
            ex_mem_unsigned <= 1'b0;
            ex_wb_sel       <= 2'b0;
            ex_csr_ren      <= 1'b0;
            ex_csr_wen      <= 1'b0;
            ex_csr_addr     <= 12'b0;
            ex_csr_op       <= 2'b0;
            ex_csr_imm      <= 1'b0;
            ex_illegal_instr <= 1'b0;
        end
        else if (!stall) begin
            // 非暂停状态下正常传递数据
            ex_pc           <= id_pc;
            ex_instr        <= id_instr;
            ex_rs1_data     <= id_rs1_data;
            ex_rs2_data     <= id_rs2_data;
            ex_rs1          <= id_rs1;
            ex_rs2          <= id_rs2;
            ex_rd           <= id_rd;
            ex_imm          <= id_imm;
            ex_reg_wen      <= id_reg_wen;
            ex_mem_wen      <= id_mem_wen;
            ex_mem_ren      <= id_mem_ren;
            ex_alu_op       <= id_alu_op;
            ex_use_imm      <= id_use_imm;
            ex_branch       <= id_branch;
            ex_jump         <= id_jump;
            ex_is_jalr      <= id_is_jalr;

            // 传递扩展的控制信号
            ex_mem_type     <= id_mem_type;
            ex_mem_unsigned <= id_mem_unsigned;
            ex_wb_sel       <= id_wb_sel;
            ex_csr_ren      <= id_csr_ren;
            ex_csr_wen      <= id_csr_wen;
            ex_csr_addr     <= id_csr_addr;
            ex_csr_op       <= id_csr_op;
            ex_csr_imm      <= id_csr_imm;
            ex_illegal_instr <= id_illegal_instr;
        end
        // 如果stall为1，保持当前值不变
    end

endmodule
