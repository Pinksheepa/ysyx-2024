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
    // DPI import at vsrc/top.v:12:34
    extern void npc_putchar(char ch);
    // DPI import at vsrc/top.v:9:33
    extern int pmem_read(int addr, int len);
    // DPI import at vsrc/top.v:10:34
    extern void pmem_write(int addr, int data, int len);
    // DPI import at vsrc/top.v:11:34
    extern void sim_exit(int exit_code);

#ifdef __cplusplus
}
#endif

#endif  // guard
