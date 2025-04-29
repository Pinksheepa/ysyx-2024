// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\PipeRegIFID.v
// IF/ID流水线寄存器模块
module PipeRegIFID (
        input  wire        clk,          // 时钟信号
        input  wire        rst,          // 复位信号
        input  wire        stall,        // 暂停信号
        input  wire        flush,        // 冲刷信号
        input  wire [31:0] if_pc,        // IF阶段的PC值
        input  wire [31:0] if_instr,     // IF阶段的指令
        output reg  [31:0] id_pc,        // ID阶段的PC值
        output reg  [31:0] id_instr      // ID阶段的指令
    );

    // 流水线寄存器更新逻辑
    always @(posedge clk) begin
        if (rst) begin
            // 复位时清零所有输出
            id_pc    <= 32'b0;
            id_instr <= 32'b0;
        end
        else if (flush) begin
            // 冲刷时插入空指令
            id_pc    <= 32'b0;
            id_instr <= 32'b0;
        end
        else if (!stall) begin
            // 非暂停状态下正常传递数据
            id_pc    <= if_pc;
            id_instr <= if_instr;
        end
        // 如果stall为1，保持当前值不变
    end

endmodule
