



//数据流建模
// module top(a,b,s,y);
//     input a,b,s;
//     output y;

//     assign y = (~s & a)|(s & b);

// endmodule

/*


//行为建模
module mux21_behavior(a,b,s,y);
    input a,b,s;
    output y;

    always @(*) begin
        if(s == 0) begin
            y = a;
        end
        else begin
            y = b;
        end

    end

endmodule




//结构化建模
module mux21_struct(a,b,s,y);
    input a,b,s;
    output y;

    wire s_n,l,o;

    and i1(.a(b), .b(s), .y(l));
    not i2(.a(s), .y(s_n));
    and i3(.a(s_n), .b(a), .y(o));
    or  i4(.a(l),.b(o), .y(y));

endmodule


module and(a,b,y);
    input a,b;
    output y;

    assign y = a & b;
endmodule

module or(a,b,y);
    input a,b;
    output y;

    assign y = a | b;
endmodule

module not(a,y);
    input a;
    output y;

    assign y = ~a;

endmodule

*/