// 4bit(complementer) ALU with logic operation and compare

module top (
        input [3:0] a,
        input [3:0] b,
        input [2:0] op,


        output reg [3:0] y,
        output reg zero,
        output reg overflow,
        output reg carry,
        output reg equal
    );

    wire [3:0] alu_result;
    wire alu_carry, alu_zero, alu_overflow;

    ALU_4b u_ALU_4b(
               .a(a),
               .b(b),
               .cin(op[0]),
               .result(alu_result),
               .carry(alu_carry),
               .zero(alu_zero),
               .overflow(alu_overflow)
           );


    always @(*) begin
        case (op)
            3'b000: begin // plus
                y = alu_result;
                carry = alu_carry;
                zero = alu_zero;
                overflow = alu_overflow;
                equal = 1'b0;
            end

            3'b001: begin // minus
                y = alu_result;
                carry = alu_carry;
                zero = alu_zero;
                overflow = alu_overflow;
                equal = 1'b0;
            end

            3'b010: begin // not
                y = ~a;
                zero = 1'b0;
                overflow = 1'b0;
                carry = 1'b0;
                equal = 1'b0;
            end

            // and
            3'b011:  begin
                y = a & b;
                zero = 1'b0;
                overflow = 1'b0;
                carry = 1'b0;
                equal = 1'b0;
            end

            // or
            3'b100:  begin
                y = a | b;
                zero = 1'b0;
                overflow = 1'b0;
                carry = 1'b0;
                equal = 1'b0;
            end

            // xor
            3'b101:  begin
                y = a ^ b;
                zero = 1'b0;
                overflow = 1'b0;
                carry = 1'b0;
                equal = 1'b0;
            end

            // compare
            3'b110:  begin
                y = 4'b0;
                zero = 1'b0;
                overflow = 1'b0;
                carry = 1'b0;
                equal = ( a < b );
            end

            // equal
            3'b111:  begin
                y = 4'b0;
                zero = 1'b0;
                overflow = 1'b0;
                carry = 1'b0;
                equal = (a == b);
            end

            default: begin
                y = 4'b0;
                zero = 1'b0;
                overflow = 1'b0;
                carry = 1'b0;
                equal = 1'b0;
            end
        endcase

    end

endmodule
