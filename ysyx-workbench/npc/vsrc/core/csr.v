module CSR (
        input  wire        clk,           // 时钟信号
        input  wire        rst,           // 复位信号
        input  wire [11:0] csr_addr,      // CSR地址
        input  wire [31:0] csr_write_data,// 写入数据
        input  wire        csr_write,     // 写使能
        output wire [31:0] csr_read_data, // 读出数据
        // EBREAK处理相关信号
        // input  wire        is_ebreak,     // 是否为EBREAK指令
        output reg         trap_flag     // 陷阱标志
        // input  wire [31:0] rs1_data       // a0寄存器的值用作退出码
    );

    // CSR寄存器 (仅实现简单的几个)
    reg [31:0] csr_regs [4095:0];

    // 读取CSR
    assign csr_read_data = csr_regs[csr_addr];

    // 添加DPI-C接口声明
    // import "DPI-C" function void sim_exit(input int exit_code);

               // 写入CSR和处理EBREAK
               always @(posedge clk) begin
                   if (rst) begin
                       trap_flag <= 1'b0;
                       // 初始化CSR
                       csr_regs[12'h300] <= 32'h0; // mstatus
                       csr_regs[12'h301] <= 32'h0; // misa
                       csr_regs[12'h305] <= 32'h0; // mtvec
                   end
                   else begin
                       if (csr_write) begin
                           csr_regs[csr_addr] <= csr_write_data;
                       end

                    //    // 处理EBREAK
                    //    if (is_ebreak) begin
                    //        trap_flag <= 1'b1;
                    //        sim_exit(csr_write_data); // 使用a0寄存器的值作为退出码
                    //    end
                   end
               end

           endmodule
