`include "include/defines.v"

module top (
        input  wire clk,   // 时钟信号
        input  wire rst    // 复位信号
    );

    // ----- 内部连线 -----
    // PC相关
    wire [31:0] pc;
    wire [31:0] next_pc;
    wire [31:0] pc_plus_4 = pc + 32'd4;
    wire [31:0] branch_target;

    // 指令相关
    wire [31:0] inst;

    // 译码器输出
    wire [ 4:0] rs1_addr;
    wire [ 4:0] rs2_addr;
    wire [ 4:0] rd_addr;
    wire [ 6:0] opcode;
    wire [ 2:0] funct3;
    wire [ 6:0] funct7;
    wire [ 2:0] inst_type;
    wire [ 3:0] alu_op;
    wire        mem_read;
    wire        mem_write;
    wire        reg_write;
    wire        is_branch;
    wire        is_jal;
    wire        is_jalr;
    wire        is_lui;
    wire        is_auipc;
    wire        is_ebreak;
    wire        use_imm;

    // 寄存器数据
    wire [31:0] rs1_data;
    wire [31:0] rs2_data;
    wire [31:0] rd_data;

    // 立即数
    wire [31:0] imm;

    // ALU相关
    wire [31:0] alu_src1;
    wire [31:0] alu_src2;
    wire [31:0] alu_result;
    wire        alu_zero;
    wire        alu_less_than;

    // 内存相关
    wire [31:0] mem_read_data;

    // CSR相关
    wire [31:0] csr_read_data;
    wire        trap_flag;

    // 分支条件判断
    wire branch_taken = is_branch & (
             (funct3 == 3'b000 & alu_zero) |             // BEQ
             (funct3 == 3'b001 & ~alu_zero) |            // BNE
             (funct3 == 3'b100 & alu_less_than) |        // BLT
             (funct3 == 3'b101 & ~alu_less_than) |       // BGE
             (funct3 == 3'b110 & (rs1_data < rs2_data)) | // BLTU
             (funct3 == 3'b111 & (rs1_data >= rs2_data))  // BGEU
         );

    // ----- 程序计数器 -----
    PC_Reg pc_reg (
               .clk(clk),
               .rst(rst),
               .next_pc(next_pc),
               .pc(pc)
           );

    // ----- 指令存储器 -----
    InstMem inst_mem (
                .clk(clk),
                .addr(pc),
                .inst(inst)
            );

    // ----- 指令译码单元 -----
    IDU idu (
            .inst(inst),
            .rs1_addr(rs1_addr),
            .rs2_addr(rs2_addr),
            .rd_addr(rd_addr),
            .opcode(opcode),
            .funct3(funct3),
            .funct7(funct7),
            .inst_type(inst_type),
            .alu_op(alu_op),
            .mem_read(mem_read),
            .mem_write(mem_write),
            .reg_write(reg_write),
            .is_branch(is_branch),
            .is_jal(is_jal),
            .is_jalr(is_jalr),
            .is_lui(is_lui),
            .is_auipc(is_auipc),
            .is_ebreak(is_ebreak),
            .use_imm(use_imm)
        );

    // ----- 立即数生成单元 -----
    ImmGen imm_gen (
               .inst(inst),
               .inst_type(inst_type),
               .imm(imm)
           );

    // ----- 通用寄存器组 -----
    GPR gpr (
            .clk(clk),
            .rst(rst),
            .rs1_addr(rs1_addr),
            .rs2_addr(rs2_addr),
            .rd_addr(rd_addr),
            .rd_data(rd_data),
            .reg_write(reg_write),
            .rs1_data(rs1_data),
            .rs2_data(rs2_data)
        );

    // ----- 算术逻辑单元 -----
    // 选择ALU输入
    assign alu_src1 = (is_auipc | is_jal) ? pc : rs1_data;
    assign alu_src2 = use_imm ? imm : rs2_data;

    ALU alu (
            .src1(alu_src1),
            .src2(alu_src2),
            .alu_op(alu_op),
            .result(alu_result),
            .zero(alu_zero),
            .less_than(alu_less_than)
        );

    // ----- 数据存储器 -----
    DataMem data_mem (
                .clk(clk),
                .addr(alu_result),
                .write_data(rs2_data),
                .mem_write(mem_write),
                .mem_read(mem_read),
                .funct3(funct3),
                .read_data(mem_read_data)
            );

    // ----- CSR控制状态寄存器 -----
    CSR csr (
            .clk(clk),
            .rst(rst),
            .csr_addr(inst[31:20]),
            .csr_write_data(rs1_data),
            .csr_write(opcode == `OPCODE_SYSTEM && funct3 != 3'b000),
            .csr_read_data(csr_read_data),
            .is_ebreak(is_ebreak),
            .trap_flag(trap_flag)
        );

    // ----- 结果选择 -----
    // 计算分支目标地址
    assign branch_target = is_jalr ? (rs1_data + imm) & ~32'h1 : pc + imm;

    // 选择下一个PC值
    assign next_pc = (is_jal || (is_branch && branch_taken) || is_jalr) ?
           branch_target : pc_plus_4;

    // 选择写回寄存器的数据
    assign rd_data = is_lui ? imm :
           (is_auipc || is_jal || is_jalr) ? pc_plus_4 :
           mem_read ? mem_read_data :
           alu_result;

    // ----- 调试信息 -----
    // 监控周期和指令执行
    reg [31:0] cycle_count;

    always @(posedge clk) begin
        if (rst) begin
            cycle_count <= 0;
        end
        else begin
            cycle_count <= cycle_count + 1;

            // 打印调试信息
            $display("-------- Cycle %0d --------", cycle_count);
            $display("PC = 0x%h, Instruction = 0x%h", pc, inst);

            if (reg_write && rd_addr != 0) begin
                $display("写入寄存器 x%0d = %0d", rd_addr, rd_data);
            end

            // 检测ebreak指令
            if (is_ebreak) begin
                $display("\n-------- EBREAK detected at PC = 0x%h --------", pc);
                $display("寄存器最终状态:");
                for (integer i = 0; i < 32; i = i + 1) begin
                    $display("x%0d = %0d", i, gpr.rf[i]);
                end
                $finish;
            end
        end
    end

endmodule

