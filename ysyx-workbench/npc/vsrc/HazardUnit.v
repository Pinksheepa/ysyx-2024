// filepath: e:\ysyx-2024\ysyx-workbench\npc\vsrc\HazardUnit.v
// 冒险检测单元 - 用于检测流水线冒险，包括数据冒险和控制冒险
module HazardUnit (
        // ID阶段输入
        input  wire [4:0]  id_rs1,          // ID阶段指令使用的rs1寄存器地址
        input  wire [4:0]  id_rs2,          // ID阶段指令使用的rs2寄存器地址

        // EX阶段输入
        input  wire [4:0]  ex_rd,           // EX阶段指令的目标寄存器地址
        input  wire        ex_mem_read,     // EX阶段指令是否为Load类指令
        input  wire        ex_branch_taken, // EX阶段分支是否跳转
        input  wire        ex_jump,         // EX阶段是否是跳转指令

        // 控制输出
        output wire        pc_stall,        // PC暂停信号
        output wire        ifid_stall,      // IF/ID寄存器暂停信号
        output wire        idex_bubble,     // ID/EX寄存器插入气泡信号
        output wire        ifid_flush,      // IF/ID寄存器冲刷信号
        output wire        if_flush         // IF阶段冲刷信号
    );

    // Load-Use 数据冒险检测逻辑
    wire load_use_hazard = ex_mem_read && (ex_rd != 0) &&
         ((id_rs1 == ex_rd) || (id_rs2 == ex_rd));

    // 控制冒险检测逻辑 - 当EX阶段的分支指令决定跳转或执行跳转指令时
    wire control_hazard = ex_branch_taken || ex_jump;

    // 生成控制信号
    // 当检测到Load-Use冒险时：
    // 1. 暂停PC
    // 2. 暂停IF/ID寄存器
    // 3. 在ID/EX寄存器中插入气泡（清除控制信号）
    assign pc_stall    = load_use_hazard;
    assign ifid_stall  = load_use_hazard;
    assign idex_bubble = load_use_hazard;

    // 当检测到控制冒险时：
    // 1. 冲刷IF阶段
    // 2. 冲刷IF/ID寄存器
    assign ifid_flush = control_hazard;
    assign if_flush   = control_hazard;

endmodule
