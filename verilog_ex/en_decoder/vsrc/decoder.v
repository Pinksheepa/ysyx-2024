// decode2to4 "case" statement

module decode24_case(x,en,y);
    input [1:0] x;
    input en;
    output reg [3:0] y;

    always @(x or en)
        begin
            if(en)
                begin
                    case (x)
                        2'b00: y = 4'b0001;
                        2'b01: y = 4'b0010;
                        2'b10: y = 4'b0100;
                        2'b11: y = 4'b1000;
                        default: y = 4'b0000;
                    endcase
                end
            else
                y = 4'b0000;
        end

endmodule


// decode3to8 "if" statement

module decode38_if(x,en,f);
    input [2:0] x;
    input en;
    output reg [7:0] f;

    integer i;

    always @(x or en) begin
        if(en)
            begin
                for(i=0; i<8; i=i+1)
                    begin
                        if(i == x)
                            f = 8'b1 << i;
                    end
                
            end
        else    
            f = 8'b00000000;
    end


endmodule //decode38_if
