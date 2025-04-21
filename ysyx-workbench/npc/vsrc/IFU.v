// 指令取指单元(IFU) - 负责从指令存储器获取指令
module IFU (
        input  wire        clk,        // 时钟信号
        input  wire        rst,        // 复位信号
        input  wire [31:0] pc,         // 当前PC值
        output wire [31:0] imem_addr,  // 指令存储器地址
        input  wire [31:0] imem_rdata, // 指令存储器读取数据
        output wire        imem_valid, // 指令存储器访问有效信号
        output wire [31:0] inst        // 输出的指令
    );

    // 指令存储器地址就是当前PC
    assign imem_addr = pc;

    // 始终有效，表示每个周期都在取指
    assign imem_valid = 1'b1;

    // 指令直接从指令存储器获取
    assign inst = imem_rdata;

endmodule
