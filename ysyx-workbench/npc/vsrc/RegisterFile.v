// 寄存器文件模块 - 32个通用寄存器
module RegisterFile (
        input  wire        clk,
        input  wire        rst,
        input  wire [4:0]  rs1,       // 源寄存器1地址
        input  wire [4:0]  rs2,       // 源寄存器2地址
        input  wire [4:0]  rd,        // 目标寄存器地址
        input  wire        we,        // 写使能
        input  wire [31:0] wdata,     // 写入数据
        output wire [31:0] rs1_data,  // 寄存器rs1值
        output wire [31:0] rs2_data,  // 寄存器rs2值

        // 添加a0寄存器值输出端口，用于EBREAK指令
        output wire [31:0] a0_value   // a0寄存器(x10)的值
    );

    // 32个寄存器
    reg [31:0] registers [0:31];

    // 读取寄存器值
    // x0寄存器值始终为0
    assign rs1_data = (rs1 == 5'b0) ? 32'b0 : registers[rs1];
    assign rs2_data = (rs2 == 5'b0) ? 32'b0 : registers[rs2];

    // 添加a0寄存器值输出
    assign a0_value = registers[10];

    // 写入寄存器
    integer i;
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i <= 31; i = i + 1) begin
                registers[i] <= 32'b0;
            end
        end
        else if (we && (rd != 5'b0)) begin // x0寄存器不可写入
            registers[rd] <= wdata;
        end
    end

    // 提供寄存器访问函数
    function [31:0] get_gpr;
        input [4:0] index;
        begin
            get_gpr = registers[index];
        end
    endfunction

`ifdef SIMULATION
    // 帮助调试 - 打印寄存器值变化
    always @(posedge clk) begin
        if (we && rd != 5'b0) begin
            $display("Register x%0d <= %8h", rd, wdata);
        end
    end
`endif

endmodule
