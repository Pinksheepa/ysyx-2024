// PC寄存器模块 - 存储程序计数器值
module PC_Reg (
        input  wire        clk,      // 时钟信号
        input  wire        rst,      // 复位信号
        input  wire        stall,    // 流水线暂停信号
        input  wire        branch_taken, // 分支/跳转信号
        input  wire [31:0] branch_target, // 分支/跳转目标地址
        input  wire [31:0] pc_plus4, // PC+4值

        // 异常处理接口
        input  wire        exception_redirect, // 异常重定向信号
        input  wire [31:0] exception_target,  // 异常处理入口地址

        output reg  [31:0] pc        // 当前PC值
    );

    // PC寄存器更新逻辑
    always @(posedge clk) begin
        if (rst) begin
            // 复位时设置为起始地址
            pc <= 32'h80000000;
        end
        else if (!stall) begin
            // 优先处理异常跳转
            if (exception_redirect)
                pc <= exception_target;
            // 其次处理分支/跳转
            else if (branch_taken)
                pc <= branch_target;
            // 最后是正常顺序执行
            else
                pc <= pc_plus4;
        end
        // 如果暂停，则保持PC不变
    end

endmodule
