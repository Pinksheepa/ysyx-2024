// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\PipeRegMEMWB.v
// MEM/WB流水线寄存器模块
module PipeRegMEMWB (
        input  wire        clk,          // 时钟信号
        input  wire        rst,          // 复位信号
        input  wire        stall,        // 暂停信号
        input  wire        flush,        // 冲刷信号

        // MEM阶段传递的数据
        input  wire [31:0] mem_pc,       // MEM阶段PC值
        input  wire [31:0] mem_instr,    // MEM阶段指令
        input  wire [31:0] mem_alu_result, // ALU计算结果
        input  wire [31:0] mem_mem_rdata,  // 内存读取数据
        input  wire [4:0]  mem_rd,       // 目标寄存器地址
        input  wire        mem_reg_wen,  // 寄存器写使能
        input  wire        mem_mem_ren,  // 内存读使能

        // MEM阶段传递的扩展控制信号
        input  wire [1:0]  mem_wb_sel,      // 写回选择
        input  wire        mem_mem_unsigned, // 内存无符号标志
        input  wire [31:0] mem_csr_rdata,   // CSR读取数据
        input  wire        mem_csr_ren,     // CSR读使能
        input  wire        mem_csr_wen,     // CSR写使能
        input  wire [11:0] mem_csr_addr,    // CSR地址
        input  wire [1:0]  mem_csr_op,      // CSR操作类型
        input  wire        mem_csr_imm,     // CSR立即数操作
        input  wire [31:0] mem_csr_write_data, // CSR写入数据

        // WB阶段接收的数据
        output reg  [31:0] wb_pc,        // WB阶段PC值
        output reg  [31:0] wb_instr,     // WB阶段指令
        output reg  [31:0] wb_alu_result, // ALU计算结果
        output reg  [31:0] wb_mem_rdata,  // 内存读取数据
        output reg  [4:0]  wb_rd,        // 目标寄存器地址
        output reg         wb_reg_wen,   // 寄存器写使能
        output reg         wb_mem_ren,   // 内存读使能

        // WB阶段接收的扩展控制信号
        output reg  [1:0]  wb_wb_sel,       // 写回选择
        output reg         wb_mem_unsigned,  // 内存无符号标志
        output reg  [31:0] wb_csr_rdata,    // CSR读取数据
        output reg         wb_csr_ren,      // CSR读使能
        output reg         wb_csr_wen,      // CSR写使能
        output reg  [11:0] wb_csr_addr,     // CSR地址
        output reg  [1:0]  wb_csr_op,       // CSR操作类型
        output reg         wb_csr_imm,      // CSR立即数操作
        output reg  [31:0] wb_csr_write_data // CSR写入数据
    );

    // 流水线寄存器更新逻辑
    always @(posedge clk) begin
        if (rst || flush) begin
            // 复位或冲刷时清零所有控制信号和数据
            wb_pc          <= 32'b0;
            wb_instr       <= 32'b0;
            wb_alu_result  <= 32'b0;
            wb_mem_rdata   <= 32'b0;
            wb_rd          <= 5'b0;
            wb_reg_wen     <= 1'b0;
            wb_mem_ren     <= 1'b0;

            // 清零扩展控制信号
            wb_wb_sel      <= 2'b0;
            wb_mem_unsigned <= 1'b0;
            wb_csr_rdata   <= 32'b0;
            wb_csr_ren     <= 1'b0;
            wb_csr_wen     <= 1'b0;
            wb_csr_addr    <= 12'b0;
            wb_csr_op      <= 2'b0;
            wb_csr_imm     <= 1'b0;
            wb_csr_write_data <= 32'b0;
        end
        else if (!stall) begin
            // 非暂停状态下正常传递数据
            wb_pc          <= mem_pc;
            wb_instr       <= mem_instr;
            wb_alu_result  <= mem_alu_result;
            wb_mem_rdata   <= mem_mem_rdata;
            wb_rd          <= mem_rd;
            wb_reg_wen     <= mem_reg_wen;
            wb_mem_ren     <= mem_mem_ren;

            // 传递扩展控制信号
            wb_wb_sel      <= mem_wb_sel;
            wb_mem_unsigned <= mem_mem_unsigned;
            wb_csr_rdata   <= mem_csr_rdata;
            wb_csr_ren     <= mem_csr_ren;
            wb_csr_wen     <= mem_csr_wen;
            wb_csr_addr    <= mem_csr_addr;
            wb_csr_op      <= mem_csr_op;
            wb_csr_imm     <= mem_csr_imm;
            wb_csr_write_data <= mem_csr_write_data;
        end
        // 如果stall为1，保持当前值不变
    end

endmodule
