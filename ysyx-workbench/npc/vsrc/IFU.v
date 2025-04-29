// 指令取指单元(IFU) - 负责从指令存储器获取指令
module IFU (
        input  wire        clk,        // 时钟信号
        input  wire        rst,        // 复位信号
        input  wire        stall,      // 流水线暂停信号
        input  wire        branch_taken,// 分支是否跳转
        input  wire [31:0] branch_target,// 分支目标地址
        input  wire [31:0] pc,         // 当前PC值
        output wire [31:0] pc_plus4,   // PC+4
        output wire [31:0] if_pc,      // IF阶段传递的PC值
        output wire [31:0] imem_addr,  // 指令存储器地址
        input  wire [31:0] imem_rdata, // 指令存储器读取数据
        output wire        imem_valid, // 指令存储器访问有效信号
        output wire [31:0] if_instr    // IF阶段输出的指令
    );

    // 指令存储器地址就是当前PC
    assign imem_addr = pc;

    // 始终有效，表示每个周期都在取指
    assign imem_valid = 1'b1;

    // PC+4，用于顺序执行时的下一条指令
    assign pc_plus4 = pc + 4;

    // IF阶段输出的PC就是当前PC
    assign if_pc = pc;

    // 指令直接从指令存储器获取
    assign if_instr = imem_rdata;

endmodule
