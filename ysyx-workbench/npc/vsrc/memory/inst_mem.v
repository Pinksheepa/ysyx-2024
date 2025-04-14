module InstMem (
        input  wire        clk,            // 时钟信号
        input  wire [31:0] addr,           // 读取地址
        output reg  [31:0] inst            // 读取的指令
    );

    // 使用DPI-C函数读取内存
    import "DPI-C" function int pmem_read(input int addr, input int len);

               always @(*) begin
                   // 添加地址有效性检查
                   if (addr[1:0] != 2'b00) begin
                       // 非对齐地址，返回非法指令
                       inst = 32'h00000013; // NOP指令(addi x0, x0, 0)
                   end
                   else begin
                       // 从DPI-C接口读取指令
                       inst = pmem_read(addr, 4);
                   end
               end
           endmodule
