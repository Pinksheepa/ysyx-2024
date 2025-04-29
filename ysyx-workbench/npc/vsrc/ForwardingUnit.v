// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\ForwardingUnit.v
// 前递单元 - 用于解决数据冒险
module ForwardingUnit (
        input  wire [4:0]  ex_rs1,          // EX阶段的rs1地址
        input  wire [4:0]  ex_rs2,          // EX阶段的rs2地址

        // MEM阶段信息
        input  wire [4:0]  mem_rd,          // MEM阶段的目标寄存器地址
        input  wire        mem_reg_wen,     // MEM阶段的寄存器写使能

        // WB阶段信息
        input  wire [4:0]  wb_rd,           // WB阶段的目标寄存器地址
        input  wire        wb_reg_wen,      // WB阶段的寄存器写使能

        // 前递控制信号
        output reg  [1:0]  forward_a,       // rs1的前递控制: 00=EX, 01=MEM, 10=WB
        output reg  [1:0]  forward_b        // rs2的前递控制: 00=EX, 01=MEM, 10=WB
    );

    // 处理rs1的前递
    always @(*) begin
        // 默认使用EX阶段原始值，不进行前递
        forward_a = 2'b00;

        // EX/MEM前递 (优先级高于MEM/WB前递)
        // 如果MEM阶段的rd不为0，且与EX阶段的rs1相等，且MEM阶段需要写回寄存器
        if (mem_reg_wen && (mem_rd != 0) && (mem_rd == ex_rs1)) begin
            forward_a = 2'b01;
        end
        // MEM/WB前递
        // 如果WB阶段的rd不为0，且与EX阶段的rs1相等，且WB阶段需要写回寄存器
        else if (wb_reg_wen && (wb_rd != 0) && (wb_rd == ex_rs1)) begin
            forward_a = 2'b10;
        end
    end

    // 处理rs2的前递
    always @(*) begin
        // 默认使用EX阶段原始值，不进行前递
        forward_b = 2'b00;

        // EX/MEM前递 (优先级高于MEM/WB前递)
        // 如果MEM阶段的rd不为0，且与EX阶段的rs2相等，且MEM阶段需要写回寄存器
        if (mem_reg_wen && (mem_rd != 0) && (mem_rd == ex_rs2)) begin
            forward_b = 2'b01;
        end
        // MEM/WB前递
        // 如果WB阶段的rd不为0，且与EX阶段的rs2相等，且WB阶段需要写回寄存器
        else if (wb_reg_wen && (wb_rd != 0) && (wb_rd == ex_rs2)) begin
            forward_b = 2'b10;
        end
    end

endmodule
