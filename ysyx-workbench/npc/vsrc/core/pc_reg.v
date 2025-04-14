module PC_Reg (
        input  wire        clk,        // 时钟信号
        input  wire        rst,        // 复位信号
        input  wire [31:0] next_pc,    // 下一个PC值
        output reg  [31:0] pc          // 当前PC
    );

    // 明确使用参数定义RESET_VECTOR
    parameter RESET_VECTOR = 32'h8000_0000;

    // PC寄存器逻辑
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // 复位时设置PC为RESET_VECTOR
            pc <= RESET_VECTOR;
        end
        else begin
            // 否则更新为next_pc
            pc <= next_pc;
        end
    end
endmodule
