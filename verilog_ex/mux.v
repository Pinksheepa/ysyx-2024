/*
数据流建模
*/
module mux21(a,b,s,y);
    input a,b,s;
    output y;

    assign y = (~s & a) | (s & b);
    
endmodule //mux21

