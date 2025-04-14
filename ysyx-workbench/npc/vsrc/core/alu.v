`include "include/defines.v"

module ALU (
        input  wire [31:0] src1,        // 第一个操作数
        input  wire [31:0] src2,        // 第二个操作数
        input  wire [ 3:0] alu_op,      // ALU操作码
        output reg  [31:0] result,      // 运算结果
        output wire        zero,         // 结果是否为零
        output wire        less_than     // 比较结果
    );

    // 零标志和比较标志
    assign zero = (result == 32'b0);
    assign less_than = (alu_op == `ALU_SLT) ?
           ($signed(src1) < $signed(src2)) :
           (src1 < src2); // SLTU的情况

    // 有符号乘法的64位结果
    wire signed [63:0] mul_signed = $signed(src1) * $signed(src2);
    // 无符号乘法结果
    wire [63:0] mul_unsigned = src1 * src2;

    always @(*) begin
        case (alu_op)
            `ALU_ADD:
                result = src1 + src2;
            `ALU_SUB:
                result = src1 - src2;
            `ALU_SLL:
                result = src1 << (src2 & 5'h1F);
            `ALU_SLT:
                result = {31'b0, $signed(src1) < $signed(src2)};
            `ALU_SLTU:
                result = {31'b0, src1 < src2};
            `ALU_XOR:
                result = src1 ^ src2;
            `ALU_SRL:
                result = src1 >> (src2 & 5'h1F);
            `ALU_SRA:
                result = $signed(src1) >>> (src2 & 5'h1F);
            `ALU_OR:
                result = src1 | src2;
            `ALU_AND:
                result = src1 & src2;
            `ALU_MUL:
                result = mul_signed[31:0];
            `ALU_MULH:
                result = mul_signed[63:32];
            `ALU_DIV:
                result = (src2 == 0) ? 32'hFFFFFFFF : $signed(src1) / $signed(src2);
            `ALU_DIVU:
                result = (src2 == 0) ? 32'hFFFFFFFF : src1 / src2;
            `ALU_REM:
                result = (src2 == 0) ? src1 : $signed(src1) % $signed(src2);
            `ALU_REMU:
                result = (src2 == 0) ? src1 : src1 % src2;
            default:
                result = 32'b0;
        endcase
    end

endmodule
