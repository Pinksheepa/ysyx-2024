// encoder4to2 "case" statement

module encode24_case(x,en,y);
    input [3:0] x;
    input en;
    output [1:0] y;
    reg [1:0] y;

    always @ (x or en)
    begin
        if(en)
        begin
            case (x)
                4'b0001: y = 2'b00;
                4'b0010: y = 2'b01;
                4'b0100: y = 2'b10;
                4'b1000: y = 2'b11;

                default: y = 2'b00;
            endcase
        end
        else    y = 2'b00;
    end

endmodule

// encoder4to2_priority

module encode24_for(x,en,y);
    input [3:0] x;
    input en;
    output reg [1:0] y;

    integer i;

    always @ (x or en)
    begin
        if(en)
        begin
            y = 0;
            // for(i=0; i<4; i=i+1)
            // begin
            //     if(x[i])    y = i[1:0]; // priority encoder
            // end
            for(i = 3; i >= 0 ; i = i - 1)
                if(x[i])
                begin
                    y = i[1:0];
                    break;
                end
            
        end
        else    y = 2'b00;
    end
    
endmodule //encod

