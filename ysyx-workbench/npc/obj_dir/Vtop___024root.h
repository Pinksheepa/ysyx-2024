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
    CData/*2:0*/ top__DOT__inst_type;
    CData/*3:0*/ top__DOT__alu_op;
    CData/*0:0*/ top__DOT__alu_less_than;
    CData/*0:0*/ top__DOT__trap_flag;
    CData/*0:0*/ top__DOT____VdfgTmp_h5482c01c__0;
    CData/*0:0*/ top__DOT__idu__DOT__i_type;
    CData/*0:0*/ top__DOT__idu__DOT__u_type;
    CData/*3:0*/ top__DOT__idu__DOT__alu_op_r_type;
    CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_h88c6b025__0;
    CData/*3:0*/ top__DOT__idu__DOT____VdfgTmp_h9f39052c__0;
    CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_h87b4775b__0;
    CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_h22a85453__0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top__DOT__pc;
    IData/*31:0*/ top__DOT__next_pc;
    IData/*31:0*/ top__DOT__inst;
    IData/*31:0*/ top__DOT__rs1_data;
    IData/*31:0*/ top__DOT__rs2_data;
    IData/*31:0*/ top__DOT__imm;
    IData/*31:0*/ top__DOT__alu_src1;
    IData/*31:0*/ top__DOT__alu_src2;
    IData/*31:0*/ top__DOT__alu_result;
    IData/*31:0*/ top__DOT__mem_read_data;
    IData/*31:0*/ top__DOT__cycle_count;
    IData/*31:0*/ top__DOT__gpr__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ top__DOT__data_mem__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __Vfunc_top__DOT__inst_mem__DOT__pmem_read__1__Vfuncout;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ top__DOT__alu__DOT__mul_signed;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__gpr__DOT__rf;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__data_mem__DOT__dmem;
    VlUnpacked<IData/*31:0*/, 4096> top__DOT__csr__DOT__csr_regs;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

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
