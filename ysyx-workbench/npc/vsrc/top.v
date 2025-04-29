// 处理器顶层模块 - 五级流水线结构
module top (
        input wire clk,            // 时钟信号
        input wire rst,            // 复位信号

        // 指令内存接口
        output wire [31:0] imem_addr,    // 指令地址
        input  wire [31:0] imem_rdata,   // 读取的指令数据
        output wire        imem_valid,   // 指令访问有效信号

        // 数据内存接口
        output wire [31:0] dmem_addr,    // 数据地址
        input  wire [31:0] dmem_rdata,   // 读取的数据
        output wire [31:0] dmem_wdata,   // 写入的数据
        output wire        dmem_valid,   // 数据访问有效信号
        output wire [3:0]  dmem_wen      // 写使能信号，按字节控制
    );

    /* verilator lint_off UNUSEDPARAM */
    // 内存基地址常量定义
    parameter DMEM_BASE = 32'h8010_0000;  // 数据内存基地址
    /* verilator lint_on UNUSEDPARAM */

    // ECALL/EBREAK指令检测信号 - 在WB阶段检测
    wire is_ecall;
    wire is_ebreak;
    wire [31:0] a0_value;
    wire dpi_terminate;
    wire wb_valid;  // WB阶段有效信号

    // 控制信号
    wire        stall_if;     // IF阶段暂停信号
    wire        stall_id;     // ID阶段暂停信号
    wire        stall_ex;     // EX阶段暂停信号
    wire        stall_mem;    // MEM阶段暂停信号
    wire        stall_wb;     // WB阶段暂停信号

    wire        flush_if;     // IF阶段冲刷信号
    wire        flush_id;     // ID阶段冲刷信号
    wire        flush_ex;     // EX阶段冲刷信号
    wire        flush_mem;    // MEM阶段冲刷信号

    // 冒险检测单元信号
    wire        pc_stall;     // PC暂停信号
    wire        ifid_stall;   // IF/ID寄存器暂停信号
    wire        idex_bubble;  // ID/EX寄存器插入气泡信号
    wire        ifid_flush;   // IF/ID寄存器冲刷信号
    wire        if_flush;     // IF阶段冲刷信号

    // 异常处理相关信号
    wire        exception_valid;      // 异常有效信号
    wire [3:0]  exception_code;       // 异常代码
    wire [31:0] exception_pc;         // 异常PC值
    wire [31:0] exception_val;        // 异常相关值
    wire        exception_redirect;   // PC异常重定向信号
    wire [31:0] exception_target;     // 异常目标地址
    wire        pipeline_flush_exc;   // 异常导致的流水线冲刷
    wire [31:0] trap_vector;          // 异常处理入口地址

    // 更新暂停和冲刷信号
    assign stall_if  = pc_stall;     // 由冒险检测单元控制
    assign stall_id  = ifid_stall;   // 由冒险检测单元控制
    assign stall_ex  = 1'b0;
    assign stall_mem = 1'b0;
    assign stall_wb  = 1'b0;

    // 更新冲刷信号，处理控制冒险
    assign flush_if  = if_flush || pipeline_flush_exc;     // 由冒险检测单元控制
    assign flush_id  = ifid_flush || pipeline_flush_exc;   // 由冒险检测单元控制
    assign flush_ex  = idex_bubble || pipeline_flush_exc;  // 冒险检测单元插入气泡
    assign flush_mem = pipeline_flush_exc;

    // ---------------------- 异常处理单元 ----------------------
    ExceptionHandler exception_handler (
                         .clk               (clk),
                         .rst               (rst),
                         // 异常输入
                         .id_illegal_instr  (id_illegal_instr),
                         .id_instr          (id_instr),
                         .id_pc             (id_pc),
                         // 流水线状态
                         .wb_valid          (1'b1),  // 简化处理，假设WB阶段总是有效
                         .wb_pc             (wb_pc),
                         .wb_instr          (wb_instr),
                         // 异常输出
                         .exception_valid   (exception_valid),
                         .exception_code    (exception_code),
                         .exception_pc      (exception_pc),
                         .exception_val     (exception_val),
                         .pipeline_flush    (pipeline_flush_exc),
                         // 异常跳转
                         .trap_vector       (trap_vector),
                         .redirect_pc       (exception_redirect),
                         .new_pc            (exception_target)
                     );

    // ---------------------- DPI系统接口 ----------------------
    // 从WB阶段指令中检测ECALL和EBREAK指令
    assign is_ecall = (wb_instr[6:0] == 7'b1110011) && (wb_instr[14:12] == 3'b000) && (wb_instr[31:20] == 12'h000);
    assign is_ebreak = (wb_instr[6:0] == 7'b1110011) && (wb_instr[14:12] == 3'b000) && (wb_instr[31:20] == 12'h001);

    // 获取a0寄存器的值（用于系统调用参数）- 使用直接引用
    assign a0_value = regfile.registers[10]; // x10 是 a0寄存器

    // WB阶段有效信号 - 简单实现，可根据需要扩展
    assign wb_valid = wb_reg_wen || wb_mem_ren || is_ecall || is_ebreak;

    // DPI_System实例化，使用WB阶段信号
    DPI_System dpi_system (
                   .clk        (clk),
                   .rst        (rst),
                   .is_ecall   (is_ecall),
                   .is_ebreak  (is_ebreak),
                   .a0_value   (a0_value),
                   .valid      (wb_valid),    // 只有WB阶段有效时才处理
                   .terminate  (dpi_terminate)
               );

    // ---------------------- IF 阶段 ----------------------
    wire [31:0] pc;           // 当前PC值
    wire [31:0] pc_plus4;     // PC+4
    wire [31:0] if_pc;        // IF阶段PC
    wire [31:0] if_instr;     // IF阶段指令

    // PC寄存器实例化
    PC_Reg pc_reg (
               .clk               (clk),
               .rst               (rst),
               .stall             (stall_if),
               .branch_taken      (ex_branch_taken),
               .branch_target     (ex_branch_target),
               .pc_plus4          (pc_plus4),
               // 异常处理接口
               .exception_redirect (exception_redirect),
               .exception_target   (exception_target),
               .pc                (pc)
           );

    // 指令取指模块实例化
    IFU ifu (
            .clk           (clk),
            .rst           (rst),
            .stall         (stall_if),
            .branch_taken  (ex_branch_taken),
            .branch_target (ex_branch_target),
            .pc            (pc),
            .pc_plus4      (pc_plus4),
            .if_pc         (if_pc),
            .imem_addr     (imem_addr),
            .imem_rdata    (imem_rdata),
            .imem_valid    (imem_valid),
            .if_instr      (if_instr)
        );

    // ---------------------- IF/ID 流水线寄存器 ----------------------
    wire [31:0] id_pc;        // ID阶段PC
    wire [31:0] id_instr;     // ID阶段指令

    PipeRegIFID pipe_reg_if_id (
                    .clk           (clk),
                    .rst           (rst),
                    .stall         (stall_id),
                    .flush         (flush_id),
                    .if_pc         (if_pc),
                    .if_instr      (if_instr),
                    .id_pc         (id_pc),
                    .id_instr      (id_instr)
                );

    // ---------------------- ID 阶段 ----------------------
    wire [4:0]  id_rs1;       // 源寄存器1地址
    wire [4:0]  id_rs2;       // 源寄存器2地址
    wire [4:0]  id_rd;        // 目标寄存器地址
    wire [31:0] id_rs1_data;  // 源寄存器1数据
    wire [31:0] id_rs2_data;  // 源寄存器2数据
    wire [31:0] id_imm;       // 立即数
    wire        id_reg_wen;   // 寄存器写使能
    wire        id_mem_wen;   // 内存写使能
    wire        id_mem_ren;   // 内存读使能
    wire [3:0]  id_alu_op;    // ALU操作码
    wire        id_use_imm;   // 使用立即数标志
    wire        id_branch;    // 分支指令标志
    wire        id_jump;      // 跳转指令标志
    wire        id_is_jalr;   // JALR指令标志

    // 扩展控制信号
    wire [2:0]  id_mem_type;     // 内存访问类型
    wire        id_mem_unsigned; // 无符号内存访问
    wire [1:0]  id_wb_sel;       // 写回选择
    wire        id_csr_ren;      // CSR读使能
    wire        id_csr_wen;      // CSR写使能
    wire [11:0] id_csr_addr;     // CSR地址
    wire        id_illegal_instr; // 非法指令
    wire [1:0]  id_csr_op;       // CSR操作类型
    wire        id_csr_imm;      // CSR立即数操作

    // WB阶段写回数据 - 由WBU提供
    wire [31:0] wb_data;      // 写回数据
    wire [4:0]  wb_rd_final;  // WB阶段的目标寄存器地址
    wire        wb_reg_wen_final; // WB阶段的寄存器写使能

    // 寄存器堆实例化
    RegisterFile regfile (
                     .clk           (clk),
                     .rst           (rst),
                     .rs1           (id_rs1),
                     .rs2           (id_rs2),
                     .rd            (wb_rd_final),
                     .we            (wb_reg_wen_final),
                     .wdata         (wb_data),
                     .rs1_data      (id_rs1_data),
                     .rs2_data      (id_rs2_data),
                     .a0_value      () // 暂时不使用
                 );

    // 指令译码单元实例化
    IDU idu (
            .clk           (clk),
            .rst           (rst),
            .id_pc         (id_pc),
            .id_instr      (id_instr),
            .rs1_data      (id_rs1_data),
            .rs2_data      (id_rs2_data),
            .rs1           (id_rs1),
            .rs2           (id_rs2),
            .rd            (id_rd),
            .imm           (id_imm),
            .reg_wen       (id_reg_wen),
            .mem_wen       (id_mem_wen),
            .mem_ren       (id_mem_ren),
            .alu_op        (id_alu_op),
            .use_imm       (id_use_imm),
            .branch        (id_branch),
            .jump          (id_jump),
            .is_jalr       (id_is_jalr),

            // 控制信号连接
            .mem_type      (id_mem_type),
            .mem_unsigned  (id_mem_unsigned),
            .wb_sel        (id_wb_sel),
            .csr_ren       (id_csr_ren),
            .csr_wen       (id_csr_wen),
            .csr_addr      (id_csr_addr),
            .csr_op        (id_csr_op),
            .csr_imm       (id_csr_imm),
            .illegal_instr (id_illegal_instr)
        );

    // 冒险检测单元实例化
    HazardUnit hazard_unit (
                   .id_rs1         (id_rs1),
                   .id_rs2         (id_rs2),
                   .ex_rd          (ex_rd),
                   .ex_mem_read    (ex_mem_ren),    // EX阶段内存读使能作为Load指令标志
                   .ex_branch_taken(ex_branch_taken), // 分支是否被采纳
                   .ex_jump        (ex_jump),       // 是否为跳转指令
                   .pc_stall       (pc_stall),
                   .ifid_stall     (ifid_stall),
                   .idex_bubble    (idex_bubble),
                   .ifid_flush     (ifid_flush),    // IF/ID寄存器冲刷信号
                   .if_flush       (if_flush)       // IF阶段冲刷信号
               );

    // ---------------------- ID/EX 流水线寄存器 ----------------------
    wire [31:0] ex_pc;        // EX阶段PC
    wire [31:0] ex_instr;     // EX阶段指令
    wire [31:0] ex_rs1_data;  // 源寄存器1数据
    wire [31:0] ex_rs2_data;  // 源寄存器2数据
    wire [4:0]  ex_rs1;       // 源寄存器1地址
    wire [4:0]  ex_rs2;       // 源寄存器2地址
    wire [4:0]  ex_rd;        // 目标寄存器地址
    wire [31:0] ex_imm;       // 立即数
    wire        ex_reg_wen;   // 寄存器写使能
    wire        ex_mem_wen;   // 内存写使能
    wire        ex_mem_ren;   // 内存读使能
    wire [3:0]  ex_alu_op;    // ALU操作码
    wire        ex_use_imm;   // 使用立即数标志
    wire        ex_branch;    // 分支指令标志
    wire        ex_jump;      // 跳转指令标志
    wire        ex_is_jalr;   // JALR指令标志

    // 扩展控制信号
    wire [2:0]  ex_mem_type;     // 内存访问类型
    wire        ex_mem_unsigned; // 无符号内存访问
    wire [1:0]  ex_wb_sel;       // 写回选择
    wire        ex_csr_ren;      // CSR读使能
    wire        ex_csr_wen;      // CSR写使能
    wire [11:0] ex_csr_addr;     // CSR地址
    wire        ex_illegal_instr; // 非法指令
    wire        ex_csr_imm;      // CSR立即数操作
    wire [1:0]  ex_csr_op;       // CSR操作类型

    PipeRegIDEX pipe_reg_id_ex (
                    .clk           (clk),
                    .rst           (rst),
                    .stall         (stall_ex),
                    .flush         (flush_ex),
                    .bubble        (idex_bubble),  // 连接气泡插入信号
                    .id_pc         (id_pc),
                    .id_instr      (id_instr),
                    .id_rs1_data   (id_rs1_data),
                    .id_rs2_data   (id_rs2_data),
                    .id_rs1        (id_rs1),
                    .id_rs2        (id_rs2),
                    .id_rd         (id_rd),
                    .id_imm        (id_imm),
                    .id_reg_wen    (id_reg_wen),
                    .id_mem_wen    (id_mem_wen),
                    .id_mem_ren    (id_mem_ren),
                    .id_alu_op     (id_alu_op),
                    .id_use_imm    (id_use_imm),
                    .id_branch     (id_branch),
                    .id_jump       (id_jump),
                    .id_is_jalr    (id_is_jalr),

                    // 扩展控制信号连接
                    .id_mem_type      (id_mem_type),
                    .id_mem_unsigned  (id_mem_unsigned),
                    .id_wb_sel        (id_wb_sel),
                    .id_csr_ren       (id_csr_ren),
                    .id_csr_wen       (id_csr_wen),
                    .id_csr_addr      (id_csr_addr),
                    .id_csr_op        (id_csr_op),
                    .id_csr_imm       (id_csr_imm),
                    .id_illegal_instr (id_illegal_instr),

                    .ex_pc         (ex_pc),
                    .ex_instr      (ex_instr),
                    .ex_rs1_data   (ex_rs1_data),
                    .ex_rs2_data   (ex_rs2_data),
                    .ex_rs1        (ex_rs1),
                    .ex_rs2        (ex_rs2),
                    .ex_rd         (ex_rd),
                    .ex_imm        (ex_imm),
                    .ex_reg_wen    (ex_reg_wen),
                    .ex_mem_wen    (ex_mem_wen),
                    .ex_mem_ren    (ex_mem_ren),
                    .ex_alu_op     (ex_alu_op),
                    .ex_use_imm    (ex_use_imm),
                    .ex_branch     (ex_branch),
                    .ex_jump       (ex_jump),
                    .ex_is_jalr    (ex_is_jalr),

                    // 扩展控制信号连接
                    .ex_mem_type      (ex_mem_type),
                    .ex_mem_unsigned  (ex_mem_unsigned),
                    .ex_wb_sel        (ex_wb_sel),
                    .ex_csr_ren       (ex_csr_ren),
                    .ex_csr_wen       (ex_csr_wen),
                    .ex_csr_addr      (ex_csr_addr),
                    .ex_csr_op        (ex_csr_op),
                    .ex_csr_imm       (ex_csr_imm),
                    .ex_illegal_instr (ex_illegal_instr)
                );

    // ---------------------- EX 阶段 ----------------------
    // 前递控制信号
    wire [1:0] forward_a;      // RS1前递控制
    wire [1:0] forward_b;      // RS2前递控制

    // 执行单元的输出
    wire [31:0] ex_alu_result; // ALU计算结果
    wire        ex_branch_taken; // 分支是否跳转
    wire [31:0] ex_store_data; // 存储数据
    wire [31:0] ex_branch_target; // 分支/跳转目标地址
    wire [2:0]  ex_funct3;     // 指令的funct3字段
    wire [31:0] ex_csr_write_data; // CSR写数据

    // 从指令中提取funct3
    assign ex_funct3 = ex_instr[14:12];

    // 前递单元实例化
    ForwardingUnit forwarding_unit (
                       .ex_rs1       (ex_rs1),
                       .ex_rs2       (ex_rs2),
                       .mem_rd       (mem_rd),
                       .mem_reg_wen  (mem_reg_wen),
                       .wb_rd        (wb_rd),
                       .wb_reg_wen   (wb_reg_wen),
                       .forward_a    (forward_a),
                       .forward_b    (forward_b)
                   );

    // 执行单元实例化
    EXU exu (
            .clk          (clk),
            .rst          (rst),
            .ex_pc        (ex_pc),
            .ex_instr     (ex_instr),
            .ex_rs1_data  (ex_rs1_data),
            .ex_rs2_data  (ex_rs2_data),
            .ex_rs1       (ex_rs1),
            .ex_rs2       (ex_rs2),
            .ex_rd        (ex_rd),
            .ex_imm       (ex_imm),
            .ex_alu_op    (ex_alu_op),
            .ex_use_imm   (ex_use_imm),
            .ex_branch    (ex_branch),
            .ex_jump      (ex_jump),
            .ex_is_jalr   (ex_is_jalr),
            .ex_reg_wen   (ex_reg_wen),
            .ex_mem_wen   (ex_mem_wen),
            .ex_mem_ren   (ex_mem_ren),

            // 扩展控制信号
            .ex_mem_type    (ex_mem_type),
            .ex_mem_unsigned(ex_mem_unsigned),
            .ex_wb_sel      (ex_wb_sel),

            // CSR相关信号
            .ex_csr_ren   (ex_csr_ren),
            .ex_csr_wen   (ex_csr_wen),
            .ex_csr_addr  (ex_csr_addr),
            .ex_csr_op    (ex_csr_op),
            .ex_csr_imm   (ex_csr_imm),

            // 前递相关信号
            .forward_a    (forward_a),
            .forward_b    (forward_b),
            .mem_alu_result(mem_alu_result),
            .wb_data      (wb_data),

            // 输出
            .alu_result   (ex_alu_result),
            .branch_taken (ex_branch_taken),
            .store_data   (ex_store_data),
            .branch_target(ex_branch_target),
            .csr_write_data (ex_csr_write_data)
        );

    // ---------------------- EX/MEM 流水线寄存器 ----------------------
    wire [31:0] mem_pc;        // MEM阶段PC
    wire [31:0] mem_instr;     // MEM阶段指令
    wire [31:0] mem_alu_result; // ALU计算结果
    wire [31:0] mem_rs2_data;  // 源寄存器2数据(用于存储)
    wire [4:0]  mem_rs1;       // 源寄存器1地址
    wire [4:0]  mem_rs2;       // 源寄存器2地址
    wire [4:0]  mem_rd;        // 目标寄存器地址
    wire        mem_reg_wen;   // 寄存器写使能
    wire        mem_mem_wen;   // 内存写使能
    wire        mem_mem_ren;   // 内存读使能
    wire        mem_branch_taken; // 分支是否跳转
    wire [2:0]  mem_funct3;    // 用于内存访问类型决定

    // 扩展控制信号
    wire [2:0]  mem_mem_type;     // 内存访问类型
    wire        mem_mem_unsigned; // 无符号内存访问
    wire [1:0]  mem_wb_sel;       // 写回选择
    wire        mem_csr_ren;      // CSR读使能
    wire        mem_csr_wen;      // CSR写使能
    wire [11:0] mem_csr_addr;     // CSR地址
    wire [1:0]  mem_csr_op;       // CSR操作类型
    wire        mem_csr_imm;      // CSR立即数操作
    wire [31:0] mem_csr_write_data; // CSR写数据

    PipeRegEXMEM pipe_reg_ex_mem (
                     .clk             (clk),
                     .rst             (rst),
                     .stall           (stall_mem),
                     .flush           (flush_mem),
                     .ex_pc           (ex_pc),
                     .ex_instr        (ex_instr),
                     .ex_alu_result   (ex_alu_result),
                     .ex_rs2_data     (ex_store_data), // 使用前递后的rs2数据
                     .ex_rs1          (ex_rs1),
                     .ex_rs2          (ex_rs2),
                     .ex_rd           (ex_rd),
                     .ex_reg_wen      (ex_reg_wen),
                     .ex_mem_wen      (ex_mem_wen),
                     .ex_mem_ren      (ex_mem_ren),
                     .ex_branch_taken (ex_branch_taken),
                     .ex_funct3       (ex_funct3),

                     // 扩展控制信号
                     .ex_mem_type     (ex_mem_type),
                     .ex_mem_unsigned (ex_mem_unsigned),
                     .ex_wb_sel       (ex_wb_sel),
                     .ex_csr_ren      (ex_csr_ren),
                     .ex_csr_wen      (ex_csr_wen),
                     .ex_csr_addr     (ex_csr_addr),
                     .ex_csr_op       (ex_csr_op),
                     .ex_csr_imm      (ex_csr_imm),
                     .ex_csr_write_data (ex_csr_write_data),

                     .mem_pc          (mem_pc),
                     .mem_instr       (mem_instr),
                     .mem_alu_result  (mem_alu_result),
                     .mem_rs2_data    (mem_rs2_data),
                     .mem_rs1         (mem_rs1),
                     .mem_rs2         (mem_rs2),
                     .mem_rd          (mem_rd),
                     .mem_reg_wen     (mem_reg_wen),
                     .mem_mem_wen     (mem_mem_wen),
                     .mem_mem_ren     (mem_mem_ren),
                     .mem_branch_taken(mem_branch_taken),
                     .mem_funct3      (mem_funct3),

                     // 扩展控制信号
                     .mem_mem_type    (mem_mem_type),
                     .mem_mem_unsigned(mem_mem_unsigned),
                     .mem_wb_sel      (mem_wb_sel),
                     .mem_csr_ren     (mem_csr_ren),
                     .mem_csr_wen     (mem_csr_wen),
                     .mem_csr_addr    (mem_csr_addr),
                     .mem_csr_op      (mem_csr_op),
                     .mem_csr_imm     (mem_csr_imm),
                     .mem_csr_write_data (mem_csr_write_data)
                 );

    // ---------------------- MEM 阶段 ----------------------
    wire [31:0] mem_read_data;  // 处理后的内存读取数据
    wire [31:0] mem_write_data; // 要写回的数据

    // CSR相关
    wire [31:0] mem_csr_rdata;  // CSR读取数据

    // CSR寄存器文件实例化
    CSRFile csr_file (
                .clk           (clk),
                .rst           (rst),
                .read_addr     (mem_csr_addr),
                .read_en       (mem_csr_ren),
                .write_addr    (mem_csr_addr),
                .write_data    (mem_csr_write_data),
                .write_en      (mem_csr_wen),
                .csr_op        (mem_csr_op),
                .read_data     (mem_csr_rdata),
                // 异常处理接口
                .exception     (exception_valid),
                .exception_code(exception_code),
                .exception_pc  (exception_pc),
                .exception_val (exception_val),
                .trap_vector   (trap_vector)
            );

    // 内存访问单元实例化
    MEMU memu (
             .clk           (clk),
             .rst           (rst),
             .mem_pc        (mem_pc),
             .mem_instr     (mem_instr),
             .mem_alu_result(mem_alu_result),
             .mem_rs2_data  (mem_rs2_data),
             .mem_rd        (mem_rd),
             .mem_reg_wen   (mem_reg_wen),
             .mem_mem_wen   (mem_mem_wen),
             .mem_mem_ren   (mem_mem_ren),

             // 扩展控制信号
             .mem_mem_type    (mem_mem_type),
             .mem_mem_unsigned(mem_mem_unsigned),
             .mem_wb_sel      (mem_wb_sel),
             .mem_csr_rdata   (mem_csr_rdata),

             // 数据内存接口
             .dmem_rdata    (dmem_rdata),
             .dmem_addr     (dmem_addr),
             .dmem_wdata    (dmem_wdata),
             .dmem_wen      (dmem_wen),
             .dmem_valid    (dmem_valid),

             // 处理后的数据
             .mem_read_data (mem_read_data),
             .wb_data       (mem_write_data)
         );

    // ---------------------- MEM/WB 流水线寄存器 ----------------------
    wire [31:0] wb_pc;         // WB阶段PC
    wire [31:0] wb_instr;      // WB阶段指令
    wire [31:0] wb_alu_result; // ALU计算结果
    wire [31:0] wb_mem_rdata;  // 从内存读取的数据
    wire [4:0]  wb_rd;         // 目标寄存器地址
    wire        wb_reg_wen;    // 寄存器写使能
    wire        wb_mem_ren;    // 内存读使能

    // 扩展控制信号
    wire [1:0]  wb_wb_sel;     // 写回数据选择
    wire        wb_mem_unsigned; // 内存无符号访问
    wire [31:0] wb_csr_rdata;  // CSR读取数据
    wire        wb_csr_ren;    // CSR读使能
    wire        wb_csr_wen;    // CSR写使能 - 明确定义，解决隐式创建问题
    wire [11:0] wb_csr_addr;   // CSR地址 - 明确定义，解决隐式创建问题
    wire [1:0]  wb_csr_op;     // CSR操作类型
    wire        wb_csr_imm;    // CSR立即数操作
    wire [31:0] wb_csr_write_data; // CSR写数据

    PipeRegMEMWB pipe_reg_mem_wb (
                     .clk           (clk),
                     .rst           (rst),
                     .stall         (stall_wb),
                     .flush         (1'b0), // WB阶段不需要冲刷
                     .mem_pc        (mem_pc),
                     .mem_instr     (mem_instr),
                     .mem_alu_result(mem_alu_result),
                     .mem_mem_rdata (mem_read_data),
                     .mem_rd        (mem_rd),
                     .mem_reg_wen   (mem_reg_wen),
                     .mem_mem_ren   (mem_mem_ren),

                     // 扩展控制信号
                     .mem_wb_sel    (mem_wb_sel),
                     .mem_mem_unsigned(mem_mem_unsigned),
                     .mem_csr_rdata (mem_csr_rdata),
                     .mem_csr_ren   (mem_csr_ren),
                     .mem_csr_wen   (mem_csr_wen),
                     .mem_csr_addr  (mem_csr_addr),
                     .mem_csr_op    (mem_csr_op),
                     .mem_csr_imm   (mem_csr_imm),
                     .mem_csr_write_data (mem_csr_write_data),

                     .wb_pc         (wb_pc),
                     .wb_instr      (wb_instr),
                     .wb_alu_result (wb_alu_result),
                     .wb_mem_rdata  (wb_mem_rdata),
                     .wb_rd         (wb_rd),
                     .wb_reg_wen    (wb_reg_wen),
                     .wb_mem_ren    (wb_mem_ren),

                     // 扩展控制信号
                     .wb_wb_sel     (wb_wb_sel),
                     .wb_mem_unsigned(wb_mem_unsigned),
                     .wb_csr_rdata  (wb_csr_rdata),
                     .wb_csr_ren    (wb_csr_ren),
                     .wb_csr_wen    (wb_csr_wen),
                     .wb_csr_addr   (wb_csr_addr),
                     .wb_csr_op     (wb_csr_op),
                     .wb_csr_imm    (wb_csr_imm),
                     .wb_csr_write_data (wb_csr_write_data)
                 );

    // ---------------------- WB 阶段 ----------------------
    // 写回单元实例化
    WBU wbu (
            .clk           (clk),
            .rst           (rst),
            .wb_pc         (wb_pc),
            .wb_instr      (wb_instr),
            .wb_alu_result (wb_alu_result),
            .wb_mem_rdata  (wb_mem_rdata),
            .wb_rd         (wb_rd),
            .wb_reg_wen    (wb_reg_wen),

            // 扩展控制信号
            .wb_wb_sel     (wb_wb_sel),
            .wb_mem_unsigned(wb_mem_unsigned),
            .wb_csr_rdata  (wb_csr_rdata),

            // 写回数据输出
            .wb_data       (wb_data),
            .wb_rd_out     (wb_rd_final),
            .wb_reg_wen_out(wb_reg_wen_final)
        );

endmodule
