// 指令译码单元(IDU) - 负责解码指令并生成控制信号
// `timescale 1ns / 1ps

module IDU (
        input  wire        clk,       // 时钟信号
        input  wire        rst,       // 复位信号
        input  wire [31:0] inst,      // 输入的指令
        input  wire [31:0] rs1_data,  // 寄存器值输入
        input  wire [31:0] rs2_data,  // 寄存器值输入
        output wire [4:0]  rs1,       // 源寄存器1
        output wire [4:0]  rs2,       // 源寄存器2
        output wire [4:0]  rd,        // 目标寄存器
        output wire [31:0] imm,       // 立即数
        output wire        reg_wen,   // 寄存器写使能
        output wire        mem_wen,   // 内存写使能
        output wire        mem_ren,   // 内存读使能
        output wire [3:0]  alu_op,    // ALU操作码
        output wire        use_imm,   // 使用立即数标志
        output wire        branch,    // 分支指令标志
        output wire        jump,       // 跳转指令标志
        // output  wire is_jal,
        output  wire is_jalr
    );

    // 指令格式字段
    wire [6:0] opcode = inst[6:0];
    wire [2:0] funct3 = inst[14:12];
    wire [6:0] funct7 = inst[31:25];
    wire [11:0] funct12 = inst[31:20]; // ebreak/ecall使用

    // ebreak指令检测: opcode=1110011, funct3=000, funct12=000000000001
    wire is_ebreak = (opcode == 7'b1110011) && (funct3 == 3'b000) && (funct12 == 12'h001);

    // 移除ebreak处理代码，由EXU模块统一处理

    // 寄存器地址
    assign rs1 = inst[19:15];
    assign rs2 = inst[24:20];
    assign rd  = inst[11:7];

    // 指令类型判断
    wire is_r_type = (opcode == 7'b0110011); // R型指令：如 add, sub
    wire is_i_type = (opcode == 7'b0010011) || (opcode == 7'b0000011) || (opcode == 7'b1100111); // I型指令：算术、加载、jalr
    wire is_s_type = (opcode == 7'b0100011); // S型指令：存储
    wire is_b_type = (opcode == 7'b1100011); // B型指令：分支
    wire is_u_type = (opcode == 7'b0110111) || (opcode == 7'b0010111); // U型指令：lui, auipc
    wire is_j_type = (opcode == 7'b1101111); // J型指令：jal

    wire is_load  = (opcode == 7'b0000011); // 加载指令
    wire is_store = (opcode == 7'b0100011); // 存储指令
    wire is_jal   = (opcode == 7'b1101111); // jal指令
    assign is_jalr  = (opcode == 7'b1100111) && (funct3 == 3'b000); // jalr指令

    // 立即数生成
    wire [31:0] i_imm = {{20{inst[31]}}, inst[31:20]};
    wire [31:0] s_imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    wire [31:0] b_imm = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
    wire [31:0] u_imm = {inst[31:12], 12'b0};
    wire [31:0] j_imm = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};

    // 立即数选择
    reg [31:0] imm_val;
    always @(*) begin
        if (is_i_type)
            imm_val = i_imm;
        else if (is_s_type)
            imm_val = s_imm;
        else if (is_b_type)
            imm_val = b_imm;
        else if (is_u_type)
            imm_val = u_imm;
        else if (is_j_type)
            imm_val = j_imm;
        else
            imm_val = 32'h0;
    end

    assign imm = imm_val;

    // ALU操作码定义
    localparam ALU_ADD  = 4'b0000;
    localparam ALU_SUB  = 4'b0001;
    localparam ALU_AND  = 4'b0010;
    localparam ALU_OR   = 4'b0011;
    localparam ALU_XOR  = 4'b0100;
    localparam ALU_SLL  = 4'b0101; // 逻辑左移
    localparam ALU_SRL  = 4'b0110; // 逻辑右移
    localparam ALU_SRA  = 4'b0111; // 算术右移
    localparam ALU_SLT  = 4'b1000; // 有符号小于
    localparam ALU_SLTU = 4'b1001; // 无符号小于

    // ALU操作码选择
    reg [3:0] alu_op_val;
    always @(*) begin
        if (is_r_type) begin
            case ({funct7[5], funct3})
                4'b0_000:
                    alu_op_val = ALU_ADD;  // add
                4'b1_000:
                    alu_op_val = ALU_SUB;  // sub
                4'b0_001:
                    alu_op_val = ALU_SLL;  // sll
                4'b0_010:
                    alu_op_val = ALU_SLT;  // slt
                4'b0_011:
                    alu_op_val = ALU_SLTU; // sltu
                4'b0_100:
                    alu_op_val = ALU_XOR;  // xor
                4'b0_101:
                    alu_op_val = ALU_SRL;  // srl
                4'b1_101:
                    alu_op_val = ALU_SRA;  // sra
                4'b0_110:
                    alu_op_val = ALU_OR;   // or
                4'b0_111:
                    alu_op_val = ALU_AND;  // and
                default:
                    alu_op_val = ALU_ADD;
            endcase
        end
        else if (is_i_type && !is_load && !is_jalr) begin
            case (funct3)
                3'b000:
                    alu_op_val = ALU_ADD;  // addi
                3'b001:
                    alu_op_val = ALU_SLL;  // slli
                3'b010:
                    alu_op_val = ALU_SLT;  // slti
                3'b011:
                    alu_op_val = ALU_SLTU; // sltiu
                3'b100:
                    alu_op_val = ALU_XOR;  // xori
                3'b101:
                    alu_op_val = (inst[30]) ? ALU_SRA : ALU_SRL; // srai, srli
                3'b110:
                    alu_op_val = ALU_OR;   // ori
                3'b111:
                    alu_op_val = ALU_AND;  // andi
                default:
                    alu_op_val = ALU_ADD;
            endcase
        end
        else if (is_load || is_store || is_jalr) begin
            alu_op_val = ALU_ADD; // 所有加载/存储/jalr指令都使用加法
        end
        else if (is_b_type) begin
            case (funct3)
                3'b000:
                    alu_op_val = ALU_SUB; // beq
                3'b001:
                    alu_op_val = ALU_SUB; // bne
                3'b100:
                    alu_op_val = ALU_SLT; // blt
                3'b101:
                    alu_op_val = ALU_SLT; // bge
                3'b110:
                    alu_op_val = ALU_SLTU; // bltu
                3'b111:
                    alu_op_val = ALU_SLTU; // bgeu
                default:
                    alu_op_val = ALU_SUB;
            endcase
        end
        else begin
            alu_op_val = ALU_ADD; // 默认为加法
        end
    end

    assign alu_op = alu_op_val;

    // 控制信号生成
    assign reg_wen = is_r_type || is_i_type || is_u_type || is_j_type || is_jalr;
    assign mem_wen = is_store;
    assign mem_ren = is_load;
    assign use_imm = is_i_type || is_s_type || is_u_type || is_j_type;
    assign branch  = is_b_type;
    assign jump    = is_jal || is_jalr;

endmodule
