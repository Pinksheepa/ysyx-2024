// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+63,"imem_addr", false,-1, 31,0);
    tracep->declBus(c+64,"imem_rdata", false,-1, 31,0);
    tracep->declBit(c+65,"imem_valid", false,-1);
    tracep->declBus(c+66,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+67,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+68,"dmem_wdata", false,-1, 31,0);
    tracep->declBit(c+69,"dmem_valid", false,-1);
    tracep->declBus(c+70,"dmem_wen", false,-1, 3,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+63,"imem_addr", false,-1, 31,0);
    tracep->declBus(c+64,"imem_rdata", false,-1, 31,0);
    tracep->declBit(c+65,"imem_valid", false,-1);
    tracep->declBus(c+66,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+67,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+68,"dmem_wdata", false,-1, 31,0);
    tracep->declBit(c+69,"dmem_valid", false,-1);
    tracep->declBus(c+70,"dmem_wen", false,-1, 3,0);
    tracep->declBus(c+93,"DMEM_BASE", false,-1, 31,0);
    tracep->declBus(c+25,"pc", false,-1, 31,0);
    tracep->declBus(c+7,"next_pc", false,-1, 31,0);
    tracep->declBit(c+94,"pc_wen", false,-1);
    tracep->declBus(c+64,"inst", false,-1, 31,0);
    tracep->declBus(c+71,"funct3", false,-1, 2,0);
    tracep->declBit(c+72,"reg_wen", false,-1);
    tracep->declBit(c+73,"mem_wen", false,-1);
    tracep->declBit(c+74,"mem_ren", false,-1);
    tracep->declBus(c+1,"alu_op", false,-1, 3,0);
    tracep->declBit(c+75,"use_imm", false,-1);
    tracep->declBit(c+76,"branch", false,-1);
    tracep->declBit(c+2,"jump", false,-1);
    tracep->declBus(c+77,"rs1", false,-1, 4,0);
    tracep->declBus(c+78,"rs2", false,-1, 4,0);
    tracep->declBus(c+79,"rd", false,-1, 4,0);
    tracep->declBus(c+8,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+9,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+3,"imm", false,-1, 31,0);
    tracep->declBus(c+95,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+96,"alu_src2", false,-1, 31,0);
    tracep->declBus(c+10,"alu_result", false,-1, 31,0);
    tracep->declBus(c+80,"wb_data", false,-1, 31,0);
    tracep->declBit(c+11,"branch_taken", false,-1);
    tracep->declBit(c+4,"is_jalr", false,-1);
    tracep->declBus(c+97,"reg_x1", false,-1, 31,0);
    tracep->declBus(c+98,"reg_x2", false,-1, 31,0);
    tracep->declBus(c+99,"reg_a0", false,-1, 31,0);
    tracep->pushNamePrefix("exu ");
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+8,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+9,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+77,"rs1", false,-1, 4,0);
    tracep->declBus(c+78,"rs2", false,-1, 4,0);
    tracep->declBus(c+79,"rd", false,-1, 4,0);
    tracep->declBus(c+3,"imm", false,-1, 31,0);
    tracep->declBus(c+25,"pc", false,-1, 31,0);
    tracep->declBit(c+72,"reg_wen", false,-1);
    tracep->declBit(c+73,"mem_wen", false,-1);
    tracep->declBit(c+74,"mem_ren", false,-1);
    tracep->declBus(c+1,"alu_op", false,-1, 3,0);
    tracep->declBit(c+75,"use_imm", false,-1);
    tracep->declBit(c+76,"branch", false,-1);
    tracep->declBit(c+2,"jump", false,-1);
    tracep->declBus(c+71,"funct3", false,-1, 2,0);
    tracep->declBus(c+64,"inst", false,-1, 31,0);
    tracep->declBus(c+80,"wb_data", false,-1, 31,0);
    tracep->declBus(c+10,"alu_result", false,-1, 31,0);
    tracep->declBit(c+11,"branch_taken", false,-1);
    tracep->declBus(c+66,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+67,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+68,"dmem_wdata", false,-1, 31,0);
    tracep->declBit(c+69,"dmem_valid", false,-1);
    tracep->declBus(c+70,"dmem_wen", false,-1, 3,0);
    tracep->declBus(c+93,"DMEM_BASE", false,-1, 31,0);
    tracep->declBit(c+4,"is_jalr", false,-1);
    tracep->declBit(c+81,"is_ebreak", false,-1);
    tracep->declBit(c+82,"is_auipc", false,-1);
    tracep->declBus(c+26,"a0_reg_value", false,-1, 31,0);
    tracep->declBus(c+8,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+12,"alu_src2", false,-1, 31,0);
    tracep->declBus(c+13,"jal_target_addr", false,-1, 31,0);
    tracep->declBus(c+14,"jalr_target_addr", false,-1, 31,0);
    tracep->declBus(c+10,"alu_result_reg", false,-1, 31,0);
    tracep->declBus(c+100,"ALU_ADD", false,-1, 3,0);
    tracep->declBus(c+101,"ALU_SUB", false,-1, 3,0);
    tracep->declBus(c+102,"ALU_AND", false,-1, 3,0);
    tracep->declBus(c+103,"ALU_OR", false,-1, 3,0);
    tracep->declBus(c+104,"ALU_XOR", false,-1, 3,0);
    tracep->declBus(c+105,"ALU_SLL", false,-1, 3,0);
    tracep->declBus(c+106,"ALU_SRL", false,-1, 3,0);
    tracep->declBus(c+107,"ALU_SRA", false,-1, 3,0);
    tracep->declBus(c+108,"ALU_SLT", false,-1, 3,0);
    tracep->declBus(c+109,"ALU_SLTU", false,-1, 3,0);
    tracep->declBit(c+15,"beq_taken", false,-1);
    tracep->declBit(c+16,"bne_taken", false,-1);
    tracep->declBit(c+17,"blt_taken", false,-1);
    tracep->declBit(c+18,"bge_taken", false,-1);
    tracep->declBit(c+19,"bltu_taken", false,-1);
    tracep->declBit(c+20,"bgeu_taken", false,-1);
    tracep->declBit(c+11,"branch_taken_reg", false,-1);
    tracep->declBus(c+21,"addr_byte_offset", false,-1, 1,0);
    tracep->declBus(c+22,"store_mask", false,-1, 3,0);
    tracep->declBus(c+23,"store_data", false,-1, 31,0);
    tracep->declBus(c+24,"load_data", false,-1, 31,0);
    tracep->declBus(c+24,"mem_read_data", false,-1, 31,0);
    tracep->declBus(c+27,"jump_target_pc", false,-1, 31,0);
    tracep->declBus(c+80,"wb_data_reg", false,-1, 31,0);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+77,"rs1", false,-1, 4,0);
    tracep->declBus(c+78,"rs2", false,-1, 4,0);
    tracep->declBus(c+79,"rd", false,-1, 4,0);
    tracep->declBit(c+72,"we", false,-1);
    tracep->declBus(c+80,"wdata", false,-1, 31,0);
    tracep->declBus(c+8,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+9,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+26,"a0_value", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+28+i*1,"registers", true,(i+0), 31,0);
    }
    tracep->declBus(c+60,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu ");
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+64,"inst", false,-1, 31,0);
    tracep->declBus(c+8,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+9,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+77,"rs1", false,-1, 4,0);
    tracep->declBus(c+78,"rs2", false,-1, 4,0);
    tracep->declBus(c+79,"rd", false,-1, 4,0);
    tracep->declBus(c+3,"imm", false,-1, 31,0);
    tracep->declBit(c+72,"reg_wen", false,-1);
    tracep->declBit(c+73,"mem_wen", false,-1);
    tracep->declBit(c+74,"mem_ren", false,-1);
    tracep->declBus(c+1,"alu_op", false,-1, 3,0);
    tracep->declBit(c+75,"use_imm", false,-1);
    tracep->declBit(c+76,"branch", false,-1);
    tracep->declBit(c+2,"jump", false,-1);
    tracep->declBit(c+4,"is_jalr", false,-1);
    tracep->declBus(c+83,"opcode", false,-1, 6,0);
    tracep->declBus(c+71,"funct3", false,-1, 2,0);
    tracep->declBus(c+84,"funct7", false,-1, 6,0);
    tracep->declBus(c+85,"funct12", false,-1, 11,0);
    tracep->declBit(c+81,"is_ebreak", false,-1);
    tracep->declBit(c+86,"is_r_type", false,-1);
    tracep->declBit(c+5,"is_i_type", false,-1);
    tracep->declBit(c+73,"is_s_type", false,-1);
    tracep->declBit(c+76,"is_b_type", false,-1);
    tracep->declBit(c+6,"is_u_type", false,-1);
    tracep->declBit(c+87,"is_j_type", false,-1);
    tracep->declBit(c+74,"is_load", false,-1);
    tracep->declBit(c+73,"is_store", false,-1);
    tracep->declBit(c+87,"is_jal", false,-1);
    tracep->declBus(c+88,"i_imm", false,-1, 31,0);
    tracep->declBus(c+89,"s_imm", false,-1, 31,0);
    tracep->declBus(c+90,"b_imm", false,-1, 31,0);
    tracep->declBus(c+91,"u_imm", false,-1, 31,0);
    tracep->declBus(c+92,"j_imm", false,-1, 31,0);
    tracep->declBus(c+3,"imm_val", false,-1, 31,0);
    tracep->declBus(c+100,"ALU_ADD", false,-1, 3,0);
    tracep->declBus(c+101,"ALU_SUB", false,-1, 3,0);
    tracep->declBus(c+102,"ALU_AND", false,-1, 3,0);
    tracep->declBus(c+103,"ALU_OR", false,-1, 3,0);
    tracep->declBus(c+104,"ALU_XOR", false,-1, 3,0);
    tracep->declBus(c+105,"ALU_SLL", false,-1, 3,0);
    tracep->declBus(c+106,"ALU_SRL", false,-1, 3,0);
    tracep->declBus(c+107,"ALU_SRA", false,-1, 3,0);
    tracep->declBus(c+108,"ALU_SLT", false,-1, 3,0);
    tracep->declBus(c+109,"ALU_SLTU", false,-1, 3,0);
    tracep->declBus(c+1,"alu_op_val", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+25,"pc", false,-1, 31,0);
    tracep->declBus(c+63,"imem_addr", false,-1, 31,0);
    tracep->declBus(c+64,"imem_rdata", false,-1, 31,0);
    tracep->declBit(c+65,"imem_valid", false,-1);
    tracep->declBus(c+64,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+7,"next_pc", false,-1, 31,0);
    tracep->declBus(c+25,"pc", false,-1, 31,0);
    tracep->declBit(c+110,"pc_wen", false,-1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBus(c+111,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+112,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+61,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+7,"din", false,-1, 31,0);
    tracep->declBus(c+25,"dout", false,-1, 31,0);
    tracep->declBit(c+110,"wen", false,-1);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__idu__DOT__alu_op_val),4);
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__jump));
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__idu__DOT__imm_val),32);
    bufp->fullBit(oldp+4,(vlSelf->top__DOT__is_jalr));
    bufp->fullBit(oldp+5,(vlSelf->top__DOT__idu__DOT__is_i_type));
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__idu__DOT__is_u_type));
    bufp->fullIData(oldp+7,(((IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg)
                              ? vlSelf->top__DOT__exu__DOT__alu_result_reg
                              : ((IData)(4U) + vlSelf->top__DOT__pc))),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__exu__DOT__alu_src1),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__rs2_data),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__exu__DOT__alu_result_reg),32);
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__exu__DOT__branch_taken_reg));
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__exu__DOT__alu_src2),32);
    bufp->fullIData(oldp+13,((vlSelf->top__DOT__idu__DOT__imm_val 
                              + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+14,((0xfffffffeU & (vlSelf->top__DOT__idu__DOT__imm_val 
                                             + vlSelf->top__DOT__exu__DOT__alu_src1))),32);
    bufp->fullBit(oldp+15,(((1U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                            & (0U == vlSelf->top__DOT__exu__DOT__alu_result_reg))));
    bufp->fullBit(oldp+16,(((1U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                            & (0U != vlSelf->top__DOT__exu__DOT__alu_result_reg))));
    bufp->fullBit(oldp+17,(((8U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                            & vlSelf->top__DOT__exu__DOT__alu_result_reg)));
    bufp->fullBit(oldp+18,(((~ vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                            & (8U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)))));
    bufp->fullBit(oldp+19,(((9U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                            & vlSelf->top__DOT__exu__DOT__alu_result_reg)));
    bufp->fullBit(oldp+20,(((~ vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                            & (9U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)))));
    bufp->fullCData(oldp+21,((3U & vlSelf->top__DOT__exu__DOT__alu_result_reg)),2);
    bufp->fullCData(oldp+22,(vlSelf->top__DOT__exu__DOT__store_mask),4);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__exu__DOT__store_data),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__exu__DOT__load_data),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers
                             [0xaU]),32);
    bufp->fullIData(oldp+27,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[1]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[2]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[3]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[4]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[5]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[6]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[7]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[8]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[9]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[10]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[11]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[12]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[13]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[14]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[15]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[16]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[17]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[18]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[19]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[20]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[21]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[22]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[23]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[24]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[25]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[26]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[27]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[28]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[29]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[30]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[31]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__exu__DOT__regfile__DOT__i),32);
    bufp->fullBit(oldp+61,(vlSelf->clk));
    bufp->fullBit(oldp+62,(vlSelf->rst));
    bufp->fullIData(oldp+63,(vlSelf->imem_addr),32);
    bufp->fullIData(oldp+64,(vlSelf->imem_rdata),32);
    bufp->fullBit(oldp+65,(vlSelf->imem_valid));
    bufp->fullIData(oldp+66,(vlSelf->dmem_addr),32);
    bufp->fullIData(oldp+67,(vlSelf->dmem_rdata),32);
    bufp->fullIData(oldp+68,(vlSelf->dmem_wdata),32);
    bufp->fullBit(oldp+69,(vlSelf->dmem_valid));
    bufp->fullCData(oldp+70,(vlSelf->dmem_wen),4);
    bufp->fullCData(oldp+71,((7U & (vlSelf->imem_rdata 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+72,(((0x33U == (0x7fU & vlSelf->imem_rdata)) 
                            | ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                               | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                  | (IData)(vlSelf->top__DOT__jump))))));
    bufp->fullBit(oldp+73,((0x23U == (0x7fU & vlSelf->imem_rdata))));
    bufp->fullBit(oldp+74,((3U == (0x7fU & vlSelf->imem_rdata))));
    bufp->fullBit(oldp+75,(((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                            | ((0x23U == (0x7fU & vlSelf->imem_rdata)) 
                               | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                  | (0x6fU == (0x7fU 
                                               & vlSelf->imem_rdata)))))));
    bufp->fullBit(oldp+76,((0x63U == (0x7fU & vlSelf->imem_rdata))));
    bufp->fullCData(oldp+77,((0x1fU & (vlSelf->imem_rdata 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+78,((0x1fU & (vlSelf->imem_rdata 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+79,((0x1fU & (vlSelf->imem_rdata 
                                       >> 7U))),5);
    bufp->fullIData(oldp+80,(((3U == (0x7fU & vlSelf->imem_rdata))
                               ? vlSelf->top__DOT__exu__DOT__load_data
                               : ((IData)(vlSelf->top__DOT__jump)
                                   ? ((IData)(4U) + vlSelf->top__DOT__pc)
                                   : vlSelf->top__DOT__exu__DOT__alu_result_reg))),32);
    bufp->fullBit(oldp+81,((IData)((0x100073U == (0xfff0707fU 
                                                  & vlSelf->imem_rdata)))));
    bufp->fullBit(oldp+82,((0x17U == (0x7fU & vlSelf->imem_rdata))));
    bufp->fullCData(oldp+83,((0x7fU & vlSelf->imem_rdata)),7);
    bufp->fullCData(oldp+84,((vlSelf->imem_rdata >> 0x19U)),7);
    bufp->fullSData(oldp+85,((vlSelf->imem_rdata >> 0x14U)),12);
    bufp->fullBit(oldp+86,((0x33U == (0x7fU & vlSelf->imem_rdata))));
    bufp->fullBit(oldp+87,((0x6fU == (0x7fU & vlSelf->imem_rdata))));
    bufp->fullIData(oldp+88,((((- (IData)((vlSelf->imem_rdata 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->imem_rdata 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+89,((((- (IData)((vlSelf->imem_rdata 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelf->imem_rdata 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelf->imem_rdata 
                                                 >> 7U))))),32);
    bufp->fullIData(oldp+90,((((- (IData)((vlSelf->imem_rdata 
                                           >> 0x1fU))) 
                               << 0xdU) | ((0x1000U 
                                            & (vlSelf->imem_rdata 
                                               >> 0x13U)) 
                                           | ((0x800U 
                                               & (vlSelf->imem_rdata 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->imem_rdata 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->imem_rdata 
                                                       >> 7U))))))),32);
    bufp->fullIData(oldp+91,((0xfffff000U & vlSelf->imem_rdata)),32);
    bufp->fullIData(oldp+92,((((- (IData)((vlSelf->imem_rdata 
                                           >> 0x1fU))) 
                               << 0x15U) | ((0x100000U 
                                             & (vlSelf->imem_rdata 
                                                >> 0xbU)) 
                                            | ((0xff000U 
                                                & vlSelf->imem_rdata) 
                                               | ((0x800U 
                                                   & (vlSelf->imem_rdata 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->imem_rdata 
                                                        >> 0x14U))))))),32);
    bufp->fullIData(oldp+93,(0x80100000U),32);
    bufp->fullBit(oldp+94,(vlSelf->top__DOT__pc_wen));
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__alu_src1),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__alu_src2),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__reg_x1),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__reg_x2),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__reg_a0),32);
    bufp->fullCData(oldp+100,(0U),4);
    bufp->fullCData(oldp+101,(1U),4);
    bufp->fullCData(oldp+102,(2U),4);
    bufp->fullCData(oldp+103,(3U),4);
    bufp->fullCData(oldp+104,(4U),4);
    bufp->fullCData(oldp+105,(5U),4);
    bufp->fullCData(oldp+106,(6U),4);
    bufp->fullCData(oldp+107,(7U),4);
    bufp->fullCData(oldp+108,(8U),4);
    bufp->fullCData(oldp+109,(9U),4);
    bufp->fullBit(oldp+110,(1U));
    bufp->fullIData(oldp+111,(0x20U),32);
    bufp->fullIData(oldp+112,(0x80000000U),32);
}
