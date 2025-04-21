// 执行单元(EXU) - 负责执行指令操作，包含ALU和寄存器文件
module EXU (
        input  wire        clk,           // 时钟信号
        input  wire        rst,           // 复位信号
        output wire [31:0] rs1_data,      // 寄存器rs1值
        output wire [31:0] rs2_data,      // 寄存器rs2值
        input  wire [4:0]  rs1,           // 源寄存器1地址
        input  wire [4:0]  rs2,           // 源寄存器2地址
        input  wire [4:0]  rd,            // 目标寄存器地址
        input  wire [31:0] imm,           // 立即数
        input  wire [31:0] pc,            // 当前PC值
        input  wire        reg_wen,       // 寄存器写使能
        input  wire        mem_wen,       // 内存写使能
        input  wire        mem_ren,       // 内存读使能
        input  wire [3:0]  alu_op,        // ALU操作码
        input  wire        use_imm,       // 使用立即数标志
        input  wire        branch,        // 分支指令标志
        input  wire        jump,          // 跳转指令标志
        input  wire [2:0]  funct3,        // 函数码，用于分支判断
        input  wire [31:0] inst,          // 添加：当前指令，用于检测EBREAK
        output wire [31:0] wb_data,       // 写回数据
        output wire [31:0] alu_result,    // ALU结果
        output wire        branch_taken,  // 分支是否跳转

        // 数据内存接口
        output wire [31:0] dmem_addr,     // 数据地址
        input  wire [31:0] dmem_rdata,    // 读取的数据
        output wire [31:0] dmem_wdata,    // 写入的数据
        output wire        dmem_valid,    // 数据访问有效信号
        output wire [3:0]  dmem_wen,      // 写使能信号

        // 内存基地址
        input  wire [31:0] DMEM_BASE,     // 从顶层传入数据内存基地址

        // // 调试接口
        // output wire [31:0] reg_x1,        // x1寄存器值(ra)
        // output wire [31:0] reg_x2,        // x2寄存器值(sp)
        // output wire [31:0] reg_a0         // a0寄存器值(x10)
        // input  wire is_jal,
        input  wire is_jalr
    );

    // DPI-C函数声明 - 使用统一的函数签名
    import "DPI-C" function void npc_ebreak(input int a0_value);

    // EBREAK指令检测 - 使用RISC-V标准的EBREAK指令编码
    wire is_ebreak = (inst[6:0] == 7'b1110011) && (inst[14:12] == 3'b000) && (inst[31:20] == 12'h001);

    // 识别AUIPC指令 (U型指令，opcode为0010111)
    wire is_auipc = (inst[6:0] == 7'b0010111);

    // 声明一个线为a0_reg_value，用于连接RegisterFile的a0_value输出
    wire [31:0] a0_reg_value;

    // 在每个时钟上升沿检查是否执行了ebreak指令
    always @(posedge clk) begin
        if (!rst && is_ebreak) begin
            // 直接传递a0寄存器(x10)的值给C++函数
            npc_ebreak(a0_reg_value); // 调用C++中的函数处理ebreak
        end
    end

    // ALU输入选择
    wire [31:0] alu_src1 = rs1_data;
    wire [31:0] alu_src2 = use_imm ? imm : rs2_data;

    // 跳转目标地址计算
    wire [31:0] jal_target_addr = pc + imm; // 对于JAL指令，目标地址是 PC + 立即数
    wire [31:0] jalr_target_addr =  ((rs1_data + imm) & ~32'h1); // 对于JALR指令，目标地址是 (rs1 + imm) & ~1

    // // 判断是否为JALR指令（根据funct3和jump标志）
    // wire is_jalr = jump && (funct3 == 3'b000);

    // ALU运算逻辑
    reg [31:0] alu_result_reg;

    // ALU操作码定义
    localparam ALU_ADD  = 4'b0000;
    localparam ALU_SUB  = 4'b0001;
    localparam ALU_AND  = 4'b0010;
    localparam ALU_OR   = 4'b0011;
    localparam ALU_XOR  = 4'b0100;
    localparam ALU_SLL  = 4'b0101; // 逻辑左移
    localparam ALU_SRL  = 4'b0110; // 逻辑右移
    localparam ALU_SRA  = 4'b0111; // 算术右移
    localparam ALU_SLT  = 4'b1000; // 有符号小于
    localparam ALU_SLTU = 4'b1001; // 无符号小于

    always @(*) begin
        case (alu_op)
            ALU_ADD:
                alu_result_reg = alu_src1 + alu_src2;
            ALU_SUB:
                alu_result_reg = alu_src1 - alu_src2;
            ALU_AND:
                alu_result_reg = alu_src1 & alu_src2;
            ALU_OR:
                alu_result_reg = alu_src1 | alu_src2;
            ALU_XOR:
                alu_result_reg = alu_src1 ^ alu_src2;
            ALU_SLL:
                alu_result_reg = alu_src1 << alu_src2[4:0];
            ALU_SRL:
                alu_result_reg = alu_src1 >> alu_src2[4:0];
            ALU_SRA:
                alu_result_reg = $signed(alu_src1) >>> alu_src2[4:0];
            ALU_SLT:
                alu_result_reg = {31'b0, $signed(alu_src1) < $signed(alu_src2)};
            ALU_SLTU:
                alu_result_reg = {31'b0, alu_src1 < alu_src2};
            default:
                alu_result_reg = alu_src1 + alu_src2;
        endcase

        // 对于跳转指令，使用正确的跳转目标地址覆盖ALU结果
        if (jump) begin
            if (is_jalr) begin
                alu_result_reg = jalr_target_addr; // JALR指令使用jalr_target_addr
            end
            else begin
                alu_result_reg = jal_target_addr;  // JAL指令使用jal_target_addr
            end
        end
        
        // 添加对AUIPC指令的特殊处理
        if (is_auipc) begin
            alu_result_reg = pc + imm; // 正确地将PC值与立即数相加
        end
    end

    assign alu_result = alu_result_reg;

    // 分支条件判断
    wire beq_taken  = (alu_op == ALU_SUB) && (alu_result == 0);             // beq
    wire bne_taken  = (alu_op == ALU_SUB) && (alu_result != 0);             // bne
    wire blt_taken  = (alu_op == ALU_SLT) && (alu_result[0] == 1'b1);      // blt
    wire bge_taken  = (alu_op == ALU_SLT) && (alu_result[0] == 1'b0);      // bge
    wire bltu_taken = (alu_op == ALU_SLTU) && (alu_result[0] == 1'b1);     // bltu
    wire bgeu_taken = (alu_op == ALU_SLTU) && (alu_result[0] == 1'b0);     // bgeu

    // 分支指令控制逻辑
    reg branch_taken_reg;
    always @(*) begin
        if (branch) begin
            case (funct3) // 使用传入的funct3替代之前的inst[14:12]
                3'b000:
                    branch_taken_reg = beq_taken;  // beq
                3'b001:
                    branch_taken_reg = bne_taken;  // bne
                3'b100:
                    branch_taken_reg = blt_taken;  // blt
                3'b101:
                    branch_taken_reg = bge_taken;  // bge
                3'b110:
                    branch_taken_reg = bltu_taken; // bltu
                3'b111:
                    branch_taken_reg = bgeu_taken; // bgeu
                default:
                    branch_taken_reg = 1'b0;
            endcase
        end
        else if (jump) begin
            branch_taken_reg = 1'b1; // 跳转指令始终跳转
        end
        else begin
            branch_taken_reg = 1'b0;
        end
    end

    assign branch_taken = branch_taken_reg;

    // 访问存储器 - 智能处理地址
    // 如果地址已经在高地址空间(80000000以上)，则直接使用，否则添加DMEM_BASE
    assign dmem_addr = (mem_wen || mem_ren) ? 
                      ((alu_result >= 32'h80000000) ? alu_result : (alu_result + DMEM_BASE)) 
                      : alu_result;
    
    // 存储指令数据处理 - 根据funct3确定存储类型
    wire [1:0] addr_byte_offset = alu_result[1:0]; // 获取地址最低两位作为字节偏移
    
    // 根据不同的存储指令类型设置写使能和数据
    reg [3:0] store_mask;
    reg [31:0] store_data;
    
    always @(*) begin
        if (mem_wen) begin
            case (funct3)
                3'b000: begin // sb - 存储字节
                    case (addr_byte_offset)
                        2'b00: store_mask = 4'b0001;
                        2'b01: store_mask = 4'b0010;
                        2'b10: store_mask = 4'b0100;
                        2'b11: store_mask = 4'b1000;
                    endcase
                    // 将rs2_data的低8位放到相应位置
                    case (addr_byte_offset)
                        2'b00: store_data = {24'b0, rs2_data[7:0]};
                        2'b01: store_data = {16'b0, rs2_data[7:0], 8'b0};
                        2'b10: store_data = {8'b0, rs2_data[7:0], 16'b0};
                        2'b11: store_data = {rs2_data[7:0], 24'b0};
                    endcase
                end
                
                3'b001: begin // sh - 存储半字
                    case (addr_byte_offset[1])
                        1'b0: store_mask = 4'b0011;
                        1'b1: store_mask = 4'b1100;
                    endcase
                    // 将rs2_data的低16位放到相应位置
                    case (addr_byte_offset[1])
                        1'b0: store_data = {16'b0, rs2_data[15:0]};
                        1'b1: store_data = {rs2_data[15:0], 16'b0};
                    endcase
                end
                
                3'b010: begin // sw - 存储字
                    store_mask = 4'b1111; 
                    store_data = rs2_data;
                end
                
                default: begin
                    store_mask = 4'b0000; // 默认不写入
                    store_data = 32'b0;
                end
            endcase
        end
        else begin
            store_mask = 4'b0000; // 不是存储指令时不写入
            store_data = 32'b0;
        end
    end
    
    // 设置dmem_wen和dmem_wdata
    assign dmem_wen = store_mask;
    assign dmem_wdata = store_data;
    
    // dmem_valid保持不变
    assign dmem_valid = mem_wen || mem_ren;

    // 读取指令数据处理，根据funct3确定加载类型
    reg [31:0] load_data;
    
    always @(*) begin
        if (mem_ren) begin
            case (funct3)
                3'b000: begin // lb - 加载字节（符号扩展）
                    case (addr_byte_offset)
                        2'b00: load_data = {{24{dmem_rdata[7]}}, dmem_rdata[7:0]};
                        2'b01: load_data = {{24{dmem_rdata[15]}}, dmem_rdata[15:8]};
                        2'b10: load_data = {{24{dmem_rdata[23]}}, dmem_rdata[23:16]};
                        2'b11: load_data = {{24{dmem_rdata[31]}}, dmem_rdata[31:24]};
                    endcase
                end
                
                3'b001: begin // lh - 加载半字（符号扩展）
                    case (addr_byte_offset[1])
                        1'b0: load_data = {{16{dmem_rdata[15]}}, dmem_rdata[15:0]};
                        1'b1: load_data = {{16{dmem_rdata[31]}}, dmem_rdata[31:16]};
                    endcase
                end
                
                3'b010: begin // lw - 加载字
                    load_data = dmem_rdata;
                end
                
                3'b100: begin // lbu - 加载字节（零扩展）
                    case (addr_byte_offset)
                        2'b00: load_data = {24'b0, dmem_rdata[7:0]};
                        2'b01: load_data = {24'b0, dmem_rdata[15:8]};
                        2'b10: load_data = {24'b0, dmem_rdata[23:16]};
                        2'b11: load_data = {24'b0, dmem_rdata[31:24]};
                    endcase
                end
                
                3'b101: begin // lhu - 加载半字（零扩展）
                    case (addr_byte_offset[1])
                        1'b0: load_data = {16'b0, dmem_rdata[15:0]};
                        1'b1: load_data = {16'b0, dmem_rdata[31:16]};
                    endcase
                end
                
                default: load_data = dmem_rdata; // 默认加载整个字
            endcase
        end
        else begin
            load_data = dmem_rdata;
        end
    end

    // 写回数据选择
    wire [31:0] mem_read_data = load_data;
    wire [31:0] jump_target_pc = pc + 4; // 为JAL/JALR准备的返回地址

    reg [31:0] wb_data_reg;
    always @(*) begin
        if (mem_ren) begin
            wb_data_reg = mem_read_data; // 加载指令，写回从内存读取的数据
        end
        else if (jump) begin
            wb_data_reg = jump_target_pc; // JAL/JALR指令，写回PC+4
        end
        else begin
            wb_data_reg = alu_result; // 其他指令写回ALU结果
        end
    end

    assign wb_data = wb_data_reg;

    // 寄存器文件实例化
    RegisterFile regfile (
        .clk      (clk),
        .rst      (rst),
        .rs1      (rs1),
        .rs2      (rs2),
        .rd       (rd),
        .we       (reg_wen),
        .wdata    (wb_data),
        .rs1_data (rs1_data),
        .rs2_data (rs2_data),
        .a0_value (a0_reg_value) // 连接a0_value输出
        //  .reg_x1   (reg_x1),
        //  .reg_x2   (reg_x2),
        //  .reg_a0   (reg_a0)
    );

endmodule
