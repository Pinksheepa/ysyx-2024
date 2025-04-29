// CSR寄存器文件 - 实现RISC-V CSR指令支持
module CSRFile (
        input  wire        clk,           // 时钟信号
        input  wire        rst,           // 复位信号
        input  wire [11:0] read_addr,     // CSR读地址
        input  wire        read_en,       // CSR读使能
        input  wire [11:0] write_addr,    // CSR写地址
        input  wire [31:0] write_data,    // CSR写数据
        input  wire        write_en,      // CSR写使能
        input  wire [1:0]  csr_op,        // CSR操作类型: 00=RW, 01=RS, 10=RC, 11=保留
        output reg  [31:0] read_data,     // CSR读出的数据

        // 异常处理接口
        input  wire        exception,     // 异常发生信号
        input  wire [3:0]  exception_code, // 异常代码
        input  wire [31:0] exception_pc,  // 异常指令的PC
        input  wire [31:0] exception_val, // 异常相关值(如非法指令本身)
        output wire [31:0] trap_vector    // 异常处理入口地址(mtvec)
    );

    /* verilator lint_off UNUSEDPARAM */
    // CSR地址定义
    localparam CSR_MSTATUS    = 12'h300;  // 机器模式状态寄存器
    localparam CSR_MISA       = 12'h301;  // 机器模式ISA寄存器
    localparam CSR_MEDELEG    = 12'h302;  // 机器模式异常委托寄存器
    localparam CSR_MIDELEG    = 12'h303;  // 机器模式中断委托寄存器
    localparam CSR_MIE        = 12'h304;  // 机器模式中断使能寄存器
    localparam CSR_MTVEC      = 12'h305;  // 机器模式异常入口基地址寄存器
    localparam CSR_MSCRATCH   = 12'h340;  // 机器模式临时存储寄存器
    localparam CSR_MEPC       = 12'h341;  // 机器模式异常PC寄存器
    localparam CSR_MCAUSE     = 12'h342;  // 机器模式异常原因寄存器
    localparam CSR_MTVAL      = 12'h343;  // 机器模式异常值寄存器
    localparam CSR_MIP        = 12'h344;  // 机器模式中断挂起寄存器
    localparam CSR_MCYCLE     = 12'hB00;  // 机器模式周期计数器低32位
    localparam CSR_MCYCLEH    = 12'hB80;  // 机器模式周期计数器高32位

    // 异常代码定义
    localparam EXC_INSTR_ADDR_MISALIGNED = 4'd0;  // 指令地址未对齐异常
    localparam EXC_INSTR_ACCESS_FAULT    = 4'd1;  // 指令访问错误异常
    localparam EXC_ILLEGAL_INSTRUCTION   = 4'd2;  // 非法指令异常
    localparam EXC_BREAKPOINT            = 4'd3;  // 断点异常
    localparam EXC_LOAD_ADDR_MISALIGNED  = 4'd4;  // 加载地址未对齐异常
    localparam EXC_LOAD_ACCESS_FAULT     = 4'd5;  // 加载访问错误异常
    localparam EXC_STORE_ADDR_MISALIGNED = 4'd6;  // 存储地址未对齐异常
    localparam EXC_STORE_ACCESS_FAULT    = 4'd7;  // 存储访问错误异常
    localparam EXC_ECALL_FROM_UMODE      = 4'd8;  // 用户模式系统调用
    localparam EXC_ECALL_FROM_SMODE      = 4'd9;  // 监管者模式系统调用
    localparam EXC_ECALL_FROM_MMODE      = 4'd11; // 机器模式系统调用
    /* verilator lint_on UNUSEDPARAM */

    // CSR寄存器
    reg [31:0] mstatus;    // 机器模式状态寄存器
    reg [31:0] misa;       // 机器模式ISA寄存器
    reg [31:0] mtvec;      // 机器模式异常入口基地址寄存器
    reg [31:0] mscratch;   // 机器模式临时存储寄存器
    reg [31:0] mepc;       // 机器模式异常PC寄存器
    reg [31:0] mcause;     // 机器模式异常原因寄存器
    reg [31:0] mtval;      // 机器模式异常值寄存器
    reg [31:0] mcycle;     // 机器模式周期计数器低32位
    reg [31:0] mcycleh;    // 机器模式周期计数器高32位

    // 异常处理地址输出
    assign trap_vector = mtvec;

    // CSR寄存器初始化与更新
    always @(posedge clk) begin
        if (rst) begin
            // 复位CSR寄存器到初始值
            mstatus  <= 32'h0;
            misa     <= 32'h40001100;  // RV32I，支持M扩展和用户模式
            mtvec    <= 32'h0;
            mscratch <= 32'h0;
            mepc     <= 32'h0;
            mcause   <= 32'h0;
            mtval    <= 32'h0;
            mcycle   <= 32'h0;
            mcycleh  <= 32'h0;
        end
        else begin
            // 更新mcycle计数器
            {mcycleh, mcycle} <= {mcycleh, mcycle} + 1;

            // 处理异常
            if (exception) begin
                // 保存异常原因到mcause
                mcause <= {28'h0, exception_code};

                // 保存异常PC到mepc
                mepc <= exception_pc;

                // 保存异常相关值到mtval
                mtval <= exception_val;

                // 更新状态 - 这里可以根据需要扩展，如保存当前中断使能等
                // 目前简化处理
                // mstatus[12:11] MPIE = 1, mstatus[7] MIE = 0
                mstatus <= (mstatus & ~(32'h80)) | (32'h1800);
            end

            // CSR写逻辑
            if (write_en) begin
                // 根据CSR地址和操作类型更新对应寄存器
                case (write_addr)
                    CSR_MSTATUS: begin
                        case (csr_op)
                            2'b00:
                                mstatus <= write_data;                     // CSRRW
                            2'b01:
                                mstatus <= mstatus | write_data;           // CSRRS
                            2'b10:
                                mstatus <= mstatus & (~write_data);        // CSRRC
                            default:
                                mstatus <= mstatus;
                        endcase
                    end

                    CSR_MTVEC: begin
                        case (csr_op)
                            2'b00:
                                mtvec <= write_data;
                            2'b01:
                                mtvec <= mtvec | write_data;
                            2'b10:
                                mtvec <= mtvec & (~write_data);
                            default:
                                mtvec <= mtvec;
                        endcase
                    end

                    CSR_MSCRATCH: begin
                        case (csr_op)
                            2'b00:
                                mscratch <= write_data;
                            2'b01:
                                mscratch <= mscratch | write_data;
                            2'b10:
                                mscratch <= mscratch & (~write_data);
                            default:
                                mscratch <= mscratch;
                        endcase
                    end

                    CSR_MEPC: begin
                        case (csr_op)
                            2'b00:
                                mepc <= write_data;
                            2'b01:
                                mepc <= mepc | write_data;
                            2'b10:
                                mepc <= mepc & (~write_data);
                            default:
                                mepc <= mepc;
                        endcase
                    end

                    CSR_MCAUSE: begin
                        case (csr_op)
                            2'b00:
                                mcause <= write_data;
                            2'b01:
                                mcause <= mcause | write_data;
                            2'b10:
                                mcause <= mcause & (~write_data);
                            default:
                                mcause <= mcause;
                        endcase
                    end

                    CSR_MTVAL: begin
                        case (csr_op)
                            2'b00:
                                mtval <= write_data;
                            2'b01:
                                mtval <= mtval | write_data;
                            2'b10:
                                mtval <= mtval & (~write_data);
                            default:
                                mtval <= mtval;
                        endcase
                    end

                    default: begin
                        // 不可写的CSR寄存器或未实现的CSR寄存器
                    end
                endcase
            end
        end
    end

    // CSR读逻辑
    always @(*) begin
        if (read_en) begin
            case (read_addr)
                CSR_MSTATUS:
                    read_data = mstatus;
                CSR_MISA:
                    read_data = misa;
                CSR_MTVEC:
                    read_data = mtvec;
                CSR_MSCRATCH:
                    read_data = mscratch;
                CSR_MEPC:
                    read_data = mepc;
                CSR_MCAUSE:
                    read_data = mcause;
                CSR_MTVAL:
                    read_data = mtval;
                CSR_MCYCLE:
                    read_data = mcycle;
                CSR_MCYCLEH:
                    read_data = mcycleh;
                default:
                    read_data = 32'h0;  // 未实现的CSR返回0
            endcase
        end
        else begin
            read_data = 32'h0;
        end
    end

endmodule
