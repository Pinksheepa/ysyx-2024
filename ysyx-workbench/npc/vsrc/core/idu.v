`include "include/defines.v"

module IDU (
        input  wire [31:0] inst,         // 指令输入
        output wire [ 4:0] rs1_addr,     // rs1寄存器地址
        output wire [ 4:0] rs2_addr,     // rs2寄存器地址
        output wire [ 4:0] rd_addr,      // rd寄存器地址
        output wire [ 6:0] opcode,       // 操作码
        output wire [ 2:0] funct3,       // 功能码3
        output wire [ 6:0] funct7,       // 功能码7
        output wire [ 2:0] inst_type,    // 指令类型
        output wire [ 3:0] alu_op,       // ALU操作
        output wire        mem_read,     // 内存读使能
        output wire        mem_write,    // 内存写使能
        output wire        reg_write,    // 寄存器写使能
        output wire        is_branch,    // 是否为分支指令
        output wire        is_jal,       // 是否为JAL指令
        output wire        is_jalr,      // 是否为JALR指令
        output wire        is_lui,       // 是否为LUI指令
        output wire        is_auipc,     // 是否为AUIPC指令
     //    output wire        is_ebreak,    // 是否为EBREAK指令
        output wire        use_imm       // 是否使用立即数
    );

    // 指令解码
    assign opcode    = inst[6:0];
    assign rd_addr   = inst[11:7];
    assign funct3    = inst[14:12];
    assign rs1_addr  = inst[19:15];
    assign rs2_addr  = inst[24:20];
    assign funct7    = inst[31:25];

    // 在译码逻辑中添加ebreak检测

    // ebreak指令：0x00100073
//     assign is_ebreak = (inst == 32'h00100073);

    // 指令类型判断
    wire r_type = (opcode == `OPCODE_R_TYPE);
    wire i_type = (opcode == `OPCODE_I_TYPE) || (opcode == `OPCODE_LOAD) || (opcode == `OPCODE_JALR);
    wire s_type = (opcode == `OPCODE_STORE);
    wire b_type = (opcode == `OPCODE_BRANCH);
    wire u_type = (opcode == `OPCODE_LUI) || (opcode == `OPCODE_AUIPC);
    wire j_type = (opcode == `OPCODE_JAL);

    // 指令类型编码
    assign inst_type = r_type ? `TYPE_R :
           i_type ? `TYPE_I :
           s_type ? `TYPE_S :
           b_type ? `TYPE_B :
           u_type ? `TYPE_U :
           j_type ? `TYPE_J : 3'b111;

    // 控制信号生成
    assign mem_read   = (opcode == `OPCODE_LOAD);
    assign mem_write  = (opcode == `OPCODE_STORE);
    assign reg_write  = r_type || i_type || u_type || j_type;
    assign is_branch  = b_type;
    assign is_jal     = (opcode == `OPCODE_JAL);
    assign is_jalr    = (opcode == `OPCODE_JALR);
    assign is_lui     = (opcode == `OPCODE_LUI);
    assign is_auipc   = (opcode == `OPCODE_AUIPC);
    assign use_imm    = i_type || s_type || b_type || u_type || j_type;

    // ALU操作解码
    wire [3:0] alu_op_r_type = ({funct7[5], funct3} == 4'b0_000) ? `ALU_ADD :
         ({funct7[5], funct3} == 4'b1_000) ? `ALU_SUB :
         (funct3 == 3'b001) ? `ALU_SLL :
         (funct3 == 3'b010) ? `ALU_SLT :
         (funct3 == 3'b011) ? `ALU_SLTU :
         (funct3 == 3'b100) ? `ALU_XOR :
         (funct3 == 3'b101 && !funct7[5]) ? `ALU_SRL :
         (funct3 == 3'b101 && funct7[5]) ? `ALU_SRA :
         (funct3 == 3'b110) ? `ALU_OR :
         (funct3 == 3'b111) ? `ALU_AND :
         // M扩展指令
         (funct7[0] && funct3 == 3'b000) ? `ALU_MUL :
         (funct7[0] && funct3 == 3'b001) ? `ALU_MULH :
         (funct7[0] && funct3 == 3'b100) ? `ALU_DIV :
         (funct7[0] && funct3 == 3'b101) ? `ALU_DIVU :
         (funct7[0] && funct3 == 3'b110) ? `ALU_REM :
         (funct7[0] && funct3 == 3'b111) ? `ALU_REMU : `ALU_ADD;

    wire [3:0] alu_op_i_type = (funct3 == 3'b000) ? `ALU_ADD :
         (funct3 == 3'b001) ? `ALU_SLL :
         (funct3 == 3'b010) ? `ALU_SLT :
         (funct3 == 3'b011) ? `ALU_SLTU :
         (funct3 == 3'b100) ? `ALU_XOR :
         (funct3 == 3'b101 && !funct7[5]) ? `ALU_SRL :
         (funct3 == 3'b101 && funct7[5]) ? `ALU_SRA :
         (funct3 == 3'b110) ? `ALU_OR :
         (funct3 == 3'b111) ? `ALU_AND : `ALU_ADD;

    // ALU操作选择
    assign alu_op = r_type ? alu_op_r_type :
           i_type ? alu_op_i_type :
           `ALU_ADD; // 默认加法操作

endmodule
