// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\MEMU.v
// MEMU.v - 内存访问单元
module MEMU (
        input  wire        clk,             // 时钟信号
        input  wire        rst,             // 复位信号
        input  wire [31:0] mem_pc,          // MEM阶段PC
        input  wire [31:0] mem_instr,       // MEM阶段指令
        input  wire [31:0] mem_alu_result,  // ALU计算结果(内存地址)
        input  wire [31:0] mem_rs2_data,    // 源寄存器2数据(用于存储)
        input  wire [4:0]  mem_rd,          // 目标寄存器地址
        input  wire        mem_reg_wen,     // 寄存器写使能
        input  wire        mem_mem_wen,     // 内存写使能
        input  wire        mem_mem_ren,     // 内存读使能

        // 扩展控制信号
        input  wire [2:0]  mem_mem_type,    // 内存访问类型
        input  wire        mem_mem_unsigned,// 内存无符号标志
        input  wire [1:0]  mem_wb_sel,      // 写回选择
        input  wire [31:0] mem_csr_rdata,   // CSR读取数据

        // 数据内存接口
        input  wire [31:0] dmem_rdata,      // 从内存读取的数据
        output wire [31:0] dmem_addr,       // 内存地址
        output wire [31:0] dmem_wdata,      // 写入内存的数据
        output wire [3:0]  dmem_wen,        // 内存写使能
        output wire        dmem_valid,      // 内存访问有效

        // 处理后的数据
        output reg  [31:0] mem_read_data,   // 处理后的内存读取数据
        output reg  [31:0] wb_data          // 要写回的数据
    );

    // 访问类型和字节使能
    wire [2:0] mem_funct3 = {mem_mem_unsigned, mem_mem_type[1:0]};

    // 内存访问类型定义 - 使用funct3的低两位
    localparam BYTE    = 2'b00;        // LB/SB
    localparam HALF    = 2'b01;        // LH/SH
    localparam WORD    = 2'b10;        // LW/SW

    // 连接到数据内存
    assign dmem_addr = mem_alu_result;
    assign dmem_wdata = mem_rs2_data;
    assign dmem_valid = mem_mem_ren || mem_mem_wen;

    // 根据访问类型确定写使能
    reg [3:0] byte_en;
    always @(*) begin
        if (mem_mem_wen) begin
            case (mem_mem_type[1:0])
                BYTE: begin
                    // 字节写入，根据地址低两位选择要写入的字节
                    case (mem_alu_result[1:0])
                        2'b00:
                            byte_en = 4'b0001;
                        2'b01:
                            byte_en = 4'b0010;
                        2'b10:
                            byte_en = 4'b0100;
                        2'b11:
                            byte_en = 4'b1000;
                    endcase
                end
                HALF: begin
                    // 半字写入，根据地址低位选择要写入的半字
                    case (mem_alu_result[1])
                        1'b0:
                            byte_en = 4'b0011;
                        1'b1:
                            byte_en = 4'b1100;
                    endcase
                end
                WORD: begin
                    // 字写入
                    byte_en = 4'b1111;
                end
                default:
                    byte_en = 4'b0000;
            endcase
        end
        else begin
            byte_en = 4'b0000;
        end
    end

    assign dmem_wen = mem_mem_wen ? byte_en : 4'b0000;

    // 处理从内存读取的数据
    always @(*) begin
        if (mem_mem_ren) begin
            case (mem_mem_type[1:0])
                BYTE: begin
                    // 字节读取，根据地址低两位选择要读取的字节
                    case (mem_alu_result[1:0])
                        2'b00:
                            mem_read_data = mem_mem_unsigned ? {24'b0, dmem_rdata[7:0]} : {{24{dmem_rdata[7]}}, dmem_rdata[7:0]};
                        2'b01:
                            mem_read_data = mem_mem_unsigned ? {24'b0, dmem_rdata[15:8]} : {{24{dmem_rdata[15]}}, dmem_rdata[15:8]};
                        2'b10:
                            mem_read_data = mem_mem_unsigned ? {24'b0, dmem_rdata[23:16]} : {{24{dmem_rdata[23]}}, dmem_rdata[23:16]};
                        2'b11:
                            mem_read_data = mem_mem_unsigned ? {24'b0, dmem_rdata[31:24]} : {{24{dmem_rdata[31]}}, dmem_rdata[31:24]};
                    endcase
                end
                HALF: begin
                    // 半字读取，根据地址低位选择要读取的半字
                    case (mem_alu_result[1])
                        1'b0:
                            mem_read_data = mem_mem_unsigned ? {16'b0, dmem_rdata[15:0]} : {{16{dmem_rdata[15]}}, dmem_rdata[15:0]};
                        1'b1:
                            mem_read_data = mem_mem_unsigned ? {16'b0, dmem_rdata[31:16]} : {{16{dmem_rdata[31]}}, dmem_rdata[31:16]};
                    endcase
                end
                WORD: begin
                    // 字读取
                    mem_read_data = dmem_rdata;
                end
                default:
                    mem_read_data = 32'h0;
            endcase
        end
        else begin
            mem_read_data = 32'h0;
        end
    end

    // 写回数据选择 (00:ALU, 01:MEM, 10:PC+4, 11:CSR)
    always @(*) begin
        case (mem_wb_sel)
            2'b00:
                wb_data = mem_alu_result; // ALU结果
            2'b01:
                wb_data = mem_read_data;  // 内存读取
            2'b10:
                wb_data = mem_pc + 4;     // PC+4 (用于JAL/JALR)
            2'b11:
                wb_data = mem_csr_rdata;  // CSR读取值
            default:
                wb_data = mem_alu_result;
        endcase
    end

endmodule
