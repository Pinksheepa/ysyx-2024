module DataMem (
        input  wire        clk,           // 时钟信号
        input  wire [31:0] addr,          // 地址
        input  wire [31:0] write_data,    // 写入数据
        input  wire        mem_write,     // 写使能
        input  wire        mem_read,      // 读使能
        input  wire [ 2:0] funct3,        // 功能码，决定访问大小
        output reg  [31:0] read_data      // 读出数据
    );

    // 数据存储器 (4KB)
    reg [7:0] dmem [4095:0];

    // 初始化内存
    initial begin
        integer i;
        for (i = 0; i < 4096; i = i + 1) begin
            dmem[i] = 8'b0;
        end
    end

    // 内存写入
    always @(posedge clk) begin
        if (mem_write) begin
            case (funct3)
                3'b000:
                    dmem[addr] <= write_data[7:0];                                // SB
                3'b001: begin                                                         // SH
                    dmem[addr]   <= write_data[7:0];
                    dmem[addr+1] <= write_data[15:8];
                end
                3'b010: begin                                                         // SW
                    dmem[addr]   <= write_data[7:0];
                    dmem[addr+1] <= write_data[15:8];
                    dmem[addr+2] <= write_data[23:16];
                    dmem[addr+3] <= write_data[31:24];
                end
            endcase
        end
    end

    // 内存读取
    always @(*) begin
        if (mem_read) begin
            case (funct3)
                3'b000:
                    read_data = {{24{dmem[addr][7]}}, dmem[addr]};                               // LB
                3'b001:
                    read_data = {{16{dmem[addr+1][7]}}, dmem[addr+1], dmem[addr]};               // LH
                3'b010:
                    read_data = {dmem[addr+3], dmem[addr+2], dmem[addr+1], dmem[addr]};          // LW
                3'b100:
                    read_data = {24'b0, dmem[addr]};                                             // LBU
                3'b101:
                    read_data = {16'b0, dmem[addr+1], dmem[addr]};                               // LHU
                default:
                    read_data = 32'b0;
            endcase
        end
        else begin
            read_data = 32'b0;
        end
    end

endmodule
