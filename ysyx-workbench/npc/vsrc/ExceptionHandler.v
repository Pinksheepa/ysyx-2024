// 异常处理单元 - 负责检测、仲裁异常并触发处理流程
module ExceptionHandler (
        input  wire        clk,                 // 时钟信号
        input  wire        rst,                 // 复位信号

        // 异常信号输入（从不同流水线阶段）
        input  wire        id_illegal_instr,    // ID阶段检测到的非法指令异常
        input  wire [31:0] id_instr,            // ID阶段的指令
        input  wire [31:0] id_pc,               // ID阶段的PC

        // 可选：其他类型异常的输入
        // input  wire        mem_load_misalign,   // MEM阶段加载地址未对齐
        // input  wire        mem_store_misalign,  // MEM阶段存储地址未对齐
        // input  wire [31:0] mem_addr,            // 内存访问地址

        // 流水线控制信号
        input  wire        wb_valid,            // WB阶段指令有效
        input  wire [31:0] wb_pc,               // WB阶段PC
        input  wire [31:0] wb_instr,            // WB阶段指令

        // 异常处理信号输出
        output reg         exception_valid,     // 异常有效信号
        output reg  [3:0]  exception_code,      // 异常代码
        output reg  [31:0] exception_pc,        // 异常PC
        output reg  [31:0] exception_val,       // 异常相关值
        output reg         pipeline_flush,      // 流水线冲刷信号

        // 从CSR获取的异常处理入口地址
        input  wire [31:0] trap_vector,         // 异常处理入口地址
        output reg         redirect_pc,         // PC重定向信号
        output reg  [31:0] new_pc               // 新的PC值
    );

    // 异常代码定义
    localparam EXC_ILLEGAL_INSTRUCTION   = 4'd2;  // 非法指令异常

    // 异常检测和仲裁
    reg exception_detected;
    reg [3:0] detected_exception_code;
    reg [31:0] detected_exception_val;

    // 异常状态（简单的状态机）
    reg handling_exception; // 指示是否正在处理异常

    // 检测和仲裁异常
    always @(*) begin
        exception_detected = 1'b0;
        detected_exception_code = 4'd0;
        detected_exception_val = 32'h0;

        // 优先级：如有多种异常，按优先级选择（例如内存异常 > 非法指令）

        // 如果有多种异常，这里可以添加其他异常检测

        // 非法指令异常检测
        if (id_illegal_instr) begin
            exception_detected = 1'b1;
            detected_exception_code = EXC_ILLEGAL_INSTRUCTION;
            detected_exception_val = id_instr; // 保存非法指令本身
        end
    end

    // 异常处理状态机
    always @(posedge clk) begin
        if (rst) begin
            handling_exception <= 1'b0;
            exception_valid <= 1'b0;
            exception_code <= 4'd0;
            exception_pc <= 32'h0;
            exception_val <= 32'h0;
            pipeline_flush <= 1'b0;
            redirect_pc <= 1'b0;
            new_pc <= 32'h0;
        end
        else begin
            // 默认值
            exception_valid <= 1'b0;
            pipeline_flush <= 1'b0;
            redirect_pc <= 1'b0;

            if (!handling_exception && exception_detected) begin
                // 检测到新异常，开始处理
                handling_exception <= 1'b1;
                exception_valid <= 1'b1;
                exception_code <= detected_exception_code;
                exception_pc <= id_pc; // 异常指令的PC（这里简化处理，使用ID阶段的PC）
                exception_val <= detected_exception_val;
                pipeline_flush <= 1'b1; // 冲刷流水线
                redirect_pc <= 1'b1;
                new_pc <= trap_vector; // 跳转到异常处理入口
            end
            else if (handling_exception) begin
                // 异常处理完成，重置状态
                handling_exception <= 1'b0;
            end
        end
    end

endmodule
