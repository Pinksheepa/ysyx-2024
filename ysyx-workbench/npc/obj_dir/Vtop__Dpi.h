// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at vsrc/DPI_System.v:14:45
    extern void npc_ebreak(int a0_value);
    // DPI import at vsrc/DPI_System.v:13:34
    extern void npc_ecall(int a0_value);

#ifdef __cplusplus
}
#endif

#endif  // guard
