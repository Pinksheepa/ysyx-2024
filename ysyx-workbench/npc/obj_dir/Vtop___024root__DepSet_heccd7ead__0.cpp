// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
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
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__dpi_system__DOT__npc_ecall_TOP(IData/*31:0*/ a0_value);
void Vtop___024root____Vdpiimwrap_top__DOT__dpi_system__DOT__npc_ebreak_TOP(IData/*31:0*/ a0_value);
extern const VlUnpacked<CData/*2:0*/, 32> Vtop__ConstPool__TABLE_h95502e58_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vtop__ConstPool__TABLE_h952cab83_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__top__DOT__exception_handler__DOT__handling_exception;
    __Vdly__top__DOT__exception_handler__DOT__handling_exception = 0;
    CData/*0:0*/ __Vdly__top__DOT__dpi_system__DOT__ecall_handled;
    __Vdly__top__DOT__dpi_system__DOT__ecall_handled = 0;
    CData/*0:0*/ __Vdly__top__DOT__dpi_system__DOT__ebreak_handled;
    __Vdly__top__DOT__dpi_system__DOT__ebreak_handled = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT__registers__v0;
    __Vdlyvset__top__DOT__regfile__DOT__registers__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__regfile__DOT__registers__v32;
    __Vdlyvdim0__top__DOT__regfile__DOT__registers__v32 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__regfile__DOT__registers__v32;
    __Vdlyvval__top__DOT__regfile__DOT__registers__v32 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT__registers__v32;
    __Vdlyvset__top__DOT__regfile__DOT__registers__v32 = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mcycle;
    __Vdly__top__DOT__csr_file__DOT__mcycle = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mcycleh;
    __Vdly__top__DOT__csr_file__DOT__mcycleh = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mtval;
    __Vdly__top__DOT__csr_file__DOT__mtval = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mcause;
    __Vdly__top__DOT__csr_file__DOT__mcause = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mscratch;
    __Vdly__top__DOT__csr_file__DOT__mscratch = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mepc;
    __Vdly__top__DOT__csr_file__DOT__mepc = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mtvec;
    __Vdly__top__DOT__csr_file__DOT__mtvec = 0;
    IData/*31:0*/ __Vdly__top__DOT__csr_file__DOT__mstatus;
    __Vdly__top__DOT__csr_file__DOT__mstatus = 0;
    // Body
    __Vdly__top__DOT__dpi_system__DOT__ebreak_handled 
        = vlSelf->top__DOT__dpi_system__DOT__ebreak_handled;
    __Vdly__top__DOT__dpi_system__DOT__ecall_handled 
        = vlSelf->top__DOT__dpi_system__DOT__ecall_handled;
    __Vdly__top__DOT__csr_file__DOT__mcycleh = vlSelf->top__DOT__csr_file__DOT__mcycleh;
    __Vdly__top__DOT__csr_file__DOT__mcycle = vlSelf->top__DOT__csr_file__DOT__mcycle;
    __Vdly__top__DOT__exception_handler__DOT__handling_exception 
        = vlSelf->top__DOT__exception_handler__DOT__handling_exception;
    __Vdlyvset__top__DOT__regfile__DOT__registers__v0 = 0U;
    __Vdlyvset__top__DOT__regfile__DOT__registers__v32 = 0U;
    __Vdly__top__DOT__csr_file__DOT__mscratch = vlSelf->top__DOT__csr_file__DOT__mscratch;
    __Vdly__top__DOT__csr_file__DOT__mtvec = vlSelf->top__DOT__csr_file__DOT__mtvec;
    __Vdly__top__DOT__csr_file__DOT__mstatus = vlSelf->top__DOT__csr_file__DOT__mstatus;
    __Vdly__top__DOT__csr_file__DOT__mepc = vlSelf->top__DOT__csr_file__DOT__mepc;
    __Vdly__top__DOT__csr_file__DOT__mcause = vlSelf->top__DOT__csr_file__DOT__mcause;
    __Vdly__top__DOT__csr_file__DOT__mtval = vlSelf->top__DOT__csr_file__DOT__mtval;
    if (vlSelf->rst) {
        vlSelf->top__DOT__regfile__DOT__i = 0x20U;
        __Vdly__top__DOT__csr_file__DOT__mcycle = 0U;
        __Vdly__top__DOT__csr_file__DOT__mcycleh = 0U;
        __Vdlyvset__top__DOT__regfile__DOT__registers__v0 = 1U;
        __Vdly__top__DOT__csr_file__DOT__mscratch = 0U;
        __Vdly__top__DOT__csr_file__DOT__mtvec = 0U;
        __Vdly__top__DOT__csr_file__DOT__mstatus = 0U;
        __Vdly__top__DOT__csr_file__DOT__mepc = 0U;
        __Vdly__top__DOT__csr_file__DOT__mcause = 0U;
        __Vdly__top__DOT__csr_file__DOT__mtval = 0U;
        vlSelf->top__DOT__csr_file__DOT__misa = 0x40001100U;
    } else {
        __Vdly__top__DOT__csr_file__DOT__mcycleh = (IData)(
                                                           ((1ULL 
                                                             + 
                                                             (((QData)((IData)(vlSelf->top__DOT__csr_file__DOT__mcycleh)) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(vlSelf->top__DOT__csr_file__DOT__mcycle)))) 
                                                            >> 0x20U));
        __Vdly__top__DOT__csr_file__DOT__mcycle = ((IData)(1U) 
                                                   + vlSelf->top__DOT__csr_file__DOT__mcycle);
        if ((((IData)(vlSelf->top__DOT__wb_reg_wen) 
              & (0U != (IData)(vlSelf->top__DOT__wb_rd))) 
             & (0U != (IData)(vlSelf->top__DOT__wb_rd)))) {
            __Vdlyvval__top__DOT__regfile__DOT__registers__v32 
                = vlSelf->top__DOT__wb_data;
            __Vdlyvset__top__DOT__regfile__DOT__registers__v32 = 1U;
            __Vdlyvdim0__top__DOT__regfile__DOT__registers__v32 
                = vlSelf->top__DOT__wb_rd;
        }
        if (vlSelf->top__DOT__exception_valid) {
            __Vdly__top__DOT__csr_file__DOT__mstatus 
                = (0x1800U | (0xffffff7fU & vlSelf->top__DOT__csr_file__DOT__mstatus));
            __Vdly__top__DOT__csr_file__DOT__mepc = vlSelf->top__DOT__exception_pc;
            __Vdly__top__DOT__csr_file__DOT__mcause 
                = vlSelf->top__DOT__exception_code;
            __Vdly__top__DOT__csr_file__DOT__mtval 
                = vlSelf->top__DOT__exception_val;
        }
        if (vlSelf->top__DOT__mem_csr_wen) {
            if ((0x300U != (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                if ((0x305U != (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                    if ((0x340U == (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                        __Vdly__top__DOT__csr_file__DOT__mscratch 
                            = ((0U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                ? vlSelf->top__DOT__mem_csr_write_data
                                : ((1U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                    ? (vlSelf->top__DOT__csr_file__DOT__mscratch 
                                       | vlSelf->top__DOT__mem_csr_write_data)
                                    : ((2U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                        ? (vlSelf->top__DOT__csr_file__DOT__mscratch 
                                           & (~ vlSelf->top__DOT__mem_csr_write_data))
                                        : vlSelf->top__DOT__csr_file__DOT__mscratch)));
                    }
                    if ((0x340U != (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                        if ((0x341U == (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                            __Vdly__top__DOT__csr_file__DOT__mepc 
                                = ((0U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                    ? vlSelf->top__DOT__mem_csr_write_data
                                    : ((1U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                        ? (vlSelf->top__DOT__csr_file__DOT__mepc 
                                           | vlSelf->top__DOT__mem_csr_write_data)
                                        : ((2U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                            ? (vlSelf->top__DOT__csr_file__DOT__mepc 
                                               & (~ vlSelf->top__DOT__mem_csr_write_data))
                                            : vlSelf->top__DOT__csr_file__DOT__mepc)));
                        }
                        if ((0x341U != (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                            if ((0x342U == (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                                __Vdly__top__DOT__csr_file__DOT__mcause 
                                    = ((0U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                        ? vlSelf->top__DOT__mem_csr_write_data
                                        : ((1U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                            ? (vlSelf->top__DOT__csr_file__DOT__mcause 
                                               | vlSelf->top__DOT__mem_csr_write_data)
                                            : ((2U 
                                                == (IData)(vlSelf->top__DOT__mem_csr_op))
                                                ? (vlSelf->top__DOT__csr_file__DOT__mcause 
                                                   & (~ vlSelf->top__DOT__mem_csr_write_data))
                                                : vlSelf->top__DOT__csr_file__DOT__mcause)));
                            }
                            if ((0x342U != (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                                if ((0x343U == (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                                    __Vdly__top__DOT__csr_file__DOT__mtval 
                                        = ((0U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                            ? vlSelf->top__DOT__mem_csr_write_data
                                            : ((1U 
                                                == (IData)(vlSelf->top__DOT__mem_csr_op))
                                                ? (vlSelf->top__DOT__csr_file__DOT__mtval 
                                                   | vlSelf->top__DOT__mem_csr_write_data)
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelf->top__DOT__mem_csr_op))
                                                    ? 
                                                   (vlSelf->top__DOT__csr_file__DOT__mtval 
                                                    & (~ vlSelf->top__DOT__mem_csr_write_data))
                                                    : vlSelf->top__DOT__csr_file__DOT__mtval)));
                                }
                            }
                        }
                    }
                }
                if ((0x305U == (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                    __Vdly__top__DOT__csr_file__DOT__mtvec 
                        = ((0U == (IData)(vlSelf->top__DOT__mem_csr_op))
                            ? vlSelf->top__DOT__mem_csr_write_data
                            : ((1U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                ? (vlSelf->top__DOT__csr_file__DOT__mtvec 
                                   | vlSelf->top__DOT__mem_csr_write_data)
                                : ((2U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                    ? (vlSelf->top__DOT__csr_file__DOT__mtvec 
                                       & (~ vlSelf->top__DOT__mem_csr_write_data))
                                    : vlSelf->top__DOT__csr_file__DOT__mtvec)));
                }
            }
            if ((0x300U == (IData)(vlSelf->top__DOT__mem_csr_addr))) {
                __Vdly__top__DOT__csr_file__DOT__mstatus 
                    = ((0U == (IData)(vlSelf->top__DOT__mem_csr_op))
                        ? vlSelf->top__DOT__mem_csr_write_data
                        : ((1U == (IData)(vlSelf->top__DOT__mem_csr_op))
                            ? (vlSelf->top__DOT__csr_file__DOT__mstatus 
                               | vlSelf->top__DOT__mem_csr_write_data)
                            : ((2U == (IData)(vlSelf->top__DOT__mem_csr_op))
                                ? (vlSelf->top__DOT__csr_file__DOT__mstatus 
                                   & (~ vlSelf->top__DOT__mem_csr_write_data))
                                : vlSelf->top__DOT__csr_file__DOT__mstatus)));
            }
        }
    }
    if (vlSelf->rst) {
        vlSelf->top__DOT__dpi_system__DOT__terminate_reg = 0U;
        __Vdly__top__DOT__dpi_system__DOT__ecall_handled = 0U;
        __Vdly__top__DOT__dpi_system__DOT__ebreak_handled = 0U;
    } else {
        if ((((IData)(vlSelf->top__DOT__is_ecall) & (IData)(vlSelf->top__DOT__wb_valid)) 
             & (~ (IData)(vlSelf->top__DOT__dpi_system__DOT__ecall_handled)))) {
            Vtop___024root____Vdpiimwrap_top__DOT__dpi_system__DOT__npc_ecall_TOP(
                                                                                vlSelf->top__DOT__regfile__DOT__registers
                                                                                [0xaU]);
            __Vdly__top__DOT__dpi_system__DOT__ecall_handled = 1U;
        } else if ((1U & (~ (IData)(vlSelf->top__DOT__is_ecall)))) {
            __Vdly__top__DOT__dpi_system__DOT__ecall_handled = 0U;
        }
        if ((((IData)(vlSelf->top__DOT__is_ebreak) 
              & (IData)(vlSelf->top__DOT__wb_valid)) 
             & (~ (IData)(vlSelf->top__DOT__dpi_system__DOT__ebreak_handled)))) {
            Vtop___024root____Vdpiimwrap_top__DOT__dpi_system__DOT__npc_ebreak_TOP(
                                                                                vlSelf->top__DOT__regfile__DOT__registers
                                                                                [0xaU]);
            __Vdly__top__DOT__dpi_system__DOT__ebreak_handled = 1U;
            vlSelf->top__DOT__dpi_system__DOT__terminate_reg = 1U;
        } else if ((1U & (~ (IData)(vlSelf->top__DOT__is_ebreak)))) {
            __Vdly__top__DOT__dpi_system__DOT__ebreak_handled = 0U;
        }
    }
    vlSelf->top__DOT__ex_illegal_instr = ((~ (((IData)(vlSelf->rst) 
                                               | (IData)(vlSelf->top__DOT__flush_ex)) 
                                              | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                          & (IData)(vlSelf->top__DOT__idu__DOT__illegal_instr_reg));
    vlSelf->top__DOT__ex_jump = ((~ (((IData)(vlSelf->rst) 
                                      | (IData)(vlSelf->top__DOT__flush_ex)) 
                                     | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                 & (IData)(vlSelf->top__DOT__id_jump));
    vlSelf->top__DOT__mem_branch_taken = ((~ ((IData)(vlSelf->rst) 
                                              | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                          & (IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg));
    if (((IData)(vlSelf->rst) | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) {
        vlSelf->top__DOT__mem_rs2_data = 0U;
        vlSelf->top__DOT__mem_mem_type = 0U;
        vlSelf->top__DOT__mem_funct3 = 0U;
        vlSelf->top__DOT__mem_rs2 = 0U;
        vlSelf->top__DOT__mem_rs1 = 0U;
    } else {
        vlSelf->top__DOT__mem_rs2_data = vlSelf->top__DOT__exu__DOT__forwarded_rs2_data;
        vlSelf->top__DOT__mem_mem_type = vlSelf->top__DOT__ex_mem_type;
        vlSelf->top__DOT__mem_funct3 = (7U & (vlSelf->top__DOT__ex_instr 
                                              >> 0xcU));
        vlSelf->top__DOT__mem_rs2 = vlSelf->top__DOT__ex_rs2;
        vlSelf->top__DOT__mem_rs1 = vlSelf->top__DOT__ex_rs1;
    }
    if (vlSelf->rst) {
        vlSelf->top__DOT__wb_mem_rdata = 0U;
        vlSelf->top__DOT__wb_csr_rdata = 0U;
        vlSelf->top__DOT__wb_alu_result = 0U;
    } else {
        vlSelf->top__DOT__wb_mem_rdata = vlSelf->top__DOT__mem_read_data;
        vlSelf->top__DOT__wb_csr_rdata = vlSelf->top__DOT__mem_csr_rdata;
        vlSelf->top__DOT__wb_alu_result = vlSelf->top__DOT__mem_alu_result;
    }
    vlSelf->top__DOT__mem_alu_result = (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                         ? 0U : vlSelf->top__DOT__exu__DOT__alu_result_reg);
    vlSelf->top__DOT__wb_pc = ((IData)(vlSelf->rst)
                                ? 0U : vlSelf->top__DOT__mem_pc);
    vlSelf->top__DOT__mem_pc = (((IData)(vlSelf->rst) 
                                 | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                 ? 0U : vlSelf->top__DOT__ex_pc);
    vlSelf->top__DOT__wb_csr_addr = ((IData)(vlSelf->rst)
                                      ? 0U : (IData)(vlSelf->top__DOT__mem_csr_addr));
    vlSelf->top__DOT__mem_csr_addr = (((IData)(vlSelf->rst) 
                                       | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                       ? 0U : (IData)(vlSelf->top__DOT__ex_csr_addr));
    vlSelf->top__DOT__wb_csr_op = ((IData)(vlSelf->rst)
                                    ? 0U : (IData)(vlSelf->top__DOT__mem_csr_op));
    vlSelf->top__DOT__mem_csr_op = (((IData)(vlSelf->rst) 
                                     | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                     ? 0U : (IData)(vlSelf->top__DOT__ex_csr_op));
    vlSelf->top__DOT__wb_instr = ((IData)(vlSelf->rst)
                                   ? 0U : vlSelf->top__DOT__mem_instr);
    vlSelf->top__DOT__mem_instr = (((IData)(vlSelf->rst) 
                                    | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                    ? 0U : vlSelf->top__DOT__ex_instr);
    vlSelf->top__DOT__wb_wb_sel = ((IData)(vlSelf->rst)
                                    ? 0U : (IData)(vlSelf->top__DOT__mem_wb_sel));
    vlSelf->top__DOT__mem_wb_sel = (((IData)(vlSelf->rst) 
                                     | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                     ? 0U : (IData)(vlSelf->top__DOT__ex_wb_sel));
    vlSelf->top__DOT__wb_csr_write_data = ((IData)(vlSelf->rst)
                                            ? 0U : vlSelf->top__DOT__mem_csr_write_data);
    vlSelf->top__DOT__mem_csr_write_data = (((IData)(vlSelf->rst) 
                                             | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                             ? 0U : 
                                            ((IData)(vlSelf->top__DOT__ex_csr_imm)
                                              ? vlSelf->top__DOT__ex_imm
                                              : vlSelf->top__DOT__exu__DOT__alu_src1));
    if (vlSelf->rst) {
        vlSelf->top__DOT__pc = 0x80000000U;
        vlSelf->top__DOT__wb_rd = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard)))) {
            vlSelf->top__DOT__pc = ((IData)(vlSelf->top__DOT__exception_redirect)
                                     ? vlSelf->top__DOT__exception_target
                                     : ((IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg)
                                         ? ((IData)(vlSelf->top__DOT__ex_is_jalr)
                                             ? (0xfffffffeU 
                                                & (vlSelf->top__DOT__ex_imm 
                                                   + vlSelf->top__DOT__exu__DOT__alu_src1))
                                             : (vlSelf->top__DOT__ex_imm 
                                                + vlSelf->top__DOT__ex_pc))
                                         : vlSelf->top__DOT__pc_plus4));
        }
        vlSelf->top__DOT__wb_rd = vlSelf->top__DOT__mem_rd;
    }
    vlSelf->top__DOT__mem_rd = (((IData)(vlSelf->rst) 
                                 | (IData)(vlSelf->top__DOT__pipeline_flush_exc))
                                 ? 0U : (IData)(vlSelf->top__DOT__ex_rd));
    if ((((IData)(vlSelf->rst) | (IData)(vlSelf->top__DOT__flush_ex)) 
         | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) {
        vlSelf->top__DOT__ex_alu_op = 0U;
        vlSelf->top__DOT__ex_rs2_data = 0U;
        vlSelf->top__DOT__ex_rs1_data = 0U;
        vlSelf->top__DOT__ex_mem_type = 0U;
        vlSelf->top__DOT__ex_rs2 = 0U;
        vlSelf->top__DOT__ex_rs1 = 0U;
        vlSelf->top__DOT__ex_pc = 0U;
        vlSelf->top__DOT__ex_csr_addr = 0U;
        vlSelf->top__DOT__ex_csr_op = 0U;
        vlSelf->top__DOT__ex_instr = 0U;
        vlSelf->top__DOT__ex_wb_sel = 0U;
        vlSelf->top__DOT__ex_imm = 0U;
        vlSelf->top__DOT__ex_rd = 0U;
    } else {
        vlSelf->top__DOT__ex_alu_op = vlSelf->top__DOT__idu__DOT__alu_op_val;
        vlSelf->top__DOT__ex_rs2_data = ((0U == (0x1fU 
                                                 & (vlSelf->top__DOT__id_instr 
                                                    >> 0x14U)))
                                          ? 0U : vlSelf->top__DOT__regfile__DOT__registers
                                         [(0x1fU & 
                                           (vlSelf->top__DOT__id_instr 
                                            >> 0x14U))]);
        vlSelf->top__DOT__ex_rs1_data = ((0U == (0x1fU 
                                                 & (vlSelf->top__DOT__id_instr 
                                                    >> 0xfU)))
                                          ? 0U : vlSelf->top__DOT__regfile__DOT__registers
                                         [(0x1fU & 
                                           (vlSelf->top__DOT__id_instr 
                                            >> 0xfU))]);
        vlSelf->top__DOT__ex_mem_type = vlSelf->top__DOT__idu__DOT__mem_type_val;
        vlSelf->top__DOT__ex_rs2 = (0x1fU & (vlSelf->top__DOT__id_instr 
                                             >> 0x14U));
        vlSelf->top__DOT__ex_rs1 = (0x1fU & (vlSelf->top__DOT__id_instr 
                                             >> 0xfU));
        vlSelf->top__DOT__ex_pc = vlSelf->top__DOT__id_pc;
        vlSelf->top__DOT__ex_csr_addr = (vlSelf->top__DOT__id_instr 
                                         >> 0x14U);
        vlSelf->top__DOT__ex_csr_op = ((IData)(vlSelf->top__DOT__idu__DOT__is_csrrw)
                                        ? 0U : (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                                 & (0x2000U 
                                                    == 
                                                    (0x3000U 
                                                     & vlSelf->top__DOT__id_instr)))
                                                 ? 1U
                                                 : 
                                                (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                                  & (0x3000U 
                                                     == 
                                                     (0x3000U 
                                                      & vlSelf->top__DOT__id_instr)))
                                                  ? 2U
                                                  : 0U)));
        vlSelf->top__DOT__ex_instr = vlSelf->top__DOT__id_instr;
        vlSelf->top__DOT__ex_wb_sel = ((3U == (0x7fU 
                                               & vlSelf->top__DOT__id_instr))
                                        ? 1U : ((IData)(vlSelf->top__DOT__id_jump)
                                                 ? 2U
                                                 : 
                                                ((IData)(vlSelf->top__DOT__idu__DOT__is_csr)
                                                  ? 3U
                                                  : 0U)));
        vlSelf->top__DOT__ex_imm = ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type)
                                     ? (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                         & (IData)(vlSelf->top__DOT__idu__DOT__is_csr_imm))
                                         ? (0x1fU & 
                                            (vlSelf->top__DOT__id_instr 
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
                                         : ((0x63U 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__id_instr))
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
                                                 ? 
                                                (0xfffff000U 
                                                 & vlSelf->top__DOT__id_instr)
                                                 : 
                                                ((0x6fU 
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
                                                  : 0U)))));
        vlSelf->top__DOT__ex_rd = (0x1fU & (vlSelf->top__DOT__id_instr 
                                            >> 7U));
    }
    vlSelf->top__DOT__ex_branch = ((~ (((IData)(vlSelf->rst) 
                                        | (IData)(vlSelf->top__DOT__flush_ex)) 
                                       | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                   & (0x63U == (0x7fU 
                                                & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__ex_use_imm = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                                       | ((0x23U == 
                                           (0x7fU & vlSelf->top__DOT__id_instr)) 
                                          | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                             | (0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__id_instr))))));
    vlSelf->top__DOT__wb_csr_imm = ((~ (IData)(vlSelf->rst)) 
                                    & (IData)(vlSelf->top__DOT__mem_csr_imm));
    vlSelf->top__DOT__wb_mem_unsigned = ((~ (IData)(vlSelf->rst)) 
                                         & (IData)(vlSelf->top__DOT__mem_mem_unsigned));
    vlSelf->top__DOT__wb_csr_ren = ((~ (IData)(vlSelf->rst)) 
                                    & (IData)(vlSelf->top__DOT__mem_csr_ren));
    vlSelf->top__DOT__mem_mem_wen = ((~ ((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                     & (IData)(vlSelf->top__DOT__ex_mem_wen));
    vlSelf->top__DOT__wb_mem_ren = ((~ (IData)(vlSelf->rst)) 
                                    & (IData)(vlSelf->top__DOT__mem_mem_ren));
    vlSelf->top__DOT__wb_csr_wen = ((~ (IData)(vlSelf->rst)) 
                                    & (IData)(vlSelf->top__DOT__mem_csr_wen));
    vlSelf->top__DOT__csr_file__DOT__mcycle = __Vdly__top__DOT__csr_file__DOT__mcycle;
    vlSelf->top__DOT__csr_file__DOT__mcycleh = __Vdly__top__DOT__csr_file__DOT__mcycleh;
    vlSelf->top__DOT__csr_file__DOT__mscratch = __Vdly__top__DOT__csr_file__DOT__mscratch;
    vlSelf->top__DOT__csr_file__DOT__mstatus = __Vdly__top__DOT__csr_file__DOT__mstatus;
    vlSelf->top__DOT__csr_file__DOT__mepc = __Vdly__top__DOT__csr_file__DOT__mepc;
    vlSelf->top__DOT__csr_file__DOT__mcause = __Vdly__top__DOT__csr_file__DOT__mcause;
    vlSelf->top__DOT__csr_file__DOT__mtval = __Vdly__top__DOT__csr_file__DOT__mtval;
    vlSelf->top__DOT__dpi_system__DOT__ecall_handled 
        = __Vdly__top__DOT__dpi_system__DOT__ecall_handled;
    vlSelf->top__DOT__dpi_system__DOT__ebreak_handled 
        = __Vdly__top__DOT__dpi_system__DOT__ebreak_handled;
    if (__Vdlyvset__top__DOT__regfile__DOT__registers__v0) {
        vlSelf->top__DOT__regfile__DOT__registers[0U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[1U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[2U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[3U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[4U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[5U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[6U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[7U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[8U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[9U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0xaU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0xbU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0xcU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0xdU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0xeU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0xfU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x10U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x11U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x12U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x13U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x14U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x15U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x16U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x17U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x18U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x19U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x1aU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x1bU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x1cU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x1dU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x1eU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers[0x1fU] = 0U;
    }
    if (__Vdlyvset__top__DOT__regfile__DOT__registers__v32) {
        vlSelf->top__DOT__regfile__DOT__registers[__Vdlyvdim0__top__DOT__regfile__DOT__registers__v32] 
            = __Vdlyvval__top__DOT__regfile__DOT__registers__v32;
    }
    vlSelf->top__DOT__wb_reg_wen = ((~ (IData)(vlSelf->rst)) 
                                    & (IData)(vlSelf->top__DOT__mem_reg_wen));
    vlSelf->dmem_wdata = vlSelf->top__DOT__mem_rs2_data;
    vlSelf->top__DOT__mem_csr_imm = ((~ ((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                     & (IData)(vlSelf->top__DOT__ex_csr_imm));
    vlSelf->top__DOT__mem_mem_unsigned = ((~ ((IData)(vlSelf->rst) 
                                              | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                          & (IData)(vlSelf->top__DOT__ex_mem_unsigned));
    vlSelf->top__DOT__mem_csr_ren = ((~ ((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                     & (IData)(vlSelf->top__DOT__ex_csr_ren));
    vlSelf->top__DOT__ex_mem_wen = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & (0x23U == (0x7fU 
                                                 & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__mem_mem_ren = ((~ ((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                     & (IData)(vlSelf->top__DOT__ex_mem_ren));
    vlSelf->top__DOT__mem_csr_wen = ((~ ((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                     & (IData)(vlSelf->top__DOT__ex_csr_wen));
    vlSelf->top__DOT____VdfgTmp_h0197263e__0 = (IData)(
                                                       (0x73U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->top__DOT__wb_instr)));
    vlSelf->top__DOT__wb_data = ((2U & (IData)(vlSelf->top__DOT__wb_wb_sel))
                                  ? ((1U & (IData)(vlSelf->top__DOT__wb_wb_sel))
                                      ? vlSelf->top__DOT__wb_csr_rdata
                                      : ((IData)(4U) 
                                         + vlSelf->top__DOT__wb_pc))
                                  : ((1U & (IData)(vlSelf->top__DOT__wb_wb_sel))
                                      ? vlSelf->top__DOT__wb_mem_rdata
                                      : vlSelf->top__DOT__wb_alu_result));
    vlSelf->top__DOT__pc_plus4 = ((IData)(4U) + vlSelf->top__DOT__pc);
    vlSelf->top__DOT__ex_is_jalr = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & (IData)(vlSelf->top__DOT__id_is_jalr));
    vlSelf->top__DOT__is_ecall = ((IData)(vlSelf->top__DOT____VdfgTmp_h0197263e__0) 
                                  & (0U == (vlSelf->top__DOT__wb_instr 
                                            >> 0x14U)));
    vlSelf->top__DOT__is_ebreak = ((IData)(vlSelf->top__DOT____VdfgTmp_h0197263e__0) 
                                   & (1U == (vlSelf->top__DOT__wb_instr 
                                             >> 0x14U)));
    vlSelf->top__DOT__mem_reg_wen = ((~ ((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__pipeline_flush_exc))) 
                                     & (IData)(vlSelf->top__DOT__ex_reg_wen));
    vlSelf->top__DOT__ex_mem_unsigned = ((~ (((IData)(vlSelf->rst) 
                                              | (IData)(vlSelf->top__DOT__flush_ex)) 
                                             | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                         & (IData)(vlSelf->top__DOT__idu__DOT__mem_unsigned_val));
    vlSelf->top__DOT__ex_csr_ren = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & (IData)(vlSelf->top__DOT__idu__DOT__is_csr));
    vlSelf->dmem_addr = vlSelf->top__DOT__mem_alu_result;
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
    vlSelf->top__DOT__ex_mem_ren = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & (3U == (0x7fU 
                                              & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__ex_csr_wen = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & ((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                       & (IData)(((0U 
                                                   != 
                                                   (0xf8000U 
                                                    & vlSelf->top__DOT__id_instr)) 
                                                  | (IData)(vlSelf->top__DOT__idu__DOT__is_csrrw)))));
    vlSelf->top__DOT__wb_valid = ((IData)(vlSelf->top__DOT__wb_reg_wen) 
                                  | ((IData)(vlSelf->top__DOT__wb_mem_ren) 
                                     | ((IData)(vlSelf->top__DOT__is_ecall) 
                                        | (IData)(vlSelf->top__DOT__is_ebreak))));
    vlSelf->top__DOT__ex_csr_imm = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & (IData)(vlSelf->top__DOT__idu__DOT__is_csr_imm));
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
    vlSelf->top__DOT__ex_reg_wen = ((~ (((IData)(vlSelf->rst) 
                                         | (IData)(vlSelf->top__DOT__flush_ex)) 
                                        | (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard))) 
                                    & ((((0x33U == 
                                          (0x7fU & vlSelf->top__DOT__id_instr)) 
                                         | ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                                            | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                               | (IData)(vlSelf->top__DOT__id_jump)))) 
                                        | (IData)(vlSelf->top__DOT__idu__DOT__is_csr)) 
                                       & (0U != (0x1fU 
                                                 & (vlSelf->top__DOT__id_instr 
                                                    >> 7U)))));
    if (vlSelf->rst) {
        __Vdly__top__DOT__exception_handler__DOT__handling_exception = 0U;
        vlSelf->top__DOT__exception_valid = 0U;
        vlSelf->top__DOT__exception_code = 0U;
        vlSelf->top__DOT__exception_pc = 0U;
        vlSelf->top__DOT__exception_val = 0U;
        vlSelf->top__DOT__pipeline_flush_exc = 0U;
        vlSelf->top__DOT__exception_redirect = 0U;
        vlSelf->top__DOT__exception_target = 0U;
        vlSelf->top__DOT__id_pc = 0U;
        vlSelf->top__DOT__id_instr = 0U;
    } else {
        vlSelf->top__DOT__exception_valid = 0U;
        vlSelf->top__DOT__pipeline_flush_exc = 0U;
        vlSelf->top__DOT__exception_redirect = 0U;
        if (((~ (IData)(vlSelf->top__DOT__exception_handler__DOT__handling_exception)) 
             & (IData)(vlSelf->top__DOT__exception_handler__DOT__exception_detected))) {
            __Vdly__top__DOT__exception_handler__DOT__handling_exception = 1U;
            vlSelf->top__DOT__exception_valid = 1U;
            vlSelf->top__DOT__exception_code = vlSelf->top__DOT__exception_handler__DOT__detected_exception_code;
            vlSelf->top__DOT__exception_pc = vlSelf->top__DOT__id_pc;
            vlSelf->top__DOT__exception_val = vlSelf->top__DOT__exception_handler__DOT__detected_exception_val;
            vlSelf->top__DOT__pipeline_flush_exc = 1U;
            vlSelf->top__DOT__exception_redirect = 1U;
            vlSelf->top__DOT__exception_target = vlSelf->top__DOT__csr_file__DOT__mtvec;
        } else if (vlSelf->top__DOT__exception_handler__DOT__handling_exception) {
            __Vdly__top__DOT__exception_handler__DOT__handling_exception = 0U;
        }
        if (vlSelf->top__DOT__flush_if) {
            vlSelf->top__DOT__id_pc = 0U;
            vlSelf->top__DOT__id_instr = 0U;
        } else if ((1U & (~ (IData)(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard)))) {
            vlSelf->top__DOT__id_pc = vlSelf->imem_addr;
            vlSelf->top__DOT__id_instr = vlSelf->imem_rdata;
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
    vlSelf->top__DOT__exception_handler__DOT__handling_exception 
        = __Vdly__top__DOT__exception_handler__DOT__handling_exception;
    vlSelf->top__DOT__csr_file__DOT__mtvec = __Vdly__top__DOT__csr_file__DOT__mtvec;
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
    vlSelf->top__DOT__exu__DOT____VdfgExtracted_ha5b322d2__0 
        = (vlSelf->top__DOT__exu__DOT__final_alu_src1 
           + vlSelf->top__DOT__exu__DOT__alu_src2);
    vlSelf->imem_addr = vlSelf->top__DOT__pc;
    vlSelf->top__DOT__flush_if = (((IData)(vlSelf->top__DOT__ex_jump) 
                                   | (IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg)) 
                                  | (IData)(vlSelf->top__DOT__pipeline_flush_exc));
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
    vlSelf->top__DOT__idu__DOT__is_u_type = ((0x37U 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__id_instr)) 
                                             | (0x17U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard 
        = ((IData)(vlSelf->top__DOT__ex_mem_ren) & 
           ((0U != (IData)(vlSelf->top__DOT__ex_rd)) 
            & (((IData)(vlSelf->top__DOT__ex_rd) == 
                (0x1fU & (vlSelf->top__DOT__id_instr 
                          >> 0xfU))) | ((IData)(vlSelf->top__DOT__ex_rd) 
                                        == (0x1fU & 
                                            (vlSelf->top__DOT__id_instr 
                                             >> 0x14U))))));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0 
        = (IData)((0x73U == (0x707fU & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__idu__DOT____VdfgExtracted_h2ec28fd3__0 
        = ((3U == (0x7fU & vlSelf->top__DOT__id_instr)) 
           | (0x23U == (0x7fU & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__id_is_jalr = (IData)((0x67U == 
                                            (0x707fU 
                                             & vlSelf->top__DOT__id_instr)));
    vlSelf->top__DOT__idu__DOT__is_csr = ((0x73U == 
                                           (0x7fU & vlSelf->top__DOT__id_instr)) 
                                          & (0U != 
                                             (7U & 
                                              (vlSelf->top__DOT__id_instr 
                                               >> 0xcU))));
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
