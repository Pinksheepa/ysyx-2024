module GPR (
        input  wire        clk,          // 时钟信号
        input  wire        rst,          // 复位信号
        input  wire [ 4:0] rs1_addr,     // rs1寄存器地址
        input  wire [ 4:0] rs2_addr,     // rs2寄存器地址
        input  wire [ 4:0] rd_addr,      // rd寄存器地址
        input  wire [31:0] rd_data,      // 写入rd的数据
        input  wire        reg_write,    // 寄存器写使能
        output wire [31:0] rs1_data,     // rs1寄存器数据
        output wire [31:0] rs2_data      // rs2寄存器数据
    );

    // 32个32位寄存器
    reg [31:0] rf [31:0];

    // 读寄存器
    assign rs1_data = (rs1_addr == 5'b0) ? 32'b0 : rf[rs1_addr];
    assign rs2_data = (rs2_addr == 5'b0) ? 32'b0 : rf[rs2_addr];

    // 写寄存器
    always @(posedge clk) begin
        if (rst) begin
            integer i;
            for (i = 0; i < 32; i = i + 1) begin
                rf[i] <= 32'b0;
            end
        end
        else if (reg_write && rd_addr != 5'b0) begin
            rf[rd_addr] <= rd_data;
        end
    end

endmodule
