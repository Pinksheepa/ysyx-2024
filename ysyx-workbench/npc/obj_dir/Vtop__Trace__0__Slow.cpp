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
    tracep->declBit(c+78,"clk", false,-1);
    tracep->declBit(c+79,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+78,"clk", false,-1);
    tracep->declBit(c+79,"rst", false,-1);
    tracep->declBus(c+37,"pc", false,-1, 31,0);
    tracep->declBus(c+80,"next_pc", false,-1, 31,0);
    tracep->declBus(c+38,"pc_plus_4", false,-1, 31,0);
    tracep->declBus(c+81,"branch_target", false,-1, 31,0);
    tracep->declBus(c+39,"inst", false,-1, 31,0);
    tracep->declBit(c+40,"is_ebreak", false,-1);
    tracep->declBus(c+41,"rs1_addr", false,-1, 4,0);
    tracep->declBus(c+42,"rs2_addr", false,-1, 4,0);
    tracep->declBus(c+43,"rd_addr", false,-1, 4,0);
    tracep->declBus(c+44,"opcode", false,-1, 6,0);
    tracep->declBus(c+45,"funct3", false,-1, 2,0);
    tracep->declBus(c+46,"funct7", false,-1, 6,0);
    tracep->declBus(c+47,"inst_type", false,-1, 2,0);
    tracep->declBus(c+48,"alu_op", false,-1, 3,0);
    tracep->declBit(c+49,"mem_read", false,-1);
    tracep->declBit(c+50,"mem_write", false,-1);
    tracep->declBit(c+51,"reg_write", false,-1);
    tracep->declBit(c+52,"is_branch", false,-1);
    tracep->declBit(c+53,"is_jal", false,-1);
    tracep->declBit(c+54,"is_jalr", false,-1);
    tracep->declBit(c+55,"is_lui", false,-1);
    tracep->declBit(c+56,"is_auipc", false,-1);
    tracep->declBit(c+57,"use_imm", false,-1);
    tracep->declBus(c+66,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+67,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+82,"rd_data", false,-1, 31,0);
    tracep->declBus(c+58,"imm", false,-1, 31,0);
    tracep->declBus(c+68,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+69,"alu_src2", false,-1, 31,0);
    tracep->declBus(c+70,"alu_result", false,-1, 31,0);
    tracep->declBit(c+71,"alu_zero", false,-1);
    tracep->declBit(c+72,"alu_less_than", false,-1);
    tracep->declBus(c+73,"mem_read_data", false,-1, 31,0);
    tracep->declBus(c+83,"csr_read_data", false,-1, 31,0);
    tracep->declBit(c+2,"trap_flag", false,-1);
    tracep->declBit(c+84,"branch_taken", false,-1);
    tracep->declBus(c+3,"cycle_count", false,-1, 31,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+68,"src1", false,-1, 31,0);
    tracep->declBus(c+69,"src2", false,-1, 31,0);
    tracep->declBus(c+48,"alu_op", false,-1, 3,0);
    tracep->declBus(c+70,"result", false,-1, 31,0);
    tracep->declBit(c+71,"zero", false,-1);
    tracep->declBit(c+72,"less_than", false,-1);
    tracep->declQuad(c+74,"mul_signed", false,-1, 63,0);
    tracep->declQuad(c+76,"mul_unsigned", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("csr ");
    tracep->declBit(c+78,"clk", false,-1);
    tracep->declBit(c+79,"rst", false,-1);
    tracep->declBus(c+59,"csr_addr", false,-1, 11,0);
    tracep->declBus(c+66,"csr_write_data", false,-1, 31,0);
    tracep->declBit(c+60,"csr_write", false,-1);
    tracep->declBus(c+83,"csr_read_data", false,-1, 31,0);
    tracep->declBit(c+2,"trap_flag", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("data_mem ");
    tracep->declBit(c+78,"clk", false,-1);
    tracep->declBus(c+70,"addr", false,-1, 31,0);
    tracep->declBus(c+67,"write_data", false,-1, 31,0);
    tracep->declBit(c+50,"mem_write", false,-1);
    tracep->declBit(c+49,"mem_read", false,-1);
    tracep->declBus(c+45,"funct3", false,-1, 2,0);
    tracep->declBus(c+73,"read_data", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gpr ");
    tracep->declBit(c+78,"clk", false,-1);
    tracep->declBit(c+79,"rst", false,-1);
    tracep->declBus(c+41,"rs1_addr", false,-1, 4,0);
    tracep->declBus(c+42,"rs2_addr", false,-1, 4,0);
    tracep->declBus(c+43,"rd_addr", false,-1, 4,0);
    tracep->declBus(c+82,"rd_data", false,-1, 31,0);
    tracep->declBit(c+51,"reg_write", false,-1);
    tracep->declBus(c+66,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+67,"rs2_data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+4+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+36,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+39,"inst", false,-1, 31,0);
    tracep->declBus(c+41,"rs1_addr", false,-1, 4,0);
    tracep->declBus(c+42,"rs2_addr", false,-1, 4,0);
    tracep->declBus(c+43,"rd_addr", false,-1, 4,0);
    tracep->declBus(c+44,"opcode", false,-1, 6,0);
    tracep->declBus(c+45,"funct3", false,-1, 2,0);
    tracep->declBus(c+46,"funct7", false,-1, 6,0);
    tracep->declBus(c+47,"inst_type", false,-1, 2,0);
    tracep->declBus(c+48,"alu_op", false,-1, 3,0);
    tracep->declBit(c+49,"mem_read", false,-1);
    tracep->declBit(c+50,"mem_write", false,-1);
    tracep->declBit(c+51,"reg_write", false,-1);
    tracep->declBit(c+52,"is_branch", false,-1);
    tracep->declBit(c+53,"is_jal", false,-1);
    tracep->declBit(c+54,"is_jalr", false,-1);
    tracep->declBit(c+55,"is_lui", false,-1);
    tracep->declBit(c+56,"is_auipc", false,-1);
    tracep->declBit(c+57,"use_imm", false,-1);
    tracep->declBit(c+61,"r_type", false,-1);
    tracep->declBit(c+62,"i_type", false,-1);
    tracep->declBit(c+50,"s_type", false,-1);
    tracep->declBit(c+52,"b_type", false,-1);
    tracep->declBit(c+63,"u_type", false,-1);
    tracep->declBit(c+53,"j_type", false,-1);
    tracep->declBus(c+64,"alu_op_r_type", false,-1, 3,0);
    tracep->declBus(c+65,"alu_op_i_type", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("imm_gen ");
    tracep->declBus(c+39,"inst", false,-1, 31,0);
    tracep->declBus(c+47,"inst_type", false,-1, 2,0);
    tracep->declBus(c+58,"imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("inst_mem ");
    tracep->declBit(c+78,"clk", false,-1);
    tracep->declBus(c+37,"addr", false,-1, 31,0);
    tracep->declBus(c+39,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBit(c+78,"clk", false,-1);
    tracep->declBit(c+79,"rst", false,-1);
    tracep->declBus(c+80,"next_pc", false,-1, 31,0);
    tracep->declBus(c+37,"pc", false,-1, 31,0);
    tracep->declBus(c+85,"RESET_VECTOR", false,-1, 31,0);
    tracep->popNamePrefix(2);
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
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__data_mem__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__trap_flag));
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__cycle_count),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__gpr__DOT__rf[0]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__gpr__DOT__rf[1]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__gpr__DOT__rf[2]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__gpr__DOT__rf[3]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__gpr__DOT__rf[4]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__gpr__DOT__rf[5]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__gpr__DOT__rf[6]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__gpr__DOT__rf[7]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__gpr__DOT__rf[8]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__gpr__DOT__rf[9]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__gpr__DOT__rf[10]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__gpr__DOT__rf[11]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__gpr__DOT__rf[12]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__gpr__DOT__rf[13]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__gpr__DOT__rf[14]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__gpr__DOT__rf[15]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__gpr__DOT__rf[16]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__gpr__DOT__rf[17]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__gpr__DOT__rf[18]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__gpr__DOT__rf[19]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__gpr__DOT__rf[20]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__gpr__DOT__rf[21]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__gpr__DOT__rf[22]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__gpr__DOT__rf[23]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__gpr__DOT__rf[24]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__gpr__DOT__rf[25]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__gpr__DOT__rf[26]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__gpr__DOT__rf[27]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__gpr__DOT__rf[28]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__gpr__DOT__rf[29]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__gpr__DOT__rf[30]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__gpr__DOT__rf[31]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__gpr__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+38,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__inst),32);
    bufp->fullBit(oldp+40,((0x100073U == vlSelf->top__DOT__inst)));
    bufp->fullCData(oldp+41,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+42,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+43,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+44,((0x7fU & vlSelf->top__DOT__inst)),7);
    bufp->fullCData(oldp+45,((7U & (vlSelf->top__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+46,((vlSelf->top__DOT__inst 
                              >> 0x19U)),7);
    bufp->fullCData(oldp+47,(vlSelf->top__DOT__inst_type),3);
    bufp->fullCData(oldp+48,(vlSelf->top__DOT__alu_op),4);
    bufp->fullBit(oldp+49,((3U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+50,((0x23U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+51,(((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
                            | ((IData)(vlSelf->top__DOT__idu__DOT__i_type) 
                               | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h88c6b025__0)))));
    bufp->fullBit(oldp+52,((0x63U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+53,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+54,((0x67U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+55,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+56,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+57,(((IData)(vlSelf->top__DOT__idu__DOT__i_type) 
                            | ((0x23U == (0x7fU & vlSelf->top__DOT__inst)) 
                               | ((0x63U == (0x7fU 
                                             & vlSelf->top__DOT__inst)) 
                                  | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h88c6b025__0))))));
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__imm),32);
    bufp->fullSData(oldp+59,((vlSelf->top__DOT__inst 
                              >> 0x14U)),12);
    bufp->fullBit(oldp+60,(((0x73U == (0x7fU & vlSelf->top__DOT__inst)) 
                            & (0U != (7U & (vlSelf->top__DOT__inst 
                                            >> 0xcU))))));
    bufp->fullBit(oldp+61,((0x33U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__idu__DOT__i_type));
    bufp->fullBit(oldp+63,(vlSelf->top__DOT__idu__DOT__u_type));
    bufp->fullCData(oldp+64,(vlSelf->top__DOT__idu__DOT__alu_op_r_type),4);
    bufp->fullCData(oldp+65,(((0U == (7U & (vlSelf->top__DOT__inst 
                                            >> 0xcU)))
                               ? 0U : ((1U == (7U & 
                                               (vlSelf->top__DOT__inst 
                                                >> 0xcU)))
                                        ? 2U : ((2U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->top__DOT__inst 
                                                     >> 0xcU)))
                                                 ? 3U
                                                 : 
                                                ((3U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->top__DOT__inst 
                                                      >> 0xcU)))
                                                  ? 4U
                                                  : 
                                                 ((4U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->top__DOT__inst 
                                                       >> 0xcU)))
                                                   ? 5U
                                                   : 
                                                  ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h87b4775b__0)
                                                    ? 6U
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h22a85453__0)
                                                     ? 7U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->top__DOT__inst 
                                                          >> 0xcU)))
                                                      ? 8U
                                                      : 
                                                     ((7U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->top__DOT__inst 
                                                           >> 0xcU)))
                                                       ? 9U
                                                       : 0U)))))))))),4);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__rs1_data),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__rs2_data),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__alu_src1),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__alu_src2),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__alu_result),32);
    bufp->fullBit(oldp+71,((0U == vlSelf->top__DOT__alu_result)));
    bufp->fullBit(oldp+72,(vlSelf->top__DOT__alu_less_than));
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__mem_read_data),32);
    bufp->fullQData(oldp+74,(vlSelf->top__DOT__alu__DOT__mul_signed),64);
    bufp->fullQData(oldp+76,(((QData)((IData)(vlSelf->top__DOT__alu_src1)) 
                              * (QData)((IData)(vlSelf->top__DOT__alu_src2)))),64);
    bufp->fullBit(oldp+78,(vlSelf->clk));
    bufp->fullBit(oldp+79,(vlSelf->rst));
    bufp->fullIData(oldp+80,((((0x6fU == (0x7fU & vlSelf->top__DOT__inst)) 
                               | ((IData)(((0x63U == 
                                            (0x7fU 
                                             & vlSelf->top__DOT__inst)) 
                                           & ((IData)(
                                                      ((0U 
                                                        == 
                                                        (0x7000U 
                                                         & vlSelf->top__DOT__inst)) 
                                                       & (0U 
                                                          == vlSelf->top__DOT__alu_result))) 
                                              | ((IData)(
                                                         ((0x1000U 
                                                           == 
                                                           (0x7000U 
                                                            & vlSelf->top__DOT__inst)) 
                                                          & (0U 
                                                             != vlSelf->top__DOT__alu_result))) 
                                                 | ((IData)(
                                                            ((0x4000U 
                                                              == 
                                                              (0x7000U 
                                                               & vlSelf->top__DOT__inst)) 
                                                             & (IData)(vlSelf->top__DOT__alu_less_than))) 
                                                    | (((~ (IData)(vlSelf->top__DOT__alu_less_than)) 
                                                        & (0x5000U 
                                                           == 
                                                           (0x7000U 
                                                            & vlSelf->top__DOT__inst))) 
                                                       | ((IData)(
                                                                  ((0x6000U 
                                                                    == 
                                                                    (0x7000U 
                                                                     & vlSelf->top__DOT__inst)) 
                                                                   & (vlSelf->top__DOT__rs1_data 
                                                                      < vlSelf->top__DOT__rs2_data))) 
                                                          | (IData)(
                                                                    ((0x7000U 
                                                                      == 
                                                                      (0x7000U 
                                                                       & vlSelf->top__DOT__inst)) 
                                                                     & (vlSelf->top__DOT__rs1_data 
                                                                        >= vlSelf->top__DOT__rs2_data)))))))))) 
                                  | (0x67U == (0x7fU 
                                               & vlSelf->top__DOT__inst))))
                               ? ((0x67U == (0x7fU 
                                             & vlSelf->top__DOT__inst))
                                   ? (0xfffffffeU & 
                                      (vlSelf->top__DOT__imm 
                                       + vlSelf->top__DOT__rs1_data))
                                   : (vlSelf->top__DOT__imm 
                                      + vlSelf->top__DOT__pc))
                               : ((IData)(4U) + vlSelf->top__DOT__pc))),32);
    bufp->fullIData(oldp+81,(((0x67U == (0x7fU & vlSelf->top__DOT__inst))
                               ? (0xfffffffeU & (vlSelf->top__DOT__imm 
                                                 + vlSelf->top__DOT__rs1_data))
                               : (vlSelf->top__DOT__imm 
                                  + vlSelf->top__DOT__pc))),32);
    bufp->fullIData(oldp+82,(((0x37U == (0x7fU & vlSelf->top__DOT__inst))
                               ? vlSelf->top__DOT__imm
                               : (((IData)(vlSelf->top__DOT____VdfgTmp_h5482c01c__0) 
                                   | (0x67U == (0x7fU 
                                                & vlSelf->top__DOT__inst)))
                                   ? ((IData)(4U) + vlSelf->top__DOT__pc)
                                   : ((3U == (0x7fU 
                                              & vlSelf->top__DOT__inst))
                                       ? vlSelf->top__DOT__mem_read_data
                                       : vlSelf->top__DOT__alu_result)))),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__csr__DOT__csr_regs
                             [(vlSelf->top__DOT__inst 
                               >> 0x14U)]),32);
    bufp->fullBit(oldp+84,(((0x63U == (0x7fU & vlSelf->top__DOT__inst)) 
                            & ((IData)(((0U == (0x7000U 
                                                & vlSelf->top__DOT__inst)) 
                                        & (0U == vlSelf->top__DOT__alu_result))) 
                               | ((IData)(((0x1000U 
                                            == (0x7000U 
                                                & vlSelf->top__DOT__inst)) 
                                           & (0U != vlSelf->top__DOT__alu_result))) 
                                  | ((IData)(((0x4000U 
                                               == (0x7000U 
                                                   & vlSelf->top__DOT__inst)) 
                                              & (IData)(vlSelf->top__DOT__alu_less_than))) 
                                     | (((~ (IData)(vlSelf->top__DOT__alu_less_than)) 
                                         & (0x5000U 
                                            == (0x7000U 
                                                & vlSelf->top__DOT__inst))) 
                                        | ((IData)(
                                                   ((0x6000U 
                                                     == 
                                                     (0x7000U 
                                                      & vlSelf->top__DOT__inst)) 
                                                    & (vlSelf->top__DOT__rs1_data 
                                                       < vlSelf->top__DOT__rs2_data))) 
                                           | (IData)(
                                                     ((0x7000U 
                                                       == 
                                                       (0x7000U 
                                                        & vlSelf->top__DOT__inst)) 
                                                      & (vlSelf->top__DOT__rs1_data 
                                                         >= vlSelf->top__DOT__rs2_data)))))))))));
    bufp->fullIData(oldp+85,(0x80000000U),32);
}
