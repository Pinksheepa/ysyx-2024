
// 1bit adder

module adder_1bit(
    input a,
    input b,
    input ci;
    output s;
    output co;

);

    assign s = a ^ b ^ ci;
    assign co = (a & b) | 

endmodule