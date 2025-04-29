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
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__is_ecall));
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__is_ebreak));
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__regfile__DOT__registers
                               [0xaU]),32);
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__dpi_system__DOT__terminate_reg));
        bufp->chgBit(oldp+4,(vlSelf->top__DOT__wb_valid));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard));
        bufp->chgBit(oldp+6,(vlSelf->top__DOT__flush_if));
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__flush_ex));
        bufp->chgBit(oldp+8,(vlSelf->top__DOT__pipeline_flush_exc));
        bufp->chgBit(oldp+9,(((IData)(vlSelf->top__DOT__ex_jump) 
                              | (IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg))));
        bufp->chgBit(oldp+10,(vlSelf->top__DOT__exception_valid));
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__exception_code),4);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__exception_pc),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__exception_val),32);
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__exception_redirect));
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__exception_target),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__csr_file__DOT__mtvec),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__pc),32);
        bufp->chgIData(oldp+18,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__id_pc),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__id_instr),32);
        bufp->chgCData(oldp+21,((0x1fU & (vlSelf->top__DOT__id_instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+22,((0x1fU & (vlSelf->top__DOT__id_instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+23,((0x1fU & (vlSelf->top__DOT__id_instr 
                                          >> 7U))),5);
        bufp->chgIData(oldp+24,(((0U == (0x1fU & (vlSelf->top__DOT__id_instr 
                                                  >> 0xfU)))
                                  ? 0U : vlSelf->top__DOT__regfile__DOT__registers
                                 [(0x1fU & (vlSelf->top__DOT__id_instr 
                                            >> 0xfU))])),32);
        bufp->chgIData(oldp+25,(((0U == (0x1fU & (vlSelf->top__DOT__id_instr 
                                                  >> 0x14U)))
                                  ? 0U : vlSelf->top__DOT__regfile__DOT__registers
                                 [(0x1fU & (vlSelf->top__DOT__id_instr 
                                            >> 0x14U))])),32);
        bufp->chgIData(oldp+26,(((IData)(vlSelf->top__DOT__idu__DOT__is_i_type)
                                  ? (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                      & (IData)(vlSelf->top__DOT__idu__DOT__is_csr_imm))
                                      ? (0x1fU & (vlSelf->top__DOT__id_instr 
                                                  >> 0xfU))
                                      : (((- (IData)(
                                                     (vlSelf->top__DOT__id_instr 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelf->top__DOT__id_instr 
                                            >> 0x14U)))
                                  : ((0x23U == (0x7fU 
                                                & vlSelf->top__DOT__id_instr))
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__id_instr 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelf->top__DOT__id_instr 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->top__DOT__id_instr 
                                                  >> 7U))))
                                      : ((0x63U == 
                                          (0x7fU & vlSelf->top__DOT__id_instr))
                                          ? (((- (IData)(
                                                         (vlSelf->top__DOT__id_instr 
                                                          >> 0x1fU))) 
                                              << 0xdU) 
                                             | ((0x1000U 
                                                 & (vlSelf->top__DOT__id_instr 
                                                    >> 0x13U)) 
                                                | ((0x800U 
                                                    & (vlSelf->top__DOT__id_instr 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlSelf->top__DOT__id_instr 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlSelf->top__DOT__id_instr 
                                                            >> 7U))))))
                                          : ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type)
                                              ? (0xfffff000U 
                                                 & vlSelf->top__DOT__id_instr)
                                              : ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__id_instr))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelf->top__DOT__id_instr 
                                                               >> 0x1fU))) 
                                                   << 0x15U) 
                                                  | ((0x100000U 
                                                      & (vlSelf->top__DOT__id_instr 
                                                         >> 0xbU)) 
                                                     | ((0xff000U 
                                                         & vlSelf->top__DOT__id_instr) 
                                                        | ((0x800U 
                                                            & (vlSelf->top__DOT__id_instr 
                                                               >> 9U)) 
                                                           | (0x7feU 
                                                              & (vlSelf->top__DOT__id_instr 
                                                                 >> 0x14U))))))
                                                  : 0U)))))),32);
        bufp->chgBit(oldp+27,(((((0x33U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                                 | ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                                    | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                       | (IData)(vlSelf->top__DOT__id_jump)))) 
                                | (IData)(vlSelf->top__DOT__idu__DOT__is_csr)) 
                               & (0U != (0x1fU & (vlSelf->top__DOT__id_instr 
                                                  >> 7U))))));
        bufp->chgBit(oldp+28,((0x23U == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgBit(oldp+29,((3U == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgCData(oldp+30,(vlSelf->top__DOT__idu__DOT__alu_op_val),4);
        bufp->chgBit(oldp+31,(((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                               | ((0x23U == (0x7fU 
                                             & vlSelf->top__DOT__id_instr)) 
                                  | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                     | (0x6fU == (0x7fU 
                                                  & vlSelf->top__DOT__id_instr)))))));
        bufp->chgBit(oldp+32,((0x63U == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgBit(oldp+33,(vlSelf->top__DOT__id_jump));
        bufp->chgBit(oldp+34,(vlSelf->top__DOT__id_is_jalr));
        bufp->chgCData(oldp+35,(vlSelf->top__DOT__idu__DOT__mem_type_val),3);
        bufp->chgBit(oldp+36,(vlSelf->top__DOT__idu__DOT__mem_unsigned_val));
        bufp->chgCData(oldp+37,(((3U == (0x7fU & vlSelf->top__DOT__id_instr))
                                  ? 1U : ((IData)(vlSelf->top__DOT__id_jump)
                                           ? 2U : ((IData)(vlSelf->top__DOT__idu__DOT__is_csr)
                                                    ? 3U
                                                    : 0U)))),2);
        bufp->chgBit(oldp+38,(vlSelf->top__DOT__idu__DOT__is_csr));
        bufp->chgBit(oldp+39,(((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                               & (IData)(((0U != (0xf8000U 
                                                  & vlSelf->top__DOT__id_instr)) 
                                          | (IData)(vlSelf->top__DOT__idu__DOT__is_csrrw))))));
        bufp->chgSData(oldp+40,((vlSelf->top__DOT__id_instr 
                                 >> 0x14U)),12);
        bufp->chgBit(oldp+41,(vlSelf->top__DOT__idu__DOT__illegal_instr_reg));
        bufp->chgCData(oldp+42,(((IData)(vlSelf->top__DOT__idu__DOT__is_csrrw)
                                  ? 0U : (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                           & (0x2000U 
                                              == (0x3000U 
                                                  & vlSelf->top__DOT__id_instr)))
                                           ? 1U : (
                                                   ((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                                    & (0x3000U 
                                                       == 
                                                       (0x3000U 
                                                        & vlSelf->top__DOT__id_instr)))
                                                    ? 2U
                                                    : 0U)))),2);
        bufp->chgBit(oldp+43,(vlSelf->top__DOT__idu__DOT__is_csr_imm));
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__wb_data),32);
        bufp->chgCData(oldp+45,(vlSelf->top__DOT__wb_rd),5);
        bufp->chgBit(oldp+46,(((IData)(vlSelf->top__DOT__wb_reg_wen) 
                               & (0U != (IData)(vlSelf->top__DOT__wb_rd)))));
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__ex_pc),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__ex_instr),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__ex_rs1_data),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__ex_rs2_data),32);
        bufp->chgCData(oldp+51,(vlSelf->top__DOT__ex_rs1),5);
        bufp->chgCData(oldp+52,(vlSelf->top__DOT__ex_rs2),5);
        bufp->chgCData(oldp+53,(vlSelf->top__DOT__ex_rd),5);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__ex_imm),32);
        bufp->chgBit(oldp+55,(vlSelf->top__DOT__ex_reg_wen));
        bufp->chgBit(oldp+56,(vlSelf->top__DOT__ex_mem_wen));
        bufp->chgBit(oldp+57,(vlSelf->top__DOT__ex_mem_ren));
        bufp->chgCData(oldp+58,(vlSelf->top__DOT__ex_alu_op),4);
        bufp->chgBit(oldp+59,(vlSelf->top__DOT__ex_use_imm));
        bufp->chgBit(oldp+60,(vlSelf->top__DOT__ex_branch));
        bufp->chgBit(oldp+61,(vlSelf->top__DOT__ex_jump));
        bufp->chgBit(oldp+62,(vlSelf->top__DOT__ex_is_jalr));
        bufp->chgCData(oldp+63,(vlSelf->top__DOT__ex_mem_type),3);
        bufp->chgBit(oldp+64,(vlSelf->top__DOT__ex_mem_unsigned));
        bufp->chgCData(oldp+65,(vlSelf->top__DOT__ex_wb_sel),2);
        bufp->chgBit(oldp+66,(vlSelf->top__DOT__ex_csr_ren));
        bufp->chgBit(oldp+67,(vlSelf->top__DOT__ex_csr_wen));
        bufp->chgSData(oldp+68,(vlSelf->top__DOT__ex_csr_addr),12);
        bufp->chgBit(oldp+69,(vlSelf->top__DOT__ex_illegal_instr));
        bufp->chgBit(oldp+70,(vlSelf->top__DOT__ex_csr_imm));
        bufp->chgCData(oldp+71,(vlSelf->top__DOT__ex_csr_op),2);
        bufp->chgCData(oldp+72,(vlSelf->top__DOT__forward_a),2);
        bufp->chgCData(oldp+73,(vlSelf->top__DOT__forward_b),2);
        bufp->chgIData(oldp+74,(vlSelf->top__DOT__exu__DOT__alu_result_reg),32);
        bufp->chgBit(oldp+75,(vlSelf->top__DOT__exu__DOT__branch_taken_reg));
        bufp->chgIData(oldp+76,(vlSelf->top__DOT__exu__DOT__forwarded_rs2_data),32);
        bufp->chgIData(oldp+77,(((IData)(vlSelf->top__DOT__ex_is_jalr)
                                  ? (0xfffffffeU & 
                                     (vlSelf->top__DOT__ex_imm 
                                      + vlSelf->top__DOT__exu__DOT__alu_src1))
                                  : (vlSelf->top__DOT__ex_imm 
                                     + vlSelf->top__DOT__ex_pc))),32);
        bufp->chgCData(oldp+78,((7U & (vlSelf->top__DOT__ex_instr 
                                       >> 0xcU))),3);
        bufp->chgIData(oldp+79,(((IData)(vlSelf->top__DOT__ex_csr_imm)
                                  ? vlSelf->top__DOT__ex_imm
                                  : vlSelf->top__DOT__exu__DOT__alu_src1)),32);
        bufp->chgIData(oldp+80,(vlSelf->top__DOT__mem_pc),32);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__mem_instr),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__mem_alu_result),32);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__mem_rs2_data),32);
        bufp->chgCData(oldp+84,(vlSelf->top__DOT__mem_rs1),5);
        bufp->chgCData(oldp+85,(vlSelf->top__DOT__mem_rs2),5);
        bufp->chgCData(oldp+86,(vlSelf->top__DOT__mem_rd),5);
        bufp->chgBit(oldp+87,(vlSelf->top__DOT__mem_reg_wen));
        bufp->chgBit(oldp+88,(vlSelf->top__DOT__mem_mem_wen));
        bufp->chgBit(oldp+89,(vlSelf->top__DOT__mem_mem_ren));
        bufp->chgBit(oldp+90,(vlSelf->top__DOT__mem_branch_taken));
        bufp->chgCData(oldp+91,(vlSelf->top__DOT__mem_funct3),3);
        bufp->chgCData(oldp+92,(vlSelf->top__DOT__mem_mem_type),3);
        bufp->chgBit(oldp+93,(vlSelf->top__DOT__mem_mem_unsigned));
        bufp->chgCData(oldp+94,(vlSelf->top__DOT__mem_wb_sel),2);
        bufp->chgBit(oldp+95,(vlSelf->top__DOT__mem_csr_ren));
        bufp->chgBit(oldp+96,(vlSelf->top__DOT__mem_csr_wen));
        bufp->chgSData(oldp+97,(vlSelf->top__DOT__mem_csr_addr),12);
        bufp->chgCData(oldp+98,(vlSelf->top__DOT__mem_csr_op),2);
        bufp->chgBit(oldp+99,(vlSelf->top__DOT__mem_csr_imm));
        bufp->chgIData(oldp+100,(vlSelf->top__DOT__mem_csr_write_data),32);
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__mem_csr_rdata),32);
        bufp->chgIData(oldp+102,(vlSelf->top__DOT__wb_pc),32);
        bufp->chgIData(oldp+103,(vlSelf->top__DOT__wb_instr),32);
        bufp->chgIData(oldp+104,(vlSelf->top__DOT__wb_alu_result),32);
        bufp->chgIData(oldp+105,(vlSelf->top__DOT__wb_mem_rdata),32);
        bufp->chgBit(oldp+106,(vlSelf->top__DOT__wb_reg_wen));
        bufp->chgBit(oldp+107,(vlSelf->top__DOT__wb_mem_ren));
        bufp->chgCData(oldp+108,(vlSelf->top__DOT__wb_wb_sel),2);
        bufp->chgBit(oldp+109,(vlSelf->top__DOT__wb_mem_unsigned));
        bufp->chgIData(oldp+110,(vlSelf->top__DOT__wb_csr_rdata),32);
        bufp->chgBit(oldp+111,(vlSelf->top__DOT__wb_csr_ren));
        bufp->chgBit(oldp+112,(vlSelf->top__DOT__wb_csr_wen));
        bufp->chgSData(oldp+113,(vlSelf->top__DOT__wb_csr_addr),12);
        bufp->chgCData(oldp+114,(vlSelf->top__DOT__wb_csr_op),2);
        bufp->chgBit(oldp+115,(vlSelf->top__DOT__wb_csr_imm));
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__wb_csr_write_data),32);
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__csr_file__DOT__mstatus),32);
        bufp->chgIData(oldp+118,(vlSelf->top__DOT__csr_file__DOT__misa),32);
        bufp->chgIData(oldp+119,(vlSelf->top__DOT__csr_file__DOT__mscratch),32);
        bufp->chgIData(oldp+120,(vlSelf->top__DOT__csr_file__DOT__mepc),32);
        bufp->chgIData(oldp+121,(vlSelf->top__DOT__csr_file__DOT__mcause),32);
        bufp->chgIData(oldp+122,(vlSelf->top__DOT__csr_file__DOT__mtval),32);
        bufp->chgIData(oldp+123,(vlSelf->top__DOT__csr_file__DOT__mcycle),32);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__csr_file__DOT__mcycleh),32);
        bufp->chgBit(oldp+125,(vlSelf->top__DOT__dpi_system__DOT__ecall_handled));
        bufp->chgBit(oldp+126,(vlSelf->top__DOT__dpi_system__DOT__ebreak_handled));
        bufp->chgBit(oldp+127,(vlSelf->top__DOT__exception_handler__DOT__exception_detected));
        bufp->chgCData(oldp+128,(vlSelf->top__DOT__exception_handler__DOT__detected_exception_code),4);
        bufp->chgIData(oldp+129,(vlSelf->top__DOT__exception_handler__DOT__detected_exception_val),32);
        bufp->chgBit(oldp+130,(vlSelf->top__DOT__exception_handler__DOT__handling_exception));
        bufp->chgIData(oldp+131,(vlSelf->top__DOT__exu__DOT__alu_src1),32);
        bufp->chgIData(oldp+132,(vlSelf->top__DOT__exu__DOT__alu_src2),32);
        bufp->chgBit(oldp+133,((0x17U == (0x7fU & vlSelf->top__DOT__ex_instr))));
        bufp->chgBit(oldp+134,((0x6fU == (0x7fU & vlSelf->top__DOT__ex_instr))));
        bufp->chgIData(oldp+135,(vlSelf->top__DOT__exu__DOT__final_alu_src1),32);
        bufp->chgCData(oldp+136,((0x7fU & vlSelf->top__DOT__id_instr)),7);
        bufp->chgCData(oldp+137,((7U & (vlSelf->top__DOT__id_instr 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+138,((vlSelf->top__DOT__id_instr 
                                  >> 0x19U)),7);
        bufp->chgBit(oldp+139,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0) 
                                & (1U == (vlSelf->top__DOT__id_instr 
                                          >> 0x14U)))));
        bufp->chgBit(oldp+140,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0) 
                                & (0U == (vlSelf->top__DOT__id_instr 
                                          >> 0x14U)))));
        bufp->chgBit(oldp+141,((0xfU == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgBit(oldp+142,(vlSelf->top__DOT__idu__DOT__is_csrrw));
        bufp->chgBit(oldp+143,(((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                & (0x2000U == (0x3000U 
                                               & vlSelf->top__DOT__id_instr)))));
        bufp->chgBit(oldp+144,(((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                & (0x3000U == (0x3000U 
                                               & vlSelf->top__DOT__id_instr)))));
        bufp->chgBit(oldp+145,((0x33U == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgBit(oldp+146,(vlSelf->top__DOT__idu__DOT__is_i_type));
        bufp->chgBit(oldp+147,(vlSelf->top__DOT__idu__DOT__is_u_type));
        bufp->chgBit(oldp+148,((0x6fU == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgBit(oldp+149,((0x37U == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgBit(oldp+150,((0x17U == (0x7fU & vlSelf->top__DOT__id_instr))));
        bufp->chgIData(oldp+151,((((- (IData)((vlSelf->top__DOT__id_instr 
                                               >> 0x1fU))) 
                                   << 0xcU) | (vlSelf->top__DOT__id_instr 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+152,((((- (IData)((vlSelf->top__DOT__id_instr 
                                               >> 0x1fU))) 
                                   << 0xcU) | ((0xfe0U 
                                                & (vlSelf->top__DOT__id_instr 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelf->top__DOT__id_instr 
                                                     >> 7U))))),32);
        bufp->chgIData(oldp+153,((((- (IData)((vlSelf->top__DOT__id_instr 
                                               >> 0x1fU))) 
                                   << 0xdU) | ((0x1000U 
                                                & (vlSelf->top__DOT__id_instr 
                                                   >> 0x13U)) 
                                               | ((0x800U 
                                                   & (vlSelf->top__DOT__id_instr 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (vlSelf->top__DOT__id_instr 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlSelf->top__DOT__id_instr 
                                                           >> 7U))))))),32);
        bufp->chgIData(oldp+154,((0xfffff000U & vlSelf->top__DOT__id_instr)),32);
        bufp->chgIData(oldp+155,((((- (IData)((vlSelf->top__DOT__id_instr 
                                               >> 0x1fU))) 
                                   << 0x15U) | ((0x100000U 
                                                 & (vlSelf->top__DOT__id_instr 
                                                    >> 0xbU)) 
                                                | ((0xff000U 
                                                    & vlSelf->top__DOT__id_instr) 
                                                   | ((0x800U 
                                                       & (vlSelf->top__DOT__id_instr 
                                                          >> 9U)) 
                                                      | (0x7feU 
                                                         & (vlSelf->top__DOT__id_instr 
                                                            >> 0x14U))))))),32);
        bufp->chgIData(oldp+156,((0x1fU & (vlSelf->top__DOT__id_instr 
                                           >> 0xfU))),32);
        bufp->chgCData(oldp+157,((((IData)(vlSelf->top__DOT__mem_mem_unsigned) 
                                   << 2U) | (3U & (IData)(vlSelf->top__DOT__mem_mem_type)))),3);
        bufp->chgCData(oldp+158,(vlSelf->top__DOT__memu__DOT__byte_en),4);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__regfile__DOT__registers
                                 [0xaU]),32);
        bufp->chgIData(oldp+160,(vlSelf->top__DOT__regfile__DOT__registers[0]),32);
        bufp->chgIData(oldp+161,(vlSelf->top__DOT__regfile__DOT__registers[1]),32);
        bufp->chgIData(oldp+162,(vlSelf->top__DOT__regfile__DOT__registers[2]),32);
        bufp->chgIData(oldp+163,(vlSelf->top__DOT__regfile__DOT__registers[3]),32);
        bufp->chgIData(oldp+164,(vlSelf->top__DOT__regfile__DOT__registers[4]),32);
        bufp->chgIData(oldp+165,(vlSelf->top__DOT__regfile__DOT__registers[5]),32);
        bufp->chgIData(oldp+166,(vlSelf->top__DOT__regfile__DOT__registers[6]),32);
        bufp->chgIData(oldp+167,(vlSelf->top__DOT__regfile__DOT__registers[7]),32);
        bufp->chgIData(oldp+168,(vlSelf->top__DOT__regfile__DOT__registers[8]),32);
        bufp->chgIData(oldp+169,(vlSelf->top__DOT__regfile__DOT__registers[9]),32);
        bufp->chgIData(oldp+170,(vlSelf->top__DOT__regfile__DOT__registers[10]),32);
        bufp->chgIData(oldp+171,(vlSelf->top__DOT__regfile__DOT__registers[11]),32);
        bufp->chgIData(oldp+172,(vlSelf->top__DOT__regfile__DOT__registers[12]),32);
        bufp->chgIData(oldp+173,(vlSelf->top__DOT__regfile__DOT__registers[13]),32);
        bufp->chgIData(oldp+174,(vlSelf->top__DOT__regfile__DOT__registers[14]),32);
        bufp->chgIData(oldp+175,(vlSelf->top__DOT__regfile__DOT__registers[15]),32);
        bufp->chgIData(oldp+176,(vlSelf->top__DOT__regfile__DOT__registers[16]),32);
        bufp->chgIData(oldp+177,(vlSelf->top__DOT__regfile__DOT__registers[17]),32);
        bufp->chgIData(oldp+178,(vlSelf->top__DOT__regfile__DOT__registers[18]),32);
        bufp->chgIData(oldp+179,(vlSelf->top__DOT__regfile__DOT__registers[19]),32);
        bufp->chgIData(oldp+180,(vlSelf->top__DOT__regfile__DOT__registers[20]),32);
        bufp->chgIData(oldp+181,(vlSelf->top__DOT__regfile__DOT__registers[21]),32);
        bufp->chgIData(oldp+182,(vlSelf->top__DOT__regfile__DOT__registers[22]),32);
        bufp->chgIData(oldp+183,(vlSelf->top__DOT__regfile__DOT__registers[23]),32);
        bufp->chgIData(oldp+184,(vlSelf->top__DOT__regfile__DOT__registers[24]),32);
        bufp->chgIData(oldp+185,(vlSelf->top__DOT__regfile__DOT__registers[25]),32);
        bufp->chgIData(oldp+186,(vlSelf->top__DOT__regfile__DOT__registers[26]),32);
        bufp->chgIData(oldp+187,(vlSelf->top__DOT__regfile__DOT__registers[27]),32);
        bufp->chgIData(oldp+188,(vlSelf->top__DOT__regfile__DOT__registers[28]),32);
        bufp->chgIData(oldp+189,(vlSelf->top__DOT__regfile__DOT__registers[29]),32);
        bufp->chgIData(oldp+190,(vlSelf->top__DOT__regfile__DOT__registers[30]),32);
        bufp->chgIData(oldp+191,(vlSelf->top__DOT__regfile__DOT__registers[31]),32);
        bufp->chgIData(oldp+192,(vlSelf->top__DOT__regfile__DOT__i),32);
    }
    bufp->chgBit(oldp+193,(vlSelf->clk));
    bufp->chgBit(oldp+194,(vlSelf->rst));
    bufp->chgIData(oldp+195,(vlSelf->imem_addr),32);
    bufp->chgIData(oldp+196,(vlSelf->imem_rdata),32);
    bufp->chgBit(oldp+197,(vlSelf->imem_valid));
    bufp->chgIData(oldp+198,(vlSelf->dmem_addr),32);
    bufp->chgIData(oldp+199,(vlSelf->dmem_rdata),32);
    bufp->chgIData(oldp+200,(vlSelf->dmem_wdata),32);
    bufp->chgBit(oldp+201,(vlSelf->dmem_valid));
    bufp->chgCData(oldp+202,(vlSelf->dmem_wen),4);
    bufp->chgIData(oldp+203,(vlSelf->top__DOT__mem_read_data),32);
    bufp->chgIData(oldp+204,(((2U & (IData)(vlSelf->top__DOT__mem_wb_sel))
                               ? ((1U & (IData)(vlSelf->top__DOT__mem_wb_sel))
                                   ? vlSelf->top__DOT__mem_csr_rdata
                                   : ((IData)(4U) + vlSelf->top__DOT__mem_pc))
                               : ((1U & (IData)(vlSelf->top__DOT__mem_wb_sel))
                                   ? vlSelf->top__DOT__mem_read_data
                                   : vlSelf->top__DOT__mem_alu_result))),32);
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
}
