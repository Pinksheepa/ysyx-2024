// PC寄存器模块 - 负责处理器程序计数器的更新
module PC_Reg (
        input  wire        clk,      // 时钟信号
        input  wire        rst,      // 复位信号
        input  wire [31:0] next_pc,  // 下一条指令地址
        output wire [31:0] pc,       // 当前PC值
        input  wire        pc_wen    // PC写使能
    );

    // 使用触发器模板实现PC寄存器
    Reg #(
            .WIDTH     (32),
            .RESET_VAL (32'h80000000)  // RISC-V默认复位地址
        ) pc_reg (
            .clk  (clk),
            .rst  (rst),
            .din  (next_pc),
            .dout (pc),
            .wen  (pc_wen)
        );

endmodule
