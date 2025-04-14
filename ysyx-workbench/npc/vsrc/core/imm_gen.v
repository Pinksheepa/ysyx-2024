`include "include/defines.v"

module ImmGen (
        input  wire [31:0] inst,        // 指令
        input  wire [ 2:0] inst_type,   // 指令类型
        output reg  [31:0] imm          // 生成的立即数
    );

    always @(*) begin
        case (inst_type)
            `TYPE_I:
                imm = {{20{inst[31]}}, inst[31:20]};
            `TYPE_S:
                imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
            `TYPE_B:
                imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
            `TYPE_U:
                imm = {inst[31:12], 12'b0};
            `TYPE_J:
                imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
            default:
                imm = 32'b0;
        endcase
    end

endmodule
