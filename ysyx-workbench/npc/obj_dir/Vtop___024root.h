// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(imem_valid,0,0);
    VL_OUT8(dmem_valid,0,0);
    VL_OUT8(dmem_wen,3,0);
    CData/*0:0*/ top__DOT__pc_wen;
    CData/*0:0*/ top__DOT__jump;
    CData/*0:0*/ top__DOT__is_jalr;
    CData/*0:0*/ top__DOT__idu__DOT__is_i_type;
    CData/*0:0*/ top__DOT__idu__DOT__is_u_type;
    CData/*3:0*/ top__DOT__idu__DOT__alu_op_val;
    CData/*0:0*/ top__DOT__exu__DOT__branch_taken_reg;
    CData/*3:0*/ top__DOT__exu__DOT__store_mask;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_OUT(imem_addr,31,0);
    VL_IN(imem_rdata,31,0);
    VL_OUT(dmem_addr,31,0);
    VL_IN(dmem_rdata,31,0);
    VL_OUT(dmem_wdata,31,0);
    IData/*31:0*/ top__DOT__pc;
    IData/*31:0*/ top__DOT__next_pc;
    IData/*31:0*/ top__DOT__rs2_data;
    IData/*31:0*/ top__DOT__alu_src1;
    IData/*31:0*/ top__DOT__alu_src2;
    IData/*31:0*/ top__DOT__reg_x1;
    IData/*31:0*/ top__DOT__reg_x2;
    IData/*31:0*/ top__DOT__reg_a0;
    IData/*31:0*/ top__DOT__idu__DOT__imm_val;
    IData/*31:0*/ top__DOT__exu__DOT__alu_src1;
    IData/*31:0*/ top__DOT__exu__DOT__alu_src2;
    IData/*31:0*/ top__DOT__exu__DOT__alu_result_reg;
    IData/*31:0*/ top__DOT__exu__DOT__store_data;
    IData/*31:0*/ top__DOT__exu__DOT__load_data;
    IData/*31:0*/ top__DOT__exu__DOT__regfile__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__exu__DOT__regfile__DOT__registers;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
