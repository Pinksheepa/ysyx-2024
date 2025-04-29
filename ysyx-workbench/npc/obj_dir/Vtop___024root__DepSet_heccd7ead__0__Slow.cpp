// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->imem_valid = 1U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 2, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*2:0*/, 32> Vtop__ConstPool__TABLE_h95502e58_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vtop__ConstPool__TABLE_h952cab83_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->imem_addr = vlSelf->top__DOT__pc;
    vlSelf->top__DOT__pc_plus4 = ((IData)(4U) + vlSelf->top__DOT__pc);
    vlSelf->dmem_addr = vlSelf->top__DOT__mem_alu_result;
    vlSelf->dmem_wdata = vlSelf->top__DOT__mem_rs2_data;
    vlSelf->top__DOT__idu__DOT__is_u_type = ((0x37U 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__id_instr)) 
                                             | (0x17U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__id_instr)));
    vlSelf->dmem_valid = ((IData)(vlSelf->top__DOT__mem_mem_ren) 
                          | (IData)(vlSelf->top__DOT__mem_mem_wen));
    if (vlSelf->top__DOT__mem_mem_ren) {
        if ((0U == (3U & (IData)(vlSelf->top__DOT__mem_mem_type)))) {
            vlSelf->top__DOT__mem_read_data = ((2U 
                                                & vlSelf->top__DOT__mem_alu_result)
                                                ? (
                                                   (1U 
                                                    & vlSelf->top__DOT__mem_alu_result)
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__mem_mem_unsigned)
                                                     ? 
                                                    (vlSelf->dmem_rdata 
                                                     >> 0x18U)
                                                     : 
                                                    (((- (IData)(
                                                                 (vlSelf->dmem_rdata 
                                                                  >> 0x1fU))) 
                                                      << 8U) 
                                                     | (vlSelf->dmem_rdata 
                                                        >> 0x18U)))
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__mem_mem_unsigned)
                                                     ? 
                                                    (0xffU 
                                                     & (vlSelf->dmem_rdata 
                                                        >> 0x10U))
                                                     : 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & (vlSelf->dmem_rdata 
                                                                     >> 0x17U)))) 
                                                      << 8U) 
                                                     | (0xffU 
                                                        & (vlSelf->dmem_rdata 
                                                           >> 0x10U)))))
                                                : (
                                                   (1U 
                                                    & vlSelf->top__DOT__mem_alu_result)
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__mem_mem_unsigned)
                                                     ? 
                                                    (0xffU 
                                                     & (vlSelf->dmem_rdata 
                                                        >> 8U))
                                                     : 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & (vlSelf->dmem_rdata 
                                                                     >> 0xfU)))) 
                                                      << 8U) 
                                                     | (0xffU 
                                                        & (vlSelf->dmem_rdata 
                                                           >> 8U))))
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__mem_mem_unsigned)
                                                     ? 
                                                    (0xffU 
                                                     & vlSelf->dmem_rdata)
                                                     : 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & (vlSelf->dmem_rdata 
                                                                     >> 7U)))) 
                                                      << 8U) 
                                                     | (0xffU 
                                                        & vlSelf->dmem_rdata)))));
        } else if ((1U == (3U & (IData)(vlSelf->top__DOT__mem_mem_type)))) {
            if ((2U & vlSelf->top__DOT__mem_alu_result)) {
                if ((2U & vlSelf->top__DOT__mem_alu_result)) {
                    vlSelf->top__DOT__mem_read_data 
                        = ((IData)(vlSelf->top__DOT__mem_mem_unsigned)
                            ? (vlSelf->dmem_rdata >> 0x10U)
                            : (((- (IData)((vlSelf->dmem_rdata 
                                            >> 0x1fU))) 
                                << 0x10U) | (vlSelf->dmem_rdata 
                                             >> 0x10U)));
                }
            } else {
                vlSelf->top__DOT__mem_read_data = ((IData)(vlSelf->top__DOT__mem_mem_unsigned)
                                                    ? 
                                                   (0xffffU 
                                                    & vlSelf->dmem_rdata)
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->dmem_rdata 
                                                                    >> 0xfU)))) 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & vlSelf->dmem_rdata)));
            }
        } else {
            vlSelf->top__DOT__mem_read_data = ((2U 
                                                == 
                                                (3U 
                                                 & (IData)(vlSelf->top__DOT__mem_mem_type)))
                                                ? vlSelf->dmem_rdata
                                                : 0U);
        }
    } else {
        vlSelf->top__DOT__mem_read_data = 0U;
    }
    if (vlSelf->top__DOT__mem_mem_wen) {
        if ((0U == (3U & (IData)(vlSelf->top__DOT__mem_mem_type)))) {
            vlSelf->top__DOT__memu__DOT__byte_en = 
                ((2U & vlSelf->top__DOT__mem_alu_result)
                  ? ((1U & vlSelf->top__DOT__mem_alu_result)
                      ? 8U : 4U) : ((1U & vlSelf->top__DOT__mem_alu_result)
                                     ? 2U : 1U));
        } else if ((1U == (3U & (IData)(vlSelf->top__DOT__mem_mem_type)))) {
            if ((2U & vlSelf->top__DOT__mem_alu_result)) {
                if ((2U & vlSelf->top__DOT__mem_alu_result)) {
                    vlSelf->top__DOT__memu__DOT__byte_en = 0xcU;
                }
            } else {
                vlSelf->top__DOT__memu__DOT__byte_en = 3U;
            }
        } else {
            vlSelf->top__DOT__memu__DOT__byte_en = 
                ((2U == (3U & (IData)(vlSelf->top__DOT__mem_mem_type)))
                  ? 0xfU : 0U);
        }
        vlSelf->dmem_wen = vlSelf->top__DOT__memu__DOT__byte_en;
    } else {
        vlSelf->top__DOT__memu__DOT__byte_en = 0U;
        vlSelf->dmem_wen = 0U;
    }
    vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard 
        = ((IData)(vlSelf->top__DOT__ex_mem_ren) & 
           ((0U != (IData)(vlSelf->top__DOT__ex_rd)) 
            & (((IData)(vlSelf->top__DOT__ex_rd) == 
                (0x1fU & (vlSelf->top__DOT__id_instr 
                          >> 0xfU))) | ((IData)(vlSelf->top__DOT__ex_rd) 
                                        == (0x1fU & 
                                            (vlSelf->top__DOT__id_instr 
                                             >> 0x14U))))));
    vlSelf->top__DOT__mem_csr_rdata = ((IData)(vlSelf->top__DOT__mem_csr_ren)
                                        ? (((((((((0x300U 
                                                   == (IData)(vlSelf->top__DOT__mem_csr_addr)) 
                                                  | (0x301U 
                                                     == (IData)(vlSelf->top__DOT__mem_csr_addr))) 
                                                 | (0x305U 
                                                    == (IData)(vlSelf->top__DOT__mem_csr_addr))) 
                                                | (0x340U 
                                                   == (IData)(vlSelf->top__DOT__mem_csr_addr))) 
                                               | (0x341U 
                                                  == (IData)(vlSelf->top__DOT__mem_csr_addr))) 
                                              | (0x342U 
                                                 == (IData)(vlSelf->top__DOT__mem_csr_addr))) 
                                             | (0x343U 
                                                == (IData)(vlSelf->top__DOT__mem_csr_addr))) 
                                            | (0xb00U 
                                               == (IData)(vlSelf->top__DOT__mem_csr_addr)))
                                            ? ((0x300U 
                                                == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                ? vlSelf->top__DOT__csr_file__DOT__mstatus
                                                : (
                                                   (0x301U 
                                                    == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                    ? vlSelf->top__DOT__csr_file__DOT__misa
                                                    : 
                                                   ((0x305U 
                                                     == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                     ? vlSelf->top__DOT__csr_file__DOT__mtvec
                                                     : 
                                                    ((0x340U 
                                                      == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                      ? vlSelf->top__DOT__csr_file__DOT__mscratch
                                                      : 
                                                     ((0x341U 
                                                       == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                       ? vlSelf->top__DOT__csr_file__DOT__mepc
                                                       : 
                                                      ((0x342U 
                                                        == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                        ? vlSelf->top__DOT__csr_file__DOT__mcause
                                                        : 
                                                       ((0x343U 
                                                         == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                         ? vlSelf->top__DOT__csr_file__DOT__mtval
                                                         : vlSelf->top__DOT__csr_file__DOT__mcycle)))))))
                                            : ((0xb80U 
                                                == (IData)(vlSelf->top__DOT__mem_csr_addr))
                                                ? vlSelf->top__DOT__csr_file__DOT__mcycleh
                                                : 0U))
                                        : 0U);
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0 
        = (IData)((0x73U == (0x707fU & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__idu__DOT____VdfgExtracted_h2ec28fd3__0 
        = ((3U == (0x7fU & vlSelf->top__DOT__id_instr)) 
           | (0x23U == (0x7fU & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT____VdfgTmp_h0197263e__0 = (IData)(
                                                       (0x73U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->top__DOT__wb_instr)));
    vlSelf->top__DOT__id_is_jalr = (IData)((0x67U == 
                                            (0x707fU 
                                             & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__idu__DOT__is_csr = ((0x73U == 
                                           (0x7fU & vlSelf->top__DOT__id_instr)) 
                                          & (0U != 
                                             (7U & 
                                              (vlSelf->top__DOT__id_instr 
                                               >> 0xcU))));
    vlSelf->top__DOT__forward_b = 0U;
    if ((((IData)(vlSelf->top__DOT__mem_reg_wen) & 
          (0U != (IData)(vlSelf->top__DOT__mem_rd))) 
         & ((IData)(vlSelf->top__DOT__mem_rd) == (IData)(vlSelf->top__DOT__ex_rs2)))) {
        vlSelf->top__DOT__forward_b = 1U;
    } else if ((((IData)(vlSelf->top__DOT__wb_reg_wen) 
                 & (0U != (IData)(vlSelf->top__DOT__wb_rd))) 
                & ((IData)(vlSelf->top__DOT__wb_rd) 
                   == (IData)(vlSelf->top__DOT__ex_rs2)))) {
        vlSelf->top__DOT__forward_b = 2U;
    }
    vlSelf->top__DOT__forward_a = 0U;
    if ((((IData)(vlSelf->top__DOT__mem_reg_wen) & 
          (0U != (IData)(vlSelf->top__DOT__mem_rd))) 
         & ((IData)(vlSelf->top__DOT__mem_rd) == (IData)(vlSelf->top__DOT__ex_rs1)))) {
        vlSelf->top__DOT__forward_a = 1U;
    } else if ((((IData)(vlSelf->top__DOT__wb_reg_wen) 
                 & (0U != (IData)(vlSelf->top__DOT__wb_rd))) 
                & ((IData)(vlSelf->top__DOT__wb_rd) 
                   == (IData)(vlSelf->top__DOT__ex_rs1)))) {
        vlSelf->top__DOT__forward_a = 2U;
    }
    vlSelf->top__DOT__wb_data = ((2U & (IData)(vlSelf->top__DOT__wb_wb_sel))
                                  ? ((1U & (IData)(vlSelf->top__DOT__wb_wb_sel))
                                      ? vlSelf->top__DOT__wb_csr_rdata
                                      : ((IData)(4U) 
                                         + vlSelf->top__DOT__wb_pc))
                                  : ((1U & (IData)(vlSelf->top__DOT__wb_wb_sel))
                                      ? vlSelf->top__DOT__wb_mem_rdata
                                      : vlSelf->top__DOT__wb_alu_result));
    vlSelf->top__DOT__flush_ex = ((IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard) 
                                  | (IData)(vlSelf->top__DOT__pipeline_flush_exc));
    vlSelf->__Vtableidx1 = ((0x10U & (vlSelf->top__DOT__id_instr 
                                      >> 0xaU)) | (
                                                   (0xeU 
                                                    & (vlSelf->top__DOT__id_instr 
                                                       >> 0xbU)) 
                                                   | (IData)(vlSelf->top__DOT__idu__DOT____VdfgExtracted_h2ec28fd3__0)));
    vlSelf->top__DOT__idu__DOT__mem_type_val = Vtop__ConstPool__TABLE_h95502e58_0
        [vlSelf->__Vtableidx1];
    vlSelf->top__DOT__idu__DOT__mem_unsigned_val = 
        Vtop__ConstPool__TABLE_h952cab83_0[vlSelf->__Vtableidx1];
    vlSelf->top__DOT__is_ecall = ((IData)(vlSelf->top__DOT____VdfgTmp_h0197263e__0) 
                                  & (0U == (vlSelf->top__DOT__wb_instr 
                                            >> 0x14U)));
    vlSelf->top__DOT__is_ebreak = ((IData)(vlSelf->top__DOT____VdfgTmp_h0197263e__0) 
                                   & (1U == (vlSelf->top__DOT__wb_instr 
                                             >> 0x14U)));
    vlSelf->top__DOT__id_jump = ((0x6fU == (0x7fU & vlSelf->top__DOT__id_instr)) 
                                 | (IData)(vlSelf->top__DOT__id_is_jalr));
    vlSelf->top__DOT__idu__DOT__is_csrrw = ((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                            & (0x1000U 
                                               == (0x3000U 
                                                   & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__idu__DOT__is_csr_imm = ((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                              & (vlSelf->top__DOT__id_instr 
                                                 >> 0xeU));
    vlSelf->top__DOT__idu__DOT__is_i_type = ((0x13U 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__id_instr)) 
                                             | ((3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__id_instr)) 
                                                | ((0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__id_instr)) 
                                                   | (IData)(vlSelf->top__DOT__idu__DOT__is_csr))));
    if ((0U == vlSelf->top__DOT__id_instr)) {
        vlSelf->top__DOT__idu__DOT__illegal_instr_reg = 0U;
    } else {
        vlSelf->top__DOT__idu__DOT__illegal_instr_reg = 1U;
        if (((((((((((((((((0x33U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                           & (1U != (vlSelf->top__DOT__id_instr 
                                     >> 0x19U))) & 
                          ((((((((IData)(((0U == (0x7000U 
                                                  & vlSelf->top__DOT__id_instr)) 
                                          & ((0U == 
                                              (vlSelf->top__DOT__id_instr 
                                               >> 0x19U)) 
                                             | (0x20U 
                                                == 
                                                (vlSelf->top__DOT__id_instr 
                                                 >> 0x19U))))) 
                                 | (IData)((0x1000U 
                                            == (0xfe007000U 
                                                & vlSelf->top__DOT__id_instr)))) 
                                | (IData)((0x2000U 
                                           == (0xfe007000U 
                                               & vlSelf->top__DOT__id_instr)))) 
                               | (IData)((0x3000U == 
                                          (0xfe007000U 
                                           & vlSelf->top__DOT__id_instr)))) 
                              | (IData)((0x4000U == 
                                         (0xfe007000U 
                                          & vlSelf->top__DOT__id_instr)))) 
                             | (IData)(((0x5000U == 
                                         (0x7000U & vlSelf->top__DOT__id_instr)) 
                                        & ((0U == (vlSelf->top__DOT__id_instr 
                                                   >> 0x19U)) 
                                           | (0x20U 
                                              == (vlSelf->top__DOT__id_instr 
                                                  >> 0x19U)))))) 
                            | (IData)((0x6000U == (0xfe007000U 
                                                   & vlSelf->top__DOT__id_instr)))) 
                           | (IData)((0x7000U == (0xfe007000U 
                                                  & vlSelf->top__DOT__id_instr))))) 
                         | ((IData)((0x2000033U == 
                                     (0xfe00007fU & vlSelf->top__DOT__id_instr))) 
                            & ((((((((0U == (7U & (vlSelf->top__DOT__id_instr 
                                                   >> 0xcU))) 
                                     | (1U == (7U & 
                                               (vlSelf->top__DOT__id_instr 
                                                >> 0xcU)))) 
                                    | (2U == (7U & 
                                              (vlSelf->top__DOT__id_instr 
                                               >> 0xcU)))) 
                                   | (3U == (7U & (vlSelf->top__DOT__id_instr 
                                                   >> 0xcU)))) 
                                  | (4U == (7U & (vlSelf->top__DOT__id_instr 
                                                  >> 0xcU)))) 
                                 | (5U == (7U & (vlSelf->top__DOT__id_instr 
                                                 >> 0xcU)))) 
                                | (6U == (7U & (vlSelf->top__DOT__id_instr 
                                                >> 0xcU)))) 
                               | (7U == (7U & (vlSelf->top__DOT__id_instr 
                                               >> 0xcU)))))) 
                        | ((0x13U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                           & ((((((((0U == (7U & (vlSelf->top__DOT__id_instr 
                                                  >> 0xcU))) 
                                    | (2U == (7U & 
                                              (vlSelf->top__DOT__id_instr 
                                               >> 0xcU)))) 
                                   | (3U == (7U & (vlSelf->top__DOT__id_instr 
                                                   >> 0xcU)))) 
                                  | (4U == (7U & (vlSelf->top__DOT__id_instr 
                                                  >> 0xcU)))) 
                                 | (6U == (7U & (vlSelf->top__DOT__id_instr 
                                                 >> 0xcU)))) 
                                | (7U == (7U & (vlSelf->top__DOT__id_instr 
                                                >> 0xcU)))) 
                               | (IData)((0x1000U == 
                                          (0xfe007000U 
                                           & vlSelf->top__DOT__id_instr)))) 
                              | (IData)(((0x5000U == 
                                          (0x7000U 
                                           & vlSelf->top__DOT__id_instr)) 
                                         & ((0U == 
                                             (vlSelf->top__DOT__id_instr 
                                              >> 0x19U)) 
                                            | (0x20U 
                                               == (vlSelf->top__DOT__id_instr 
                                                   >> 0x19U)))))))) 
                       | ((3U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                          & (((((0U == (7U & (vlSelf->top__DOT__id_instr 
                                              >> 0xcU))) 
                                | (1U == (7U & (vlSelf->top__DOT__id_instr 
                                                >> 0xcU)))) 
                               | (2U == (7U & (vlSelf->top__DOT__id_instr 
                                               >> 0xcU)))) 
                              | (4U == (7U & (vlSelf->top__DOT__id_instr 
                                              >> 0xcU)))) 
                             | (5U == (7U & (vlSelf->top__DOT__id_instr 
                                             >> 0xcU)))))) 
                      | ((0x23U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                         & (((0U == (7U & (vlSelf->top__DOT__id_instr 
                                           >> 0xcU))) 
                             | (1U == (7U & (vlSelf->top__DOT__id_instr 
                                             >> 0xcU)))) 
                            | (2U == (7U & (vlSelf->top__DOT__id_instr 
                                            >> 0xcU)))))) 
                     | ((0x63U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                        & ((((((0U == (7U & (vlSelf->top__DOT__id_instr 
                                             >> 0xcU))) 
                               | (1U == (7U & (vlSelf->top__DOT__id_instr 
                                               >> 0xcU)))) 
                              | (4U == (7U & (vlSelf->top__DOT__id_instr 
                                              >> 0xcU)))) 
                             | (5U == (7U & (vlSelf->top__DOT__id_instr 
                                             >> 0xcU)))) 
                            | (6U == (7U & (vlSelf->top__DOT__id_instr 
                                            >> 0xcU)))) 
                           | (7U == (7U & (vlSelf->top__DOT__id_instr 
                                           >> 0xcU)))))) 
                    | (IData)(vlSelf->top__DOT__id_is_jalr)) 
                   | (0x37U == (0x7fU & vlSelf->top__DOT__id_instr))) 
                  | (0x17U == (0x7fU & vlSelf->top__DOT__id_instr))) 
                 | (0x6fU == (0x7fU & vlSelf->top__DOT__id_instr))) 
                | (0xfU == (0x7fU & vlSelf->top__DOT__id_instr))) 
               | (IData)(vlSelf->top__DOT__idu__DOT__is_csr)) 
              | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0) 
                 & (0U == (vlSelf->top__DOT__id_instr 
                           >> 0x14U)))) | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0) 
                                           & (1U == 
                                              (vlSelf->top__DOT__id_instr 
                                               >> 0x14U))))) {
            vlSelf->top__DOT__idu__DOT__illegal_instr_reg = 0U;
        }
    }
    vlSelf->top__DOT__exu__DOT__forwarded_rs2_data 
        = ((0U == (IData)(vlSelf->top__DOT__forward_b))
            ? vlSelf->top__DOT__ex_rs2_data : ((1U 
                                                == (IData)(vlSelf->top__DOT__forward_b))
                                                ? vlSelf->top__DOT__mem_alu_result
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelf->top__DOT__forward_b))
                                                    ? vlSelf->top__DOT__wb_data
                                                    : vlSelf->top__DOT__ex_rs2_data)));
    vlSelf->top__DOT__exu__DOT__alu_src1 = ((0U == (IData)(vlSelf->top__DOT__forward_a))
                                             ? vlSelf->top__DOT__ex_rs1_data
                                             : ((1U 
                                                 == (IData)(vlSelf->top__DOT__forward_a))
                                                 ? vlSelf->top__DOT__mem_alu_result
                                                 : 
                                                ((2U 
                                                  == (IData)(vlSelf->top__DOT__forward_a))
                                                  ? vlSelf->top__DOT__wb_data
                                                  : vlSelf->top__DOT__ex_rs1_data)));
    vlSelf->top__DOT__wb_valid = ((IData)(vlSelf->top__DOT__wb_reg_wen) 
                                  | ((IData)(vlSelf->top__DOT__wb_mem_ren) 
                                     | ((IData)(vlSelf->top__DOT__is_ecall) 
                                        | (IData)(vlSelf->top__DOT__is_ebreak))));
    vlSelf->top__DOT__idu__DOT__alu_op_val = ((0x33U 
                                               == (0x7fU 
                                                   & vlSelf->top__DOT__id_instr))
                                               ? ((0x40000000U 
                                                   & vlSelf->top__DOT__id_instr)
                                                   ? 
                                                  ((0x4000U 
                                                    & vlSelf->top__DOT__id_instr)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 7U
                                                      : 0U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 0U
                                                      : 1U)))
                                                   : 
                                                  ((0x4000U 
                                                    & vlSelf->top__DOT__id_instr)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->top__DOT__id_instr)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 2U
                                                      : 3U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 6U
                                                      : 4U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->top__DOT__id_instr)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 9U
                                                      : 8U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 5U
                                                      : 0U))))
                                               : ((
                                                   (~ 
                                                    ((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__id_instr)) 
                                                     | ((IData)(vlSelf->top__DOT__id_is_jalr) 
                                                        | (IData)(vlSelf->top__DOT__idu__DOT__is_csr)))) 
                                                   & (IData)(vlSelf->top__DOT__idu__DOT__is_i_type))
                                                   ? 
                                                  ((0x4000U 
                                                    & vlSelf->top__DOT__id_instr)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->top__DOT__id_instr)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 2U
                                                      : 3U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 
                                                     ((0x40000000U 
                                                       & vlSelf->top__DOT__id_instr)
                                                       ? 7U
                                                       : 6U)
                                                      : 4U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->top__DOT__id_instr)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 9U
                                                      : 8U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 5U
                                                      : 0U)))
                                                   : 
                                                  (((IData)(vlSelf->top__DOT__idu__DOT____VdfgExtracted_h2ec28fd3__0) 
                                                    | (IData)(vlSelf->top__DOT__id_is_jalr))
                                                    ? 0U
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__id_instr))
                                                     ? 
                                                    ((0x4000U 
                                                      & vlSelf->top__DOT__id_instr)
                                                      ? 
                                                     ((0x2000U 
                                                       & vlSelf->top__DOT__id_instr)
                                                       ? 9U
                                                       : 8U)
                                                      : 1U)
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__id_instr))
                                                      ? 0xaU
                                                      : 
                                                     ((0x17U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->top__DOT__id_instr))
                                                       ? 0U
                                                       : 
                                                      ((IData)(vlSelf->top__DOT__idu__DOT__is_csr)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlSelf->top__DOT__id_instr)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlSelf->top__DOT__id_instr)
                                                          ? 0xcU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelf->top__DOT__id_instr)
                                                           ? 0xcU
                                                           : 0U))
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelf->top__DOT__id_instr)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelf->top__DOT__id_instr)
                                                           ? 0xbU
                                                           : 0U)))
                                                        : 0U)))))));
    vlSelf->top__DOT__exception_handler__DOT__exception_detected = 0U;
    vlSelf->top__DOT__exception_handler__DOT__detected_exception_code = 0U;
    vlSelf->top__DOT__exception_handler__DOT__detected_exception_val = 0U;
    if (vlSelf->top__DOT__idu__DOT__illegal_instr_reg) {
        vlSelf->top__DOT__exception_handler__DOT__exception_detected = 1U;
        vlSelf->top__DOT__exception_handler__DOT__detected_exception_code = 2U;
        vlSelf->top__DOT__exception_handler__DOT__detected_exception_val 
            = vlSelf->top__DOT__id_instr;
    }
    vlSelf->top__DOT__exu__DOT__alu_src2 = ((IData)(vlSelf->top__DOT__ex_use_imm)
                                             ? vlSelf->top__DOT__ex_imm
                                             : vlSelf->top__DOT__exu__DOT__forwarded_rs2_data);
    vlSelf->top__DOT__exu__DOT__branch_taken_reg = 
        ((IData)(vlSelf->top__DOT__ex_branch) ? ((0x4000U 
                                                  & vlSelf->top__DOT__ex_instr)
                                                  ? 
                                                 ((0x2000U 
                                                   & vlSelf->top__DOT__ex_instr)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->top__DOT__ex_instr)
                                                    ? 
                                                   (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                    >= vlSelf->top__DOT__exu__DOT__forwarded_rs2_data)
                                                    : 
                                                   (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                    < vlSelf->top__DOT__exu__DOT__forwarded_rs2_data))
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->top__DOT__ex_instr)
                                                    ? 
                                                   VL_GTES_III(32, vlSelf->top__DOT__exu__DOT__alu_src1, vlSelf->top__DOT__exu__DOT__forwarded_rs2_data)
                                                    : 
                                                   VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu_src1, vlSelf->top__DOT__exu__DOT__forwarded_rs2_data)))
                                                  : 
                                                 ((~ 
                                                   (vlSelf->top__DOT__ex_instr 
                                                    >> 0xdU)) 
                                                  & ((0x1000U 
                                                      & vlSelf->top__DOT__ex_instr)
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      != vlSelf->top__DOT__exu__DOT__forwarded_rs2_data)
                                                      : 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      == vlSelf->top__DOT__exu__DOT__forwarded_rs2_data))))
          : (IData)(vlSelf->top__DOT__ex_jump));
    vlSelf->top__DOT__exu__DOT__final_alu_src1 = ((
                                                   (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__ex_instr)) 
                                                   | ((0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->top__DOT__ex_instr)) 
                                                      | (IData)(vlSelf->top__DOT__ex_is_jalr)))
                                                   ? vlSelf->top__DOT__ex_pc
                                                   : vlSelf->top__DOT__exu__DOT__alu_src1);
    vlSelf->top__DOT__flush_if = (((IData)(vlSelf->top__DOT__ex_jump) 
                                   | (IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg)) 
                                  | (IData)(vlSelf->top__DOT__pipeline_flush_exc));
    vlSelf->top__DOT__exu__DOT____VdfgExtracted_ha5b322d2__0 
        = (vlSelf->top__DOT__exu__DOT__final_alu_src1 
           + vlSelf->top__DOT__exu__DOT__alu_src2);
    vlSelf->top__DOT__exu__DOT__alu_result_reg = ((8U 
                                                   & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                     ? vlSelf->top__DOT__exu__DOT____VdfgExtracted_ha5b322d2__0
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                      ? vlSelf->top__DOT__exu__DOT____VdfgExtracted_ha5b322d2__0
                                                      : vlSelf->top__DOT__exu__DOT__alu_src2))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                      ? vlSelf->top__DOT__exu__DOT__final_alu_src1
                                                      : vlSelf->top__DOT__exu__DOT__alu_src2)
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__final_alu_src1 
                                                      < vlSelf->top__DOT__exu__DOT__alu_src2)
                                                      : 
                                                     VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__final_alu_src1, vlSelf->top__DOT__exu__DOT__alu_src2))))
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__final_alu_src1, 
                                                                    (0x1fU 
                                                                     & vlSelf->top__DOT__exu__DOT__alu_src2))
                                                      : 
                                                     (vlSelf->top__DOT__exu__DOT__final_alu_src1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->top__DOT__exu__DOT__alu_src2)))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__final_alu_src1 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelf->top__DOT__exu__DOT__alu_src2))
                                                      : 
                                                     (vlSelf->top__DOT__exu__DOT__final_alu_src1 
                                                      ^ vlSelf->top__DOT__exu__DOT__alu_src2)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__final_alu_src1 
                                                      | vlSelf->top__DOT__exu__DOT__alu_src2)
                                                      : 
                                                     (vlSelf->top__DOT__exu__DOT__final_alu_src1 
                                                      & vlSelf->top__DOT__exu__DOT__alu_src2))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__ex_alu_op))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__final_alu_src1 
                                                      - vlSelf->top__DOT__exu__DOT__alu_src2)
                                                      : vlSelf->top__DOT__exu__DOT____VdfgExtracted_ha5b322d2__0))));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->imem_addr = VL_RAND_RESET_I(32);
    vlSelf->imem_rdata = VL_RAND_RESET_I(32);
    vlSelf->imem_valid = VL_RAND_RESET_I(1);
    vlSelf->dmem_addr = VL_RAND_RESET_I(32);
    vlSelf->dmem_rdata = VL_RAND_RESET_I(32);
    vlSelf->dmem_wdata = VL_RAND_RESET_I(32);
    vlSelf->dmem_valid = VL_RAND_RESET_I(1);
    vlSelf->dmem_wen = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__is_ecall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__is_ebreak = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__flush_if = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__flush_ex = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exception_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exception_code = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__exception_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exception_val = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exception_redirect = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exception_target = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pipeline_flush_exc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_plus4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_jump = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_is_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_rs1_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__ex_rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__ex_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__ex_imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_reg_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_ren = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_alu_op = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ex_use_imm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_jump = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_is_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_type = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ex_mem_unsigned = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_wb_sel = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ex_csr_ren = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_csr_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_csr_addr = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__ex_illegal_instr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_csr_imm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_csr_op = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__forward_a = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__forward_b = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_alu_result = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__mem_rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__mem_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__mem_reg_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_mem_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_mem_ren = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_branch_taken = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_funct3 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__mem_mem_type = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__mem_mem_unsigned = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_wb_sel = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_csr_ren = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_csr_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_csr_addr = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__mem_csr_op = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_csr_imm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_csr_write_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_read_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_csr_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wb_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wb_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wb_alu_result = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wb_mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wb_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__wb_reg_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_mem_ren = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_wb_sel = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__wb_mem_unsigned = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_csr_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wb_csr_ren = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_csr_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_csr_addr = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__wb_csr_op = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__wb_csr_imm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wb_csr_write_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____VdfgTmp_h0197263e__0 = 0;
    vlSelf->top__DOT__exception_handler__DOT__exception_detected = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exception_handler__DOT__detected_exception_code = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__exception_handler__DOT__detected_exception_val = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exception_handler__DOT__handling_exception = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dpi_system__DOT__terminate_reg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dpi_system__DOT__ecall_handled = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dpi_system__DOT__ebreak_handled = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regfile__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu__DOT__is_csr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__is_csrrw = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__is_csr_imm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__is_u_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__alu_op_val = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__idu__DOT__mem_type_val = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__idu__DOT__mem_unsigned_val = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__illegal_instr_reg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT____VdfgExtracted_h2ec28fd3__0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0 = 0;
    vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__forwarded_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu_src2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__final_alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu_result_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__branch_taken_reg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT____VdfgExtracted_ha5b322d2__0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mstatus = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__misa = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mscratch = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mepc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mcause = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mtval = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mcycle = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__csr_file__DOT__mcycleh = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__memu__DOT__byte_en = VL_RAND_RESET_I(4);
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
