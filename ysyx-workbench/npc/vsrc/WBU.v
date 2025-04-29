// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\WBU.v
// WBU.v - 写回单元
module WBU (
        input  wire        clk,             // 时钟信号
        input  wire        rst,             // 复位信号
        input  wire [31:0] wb_pc,           // WB阶段PC值
        input  wire [31:0] wb_instr,        // WB阶段指令
        input  wire [31:0] wb_alu_result,   // ALU计算结果
        input  wire [31:0] wb_mem_rdata,    // 内存读取数据
        input  wire [4:0]  wb_rd,           // 目标寄存器地址
        input  wire        wb_reg_wen,      // 寄存器写使能

        // 扩展控制信号
        input  wire [1:0]  wb_wb_sel,       // 写回选择 (0=ALU结果, 1=内存数据, 2=PC+4)
        input  wire        wb_mem_unsigned, // 内存读取无符号扩展
        input  wire [31:0] wb_csr_rdata,    // CSR读取数据

        // 写回数据输出
        output reg  [31:0] wb_data,         // 最终写回数据
        output wire [4:0]  wb_rd_out,       // 输出目标寄存器地址
        output wire        wb_reg_wen_out   // 输出寄存器写使能
    );

    // 选择最终写回的数据
    always @(*) begin
        case (wb_wb_sel)
            2'b00:
                wb_data = wb_alu_result;    // ALU结果
            2'b01:
                wb_data = wb_mem_rdata;     // 内存数据
            2'b10:
                wb_data = wb_pc + 4;        // PC+4 (用于JAL/JALR)
            2'b11:
                wb_data = wb_csr_rdata;     // CSR数据
            default:
                wb_data = wb_alu_result;  // 默认ALU结果
        endcase
    end

    // 传递控制信号
    assign wb_rd_out = wb_rd;

    // 寄存器写回使能：只有当目标寄存器不为x0且写使能有效时才写回
    assign wb_reg_wen_out = wb_reg_wen && (wb_rd != 5'b00000);

endmodule
