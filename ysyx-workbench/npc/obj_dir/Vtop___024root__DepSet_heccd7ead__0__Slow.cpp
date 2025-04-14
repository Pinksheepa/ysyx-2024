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
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top__DOT__data_mem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1000U, vlSelf->top__DOT__data_mem__DOT__unnamedblk1__DOT__i)) {
        vlSelf->top__DOT__data_mem__DOT__dmem[(0xfffU 
                                               & vlSelf->top__DOT__data_mem__DOT__unnamedblk1__DOT__i)] = 0U;
        vlSelf->top__DOT__data_mem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelf->top__DOT__data_mem__DOT__unnamedblk1__DOT__i);
    }
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
                VL_FATAL_MT("vsrc/top.v", 3, "", "Settle region did not converge.");
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

void Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((0U != (3U & vlSelf->top__DOT__pc))) {
        vlSelf->top__DOT__inst = 0x13U;
    } else {
        Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(vlSelf->top__DOT__pc, 4U, vlSelf->__Vfunc_top__DOT__inst_mem__DOT__pmem_read__1__Vfuncout);
        vlSelf->top__DOT__inst = vlSelf->__Vfunc_top__DOT__inst_mem__DOT__pmem_read__1__Vfuncout;
    }
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h9f39052c__0 
        = ((8U & (vlSelf->top__DOT__inst >> 0x1bU)) 
           | (7U & (vlSelf->top__DOT__inst >> 0xcU)));
    vlSelf->top__DOT____VdfgTmp_h5482c01c__0 = ((0x17U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__inst)) 
                                                | (0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__rs1_data = ((0U == (0x1fU & (vlSelf->top__DOT__inst 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->top__DOT__gpr__DOT__rf
                                  [(0x1fU & (vlSelf->top__DOT__inst 
                                             >> 0xfU))]);
    vlSelf->top__DOT__rs2_data = ((0U == (0x1fU & (vlSelf->top__DOT__inst 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->top__DOT__gpr__DOT__rf
                                  [(0x1fU & (vlSelf->top__DOT__inst 
                                             >> 0x14U))]);
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h87b4775b__0 
        = (IData)((0x5000U == (0x40007000U & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h22a85453__0 
        = (IData)((0x40005000U == (0x40007000U & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT__u_type = ((0x37U == 
                                           (0x7fU & vlSelf->top__DOT__inst)) 
                                          | (0x17U 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT__i_type = ((0x13U == 
                                           (0x7fU & vlSelf->top__DOT__inst)) 
                                          | ((3U == 
                                              (0x7fU 
                                               & vlSelf->top__DOT__inst)) 
                                             | (0x67U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__inst))));
    vlSelf->top__DOT__alu_src1 = ((IData)(vlSelf->top__DOT____VdfgTmp_h5482c01c__0)
                                   ? vlSelf->top__DOT__pc
                                   : vlSelf->top__DOT__rs1_data);
    vlSelf->top__DOT__idu__DOT__alu_op_r_type = ((0U 
                                                  == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h9f39052c__0))
                                                  ? 0U
                                                  : 
                                                 ((8U 
                                                   == (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h9f39052c__0))
                                                   ? 1U
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->top__DOT__inst 
                                                        >> 0xcU)))
                                                    ? 2U
                                                    : 
                                                   ((2U 
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
                                                           : 
                                                          ((IData)(
                                                                   (0x2000000U 
                                                                    == 
                                                                    (0x2007000U 
                                                                     & vlSelf->top__DOT__inst)))
                                                            ? 0xaU
                                                            : 
                                                           ((IData)(
                                                                    (0x2001000U 
                                                                     == 
                                                                     (0x2007000U 
                                                                      & vlSelf->top__DOT__inst)))
                                                             ? 0xbU
                                                             : 
                                                            ((IData)(
                                                                     (0x2004000U 
                                                                      == 
                                                                      (0x2007000U 
                                                                       & vlSelf->top__DOT__inst)))
                                                              ? 0xcU
                                                              : 
                                                             ((IData)(
                                                                      (0x2005000U 
                                                                       == 
                                                                       (0x2007000U 
                                                                        & vlSelf->top__DOT__inst)))
                                                               ? 0xdU
                                                               : 
                                                              ((IData)(
                                                                       (0x2006000U 
                                                                        == 
                                                                        (0x2007000U 
                                                                         & vlSelf->top__DOT__inst)))
                                                                ? 0xeU
                                                                : 
                                                               ((IData)(
                                                                        (0x2007000U 
                                                                         == 
                                                                         (0x2007000U 
                                                                          & vlSelf->top__DOT__inst)))
                                                                 ? 0xfU
                                                                 : 0U))))))))))))))));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h88c6b025__0 
        = ((IData)(vlSelf->top__DOT__idu__DOT__u_type) 
           | (0x6fU == (0x7fU & vlSelf->top__DOT__inst)));
    if ((0x33U == (0x7fU & vlSelf->top__DOT__inst))) {
        vlSelf->top__DOT__inst_type = 0U;
        vlSelf->top__DOT__alu_op = vlSelf->top__DOT__idu__DOT__alu_op_r_type;
    } else if (vlSelf->top__DOT__idu__DOT__i_type) {
        vlSelf->top__DOT__inst_type = 1U;
        vlSelf->top__DOT__alu_op = ((0U == (7U & (vlSelf->top__DOT__inst 
                                                  >> 0xcU)))
                                     ? 0U : ((1U == 
                                              (7U & 
                                               (vlSelf->top__DOT__inst 
                                                >> 0xcU)))
                                              ? 2U : 
                                             ((2U == 
                                               (7U 
                                                & (vlSelf->top__DOT__inst 
                                                   >> 0xcU)))
                                               ? 3U
                                               : ((3U 
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
                                                        : 0U)))))))));
    } else {
        vlSelf->top__DOT__inst_type = ((0x23U == (0x7fU 
                                                  & vlSelf->top__DOT__inst))
                                        ? 2U : ((0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__inst))
                                                 ? 3U
                                                 : 
                                                ((IData)(vlSelf->top__DOT__idu__DOT__u_type)
                                                  ? 4U
                                                  : 
                                                 ((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__inst))
                                                   ? 5U
                                                   : 7U))));
        vlSelf->top__DOT__alu_op = 0U;
    }
    vlSelf->top__DOT__imm = ((4U & (IData)(vlSelf->top__DOT__inst_type))
                              ? ((2U & (IData)(vlSelf->top__DOT__inst_type))
                                  ? 0U : ((1U & (IData)(vlSelf->top__DOT__inst_type))
                                           ? (((- (IData)(
                                                          (vlSelf->top__DOT__inst 
                                                           >> 0x1fU))) 
                                               << 0x14U) 
                                              | ((0xff000U 
                                                  & vlSelf->top__DOT__inst) 
                                                 | ((0x800U 
                                                     & (vlSelf->top__DOT__inst 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->top__DOT__inst 
                                                          >> 0x14U)))))
                                           : (0xfffff000U 
                                              & vlSelf->top__DOT__inst)))
                              : ((2U & (IData)(vlSelf->top__DOT__inst_type))
                                  ? ((1U & (IData)(vlSelf->top__DOT__inst_type))
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0x800U 
                                             & (vlSelf->top__DOT__inst 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelf->top__DOT__inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->top__DOT__inst 
                                                     >> 7U)))))
                                      : (((- (IData)(
                                                     (vlSelf->top__DOT__inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelf->top__DOT__inst 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->top__DOT__inst 
                                                  >> 7U)))))
                                  : ((1U & (IData)(vlSelf->top__DOT__inst_type))
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelf->top__DOT__inst 
                                            >> 0x14U))
                                      : 0U)));
    vlSelf->top__DOT__alu_src2 = (((IData)(vlSelf->top__DOT__idu__DOT__i_type) 
                                   | ((0x23U == (0x7fU 
                                                 & vlSelf->top__DOT__inst)) 
                                      | ((0x63U == 
                                          (0x7fU & vlSelf->top__DOT__inst)) 
                                         | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h88c6b025__0))))
                                   ? vlSelf->top__DOT__imm
                                   : vlSelf->top__DOT__rs2_data);
    vlSelf->top__DOT__alu_less_than = ((3U == (IData)(vlSelf->top__DOT__alu_op))
                                        ? VL_LTS_III(32, vlSelf->top__DOT__alu_src1, vlSelf->top__DOT__alu_src2)
                                        : (vlSelf->top__DOT__alu_src1 
                                           < vlSelf->top__DOT__alu_src2));
    vlSelf->top__DOT__alu__DOT__mul_signed = VL_MULS_QQQ(64, 
                                                         VL_EXTENDS_QI(64,32, vlSelf->top__DOT__alu_src1), 
                                                         VL_EXTENDS_QI(64,32, vlSelf->top__DOT__alu_src2));
    vlSelf->top__DOT__alu_result = ((8U & (IData)(vlSelf->top__DOT__alu_op))
                                     ? ((4U & (IData)(vlSelf->top__DOT__alu_op))
                                         ? ((2U & (IData)(vlSelf->top__DOT__alu_op))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? 
                                                ((0U 
                                                  == vlSelf->top__DOT__alu_src2)
                                                  ? vlSelf->top__DOT__alu_src1
                                                  : 
                                                 VL_MODDIV_III(32, vlSelf->top__DOT__alu_src1, vlSelf->top__DOT__alu_src2))
                                                 : 
                                                ((0U 
                                                  == vlSelf->top__DOT__alu_src2)
                                                  ? vlSelf->top__DOT__alu_src1
                                                  : 
                                                 VL_MODDIV_III(32, vlSelf->top__DOT__alu_src1, vlSelf->top__DOT__alu_src2)))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? 
                                                ((0U 
                                                  == vlSelf->top__DOT__alu_src2)
                                                  ? 0xffffffffU
                                                  : 
                                                 VL_DIV_III(32, vlSelf->top__DOT__alu_src1, vlSelf->top__DOT__alu_src2))
                                                 : 
                                                ((0U 
                                                  == vlSelf->top__DOT__alu_src2)
                                                  ? 0xffffffffU
                                                  : 
                                                 VL_DIV_III(32, vlSelf->top__DOT__alu_src1, vlSelf->top__DOT__alu_src2))))
                                         : ((2U & (IData)(vlSelf->top__DOT__alu_op))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? (IData)(
                                                           (vlSelf->top__DOT__alu__DOT__mul_signed 
                                                            >> 0x20U))
                                                 : (IData)(vlSelf->top__DOT__alu__DOT__mul_signed))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? 
                                                (vlSelf->top__DOT__alu_src1 
                                                 & vlSelf->top__DOT__alu_src2)
                                                 : 
                                                (vlSelf->top__DOT__alu_src1 
                                                 | vlSelf->top__DOT__alu_src2))))
                                     : ((4U & (IData)(vlSelf->top__DOT__alu_op))
                                         ? ((2U & (IData)(vlSelf->top__DOT__alu_op))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__alu_src2))
                                                  ? 
                                                 VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__alu_src1, 
                                                                (0x1fU 
                                                                 & vlSelf->top__DOT__alu_src2))
                                                  : 
                                                 (- 
                                                  (vlSelf->top__DOT__alu_src1 
                                                   >> 0x1fU)))
                                                 : 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__alu_src2))
                                                  ? 
                                                 (vlSelf->top__DOT__alu_src1 
                                                  >> 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__alu_src2))
                                                  : 0U))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? 
                                                (vlSelf->top__DOT__alu_src1 
                                                 ^ vlSelf->top__DOT__alu_src2)
                                                 : 
                                                (vlSelf->top__DOT__alu_src1 
                                                 < vlSelf->top__DOT__alu_src2)))
                                         : ((2U & (IData)(vlSelf->top__DOT__alu_op))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? 
                                                VL_LTS_III(32, vlSelf->top__DOT__alu_src1, vlSelf->top__DOT__alu_src2)
                                                 : 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__alu_src2))
                                                  ? 
                                                 (vlSelf->top__DOT__alu_src1 
                                                  << 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__alu_src2))
                                                  : 0U))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__alu_op))
                                                 ? 
                                                (vlSelf->top__DOT__alu_src1 
                                                 - vlSelf->top__DOT__alu_src2)
                                                 : 
                                                (vlSelf->top__DOT__alu_src1 
                                                 + vlSelf->top__DOT__alu_src2)))));
    vlSelf->top__DOT__mem_read_data = ((3U == (0x7fU 
                                               & vlSelf->top__DOT__inst))
                                        ? ((0x4000U 
                                            & vlSelf->top__DOT__inst)
                                            ? ((0x2000U 
                                                & vlSelf->top__DOT__inst)
                                                ? 0U
                                                : (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__inst)
                                                    ? 
                                                   ((vlSelf->top__DOT__data_mem__DOT__dmem
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(1U) 
                                                         + vlSelf->top__DOT__alu_result))] 
                                                     << 8U) 
                                                    | vlSelf->top__DOT__data_mem__DOT__dmem
                                                    [
                                                    (0xfffU 
                                                     & vlSelf->top__DOT__alu_result)])
                                                    : 
                                                   vlSelf->top__DOT__data_mem__DOT__dmem
                                                   [
                                                   (0xfffU 
                                                    & vlSelf->top__DOT__alu_result)]))
                                            : ((0x2000U 
                                                & vlSelf->top__DOT__inst)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__inst)
                                                    ? 0U
                                                    : 
                                                   ((vlSelf->top__DOT__data_mem__DOT__dmem
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(3U) 
                                                         + vlSelf->top__DOT__alu_result))] 
                                                     << 0x18U) 
                                                    | ((vlSelf->top__DOT__data_mem__DOT__dmem
                                                        [
                                                        (0xfffU 
                                                         & ((IData)(2U) 
                                                            + vlSelf->top__DOT__alu_result))] 
                                                        << 0x10U) 
                                                       | ((vlSelf->top__DOT__data_mem__DOT__dmem
                                                           [
                                                           (0xfffU 
                                                            & ((IData)(1U) 
                                                               + vlSelf->top__DOT__alu_result))] 
                                                           << 8U) 
                                                          | vlSelf->top__DOT__data_mem__DOT__dmem
                                                          [
                                                          (0xfffU 
                                                           & vlSelf->top__DOT__alu_result)]))))
                                                : (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__inst)
                                                    ? 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->top__DOT__data_mem__DOT__dmem
                                                                    [
                                                                    (0xfffU 
                                                                     & ((IData)(1U) 
                                                                        + vlSelf->top__DOT__alu_result))] 
                                                                    >> 7U)))) 
                                                     << 0x10U) 
                                                    | ((vlSelf->top__DOT__data_mem__DOT__dmem
                                                        [
                                                        (0xfffU 
                                                         & ((IData)(1U) 
                                                            + vlSelf->top__DOT__alu_result))] 
                                                        << 8U) 
                                                       | vlSelf->top__DOT__data_mem__DOT__dmem
                                                       [
                                                       (0xfffU 
                                                        & vlSelf->top__DOT__alu_result)]))
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->top__DOT__data_mem__DOT__dmem
                                                                    [
                                                                    (0xfffU 
                                                                     & vlSelf->top__DOT__alu_result)] 
                                                                    >> 7U)))) 
                                                     << 8U) 
                                                    | vlSelf->top__DOT__data_mem__DOT__dmem
                                                    [
                                                    (0xfffU 
                                                     & vlSelf->top__DOT__alu_result)]))))
                                        : 0U);
    vlSelf->top__DOT__next_pc = (((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__inst)) 
                                  | ((IData)(((0x63U 
                                               == (0x7fU 
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
                                      ? (0xfffffffeU 
                                         & (vlSelf->top__DOT__imm 
                                            + vlSelf->top__DOT__rs1_data))
                                      : (vlSelf->top__DOT__imm 
                                         + vlSelf->top__DOT__pc))
                                  : ((IData)(4U) + vlSelf->top__DOT__pc));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

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
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
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
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
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
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__inst_type = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__alu_op = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__rs1_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_src2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_less_than = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_read_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__trap_flag = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cycle_count = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____VdfgTmp_h5482c01c__0 = 0;
    vlSelf->top__DOT__idu__DOT__i_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__u_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu__DOT__alu_op_r_type = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h88c6b025__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h9f39052c__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h87b4775b__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h22a85453__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__gpr__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__gpr__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu__DOT__mul_signed = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__data_mem__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->top__DOT__csr__DOT__csr_regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vfunc_top__DOT__inst_mem__DOT__pmem_read__1__Vfuncout = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
