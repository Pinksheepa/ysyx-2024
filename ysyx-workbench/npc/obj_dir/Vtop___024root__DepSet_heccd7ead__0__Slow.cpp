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

extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_hb2728f61_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ top__DOT__exu__DOT____VdfgExtracted_h34086c27__0;
    top__DOT__exu__DOT____VdfgExtracted_h34086c27__0 = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->imem_addr = vlSelf->top__DOT__pc;
    vlSelf->dmem_valid = ((3U == (0x7fU & vlSelf->imem_rdata)) 
                          | (0x23U == (0x7fU & vlSelf->imem_rdata)));
    vlSelf->top__DOT__exu__DOT__alu_src1 = ((0U == 
                                             (0x1fU 
                                              & (vlSelf->imem_rdata 
                                                 >> 0xfU)))
                                             ? 0U : 
                                            vlSelf->top__DOT__exu__DOT__regfile__DOT__registers
                                            [(0x1fU 
                                              & (vlSelf->imem_rdata 
                                                 >> 0xfU))]);
    vlSelf->top__DOT__rs2_data = ((0U == (0x1fU & (vlSelf->imem_rdata 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->top__DOT__exu__DOT__regfile__DOT__registers
                                  [(0x1fU & (vlSelf->imem_rdata 
                                             >> 0x14U))]);
    vlSelf->top__DOT__is_jalr = (IData)((0x67U == (0x707fU 
                                                   & vlSelf->imem_rdata)));
    vlSelf->top__DOT__idu__DOT__is_u_type = ((0x37U 
                                              == (0x7fU 
                                                  & vlSelf->imem_rdata)) 
                                             | (0x17U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->imem_rdata)));
    vlSelf->top__DOT__idu__DOT__is_i_type = ((0x13U 
                                              == (0x7fU 
                                                  & vlSelf->imem_rdata)) 
                                             | ((3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->imem_rdata)) 
                                                | (0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->imem_rdata))));
    vlSelf->top__DOT__jump = ((0x6fU == (0x7fU & vlSelf->imem_rdata)) 
                              | (IData)(vlSelf->top__DOT__is_jalr));
    vlSelf->top__DOT__idu__DOT__alu_op_val = ((0x33U 
                                               == (0x7fU 
                                                   & vlSelf->imem_rdata))
                                               ? ((0x40000000U 
                                                   & vlSelf->imem_rdata)
                                                   ? 
                                                  ((0x4000U 
                                                    & vlSelf->imem_rdata)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->imem_rdata)
                                                     ? 0U
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 7U
                                                      : 0U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->imem_rdata)
                                                     ? 0U
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 0U
                                                      : 1U)))
                                                   : 
                                                  ((0x4000U 
                                                    & vlSelf->imem_rdata)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->imem_rdata)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 2U
                                                      : 3U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 6U
                                                      : 4U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->imem_rdata)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 9U
                                                      : 8U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 5U
                                                      : 0U))))
                                               : ((
                                                   (~ 
                                                    ((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->imem_rdata)) 
                                                     | (IData)(vlSelf->top__DOT__is_jalr))) 
                                                   & (IData)(vlSelf->top__DOT__idu__DOT__is_i_type))
                                                   ? 
                                                  ((0x4000U 
                                                    & vlSelf->imem_rdata)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->imem_rdata)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 2U
                                                      : 3U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 
                                                     ((0x40000000U 
                                                       & vlSelf->imem_rdata)
                                                       ? 7U
                                                       : 6U)
                                                      : 4U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->imem_rdata)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 9U
                                                      : 8U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 5U
                                                      : 0U)))
                                                   : 
                                                  (((3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->imem_rdata)) 
                                                    | ((0x23U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelf->imem_rdata)) 
                                                       | (IData)(vlSelf->top__DOT__is_jalr)))
                                                    ? 0U
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->imem_rdata))
                                                     ? 
                                                    ((0x4000U 
                                                      & vlSelf->imem_rdata)
                                                      ? 
                                                     ((0x2000U 
                                                       & vlSelf->imem_rdata)
                                                       ? 9U
                                                       : 8U)
                                                      : 1U)
                                                     : 0U))));
    vlSelf->top__DOT__idu__DOT__imm_val = ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type)
                                            ? (((- (IData)(
                                                           (vlSelf->imem_rdata 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelf->imem_rdata 
                                                  >> 0x14U))
                                            : ((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->imem_rdata))
                                                ? (
                                                   ((- (IData)(
                                                               (vlSelf->imem_rdata 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelf->imem_rdata 
                                                          >> 0x14U)) 
                                                      | (0x1fU 
                                                         & (vlSelf->imem_rdata 
                                                            >> 7U))))
                                                : (
                                                   (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->imem_rdata))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->imem_rdata 
                                                                 >> 0x1fU))) 
                                                     << 0xdU) 
                                                    | ((0x1000U 
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
                                                                   >> 7U))))))
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type)
                                                     ? 
                                                    (0xfffff000U 
                                                     & vlSelf->imem_rdata)
                                                     : 
                                                    ((0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->imem_rdata))
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->imem_rdata 
                                                                   >> 0x1fU))) 
                                                       << 0x15U) 
                                                      | ((0x100000U 
                                                          & (vlSelf->imem_rdata 
                                                             >> 0xbU)) 
                                                         | ((0xff000U 
                                                             & vlSelf->imem_rdata) 
                                                            | ((0x800U 
                                                                & (vlSelf->imem_rdata 
                                                                   >> 9U)) 
                                                               | (0x7feU 
                                                                  & (vlSelf->imem_rdata 
                                                                     >> 0x14U))))))
                                                      : 0U)))));
    vlSelf->top__DOT__exu__DOT__alu_src2 = (((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                                             | ((0x23U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->imem_rdata)) 
                                                | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                                   | (0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->imem_rdata)))))
                                             ? vlSelf->top__DOT__idu__DOT__imm_val
                                             : vlSelf->top__DOT__rs2_data);
    top__DOT__exu__DOT____VdfgExtracted_h34086c27__0 
        = (vlSelf->top__DOT__exu__DOT__alu_src1 + vlSelf->top__DOT__exu__DOT__alu_src2);
    vlSelf->top__DOT__exu__DOT__alu_result_reg = ((8U 
                                                   & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                    ? top__DOT__exu__DOT____VdfgExtracted_h34086c27__0
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                     ? top__DOT__exu__DOT____VdfgExtracted_h34086c27__0
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      < vlSelf->top__DOT__exu__DOT__alu_src2)
                                                      : 
                                                     VL_LTS_III(32, vlSelf->top__DOT__exu__DOT__alu_src1, vlSelf->top__DOT__exu__DOT__alu_src2))))
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu__DOT__alu_src1, 
                                                                    (0x1fU 
                                                                     & vlSelf->top__DOT__exu__DOT__alu_src2))
                                                      : 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->top__DOT__exu__DOT__alu_src2)))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelf->top__DOT__exu__DOT__alu_src2))
                                                      : 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      ^ vlSelf->top__DOT__exu__DOT__alu_src2)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      | vlSelf->top__DOT__exu__DOT__alu_src2)
                                                      : 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      & vlSelf->top__DOT__exu__DOT__alu_src2))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      - vlSelf->top__DOT__exu__DOT__alu_src2)
                                                      : top__DOT__exu__DOT____VdfgExtracted_h34086c27__0))));
    if (vlSelf->top__DOT__jump) {
        vlSelf->top__DOT__exu__DOT__alu_result_reg 
            = ((IData)(vlSelf->top__DOT__is_jalr) ? 
               (0xfffffffeU & (vlSelf->top__DOT__idu__DOT__imm_val 
                               + vlSelf->top__DOT__exu__DOT__alu_src1))
                : (vlSelf->top__DOT__idu__DOT__imm_val 
                   + vlSelf->top__DOT__pc));
    }
    if ((0x17U == (0x7fU & vlSelf->imem_rdata))) {
        vlSelf->top__DOT__exu__DOT__alu_result_reg 
            = (vlSelf->top__DOT__pc + vlSelf->top__DOT__idu__DOT__imm_val);
    }
    vlSelf->dmem_addr = ((IData)(vlSelf->dmem_valid)
                          ? ((0x80000000U <= vlSelf->top__DOT__exu__DOT__alu_result_reg)
                              ? vlSelf->top__DOT__exu__DOT__alu_result_reg
                              : ((IData)(0x80100000U) 
                                 + vlSelf->top__DOT__exu__DOT__alu_result_reg))
                          : vlSelf->top__DOT__exu__DOT__alu_result_reg);
    if ((3U == (0x7fU & vlSelf->imem_rdata))) {
        if ((0x4000U & vlSelf->imem_rdata)) {
            if ((0x2000U & vlSelf->imem_rdata)) {
                vlSelf->top__DOT__exu__DOT__load_data 
                    = vlSelf->dmem_rdata;
            } else if ((0x1000U & vlSelf->imem_rdata)) {
                if ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                    if ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                        vlSelf->top__DOT__exu__DOT__load_data 
                            = (vlSelf->dmem_rdata >> 0x10U);
                    }
                } else {
                    vlSelf->top__DOT__exu__DOT__load_data 
                        = (0xffffU & vlSelf->dmem_rdata);
                }
            } else {
                vlSelf->top__DOT__exu__DOT__load_data 
                    = ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)
                        ? ((1U & vlSelf->top__DOT__exu__DOT__alu_result_reg)
                            ? (vlSelf->dmem_rdata >> 0x18U)
                            : (0xffU & (vlSelf->dmem_rdata 
                                        >> 0x10U)))
                        : ((1U & vlSelf->top__DOT__exu__DOT__alu_result_reg)
                            ? (0xffU & (vlSelf->dmem_rdata 
                                        >> 8U)) : (0xffU 
                                                   & vlSelf->dmem_rdata)));
            }
        } else if ((0x2000U & vlSelf->imem_rdata)) {
            vlSelf->top__DOT__exu__DOT__load_data = vlSelf->dmem_rdata;
        } else if ((0x1000U & vlSelf->imem_rdata)) {
            if ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                if ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                    vlSelf->top__DOT__exu__DOT__load_data 
                        = (((- (IData)((vlSelf->dmem_rdata 
                                        >> 0x1fU))) 
                            << 0x10U) | (vlSelf->dmem_rdata 
                                         >> 0x10U));
                }
            } else {
                vlSelf->top__DOT__exu__DOT__load_data 
                    = (((- (IData)((1U & (vlSelf->dmem_rdata 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelf->dmem_rdata));
            }
        } else {
            vlSelf->top__DOT__exu__DOT__load_data = 
                ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)
                  ? ((1U & vlSelf->top__DOT__exu__DOT__alu_result_reg)
                      ? (((- (IData)((vlSelf->dmem_rdata 
                                      >> 0x1fU))) << 8U) 
                         | (vlSelf->dmem_rdata >> 0x18U))
                      : (((- (IData)((1U & (vlSelf->dmem_rdata 
                                            >> 0x17U)))) 
                          << 8U) | (0xffU & (vlSelf->dmem_rdata 
                                             >> 0x10U))))
                  : ((1U & vlSelf->top__DOT__exu__DOT__alu_result_reg)
                      ? (((- (IData)((1U & (vlSelf->dmem_rdata 
                                            >> 0xfU)))) 
                          << 8U) | (0xffU & (vlSelf->dmem_rdata 
                                             >> 8U)))
                      : (((- (IData)((1U & (vlSelf->dmem_rdata 
                                            >> 7U)))) 
                          << 8U) | (0xffU & vlSelf->dmem_rdata))));
        }
    } else {
        vlSelf->top__DOT__exu__DOT__load_data = vlSelf->dmem_rdata;
    }
    if ((0x23U == (0x7fU & vlSelf->imem_rdata))) {
        if ((0U == (7U & (vlSelf->imem_rdata >> 0xcU)))) {
            if ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                if ((1U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                    vlSelf->top__DOT__exu__DOT__store_mask = 8U;
                    vlSelf->top__DOT__exu__DOT__store_data 
                        = (vlSelf->top__DOT__rs2_data 
                           << 0x18U);
                } else {
                    vlSelf->top__DOT__exu__DOT__store_mask = 4U;
                    vlSelf->top__DOT__exu__DOT__store_data 
                        = (0xff0000U & (vlSelf->top__DOT__rs2_data 
                                        << 0x10U));
                }
            } else if ((1U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                vlSelf->top__DOT__exu__DOT__store_mask = 2U;
                vlSelf->top__DOT__exu__DOT__store_data 
                    = (0xff00U & (vlSelf->top__DOT__rs2_data 
                                  << 8U));
            } else {
                vlSelf->top__DOT__exu__DOT__store_mask = 1U;
                vlSelf->top__DOT__exu__DOT__store_data 
                    = (0xffU & vlSelf->top__DOT__rs2_data);
            }
        } else if ((1U == (7U & (vlSelf->imem_rdata 
                                 >> 0xcU)))) {
            if ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                if ((2U & vlSelf->top__DOT__exu__DOT__alu_result_reg)) {
                    vlSelf->top__DOT__exu__DOT__store_mask = 0xcU;
                    vlSelf->top__DOT__exu__DOT__store_data 
                        = (vlSelf->top__DOT__rs2_data 
                           << 0x10U);
                }
            } else {
                vlSelf->top__DOT__exu__DOT__store_mask = 3U;
                vlSelf->top__DOT__exu__DOT__store_data 
                    = (0xffffU & vlSelf->top__DOT__rs2_data);
            }
        } else if ((2U == (7U & (vlSelf->imem_rdata 
                                 >> 0xcU)))) {
            vlSelf->top__DOT__exu__DOT__store_mask = 0xfU;
            vlSelf->top__DOT__exu__DOT__store_data 
                = vlSelf->top__DOT__rs2_data;
        } else {
            vlSelf->top__DOT__exu__DOT__store_mask = 0U;
            vlSelf->top__DOT__exu__DOT__store_data = 0U;
        }
    } else {
        vlSelf->top__DOT__exu__DOT__store_mask = 0U;
        vlSelf->top__DOT__exu__DOT__store_data = 0U;
    }
    __Vtableidx1 = (((IData)(vlSelf->top__DOT__jump) 
                     << 0xaU) | ((((1U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                                   & (0U == vlSelf->top__DOT__exu__DOT__alu_result_reg)) 
                                  << 9U) | ((((1U == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                                              & (0U 
                                                 != vlSelf->top__DOT__exu__DOT__alu_result_reg)) 
                                             << 8U) 
                                            | ((((8U 
                                                  == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                                                 & vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                                                << 7U) 
                                               | ((((~ vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                                                    & (8U 
                                                       == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))) 
                                                   << 6U) 
                                                  | ((((9U 
                                                        == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val)) 
                                                       & vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                                                      << 5U) 
                                                     | ((((~ vlSelf->top__DOT__exu__DOT__alu_result_reg) 
                                                          & (9U 
                                                             == (IData)(vlSelf->top__DOT__idu__DOT__alu_op_val))) 
                                                         << 4U) 
                                                        | ((0xeU 
                                                            & (vlSelf->imem_rdata 
                                                               >> 0xbU)) 
                                                           | (0x63U 
                                                              == 
                                                              (0x7fU 
                                                               & vlSelf->imem_rdata))))))))));
    vlSelf->top__DOT__exu__DOT__branch_taken_reg = 
        Vtop__ConstPool__TABLE_hb2728f61_0[__Vtableidx1];
    vlSelf->dmem_wen = vlSelf->top__DOT__exu__DOT__store_mask;
    vlSelf->dmem_wdata = vlSelf->top__DOT__exu__DOT__store_data;
    vlSelf->top__DOT__next_pc = ((IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg)
                                  ? vlSelf->top__DOT__exu__DOT__alu_result_reg
                                  : ((IData)(4U) + vlSelf->top__DOT__pc));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__jump = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_src2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__reg_x1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__reg_x2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__reg_a0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__is_u_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__imm_val = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu__DOT__alu_op_val = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__exu__DOT__alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu_src2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__alu_result_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__branch_taken_reg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu__DOT__store_mask = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__exu__DOT__store_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu__DOT__load_data = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__exu__DOT__regfile__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
