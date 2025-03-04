// 8to3encoder & 7 segment digit display

module top(x,en,zero_all,y,seg);
    input [7:0] x;
    input en;

    output zero_all;
    output reg [2:0] y;
    output reg [7:0] seg[3:0];

    encode83_priority enc(
                          .x(x),
                          .en(en),
                          .y(y)
                      );
    
    assign  zero_all = |x;

    bcd7seg o_y(
                .bcd({1'b0,y}),
                .seg(seg[0])
            );

    bcd7seg o_zero(
                .bcd 	({3'b0,zero_all}  ),
                .seg 	(seg[3])
            );

endmodule

// 8to3encoder priority

module encode83_priority(x, en, y);
    input [7:0] x;
    input en;
    output reg [2:0] y;

    integer i;

    always @(x or en) begin
        if(en) begin
            for(i=7; i>=0; i=i-1) begin
                if(x[i] == 1) begin
                    y = i[2:0];
                    break;
                end
                else
                    y=3'b000;
            end
        end
        else
            y = 3'b000;
    end
endmodule


// 7 segment digit display
module bcd7seg(bcd, seg);
    input [3:0] bcd;
    output reg [7:0] seg;

    always @(*) begin
        case (bcd)
            4'd0:
                seg = 8'b00000010; // 0
            4'd1:
                seg = 8'b10011110; // 1
            4'd2:
                seg = 8'b00100100; // 2
            4'd3:
                seg = 8'b00001100; // 3
            4'd4:
                seg = 8'b10011000; // 4
            4'd5:
                seg = 8'b01001000; // 5
            4'd6:
                seg = 8'b01000000; // 6
            4'd7:
                seg = 8'b00011110; // 7
            4'd8:
                seg = 8'b00000000; // 8
            4'd9:
                seg = 8'b00001000; // 9
            4'd10:
                seg = 8'b00010000; // A
            4'd11:
                seg = 8'b11000000; // b
            4'd12:
                seg = 8'b01100010; // C
            4'd13:
                seg = 8'b10000100; // d
            4'd14:
                seg = 8'b01100000; // E
            4'd15:
                seg = 8'b01110000; // F

            default:
                seg = 8'b11111111; // off
        endcase
    end
endmodule
