module top(x,y,f);
    input [1:0] x[3:0];
    input [1:0] y;
    output reg [1:0]  f;

    MuxKey #(4,2,2) i0(f, y, {
        2'b00, x[0],
        2'b01, x[1],
        2'b10, x[2],
        2'b11, x[3]
    });

endmodule
