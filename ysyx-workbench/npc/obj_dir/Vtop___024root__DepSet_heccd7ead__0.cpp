// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__sim_exit_TOP(IData/*31:0*/ exit_code);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__top__DOT__cycle_count;
    __Vdly__top__DOT__cycle_count = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__gpr__DOT__rf__v0;
    __Vdlyvset__top__DOT__gpr__DOT__rf__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__gpr__DOT__rf__v32;
    __Vdlyvdim0__top__DOT__gpr__DOT__rf__v32 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__gpr__DOT__rf__v32;
    __Vdlyvval__top__DOT__gpr__DOT__rf__v32 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__gpr__DOT__rf__v32;
    __Vdlyvset__top__DOT__gpr__DOT__rf__v32 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v0;
    __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__data_mem__DOT__dmem__v0;
    __Vdlyvval__top__DOT__data_mem__DOT__dmem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__data_mem__DOT__dmem__v0;
    __Vdlyvset__top__DOT__data_mem__DOT__dmem__v0 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v1;
    __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__data_mem__DOT__dmem__v1;
    __Vdlyvval__top__DOT__data_mem__DOT__dmem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__data_mem__DOT__dmem__v1;
    __Vdlyvset__top__DOT__data_mem__DOT__dmem__v1 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v2;
    __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v2 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__data_mem__DOT__dmem__v2;
    __Vdlyvval__top__DOT__data_mem__DOT__dmem__v2 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v3;
    __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v3 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__data_mem__DOT__dmem__v3;
    __Vdlyvval__top__DOT__data_mem__DOT__dmem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__data_mem__DOT__dmem__v3;
    __Vdlyvset__top__DOT__data_mem__DOT__dmem__v3 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v4;
    __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v4 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__data_mem__DOT__dmem__v4;
    __Vdlyvval__top__DOT__data_mem__DOT__dmem__v4 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v5;
    __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v5 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__data_mem__DOT__dmem__v5;
    __Vdlyvval__top__DOT__data_mem__DOT__dmem__v5 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v6;
    __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v6 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__data_mem__DOT__dmem__v6;
    __Vdlyvval__top__DOT__data_mem__DOT__dmem__v6 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__csr__DOT__csr_regs__v0;
    __Vdlyvset__top__DOT__csr__DOT__csr_regs__v0 = 0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__csr__DOT__csr_regs__v3;
    __Vdlyvdim0__top__DOT__csr__DOT__csr_regs__v3 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__csr__DOT__csr_regs__v3;
    __Vdlyvval__top__DOT__csr__DOT__csr_regs__v3 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__csr__DOT__csr_regs__v3;
    __Vdlyvset__top__DOT__csr__DOT__csr_regs__v3 = 0;
    // Body
    __Vdlyvset__top__DOT__csr__DOT__csr_regs__v0 = 0U;
    __Vdlyvset__top__DOT__csr__DOT__csr_regs__v3 = 0U;
    __Vdlyvset__top__DOT__data_mem__DOT__dmem__v0 = 0U;
    __Vdlyvset__top__DOT__data_mem__DOT__dmem__v1 = 0U;
    __Vdlyvset__top__DOT__data_mem__DOT__dmem__v3 = 0U;
    __Vdly__top__DOT__cycle_count = vlSelf->top__DOT__cycle_count;
    __Vdlyvset__top__DOT__gpr__DOT__rf__v0 = 0U;
    __Vdlyvset__top__DOT__gpr__DOT__rf__v32 = 0U;
    if ((0x23U == (0x7fU & vlSelf->top__DOT__inst))) {
        if ((0U == (7U & (vlSelf->top__DOT__inst >> 0xcU)))) {
            __Vdlyvval__top__DOT__data_mem__DOT__dmem__v0 
                = (0xffU & vlSelf->top__DOT__rs2_data);
            __Vdlyvset__top__DOT__data_mem__DOT__dmem__v0 = 1U;
            __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v0 
                = (0xfffU & vlSelf->top__DOT__alu_result);
        } else if ((1U == (7U & (vlSelf->top__DOT__inst 
                                 >> 0xcU)))) {
            __Vdlyvval__top__DOT__data_mem__DOT__dmem__v1 
                = (0xffU & vlSelf->top__DOT__rs2_data);
            __Vdlyvset__top__DOT__data_mem__DOT__dmem__v1 = 1U;
            __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v1 
                = (0xfffU & vlSelf->top__DOT__alu_result);
            __Vdlyvval__top__DOT__data_mem__DOT__dmem__v2 
                = (0xffU & (vlSelf->top__DOT__rs2_data 
                            >> 8U));
            __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v2 
                = (0xfffU & ((IData)(1U) + vlSelf->top__DOT__alu_result));
        } else if ((2U == (7U & (vlSelf->top__DOT__inst 
                                 >> 0xcU)))) {
            __Vdlyvval__top__DOT__data_mem__DOT__dmem__v3 
                = (0xffU & vlSelf->top__DOT__rs2_data);
            __Vdlyvset__top__DOT__data_mem__DOT__dmem__v3 = 1U;
            __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v3 
                = (0xfffU & vlSelf->top__DOT__alu_result);
            __Vdlyvval__top__DOT__data_mem__DOT__dmem__v4 
                = (0xffU & (vlSelf->top__DOT__rs2_data 
                            >> 8U));
            __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v4 
                = (0xfffU & ((IData)(1U) + vlSelf->top__DOT__alu_result));
            __Vdlyvval__top__DOT__data_mem__DOT__dmem__v5 
                = (0xffU & (vlSelf->top__DOT__rs2_data 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v5 
                = (0xfffU & ((IData)(2U) + vlSelf->top__DOT__alu_result));
            __Vdlyvval__top__DOT__data_mem__DOT__dmem__v6 
                = (vlSelf->top__DOT__rs2_data >> 0x18U);
            __Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v6 
                = (0xfffU & ((IData)(3U) + vlSelf->top__DOT__alu_result));
        }
    }
    if (vlSelf->rst) {
        vlSelf->top__DOT__gpr__DOT__unnamedblk1__DOT__i = 0x20U;
        __Vdlyvset__top__DOT__csr__DOT__csr_regs__v0 = 1U;
    } else if (((0x73U == (0x7fU & vlSelf->top__DOT__inst)) 
                & (0U != (7U & (vlSelf->top__DOT__inst 
                                >> 0xcU))))) {
        __Vdlyvval__top__DOT__csr__DOT__csr_regs__v3 
            = vlSelf->top__DOT__rs1_data;
        __Vdlyvset__top__DOT__csr__DOT__csr_regs__v3 = 1U;
        __Vdlyvdim0__top__DOT__csr__DOT__csr_regs__v3 
            = (vlSelf->top__DOT__inst >> 0x14U);
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__cycle_count = 0U;
    } else {
        __Vdly__top__DOT__cycle_count = ((IData)(1U) 
                                         + vlSelf->top__DOT__cycle_count);
        if (VL_UNLIKELY((0x100073U == vlSelf->top__DOT__inst))) {
            VL_WRITEF("\n\n=== EBREAK \346\214\207\344\273\244\350\242\253\346\211\247\350\241\214 ===\nPC = 0x%x\n\351\200\200\345\207\272\347\240\201 = %10# (a0 \345\257\204\345\255\230\345\231\250\344\270\255\347\232\204\345\200\274)\n",
                      32,vlSelf->top__DOT__pc,32,vlSelf->top__DOT__gpr__DOT__rf
                      [0xaU]);
            Vtop___024root____Vdpiimwrap_top__DOT__sim_exit_TOP(
                                                                vlSelf->top__DOT__gpr__DOT__rf
                                                                [0xaU]);
        }
    }
    if (vlSelf->rst) {
        __Vdlyvset__top__DOT__gpr__DOT__rf__v0 = 1U;
        vlSelf->top__DOT__trap_flag = 0U;
    } else if ((((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
                 | ((IData)(vlSelf->top__DOT__idu__DOT__i_type) 
                    | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h88c6b025__0))) 
                & (0U != (0x1fU & (vlSelf->top__DOT__inst 
                                   >> 7U))))) {
        __Vdlyvval__top__DOT__gpr__DOT__rf__v32 = (
                                                   (0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__inst))
                                                    ? vlSelf->top__DOT__imm
                                                    : 
                                                   (((IData)(vlSelf->top__DOT____VdfgTmp_h5482c01c__0) 
                                                     | (0x67U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelf->top__DOT__inst)))
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlSelf->top__DOT__pc)
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__inst))
                                                      ? vlSelf->top__DOT__mem_read_data
                                                      : vlSelf->top__DOT__alu_result)));
        __Vdlyvset__top__DOT__gpr__DOT__rf__v32 = 1U;
        __Vdlyvdim0__top__DOT__gpr__DOT__rf__v32 = 
            (0x1fU & (vlSelf->top__DOT__inst >> 7U));
    }
    if (__Vdlyvset__top__DOT__csr__DOT__csr_regs__v0) {
        vlSelf->top__DOT__csr__DOT__csr_regs[0x300U] = 0U;
        vlSelf->top__DOT__csr__DOT__csr_regs[0x301U] = 0U;
        vlSelf->top__DOT__csr__DOT__csr_regs[0x305U] = 0U;
    }
    if (__Vdlyvset__top__DOT__csr__DOT__csr_regs__v3) {
        vlSelf->top__DOT__csr__DOT__csr_regs[__Vdlyvdim0__top__DOT__csr__DOT__csr_regs__v3] 
            = __Vdlyvval__top__DOT__csr__DOT__csr_regs__v3;
    }
    if (__Vdlyvset__top__DOT__data_mem__DOT__dmem__v0) {
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v0] 
            = __Vdlyvval__top__DOT__data_mem__DOT__dmem__v0;
    }
    if (__Vdlyvset__top__DOT__data_mem__DOT__dmem__v1) {
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v1] 
            = __Vdlyvval__top__DOT__data_mem__DOT__dmem__v1;
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v2] 
            = __Vdlyvval__top__DOT__data_mem__DOT__dmem__v2;
    }
    if (__Vdlyvset__top__DOT__data_mem__DOT__dmem__v3) {
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v3] 
            = __Vdlyvval__top__DOT__data_mem__DOT__dmem__v3;
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v4] 
            = __Vdlyvval__top__DOT__data_mem__DOT__dmem__v4;
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v5] 
            = __Vdlyvval__top__DOT__data_mem__DOT__dmem__v5;
        vlSelf->top__DOT__data_mem__DOT__dmem[__Vdlyvdim0__top__DOT__data_mem__DOT__dmem__v6] 
            = __Vdlyvval__top__DOT__data_mem__DOT__dmem__v6;
    }
    vlSelf->top__DOT__cycle_count = __Vdly__top__DOT__cycle_count;
    if (__Vdlyvset__top__DOT__gpr__DOT__rf__v0) {
        vlSelf->top__DOT__gpr__DOT__rf[0U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[1U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[2U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[3U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[4U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[5U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[6U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[7U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[8U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[9U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0xaU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0xbU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0xcU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0xdU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0xeU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0xfU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x10U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x11U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x12U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x13U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x14U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x15U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x16U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x17U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x18U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x19U] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x1aU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x1bU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x1cU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x1dU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x1eU] = 0U;
        vlSelf->top__DOT__gpr__DOT__rf[0x1fU] = 0U;
    }
    if (__Vdlyvset__top__DOT__gpr__DOT__rf__v32) {
        vlSelf->top__DOT__gpr__DOT__rf[__Vdlyvdim0__top__DOT__gpr__DOT__rf__v32] 
            = __Vdlyvval__top__DOT__gpr__DOT__rf__v32;
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__pc = ((IData)(vlSelf->rst) ? 0x80000000U
                             : vlSelf->top__DOT__next_pc);
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
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
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
    vlSelf->top__DOT__alu_src1 = ((IData)(vlSelf->top__DOT____VdfgTmp_h5482c01c__0)
                                   ? vlSelf->top__DOT__pc
                                   : vlSelf->top__DOT__rs1_data);
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
