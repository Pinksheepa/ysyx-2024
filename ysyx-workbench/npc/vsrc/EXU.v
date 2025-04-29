// 执行单元(EXU) - 负责计算结果和分支判断
module EXU (
        input  wire        clk,              // 时钟信号
        input  wire        rst,              // 复位信号

        // 来自ID/EX流水线寄存器的输入
        input  wire [31:0] ex_pc,            // EX阶段PC值
        input  wire [31:0] ex_instr,         // EX阶段指令
        input  wire [31:0] ex_rs1_data,      // 寄存器rs1原始值
        input  wire [31:0] ex_rs2_data,      // 寄存器rs2原始值
        input  wire [4:0]  ex_rs1,           // rs1地址
        input  wire [4:0]  ex_rs2,           // rs2地址
        input  wire [4:0]  ex_rd,            // 目标寄存器地址
        input  wire [31:0] ex_imm,           // 立即数
        input  wire [3:0]  ex_alu_op,        // ALU操作码
        input  wire        ex_use_imm,       // 使用立即数标志
        input  wire        ex_branch,        // 分支指令标志
        input  wire        ex_jump,          // 跳转指令标志
        input  wire        ex_is_jalr,       // jalr指令标志
        input  wire        ex_reg_wen,       // 寄存器写使能
        input  wire        ex_mem_wen,       // 内存写使能
        input  wire        ex_mem_ren,       // 内存读使能

        // 扩展控制信号
        input  wire [2:0]  ex_mem_type,      // 内存访问类型
        input  wire        ex_mem_unsigned,  // 内存无符号标志
        input  wire [1:0]  ex_wb_sel,        // 写回选择
        input  wire        ex_csr_ren,       // CSR读使能
        input  wire        ex_csr_wen,       // CSR写使能
        input  wire [11:0] ex_csr_addr,      // CSR地址
        input  wire [1:0]  ex_csr_op,        // CSR操作类型
        input  wire        ex_csr_imm,       // CSR立即数操作

        // 前递单元相关信号
        input  wire [1:0]  forward_a,        // 操作数A的前递控制
        input  wire [1:0]  forward_b,        // 操作数B的前递控制
        input  wire [31:0] mem_alu_result,   // 从MEM阶段前递的ALU结果
        input  wire [31:0] wb_data,          // 从WB阶段前递的写回数据

        // 执行单元输出
        output wire [31:0] alu_result,       // ALU计算结果
        output wire        branch_taken,     // 分支是否跳转
        output wire [31:0] store_data,       // 用于存储的数据
        output wire [31:0] branch_target,    // 分支/跳转目标地址
        output wire [31:0] csr_write_data    // CSR写数据
    );

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

    // 应用前递逻辑，选择正确的rs1_data
    reg [31:0] alu_src1;
    always @(*) begin
        case (forward_a)
            2'b00:
                alu_src1 = ex_rs1_data;          // 使用ID/EX中的值(无前递)
            2'b01:
                alu_src1 = mem_alu_result;       // 从MEM阶段前递
            2'b10:
                alu_src1 = wb_data;              // 从WB阶段前递
            default:
                alu_src1 = ex_rs1_data;
        endcase
    end

    // 应用前递逻辑，选择正确的rs2_data
    reg [31:0] forwarded_rs2_data;
    always @(*) begin
        case (forward_b)
            2'b00:
                forwarded_rs2_data = ex_rs2_data; // 使用ID/EX中的值(无前递)
            2'b01:
                forwarded_rs2_data = mem_alu_result; // 从MEM阶段前递
            2'b10:
                forwarded_rs2_data = wb_data;     // 从WB阶段前递
            default:
                forwarded_rs2_data = ex_rs2_data;
        endcase
    end

    // ALU源操作数2
    wire [31:0] alu_src2 = ex_use_imm ? ex_imm : forwarded_rs2_data;

    // 特殊情况处理：auipc/jal/jalr使用PC作为操作数1
    wire is_auipc = (ex_instr[6:0] == 7'b0010111);
    wire is_jal   = (ex_instr[6:0] == 7'b1101111);

    // 最终的第一个ALU操作数
    wire [31:0] final_alu_src1 = (is_auipc || is_jal || ex_is_jalr) ? ex_pc : alu_src1;

    // ALU计算逻辑
    reg [31:0] alu_result_reg;
    always @(*) begin
        case (ex_alu_op)
            ALU_ADD:
                alu_result_reg = final_alu_src1 + alu_src2;                     // ADD
            ALU_SUB:
                alu_result_reg = final_alu_src1 - alu_src2;                     // SUB
            ALU_AND:
                alu_result_reg = final_alu_src1 & alu_src2;                     // AND
            ALU_OR:
                alu_result_reg = final_alu_src1 | alu_src2;                     // OR
            ALU_XOR:
                alu_result_reg = final_alu_src1 ^ alu_src2;                     // XOR
            ALU_SLL:
                alu_result_reg = final_alu_src1 << alu_src2[4:0];              // SLL
            ALU_SRL:
                alu_result_reg = final_alu_src1 >> alu_src2[4:0];              // SRL
            ALU_SRA:
                alu_result_reg = $signed(final_alu_src1) >>> alu_src2[4:0];    // SRA
            ALU_SLT:
                alu_result_reg = $signed(final_alu_src1) < $signed(alu_src2);  // SLT
            ALU_SLTU:
                alu_result_reg = final_alu_src1 < alu_src2;                    // SLTU
            ALU_LUI:
                alu_result_reg = alu_src2;                                     // LUI (pass IMM)
            ALU_COPY_A:
                alu_result_reg = final_alu_src1;                             // COPY_A
            ALU_COPY_B:
                alu_result_reg = alu_src2;                                   // COPY_B
            default:
                alu_result_reg = final_alu_src1 + alu_src2;                     // 默认为ADD
        endcase
    end
    assign alu_result = alu_result_reg;

    // 分支/跳转目标地址计算
    reg [31:0] branch_target_reg;
    always @(*) begin
        if (ex_is_jalr) begin
            // jalr指令: rs1 + imm，然后将最低位清零
            branch_target_reg = (alu_src1 + ex_imm) & ~32'h1;
        end
        else begin
            // 分支指令和jal指令: PC + imm
            branch_target_reg = ex_pc + ex_imm;
        end
    end
    assign branch_target = branch_target_reg;

    // 分支判断逻辑
    wire [2:0] funct3 = ex_instr[14:12];
    reg branch_taken_reg;
    always @(*) begin
        if (ex_branch) begin
            case (funct3)
                3'b000:
                    branch_taken_reg = (alu_src1 == forwarded_rs2_data);          // BEQ
                3'b001:
                    branch_taken_reg = (alu_src1 != forwarded_rs2_data);          // BNE
                3'b100:
                    branch_taken_reg = $signed(alu_src1) < $signed(forwarded_rs2_data); // BLT
                3'b101:
                    branch_taken_reg = $signed(alu_src1) >= $signed(forwarded_rs2_data); // BGE
                3'b110:
                    branch_taken_reg = alu_src1 < forwarded_rs2_data;             // BLTU
                3'b111:
                    branch_taken_reg = alu_src1 >= forwarded_rs2_data;            // BGEU
                default:
                    branch_taken_reg = 1'b0;
            endcase
        end
        else if (ex_jump) begin
            branch_taken_reg = 1'b1; // JAL/JALR总是跳转
        end
        else begin
            branch_taken_reg = 1'b0;
        end
    end
    assign branch_taken = branch_taken_reg;

    // 用于存储指令的数据(可能需要前递)
    assign store_data = forwarded_rs2_data;

    // CSR写数据生成逻辑
    reg [31:0] csr_write_data_reg;
    always @(*) begin
        if (ex_csr_imm) begin
            // 立即数CSR指令：使用uimm作为源操作数
            csr_write_data_reg = ex_imm;
        end
        else begin
            // 寄存器CSR指令：使用前递后的rs1数据
            csr_write_data_reg = alu_src1;
        end
    end
    assign csr_write_data = csr_write_data_reg;

endmodule
