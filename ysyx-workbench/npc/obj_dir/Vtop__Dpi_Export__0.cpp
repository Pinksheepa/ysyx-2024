// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "Vtop.h"
#include "Vtop__Syms.h"
#include "verilated_dpi.h"


int Vtop::get_gpr(int index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root::get_gpr\n"); );
    // Init
    IData/*31:0*/ index__Vcvt;
    index__Vcvt = 0;
    IData/*31:0*/ get_gpr__Vfuncrtn__Vcvt;
    get_gpr__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_gpr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vtop__Vcb_get_gpr_t __Vcb = (Vtop__Vcb_get_gpr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    index__Vcvt = index;
    (*__Vcb)((Vtop__Syms*)(__Vscopep->symsp()), index__Vcvt, get_gpr__Vfuncrtn__Vcvt);
    int get_gpr__Vfuncrtn;
    for (size_t get_gpr__Vfuncrtn__Vidx = 0; get_gpr__Vfuncrtn__Vidx < 1; ++get_gpr__Vfuncrtn__Vidx) get_gpr__Vfuncrtn = get_gpr__Vfuncrtn__Vcvt;
    return get_gpr__Vfuncrtn;
}
