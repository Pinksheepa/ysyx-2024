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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_OUT8(imem_valid,0,0);
        VL_OUT8(dmem_valid,0,0);
        VL_OUT8(dmem_wen,3,0);
        CData/*0:0*/ top__DOT__is_ecall;
        CData/*0:0*/ top__DOT__is_ebreak;
        CData/*0:0*/ top__DOT__wb_valid;
        CData/*0:0*/ top__DOT__flush_if;
        CData/*0:0*/ top__DOT__flush_ex;
        CData/*0:0*/ top__DOT__exception_valid;
        CData/*3:0*/ top__DOT__exception_code;
        CData/*0:0*/ top__DOT__exception_redirect;
        CData/*0:0*/ top__DOT__pipeline_flush_exc;
        CData/*0:0*/ top__DOT__id_jump;
        CData/*0:0*/ top__DOT__id_is_jalr;
        CData/*4:0*/ top__DOT__ex_rs1;
        CData/*4:0*/ top__DOT__ex_rs2;
        CData/*4:0*/ top__DOT__ex_rd;
        CData/*0:0*/ top__DOT__ex_reg_wen;
        CData/*0:0*/ top__DOT__ex_mem_wen;
        CData/*0:0*/ top__DOT__ex_mem_ren;
        CData/*3:0*/ top__DOT__ex_alu_op;
        CData/*0:0*/ top__DOT__ex_use_imm;
        CData/*0:0*/ top__DOT__ex_branch;
        CData/*0:0*/ top__DOT__ex_jump;
        CData/*0:0*/ top__DOT__ex_is_jalr;
        CData/*2:0*/ top__DOT__ex_mem_type;
        CData/*0:0*/ top__DOT__ex_mem_unsigned;
        CData/*1:0*/ top__DOT__ex_wb_sel;
        CData/*0:0*/ top__DOT__ex_csr_ren;
        CData/*0:0*/ top__DOT__ex_csr_wen;
        CData/*0:0*/ top__DOT__ex_illegal_instr;
        CData/*0:0*/ top__DOT__ex_csr_imm;
        CData/*1:0*/ top__DOT__ex_csr_op;
        CData/*1:0*/ top__DOT__forward_a;
        CData/*1:0*/ top__DOT__forward_b;
        CData/*4:0*/ top__DOT__mem_rs1;
        CData/*4:0*/ top__DOT__mem_rs2;
        CData/*4:0*/ top__DOT__mem_rd;
        CData/*0:0*/ top__DOT__mem_reg_wen;
        CData/*0:0*/ top__DOT__mem_mem_wen;
        CData/*0:0*/ top__DOT__mem_mem_ren;
        CData/*0:0*/ top__DOT__mem_branch_taken;
        CData/*2:0*/ top__DOT__mem_funct3;
        CData/*2:0*/ top__DOT__mem_mem_type;
        CData/*0:0*/ top__DOT__mem_mem_unsigned;
        CData/*1:0*/ top__DOT__mem_wb_sel;
        CData/*0:0*/ top__DOT__mem_csr_ren;
        CData/*0:0*/ top__DOT__mem_csr_wen;
        CData/*1:0*/ top__DOT__mem_csr_op;
        CData/*0:0*/ top__DOT__mem_csr_imm;
        CData/*4:0*/ top__DOT__wb_rd;
        CData/*0:0*/ top__DOT__wb_reg_wen;
        CData/*0:0*/ top__DOT__wb_mem_ren;
        CData/*1:0*/ top__DOT__wb_wb_sel;
        CData/*0:0*/ top__DOT__wb_mem_unsigned;
        CData/*0:0*/ top__DOT__wb_csr_ren;
        CData/*0:0*/ top__DOT__wb_csr_wen;
        CData/*1:0*/ top__DOT__wb_csr_op;
        CData/*0:0*/ top__DOT__wb_csr_imm;
        CData/*0:0*/ top__DOT____VdfgTmp_h0197263e__0;
        CData/*0:0*/ top__DOT__exception_handler__DOT__exception_detected;
        CData/*3:0*/ top__DOT__exception_handler__DOT__detected_exception_code;
    };
    struct {
        CData/*0:0*/ top__DOT__exception_handler__DOT__handling_exception;
        CData/*0:0*/ top__DOT__dpi_system__DOT__terminate_reg;
        CData/*0:0*/ top__DOT__dpi_system__DOT__ecall_handled;
        CData/*0:0*/ top__DOT__dpi_system__DOT__ebreak_handled;
        CData/*0:0*/ top__DOT__idu__DOT__is_csr;
        CData/*0:0*/ top__DOT__idu__DOT__is_csrrw;
        CData/*0:0*/ top__DOT__idu__DOT__is_csr_imm;
        CData/*0:0*/ top__DOT__idu__DOT__is_i_type;
        CData/*0:0*/ top__DOT__idu__DOT__is_u_type;
        CData/*3:0*/ top__DOT__idu__DOT__alu_op_val;
        CData/*2:0*/ top__DOT__idu__DOT__mem_type_val;
        CData/*0:0*/ top__DOT__idu__DOT__mem_unsigned_val;
        CData/*0:0*/ top__DOT__idu__DOT__illegal_instr_reg;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgExtracted_h2ec28fd3__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0;
        CData/*0:0*/ top__DOT__hazard_unit__DOT__load_use_hazard;
        CData/*0:0*/ top__DOT__exu__DOT__branch_taken_reg;
        CData/*3:0*/ top__DOT__memu__DOT__byte_en;
        CData/*4:0*/ __Vtableidx1;
        CData/*0:0*/ __Vtrigrprev__TOP__clk;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ top__DOT__ex_csr_addr;
        SData/*11:0*/ top__DOT__mem_csr_addr;
        SData/*11:0*/ top__DOT__wb_csr_addr;
        VL_OUT(imem_addr,31,0);
        VL_IN(imem_rdata,31,0);
        VL_OUT(dmem_addr,31,0);
        VL_IN(dmem_rdata,31,0);
        VL_OUT(dmem_wdata,31,0);
        IData/*31:0*/ top__DOT__exception_pc;
        IData/*31:0*/ top__DOT__exception_val;
        IData/*31:0*/ top__DOT__exception_target;
        IData/*31:0*/ top__DOT__pc;
        IData/*31:0*/ top__DOT__pc_plus4;
        IData/*31:0*/ top__DOT__id_pc;
        IData/*31:0*/ top__DOT__id_instr;
        IData/*31:0*/ top__DOT__wb_data;
        IData/*31:0*/ top__DOT__ex_pc;
        IData/*31:0*/ top__DOT__ex_instr;
        IData/*31:0*/ top__DOT__ex_rs1_data;
        IData/*31:0*/ top__DOT__ex_rs2_data;
        IData/*31:0*/ top__DOT__ex_imm;
        IData/*31:0*/ top__DOT__mem_pc;
        IData/*31:0*/ top__DOT__mem_instr;
        IData/*31:0*/ top__DOT__mem_alu_result;
        IData/*31:0*/ top__DOT__mem_rs2_data;
        IData/*31:0*/ top__DOT__mem_csr_write_data;
        IData/*31:0*/ top__DOT__mem_read_data;
        IData/*31:0*/ top__DOT__mem_csr_rdata;
        IData/*31:0*/ top__DOT__wb_pc;
        IData/*31:0*/ top__DOT__wb_instr;
        IData/*31:0*/ top__DOT__wb_alu_result;
        IData/*31:0*/ top__DOT__wb_mem_rdata;
        IData/*31:0*/ top__DOT__wb_csr_rdata;
        IData/*31:0*/ top__DOT__wb_csr_write_data;
        IData/*31:0*/ top__DOT__exception_handler__DOT__detected_exception_val;
        IData/*31:0*/ top__DOT__regfile__DOT__i;
        IData/*31:0*/ top__DOT__exu__DOT__alu_src1;
        IData/*31:0*/ top__DOT__exu__DOT__forwarded_rs2_data;
        IData/*31:0*/ top__DOT__exu__DOT__alu_src2;
        IData/*31:0*/ top__DOT__exu__DOT__final_alu_src1;
        IData/*31:0*/ top__DOT__exu__DOT__alu_result_reg;
        IData/*31:0*/ top__DOT__exu__DOT____VdfgExtracted_ha5b322d2__0;
        IData/*31:0*/ top__DOT__csr_file__DOT__mstatus;
    };
    struct {
        IData/*31:0*/ top__DOT__csr_file__DOT__misa;
        IData/*31:0*/ top__DOT__csr_file__DOT__mtvec;
        IData/*31:0*/ top__DOT__csr_file__DOT__mscratch;
        IData/*31:0*/ top__DOT__csr_file__DOT__mepc;
        IData/*31:0*/ top__DOT__csr_file__DOT__mcause;
        IData/*31:0*/ top__DOT__csr_file__DOT__mtval;
        IData/*31:0*/ top__DOT__csr_file__DOT__mcycle;
        IData/*31:0*/ top__DOT__csr_file__DOT__mcycleh;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__registers;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
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
