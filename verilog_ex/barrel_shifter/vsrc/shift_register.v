// barrel shifter 8bit

module barrel_shifter_8bit(
       input [7:0] data_in,       // 8-bit input data
       input [2:0] shift_amount,  // Shift amount (0-7 bits)
       input direction,           // Shift direction: 0=right, 1=left
       input arithmetic,          // Shift type: 0=logical shift, 1=arithmetic shift
       output [7:0] data_out      // Shifted output data
    );

    wire [7:0] stage1, stage2, stage3;
    wire fill_bit;

    // For arithmetic right shift, fill bit is sign bit (data_in[7])
    // For logical shift and left shift, fill bit is 0
    assign fill_bit = (arithmetic && !direction) ? data_in[7] : 1'b0;

    // Stage 1: Shift by 0 or 1 bit
    assign stage1 = shift_amount[0] ?
          (direction ? {data_in[6:0], fill_bit} : {fill_bit, data_in[7:1]}) :
          data_in;

    // Stage 2: Shift by 0 or 2 bits
    assign stage2 = shift_amount[1] ?
          (direction ? {stage1[5:0], {2{fill_bit}}} : {{2{fill_bit}}, stage1[7:2]}) :
          stage1;

    // Stage 3: Shift by 0 or 4 bits
    assign stage3 = shift_amount[2] ?
          (direction ? {stage2[3:0], {4{fill_bit}}} : {{4{fill_bit}}, stage2[7:4]}) :
          stage2;

    // Final output
    assign data_out = stage3;

endmodule

