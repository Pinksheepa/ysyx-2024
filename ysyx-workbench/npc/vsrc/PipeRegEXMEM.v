// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\PipeRegEXMEM.v
// EX/MEM流水线寄存器模块
module PipeRegEXMEM (
        input  wire        clk,          // 时钟信号
        input  wire        rst,          // 复位信号
        input  wire        stall,        // 暂停信号
        input  wire        flush,        // 冲刷信号

        // EX阶段传递的数据
        input  wire [31:0] ex_pc,        // EX阶段的PC值
        input  wire [31:0] ex_instr,     // EX阶段的指令
        input  wire [31:0] ex_alu_result,// ALU计算结果
        input  wire [31:0] ex_rs2_data,  // 源寄存器2数据(用于存储)
        input  wire [4:0]  ex_rs1,       // 源寄存器1地址
        input  wire [4:0]  ex_rs2,       // 源寄存器2地址
        input  wire [4:0]  ex_rd,        // 目标寄存器地址
        input  wire        ex_reg_wen,   // 寄存器写使能
        input  wire        ex_mem_wen,   // 内存写使能
        input  wire        ex_mem_ren,   // 内存读使能
        input  wire        ex_branch_taken, // 分支是否跳转
        input  wire [2:0]  ex_funct3,    // 用于内存访问类型决定

        // EX阶段传递的扩展控制信号
        input  wire [2:0]  ex_mem_type,     // 内存访问类型
        input  wire        ex_mem_unsigned,  // 内存无符号访问
        input  wire [1:0]  ex_wb_sel,        // 写回选择
        input  wire        ex_csr_ren,       // CSR读使能
        input  wire        ex_csr_wen,       // CSR写使能
        input  wire [11:0] ex_csr_addr,      // CSR地址
        input  wire [1:0]  ex_csr_op,        // CSR操作类型
        input  wire        ex_csr_imm,       // CSR立即数操作
        input  wire [31:0] ex_csr_write_data, // CSR写入数据

        // MEM阶段接收的数据
        output reg  [31:0] mem_pc,       // MEM阶段的PC值
        output reg  [31:0] mem_instr,    // MEM阶段的指令
        output reg  [31:0] mem_alu_result, // ALU计算结果
        output reg  [31:0] mem_rs2_data, // 源寄存器2数据(用于存储)
        output reg  [4:0]  mem_rs1,      // 源寄存器1地址
        output reg  [4:0]  mem_rs2,      // 源寄存器2地址
        output reg  [4:0]  mem_rd,       // 目标寄存器地址
        output reg         mem_reg_wen,  // 寄存器写使能
        output reg         mem_mem_wen,  // 内存写使能
        output reg         mem_mem_ren,  // 内存读使能
        output reg         mem_branch_taken, // 分支是否跳转
        output reg  [2:0]  mem_funct3,   // 用于内存访问类型决定

        // MEM阶段接收的扩展控制信号
        output reg  [2:0]  mem_mem_type,     // 内存访问类型
        output reg         mem_mem_unsigned,  // 内存无符号访问
        output reg  [1:0]  mem_wb_sel,        // 写回选择
        output reg         mem_csr_ren,       // CSR读使能
        output reg         mem_csr_wen,       // CSR写使能
        output reg  [11:0] mem_csr_addr,      // CSR地址
        output reg  [1:0]  mem_csr_op,        // CSR操作类型
        output reg         mem_csr_imm,       // CSR立即数操作
        output reg  [31:0] mem_csr_write_data // CSR写入数据
    );

    // 流水线寄存器更新逻辑
    always @(posedge clk) begin
        if (rst || flush) begin
            // 复位或冲刷时清零所有控制信号和数据
            mem_pc         <= 32'b0;
            mem_instr      <= 32'b0;
            mem_alu_result <= 32'b0;
            mem_rs2_data   <= 32'b0;
            mem_rs1        <= 5'b0;
            mem_rs2        <= 5'b0;
            mem_rd         <= 5'b0;
            mem_reg_wen    <= 1'b0;
            mem_mem_wen    <= 1'b0;
            mem_mem_ren    <= 1'b0;
            mem_branch_taken <= 1'b0;
            mem_funct3     <= 3'b0;

            // 清零扩展控制信号
            mem_mem_type   <= 3'b0;
            mem_mem_unsigned <= 1'b0;
            mem_wb_sel     <= 2'b0;
            mem_csr_ren    <= 1'b0;
            mem_csr_wen    <= 1'b0;
            mem_csr_addr   <= 12'b0;
            mem_csr_op     <= 2'b0;
            mem_csr_imm    <= 1'b0;
            mem_csr_write_data <= 32'b0;
        end
        else if (!stall) begin
            // 非暂停状态下正常传递数据
            mem_pc         <= ex_pc;
            mem_instr      <= ex_instr;
            mem_alu_result <= ex_alu_result;
            mem_rs2_data   <= ex_rs2_data;
            mem_rs1        <= ex_rs1;
            mem_rs2        <= ex_rs2;
            mem_rd         <= ex_rd;
            mem_reg_wen    <= ex_reg_wen;
            mem_mem_wen    <= ex_mem_wen;
            mem_mem_ren    <= ex_mem_ren;
            mem_branch_taken <= ex_branch_taken;
            mem_funct3     <= ex_funct3;

            // 传递扩展控制信号
            mem_mem_type   <= ex_mem_type;
            mem_mem_unsigned <= ex_mem_unsigned;
            mem_wb_sel     <= ex_wb_sel;
            mem_csr_ren    <= ex_csr_ren;
            mem_csr_wen    <= ex_csr_wen;
            mem_csr_addr   <= ex_csr_addr;
            mem_csr_op     <= ex_csr_op;
            mem_csr_imm    <= ex_csr_imm;
            mem_csr_write_data <= ex_csr_write_data;
        end
        // 如果stall为1，保持当前值不变
    end

endmodule
