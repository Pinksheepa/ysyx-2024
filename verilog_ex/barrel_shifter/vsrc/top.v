// randomizer
// linear-feedback shifter register

module top (
        input [7:0] data_in,       // 8-bit input data
        input clk,                 // Clock

        // output [7:0] data_out,      // Shifted output data
        output reg [7:0] seg
    );

    wire fill_bit;
    reg [7:0] data_out;
    reg [7:0] shift_reg;



    assign fill_bit = shift_reg[3] ^ shift_reg[2] ^ shift_reg[1] ^ shift_reg[0];
    assign data_out = {fill_bit, shift_reg[7:1]};


    // output declaration of module encode83_priority
    reg [2:0] y;

    encode83_priority u_encode83_priority(
                          .x  	(data_out),
                          .en 	(1'b1),
                          .y  	(y)
                      );

    // output declaration of module bcd7seg
    bcd7seg u_bcd7seg(
                .bcd({1'b0,y}),
                .seg(seg)
            );

    always @(posedge clk) begin
        if (shift_reg == 8'h00)  // zero load seed
            shift_reg <= 8'h01;
        else
            shift_reg <= data_out;
    end


endmodule


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
