// 指令译码单元(IDU) - 负责解码指令并生成控制信号
// `timescale 1ns / 1ps

module IDU (
        input  wire        clk,       // 时钟信号
        input  wire        rst,       // 复位信号
        input  wire [31:0] id_pc,     // ID阶段的PC值
        input  wire [31:0] id_instr,  // ID阶段的指令

        // 寄存器堆接口
        input  wire [31:0] rs1_data,  // 寄存器值输入
        input  wire [31:0] rs2_data,  // 寄存器值输入
        output wire [4:0]  rs1,       // 源寄存器1地址
        output wire [4:0]  rs2,       // 源寄存器2地址
        output wire [4:0]  rd,        // 目标寄存器地址

        // 控制信号和数据输出
        output wire [31:0] imm,       // 立即数
        output wire        reg_wen,   // 寄存器写使能
        output wire        mem_wen,   // 内存写使能
        output wire        mem_ren,   // 内存读使能
        output wire [3:0]  alu_op,    // ALU操作码
        output wire        use_imm,   // 使用立即数标志
        output wire        branch,    // 分支指令标志
        output wire        jump,      // 跳转指令标志
        output wire        is_jalr,   // jalr指令标志

        // 增加额外的控制信号
        output wire [2:0]  mem_type,  // 内存访问类型 (00:字节, 01:半字, 10:字)
        output wire        mem_unsigned, // 内存无符号加载
        output wire [1:0]  wb_sel,    // 写回数据选择 (00:ALU, 01:MEM, 10:PC+4)
        output wire        csr_ren,   // CSR读使能
        output wire        csr_wen,   // CSR写使能
        output wire [11:0] csr_addr,  // CSR地址
        output wire [1:0]  csr_op,    // CSR操作类型: 00=RW, 01=RS, 10=RC, 11=保留
        output wire        csr_imm,   // CSR立即数操作
        output wire        illegal_instr // 非法指令标志
    );

    // 指令格式字段
    wire [6:0] opcode = id_instr[6:0];
    wire [2:0] funct3 = id_instr[14:12];
    wire [6:0] funct7 = id_instr[31:25];
    wire [11:0] funct12 = id_instr[31:20]; // ebreak/ecall使用

    // CSR地址
    assign csr_addr = id_instr[31:20];

    // 特殊指令检测
    wire is_ebreak = (opcode == 7'b1110011) && (funct3 == 3'b000) && (funct12 == 12'h001);
    wire is_ecall  = (opcode == 7'b1110011) && (funct3 == 3'b000) && (funct12 == 12'h000);
    wire is_fence  = (opcode == 7'b0001111);
    wire is_csr    = (opcode == 7'b1110011) && (funct3 != 3'b000);

    // CSR指令类型细分
    wire is_csrrw  = is_csr && (funct3[1:0] == 2'b01);    // csrrw/csrrwi
    wire is_csrrs  = is_csr && (funct3[1:0] == 2'b10);    // csrrs/csrrsi
    wire is_csrrc  = is_csr && (funct3[1:0] == 2'b11);    // csrrc/csrrci
    wire is_csr_imm = is_csr && funct3[2];                // 立即数版CSR指令

    // 寄存器地址
    assign rs1 = id_instr[19:15];
    assign rs2 = id_instr[24:20];
    assign rd  = id_instr[11:7];

    // 指令类型判断
    wire is_r_type = (opcode == 7'b0110011); // R型指令：如 add, sub
    wire is_i_type = (opcode == 7'b0010011) || (opcode == 7'b0000011) || (opcode == 7'b1100111) || is_csr; // I型指令：算术、加载、jalr、CSR
    wire is_s_type = (opcode == 7'b0100011); // S型指令：存储
    wire is_b_type = (opcode == 7'b1100011); // B型指令：分支
    wire is_u_type = (opcode == 7'b0110111) || (opcode == 7'b0010111); // U型指令：lui, auipc
    wire is_j_type = (opcode == 7'b1101111); // J型指令：jal

    wire is_load  = (opcode == 7'b0000011); // 加载指令
    wire is_store = (opcode == 7'b0100011); // 存储指令
    wire is_jal   = (opcode == 7'b1101111); // jal指令
    assign is_jalr  = (opcode == 7'b1100111) && (funct3 == 3'b000); // jalr指令
    wire is_lui   = (opcode == 7'b0110111); // lui指令
    wire is_auipc = (opcode == 7'b0010111); // auipc指令

    // 立即数生成
    wire [31:0] i_imm = {{20{id_instr[31]}}, id_instr[31:20]};
    wire [31:0] s_imm = {{20{id_instr[31]}}, id_instr[31:25], id_instr[11:7]};
    wire [31:0] b_imm = {{19{id_instr[31]}}, id_instr[31], id_instr[7], id_instr[30:25], id_instr[11:8], 1'b0};
    wire [31:0] u_imm = {id_instr[31:12], 12'b0};
    wire [31:0] j_imm = {{11{id_instr[31]}}, id_instr[31], id_instr[19:12], id_instr[20], id_instr[30:21], 1'b0};
    wire [31:0] csr_zimm = {27'b0, rs1}; // CSR立即数指令使用rs1字段作为无符号5位立即数

    // 立即数选择
    reg [31:0] imm_val;
    always @(*) begin
        if (is_i_type) begin
            if (is_csr && is_csr_imm)
                imm_val = csr_zimm;
            else
                imm_val = i_imm;
        end
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
    localparam ALU_LUI  = 4'b1010; // LUI操作，直接输出imm
    localparam ALU_COPY_A = 4'b1011; // 直接输出A（用于CSR操作）
    localparam ALU_COPY_B = 4'b1100; // 直接输出B（用于CSR操作）

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
        else if (is_i_type && !is_load && !is_jalr && !is_csr) begin
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
                    alu_op_val = (id_instr[30]) ? ALU_SRA : ALU_SRL; // srai, srli
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
        else if (is_lui) begin
            alu_op_val = ALU_LUI; // lui直接传递立即数
        end
        else if (is_auipc) begin
            alu_op_val = ALU_ADD; // auipc是PC+立即数
        end
        else if (is_csr) begin
            case (funct3)
                3'b001:
                    alu_op_val = ALU_COPY_A;  // csrrw
                3'b010:
                    alu_op_val = ALU_COPY_A;  // csrrs
                3'b011:
                    alu_op_val = ALU_COPY_A;  // csrrc
                3'b101:
                    alu_op_val = ALU_COPY_B;  // csrrwi
                3'b110:
                    alu_op_val = ALU_COPY_B;  // csrrsi
                3'b111:
                    alu_op_val = ALU_COPY_B;  // csrrci
                default:
                    alu_op_val = ALU_ADD;
            endcase
        end
        else begin
            alu_op_val = ALU_ADD; // 默认为加法
        end
    end

    assign alu_op = alu_op_val;

    // 内存访问类型 (00:字节, 01:半字, 10:字)
    reg [2:0] mem_type_val;
    reg mem_unsigned_val;
    always @(*) begin
        if (is_load || is_store) begin
            case (funct3[1:0])
                2'b00:
                    mem_type_val = 2'b00; // 字节
                2'b01:
                    mem_type_val = 2'b01; // 半字
                2'b10:
                    mem_type_val = 2'b10; // 字
                default:
                    mem_type_val = 2'b00;
            endcase
            mem_unsigned_val = funct3[2]; // 第三位表示是否无符号
        end
        else begin
            mem_type_val = 2'b00;
            mem_unsigned_val = 1'b0;
        end
    end

    assign mem_type = mem_type_val;
    assign mem_unsigned = mem_unsigned_val;

    // 写回数据选择 (00:ALU, 01:MEM, 10:PC+4, 11:CSR)
    reg [1:0] wb_sel_val;
    always @(*) begin
        if (is_load)
            wb_sel_val = 2'b01; // 从内存读取
        else if (is_jal || is_jalr)
            wb_sel_val = 2'b10; // PC+4
        else if (is_csr)
            wb_sel_val = 2'b11; // CSR读取值
        else
            wb_sel_val = 2'b00; // ALU结果
    end

    assign wb_sel = wb_sel_val;

    // CSR控制信号
    assign csr_ren = is_csr;
    assign csr_wen = is_csr && (rs1 != 5'b0 || is_csrrw); // 当rs1=0时，csrrs/csrrc不会写CSR，但csrrw仍会
    assign csr_imm = is_csr_imm;

    // CSR操作类型
    reg [1:0] csr_op_val;
    always @(*) begin
        if (is_csrrw)
            csr_op_val = 2'b00; // RW
        else if (is_csrrs)
            csr_op_val = 2'b01; // RS
        else if (is_csrrc)
            csr_op_val = 2'b10; // RC
        else
            csr_op_val = 2'b00; // 默认RW
    end

    assign csr_op = csr_op_val;

    // 非法指令检测逻辑
    reg illegal_instr_reg;
    always @(*) begin
        if (id_instr == 32'h0)
            illegal_instr_reg = 1'b0; // 空指令(0x00000000)不认为是非法指令
        else begin
            // 默认假设指令是非法的
            illegal_instr_reg = 1'b1;

            // 检查是否为有效的指令类型
            if (
                // R型指令
                (is_r_type && funct7 != 7'h01 && (
                     (funct3 == 3'b000 && (funct7 == 7'h00 || funct7 == 7'h20)) || // add, sub
                     (funct3 == 3'b001 && funct7 == 7'h00) || // sll
                     (funct3 == 3'b010 && funct7 == 7'h00) || // slt
                     (funct3 == 3'b011 && funct7 == 7'h00) || // sltu
                     (funct3 == 3'b100 && funct7 == 7'h00) || // xor
                     (funct3 == 3'b101 && (funct7 == 7'h00 || funct7 == 7'h20)) || // srl, sra
                     (funct3 == 3'b110 && funct7 == 7'h00) || // or
                     (funct3 == 3'b111 && funct7 == 7'h00)    // and
                 )) ||

                // R型乘除法指令(M扩展)
                (is_r_type && funct7 == 7'h01 && (
                     (funct3 == 3'b000) || // mul
                     (funct3 == 3'b001) || // mulh
                     (funct3 == 3'b010) || // mulhsu
                     (funct3 == 3'b011) || // mulhu
                     (funct3 == 3'b100) || // div
                     (funct3 == 3'b101) || // divu
                     (funct3 == 3'b110) || // rem
                     (funct3 == 3'b111)    // remu
                 )) ||

                // I型算术指令
                (opcode == 7'b0010011 && (
                     (funct3 == 3'b000) || // addi
                     (funct3 == 3'b010) || // slti
                     (funct3 == 3'b011) || // sltiu
                     (funct3 == 3'b100) || // xori
                     (funct3 == 3'b110) || // ori
                     (funct3 == 3'b111) || // andi
                     (funct3 == 3'b001 && id_instr[31:25] == 7'h00) || // slli
                     // srli, srai - 检查imm[5:11]是否正确
                     (funct3 == 3'b101 && (id_instr[31:25] == 7'h00 || id_instr[31:25] == 7'h20))
                 )) ||

                // 加载指令
                (is_load && (
                     (funct3 == 3'b000) || // lb
                     (funct3 == 3'b001) || // lh
                     (funct3 == 3'b010) || // lw
                     (funct3 == 3'b100) || // lbu
                     (funct3 == 3'b101)    // lhu
                 )) ||

                // 存储指令
                (is_store && (
                     (funct3 == 3'b000) || // sb
                     (funct3 == 3'b001) || // sh
                     (funct3 == 3'b010)    // sw
                 )) ||

                // 分支指令
                (is_b_type && (
                     (funct3 == 3'b000) || // beq
                     (funct3 == 3'b001) || // bne
                     (funct3 == 3'b100) || // blt
                     (funct3 == 3'b101) || // bge
                     (funct3 == 3'b110) || // bltu
                     (funct3 == 3'b111)    // bgeu
                 )) ||

                // jalr指令
                is_jalr ||

                // U型和J型指令
                is_lui || is_auipc || is_jal ||

                // fence指令
                is_fence ||

                // CSR指令
                is_csr ||

                // ecall/ebreak指令
                is_ecall || is_ebreak
            ) begin
                illegal_instr_reg = 1'b0; // 是有效指令
            end
        end
    end

    // 将生成的非法指令信号输出
    assign illegal_instr = illegal_instr_reg;

    // 基本控制信号生成
    assign reg_wen = ((is_r_type || is_i_type || is_u_type || is_j_type || is_jalr) && (rd != 5'b0)) || (is_csr && (rd != 5'b0));
    assign mem_wen = is_store;
    assign mem_ren = is_load;
    assign use_imm = is_i_type || is_s_type || is_u_type || is_j_type;
    assign branch  = is_b_type;
    assign jump    = is_jal || is_jalr;

endmodule
