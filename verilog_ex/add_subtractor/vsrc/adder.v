
// 1bit adder

module adder_1bit(
        input a,
        input b,
        input ci,
        output s,
        output co

    );

    assign s = a ^ b ^ ci;
    assign co = (a & b) | ( ci & (a ^ b) );

endmodule

// 4bit adder with complementer

module ALU_4b(
        input [3:0] a,
        input [3:0] b,
        input cin,

        output [3:0] result,
        output carry,
        output zero,
        output overflow
    );

    wire [3:0] negation;

    assign negation = { 4{ cin } } ^ b;
    assign {carry, result} = {1'b0, a} + {1'b0, negation} + {4'b0,cin};
    assign overflow = ( a[3] == negation[3] ) && ( a[3] != result[3] );
    assign zero = ~( | result );


endmodule


