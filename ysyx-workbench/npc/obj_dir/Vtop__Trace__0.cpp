// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__idu__DOT__alu_op_val),4);
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__jump));
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__idu__DOT__imm_val),32);
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__is_jalr));
        bufp->chgBit(oldp+4,(vlSelf->top__DOT__idu__DOT__is_i_type));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__idu__DOT__is_u_type));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+6,(((IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg)
                                 ? vlSelf->top__DOT__exu__DOT__alu_result_reg
                                 : ((IData)(4U) + vlSelf->top__DOT__pc))),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__exu__DOT__alu_src1),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__rs2_data),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__exu__DOT__alu_result_reg),32);
        bufp->chgBit(oldp+10,(vlSelf->top__DOT__exu__DOT__branch_taken_reg));
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__exu__DOT__alu_src2),32);
        bufp->chgIData(oldp+12,((vlSelf->top__DOT__idu__DOT__imm_val 
                                 + vlSelf->top__DOT__pc)),32);
        bufp->chgIData(oldp+13,((0xfffffffeU & (vlSelf->top__DOT__idu__DOT__imm_val 
                                                + vlSelf->top__DOT__exu__DOT__alu_src1))),32);
        bufp->chgBit(oldp+14,(((1U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                               & (0U == vlSelf->top__DOT__exu__DOT__alu_result_reg))));
        bufp->chgBit(oldp+15,(((1U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                               & (0U != vlSelf->top__DOT__exu__DOT__alu_result_reg))));
        bufp->chgBit(oldp+16,(((8U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                               & vlSelf->top__DOT__exu__DOT__alu_result_reg)));
        bufp->chgBit(oldp+17,(((~ vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                               & (8U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)))));
        bufp->chgBit(oldp+18,(((9U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                               & vlSelf->top__DOT__exu__DOT__alu_result_reg)));
        bufp->chgBit(oldp+19,(((~ vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                               & (9U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)))));
        bufp->chgCData(oldp+20,((3U & vlSelf->top__DOT__exu__DOT__alu_result_reg)),2);
        bufp->chgCData(oldp+21,(vlSelf->top__DOT__exu__DOT__store_mask),4);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__exu__DOT__store_data),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__exu__DOT__load_data),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__pc),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers
                                [0xaU]),32);
        bufp->chgIData(oldp+26,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[1]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[2]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[3]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[4]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[5]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[6]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[7]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[8]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[9]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[10]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[11]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[12]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[13]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[14]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[15]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[16]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[17]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[18]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[19]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[20]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[21]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[22]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[23]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[24]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[25]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[26]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[27]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[28]),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[29]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[30]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[31]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__exu__DOT__regfile__DOT__i),32);
    }
    bufp->chgBit(oldp+60,(vlSelf->clk));
    bufp->chgBit(oldp+61,(vlSelf->rst));
    bufp->chgIData(oldp+62,(vlSelf->imem_addr),32);
    bufp->chgIData(oldp+63,(vlSelf->imem_rdata),32);
    bufp->chgBit(oldp+64,(vlSelf->imem_valid));
    bufp->chgIData(oldp+65,(vlSelf->dmem_addr),32);
    bufp->chgIData(oldp+66,(vlSelf->dmem_rdata),32);
    bufp->chgIData(oldp+67,(vlSelf->dmem_wdata),32);
    bufp->chgBit(oldp+68,(vlSelf->dmem_valid));
    bufp->chgCData(oldp+69,(vlSelf->dmem_wen),4);
    bufp->chgCData(oldp+70,((7U & (vlSelf->imem_rdata 
                                   >> 0xcU))),3);
    bufp->chgBit(oldp+71,(((0x33U == (0x7fU & vlSelf->imem_rdata)) 
                           | ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                              | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                 | (IData)(vlSelf->top__DOT__jump))))));
    bufp->chgBit(oldp+72,((0x23U == (0x7fU & vlSelf->imem_rdata))));
    bufp->chgBit(oldp+73,((3U == (0x7fU & vlSelf->imem_rdata))));
    bufp->chgBit(oldp+74,(((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                           | ((0x23U == (0x7fU & vlSelf->imem_rdata)) 
                              | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                 | (0x6fU == (0x7fU 
                                              & vlSelf->imem_rdata)))))));
    bufp->chgBit(oldp+75,((0x63U == (0x7fU & vlSelf->imem_rdata))));
    bufp->chgCData(oldp+76,((0x1fU & (vlSelf->imem_rdata 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+77,((0x1fU & (vlSelf->imem_rdata 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+78,((0x1fU & (vlSelf->imem_rdata 
                                      >> 7U))),5);
    bufp->chgIData(oldp+79,(((3U == (0x7fU & vlSelf->imem_rdata))
                              ? vlSelf->top__DOT__exu__DOT__load_data
                              : ((IData)(vlSelf->top__DOT__jump)
                                  ? ((IData)(4U) + vlSelf->top__DOT__pc)
                                  : vlSelf->top__DOT__exu__DOT__alu_result_reg))),32);
    bufp->chgBit(oldp+80,((IData)((0x100073U == (0xfff0707fU 
                                                 & vlSelf->imem_rdata)))));
    bufp->chgBit(oldp+81,((0x17U == (0x7fU & vlSelf->imem_rdata))));
    bufp->chgCData(oldp+82,((0x7fU & vlSelf->imem_rdata)),7);
    bufp->chgCData(oldp+83,((vlSelf->imem_rdata >> 0x19U)),7);
    bufp->chgSData(oldp+84,((vlSelf->imem_rdata >> 0x14U)),12);
    bufp->chgBit(oldp+85,((0x33U == (0x7fU & vlSelf->imem_rdata))));
    bufp->chgBit(oldp+86,((0x6fU == (0x7fU & vlSelf->imem_rdata))));
    bufp->chgIData(oldp+87,((((- (IData)((vlSelf->imem_rdata 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelf->imem_rdata 
                                          >> 0x14U))),32);
    bufp->chgIData(oldp+88,((((- (IData)((vlSelf->imem_rdata 
                                          >> 0x1fU))) 
                              << 0xcU) | ((0xfe0U & 
                                           (vlSelf->imem_rdata 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlSelf->imem_rdata 
                                                >> 7U))))),32);
    bufp->chgIData(oldp+89,((((- (IData)((vlSelf->imem_rdata 
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
    bufp->chgIData(oldp+90,((0xfffff000U & vlSelf->imem_rdata)),32);
    bufp->chgIData(oldp+91,((((- (IData)((vlSelf->imem_rdata 
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
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
