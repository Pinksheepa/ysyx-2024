// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_hb2728f61_0;

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ top__DOT__exu__DOT____VdfgExtracted_h34086c27__0;
    top__DOT__exu__DOT____VdfgExtracted_h34086c27__0 = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__exu__DOT__npc_ebreak_TOP(IData/*31:0*/ a0_value);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v0;
    __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__exu__DOT__regfile__DOT__registers__v32;
    __Vdlyvdim0__top__DOT__exu__DOT__regfile__DOT__registers__v32 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__exu__DOT__regfile__DOT__registers__v32;
    __Vdlyvval__top__DOT__exu__DOT__regfile__DOT__registers__v32 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v32;
    __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v32 = 0;
    // Body
    if (((~ (IData)(vlSelf->rst)) & (IData)((0x100073U 
                                             == (0xfff0707fU 
                                                 & vlSelf->imem_rdata))))) {
        Vtop___024root____Vdpiimwrap_top__DOT__exu__DOT__npc_ebreak_TOP(
                                                                        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers
                                                                        [0xaU]);
    }
    __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v0 = 0U;
    __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v32 = 0U;
    if (vlSelf->rst) {
        vlSelf->top__DOT__exu__DOT__regfile__DOT__i = 0x20U;
        __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v0 = 1U;
        vlSelf->top__DOT__pc = 0x80000000U;
    } else {
        if ((((0x33U == (0x7fU & vlSelf->imem_rdata)) 
              | ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                 | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                    | (IData)(vlSelf->top__DOT__jump)))) 
             & (0U != (0x1fU & (vlSelf->imem_rdata 
                                >> 7U))))) {
            __Vdlyvval__top__DOT__exu__DOT__regfile__DOT__registers__v32 
                = ((3U == (0x7fU & vlSelf->imem_rdata))
                    ? vlSelf->top__DOT__exu__DOT__load_data
                    : ((IData)(vlSelf->top__DOT__jump)
                        ? ((IData)(4U) + vlSelf->top__DOT__pc)
                        : vlSelf->top__DOT__exu__DOT__alu_result_reg));
            __Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v32 = 1U;
            __Vdlyvdim0__top__DOT__exu__DOT__regfile__DOT__registers__v32 
                = (0x1fU & (vlSelf->imem_rdata >> 7U));
        }
        vlSelf->top__DOT__pc = vlSelf->top__DOT__next_pc;
    }
    if (__Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v0) {
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[1U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[2U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[3U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[4U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[5U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[6U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[7U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[8U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[9U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0xaU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0xbU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0xcU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0xdU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0xeU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0xfU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x10U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x11U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x12U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x13U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x14U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x15U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x16U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x17U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x18U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x19U] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x1aU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x1bU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x1cU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x1dU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x1eU] = 0U;
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[0x1fU] = 0U;
    }
    if (__Vdlyvset__top__DOT__exu__DOT__regfile__DOT__registers__v32) {
        vlSelf->top__DOT__exu__DOT__regfile__DOT__registers[__Vdlyvdim0__top__DOT__exu__DOT__regfile__DOT__registers__v32] 
            = __Vdlyvval__top__DOT__exu__DOT__regfile__DOT__registers__v32;
    }
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
    vlSelf->imem_addr = vlSelf->top__DOT__pc;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ top__DOT__exu__DOT____VdfgExtracted_h34086c27__0;
    top__DOT__exu__DOT____VdfgExtracted_h34086c27__0 = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
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
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 2, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
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
                    VL_FATAL_MT("vsrc/top.v", 2, "", "Active region did not converge.");
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
                VL_FATAL_MT("vsrc/top.v", 2, "", "NBA region did not converge.");
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
