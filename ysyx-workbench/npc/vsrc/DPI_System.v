// DPI_System.v - 系统调用和环境调用接口模块
module DPI_System (
        input  wire        clk,
        input  wire        rst,
        input  wire        is_ecall,    // ECALL指令标志，应该在WB阶段检测
        input  wire        is_ebreak,   // EBREAK指令标志，应该在WB阶段检测
        input  wire [31:0] a0_value,    // x10(a0)寄存器的值，用作系统调用参数
        input  wire        valid,       // 指令有效标志，防止重复触发
        output wire        terminate    // 终止模拟标志
    );

    // DPI-C函数声明 - 在C++中实现
    import "DPI-C" function void npc_ecall(input int a0_value);
               import "DPI-C" function void npc_ebreak(input int a0_value);

                          // 终止标志
                          reg terminate_reg;
                          assign terminate = terminate_reg;

                          // 指令执行追踪
                          reg ecall_handled;
                          reg ebreak_handled;

                          // 处理ECALL和EBREAK指令
                          always @(posedge clk) begin
                              if (rst) begin
                                  terminate_reg <= 1'b0;
                                  ecall_handled <= 1'b0;
                                  ebreak_handled <= 1'b0;
                              end
                              else begin
                                  // 当指令有效且尚未处理时才执行
                                  if (is_ecall && valid && !ecall_handled) begin
                                      // 调用C++中的ecall处理函数
                                      npc_ecall(a0_value);
                                      ecall_handled <= 1'b1; // 标记为已处理
                                      // 通常情况下ECALL不会导致模拟终止，除非系统调用显式要求
                                  end
                                  else if (!is_ecall) begin
                                      ecall_handled <= 1'b0; // 重置标志，为下一次ECALL做准备
                                  end

                                  if (is_ebreak && valid && !ebreak_handled) begin
                                      // 调用C++中的ebreak处理函数
                                      npc_ebreak(a0_value);
                                      ebreak_handled <= 1'b1; // 标记为已处理
                                      // EBREAK通常表示程序结束
                                      terminate_reg <= 1'b1;
                                  end
                                  else if (!is_ebreak) begin
                                      ebreak_handled <= 1'b0; // 重置标志，为下一次EBREAK做准备
                                  end
                              end
                          end

                      endmodule
