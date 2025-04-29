// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+196,"imem_addr", false,-1, 31,0);
    tracep->declBus(c+197,"imem_rdata", false,-1, 31,0);
    tracep->declBit(c+198,"imem_valid", false,-1);
    tracep->declBus(c+199,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+200,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+201,"dmem_wdata", false,-1, 31,0);
    tracep->declBit(c+202,"dmem_valid", false,-1);
    tracep->declBus(c+203,"dmem_wen", false,-1, 3,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+196,"imem_addr", false,-1, 31,0);
    tracep->declBus(c+197,"imem_rdata", false,-1, 31,0);
    tracep->declBit(c+198,"imem_valid", false,-1);
    tracep->declBus(c+199,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+200,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+201,"dmem_wdata", false,-1, 31,0);
    tracep->declBit(c+202,"dmem_valid", false,-1);
    tracep->declBus(c+203,"dmem_wen", false,-1, 3,0);
    tracep->declBus(c+206,"DMEM_BASE", false,-1, 31,0);
    tracep->declBit(c+1,"is_ecall", false,-1);
    tracep->declBit(c+2,"is_ebreak", false,-1);
    tracep->declBus(c+3,"a0_value", false,-1, 31,0);
    tracep->declBit(c+4,"dpi_terminate", false,-1);
    tracep->declBit(c+5,"wb_valid", false,-1);
    tracep->declBit(c+6,"stall_if", false,-1);
    tracep->declBit(c+6,"stall_id", false,-1);
    tracep->declBit(c+207,"stall_ex", false,-1);
    tracep->declBit(c+207,"stall_mem", false,-1);
    tracep->declBit(c+207,"stall_wb", false,-1);
    tracep->declBit(c+7,"flush_if", false,-1);
    tracep->declBit(c+7,"flush_id", false,-1);
    tracep->declBit(c+8,"flush_ex", false,-1);
    tracep->declBit(c+9,"flush_mem", false,-1);
    tracep->declBit(c+6,"pc_stall", false,-1);
    tracep->declBit(c+6,"ifid_stall", false,-1);
    tracep->declBit(c+6,"idex_bubble", false,-1);
    tracep->declBit(c+10,"ifid_flush", false,-1);
    tracep->declBit(c+10,"if_flush", false,-1);
    tracep->declBit(c+11,"exception_valid", false,-1);
    tracep->declBus(c+12,"exception_code", false,-1, 3,0);
    tracep->declBus(c+13,"exception_pc", false,-1, 31,0);
    tracep->declBus(c+14,"exception_val", false,-1, 31,0);
    tracep->declBit(c+15,"exception_redirect", false,-1);
    tracep->declBus(c+16,"exception_target", false,-1, 31,0);
    tracep->declBit(c+9,"pipeline_flush_exc", false,-1);
    tracep->declBus(c+17,"trap_vector", false,-1, 31,0);
    tracep->declBus(c+18,"pc", false,-1, 31,0);
    tracep->declBus(c+19,"pc_plus4", false,-1, 31,0);
    tracep->declBus(c+196,"if_pc", false,-1, 31,0);
    tracep->declBus(c+197,"if_instr", false,-1, 31,0);
    tracep->declBus(c+20,"id_pc", false,-1, 31,0);
    tracep->declBus(c+21,"id_instr", false,-1, 31,0);
    tracep->declBus(c+22,"id_rs1", false,-1, 4,0);
    tracep->declBus(c+23,"id_rs2", false,-1, 4,0);
    tracep->declBus(c+24,"id_rd", false,-1, 4,0);
    tracep->declBus(c+25,"id_rs1_data", false,-1, 31,0);
    tracep->declBus(c+26,"id_rs2_data", false,-1, 31,0);
    tracep->declBus(c+27,"id_imm", false,-1, 31,0);
    tracep->declBit(c+28,"id_reg_wen", false,-1);
    tracep->declBit(c+29,"id_mem_wen", false,-1);
    tracep->declBit(c+30,"id_mem_ren", false,-1);
    tracep->declBus(c+31,"id_alu_op", false,-1, 3,0);
    tracep->declBit(c+32,"id_use_imm", false,-1);
    tracep->declBit(c+33,"id_branch", false,-1);
    tracep->declBit(c+34,"id_jump", false,-1);
    tracep->declBit(c+35,"id_is_jalr", false,-1);
    tracep->declBus(c+36,"id_mem_type", false,-1, 2,0);
    tracep->declBit(c+37,"id_mem_unsigned", false,-1);
    tracep->declBus(c+38,"id_wb_sel", false,-1, 1,0);
    tracep->declBit(c+39,"id_csr_ren", false,-1);
    tracep->declBit(c+40,"id_csr_wen", false,-1);
    tracep->declBus(c+41,"id_csr_addr", false,-1, 11,0);
    tracep->declBit(c+42,"id_illegal_instr", false,-1);
    tracep->declBus(c+43,"id_csr_op", false,-1, 1,0);
    tracep->declBit(c+44,"id_csr_imm", false,-1);
    tracep->declBus(c+45,"wb_data", false,-1, 31,0);
    tracep->declBus(c+46,"wb_rd_final", false,-1, 4,0);
    tracep->declBit(c+47,"wb_reg_wen_final", false,-1);
    tracep->declBus(c+48,"ex_pc", false,-1, 31,0);
    tracep->declBus(c+49,"ex_instr", false,-1, 31,0);
    tracep->declBus(c+50,"ex_rs1_data", false,-1, 31,0);
    tracep->declBus(c+51,"ex_rs2_data", false,-1, 31,0);
    tracep->declBus(c+52,"ex_rs1", false,-1, 4,0);
    tracep->declBus(c+53,"ex_rs2", false,-1, 4,0);
    tracep->declBus(c+54,"ex_rd", false,-1, 4,0);
    tracep->declBus(c+55,"ex_imm", false,-1, 31,0);
    tracep->declBit(c+56,"ex_reg_wen", false,-1);
    tracep->declBit(c+57,"ex_mem_wen", false,-1);
    tracep->declBit(c+58,"ex_mem_ren", false,-1);
    tracep->declBus(c+59,"ex_alu_op", false,-1, 3,0);
    tracep->declBit(c+60,"ex_use_imm", false,-1);
    tracep->declBit(c+61,"ex_branch", false,-1);
    tracep->declBit(c+62,"ex_jump", false,-1);
    tracep->declBit(c+63,"ex_is_jalr", false,-1);
    tracep->declBus(c+64,"ex_mem_type", false,-1, 2,0);
    tracep->declBit(c+65,"ex_mem_unsigned", false,-1);
    tracep->declBus(c+66,"ex_wb_sel", false,-1, 1,0);
    tracep->declBit(c+67,"ex_csr_ren", false,-1);
    tracep->declBit(c+68,"ex_csr_wen", false,-1);
    tracep->declBus(c+69,"ex_csr_addr", false,-1, 11,0);
    tracep->declBit(c+70,"ex_illegal_instr", false,-1);
    tracep->declBit(c+71,"ex_csr_imm", false,-1);
    tracep->declBus(c+72,"ex_csr_op", false,-1, 1,0);
    tracep->declBus(c+73,"forward_a", false,-1, 1,0);
    tracep->declBus(c+74,"forward_b", false,-1, 1,0);
    tracep->declBus(c+75,"ex_alu_result", false,-1, 31,0);
    tracep->declBit(c+76,"ex_branch_taken", false,-1);
    tracep->declBus(c+77,"ex_store_data", false,-1, 31,0);
    tracep->declBus(c+78,"ex_branch_target", false,-1, 31,0);
    tracep->declBus(c+79,"ex_funct3", false,-1, 2,0);
    tracep->declBus(c+80,"ex_csr_write_data", false,-1, 31,0);
    tracep->declBus(c+81,"mem_pc", false,-1, 31,0);
    tracep->declBus(c+82,"mem_instr", false,-1, 31,0);
    tracep->declBus(c+83,"mem_alu_result", false,-1, 31,0);
    tracep->declBus(c+84,"mem_rs2_data", false,-1, 31,0);
    tracep->declBus(c+85,"mem_rs1", false,-1, 4,0);
    tracep->declBus(c+86,"mem_rs2", false,-1, 4,0);
    tracep->declBus(c+87,"mem_rd", false,-1, 4,0);
    tracep->declBit(c+88,"mem_reg_wen", false,-1);
    tracep->declBit(c+89,"mem_mem_wen", false,-1);
    tracep->declBit(c+90,"mem_mem_ren", false,-1);
    tracep->declBit(c+91,"mem_branch_taken", false,-1);
    tracep->declBus(c+92,"mem_funct3", false,-1, 2,0);
    tracep->declBus(c+93,"mem_mem_type", false,-1, 2,0);
    tracep->declBit(c+94,"mem_mem_unsigned", false,-1);
    tracep->declBus(c+95,"mem_wb_sel", false,-1, 1,0);
    tracep->declBit(c+96,"mem_csr_ren", false,-1);
    tracep->declBit(c+97,"mem_csr_wen", false,-1);
    tracep->declBus(c+98,"mem_csr_addr", false,-1, 11,0);
    tracep->declBus(c+99,"mem_csr_op", false,-1, 1,0);
    tracep->declBit(c+100,"mem_csr_imm", false,-1);
    tracep->declBus(c+101,"mem_csr_write_data", false,-1, 31,0);
    tracep->declBus(c+204,"mem_read_data", false,-1, 31,0);
    tracep->declBus(c+205,"mem_write_data", false,-1, 31,0);
    tracep->declBus(c+102,"mem_csr_rdata", false,-1, 31,0);
    tracep->declBus(c+103,"wb_pc", false,-1, 31,0);
    tracep->declBus(c+104,"wb_instr", false,-1, 31,0);
    tracep->declBus(c+105,"wb_alu_result", false,-1, 31,0);
    tracep->declBus(c+106,"wb_mem_rdata", false,-1, 31,0);
    tracep->declBus(c+46,"wb_rd", false,-1, 4,0);
    tracep->declBit(c+107,"wb_reg_wen", false,-1);
    tracep->declBit(c+108,"wb_mem_ren", false,-1);
    tracep->declBus(c+109,"wb_wb_sel", false,-1, 1,0);
    tracep->declBit(c+110,"wb_mem_unsigned", false,-1);
    tracep->declBus(c+111,"wb_csr_rdata", false,-1, 31,0);
    tracep->declBit(c+112,"wb_csr_ren", false,-1);
    tracep->declBit(c+113,"wb_csr_wen", false,-1);
    tracep->declBus(c+114,"wb_csr_addr", false,-1, 11,0);
    tracep->declBus(c+115,"wb_csr_op", false,-1, 1,0);
    tracep->declBit(c+116,"wb_csr_imm", false,-1);
    tracep->declBus(c+117,"wb_csr_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("csr_file ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+98,"read_addr", false,-1, 11,0);
    tracep->declBit(c+96,"read_en", false,-1);
    tracep->declBus(c+98,"write_addr", false,-1, 11,0);
    tracep->declBus(c+101,"write_data", false,-1, 31,0);
    tracep->declBit(c+97,"write_en", false,-1);
    tracep->declBus(c+99,"csr_op", false,-1, 1,0);
    tracep->declBus(c+102,"read_data", false,-1, 31,0);
    tracep->declBit(c+11,"exception", false,-1);
    tracep->declBus(c+12,"exception_code", false,-1, 3,0);
    tracep->declBus(c+13,"exception_pc", false,-1, 31,0);
    tracep->declBus(c+14,"exception_val", false,-1, 31,0);
    tracep->declBus(c+17,"trap_vector", false,-1, 31,0);
    tracep->declBus(c+208,"CSR_MSTATUS", false,-1, 11,0);
    tracep->declBus(c+209,"CSR_MISA", false,-1, 11,0);
    tracep->declBus(c+210,"CSR_MEDELEG", false,-1, 11,0);
    tracep->declBus(c+211,"CSR_MIDELEG", false,-1, 11,0);
    tracep->declBus(c+212,"CSR_MIE", false,-1, 11,0);
    tracep->declBus(c+213,"CSR_MTVEC", false,-1, 11,0);
    tracep->declBus(c+214,"CSR_MSCRATCH", false,-1, 11,0);
    tracep->declBus(c+215,"CSR_MEPC", false,-1, 11,0);
    tracep->declBus(c+216,"CSR_MCAUSE", false,-1, 11,0);
    tracep->declBus(c+217,"CSR_MTVAL", false,-1, 11,0);
    tracep->declBus(c+218,"CSR_MIP", false,-1, 11,0);
    tracep->declBus(c+219,"CSR_MCYCLE", false,-1, 11,0);
    tracep->declBus(c+220,"CSR_MCYCLEH", false,-1, 11,0);
    tracep->declBus(c+221,"EXC_INSTR_ADDR_MISALIGNED", false,-1, 3,0);
    tracep->declBus(c+222,"EXC_INSTR_ACCESS_FAULT", false,-1, 3,0);
    tracep->declBus(c+223,"EXC_ILLEGAL_INSTRUCTION", false,-1, 3,0);
    tracep->declBus(c+224,"EXC_BREAKPOINT", false,-1, 3,0);
    tracep->declBus(c+225,"EXC_LOAD_ADDR_MISALIGNED", false,-1, 3,0);
    tracep->declBus(c+226,"EXC_LOAD_ACCESS_FAULT", false,-1, 3,0);
    tracep->declBus(c+227,"EXC_STORE_ADDR_MISALIGNED", false,-1, 3,0);
    tracep->declBus(c+228,"EXC_STORE_ACCESS_FAULT", false,-1, 3,0);
    tracep->declBus(c+229,"EXC_ECALL_FROM_UMODE", false,-1, 3,0);
    tracep->declBus(c+230,"EXC_ECALL_FROM_SMODE", false,-1, 3,0);
    tracep->declBus(c+231,"EXC_ECALL_FROM_MMODE", false,-1, 3,0);
    tracep->declBus(c+118,"mstatus", false,-1, 31,0);
    tracep->declBus(c+119,"misa", false,-1, 31,0);
    tracep->declBus(c+17,"mtvec", false,-1, 31,0);
    tracep->declBus(c+120,"mscratch", false,-1, 31,0);
    tracep->declBus(c+121,"mepc", false,-1, 31,0);
    tracep->declBus(c+122,"mcause", false,-1, 31,0);
    tracep->declBus(c+123,"mtval", false,-1, 31,0);
    tracep->declBus(c+124,"mcycle", false,-1, 31,0);
    tracep->declBus(c+125,"mcycleh", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("dpi_system ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+1,"is_ecall", false,-1);
    tracep->declBit(c+2,"is_ebreak", false,-1);
    tracep->declBus(c+3,"a0_value", false,-1, 31,0);
    tracep->declBit(c+5,"valid", false,-1);
    tracep->declBit(c+4,"terminate", false,-1);
    tracep->declBit(c+4,"terminate_reg", false,-1);
    tracep->declBit(c+126,"ecall_handled", false,-1);
    tracep->declBit(c+127,"ebreak_handled", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exception_handler ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+42,"id_illegal_instr", false,-1);
    tracep->declBus(c+21,"id_instr", false,-1, 31,0);
    tracep->declBus(c+20,"id_pc", false,-1, 31,0);
    tracep->declBit(c+232,"wb_valid", false,-1);
    tracep->declBus(c+103,"wb_pc", false,-1, 31,0);
    tracep->declBus(c+104,"wb_instr", false,-1, 31,0);
    tracep->declBit(c+11,"exception_valid", false,-1);
    tracep->declBus(c+12,"exception_code", false,-1, 3,0);
    tracep->declBus(c+13,"exception_pc", false,-1, 31,0);
    tracep->declBus(c+14,"exception_val", false,-1, 31,0);
    tracep->declBit(c+9,"pipeline_flush", false,-1);
    tracep->declBus(c+17,"trap_vector", false,-1, 31,0);
    tracep->declBit(c+15,"redirect_pc", false,-1);
    tracep->declBus(c+16,"new_pc", false,-1, 31,0);
    tracep->declBus(c+223,"EXC_ILLEGAL_INSTRUCTION", false,-1, 3,0);
    tracep->declBit(c+128,"exception_detected", false,-1);
    tracep->declBus(c+129,"detected_exception_code", false,-1, 3,0);
    tracep->declBus(c+130,"detected_exception_val", false,-1, 31,0);
    tracep->declBit(c+131,"handling_exception", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+48,"ex_pc", false,-1, 31,0);
    tracep->declBus(c+49,"ex_instr", false,-1, 31,0);
    tracep->declBus(c+50,"ex_rs1_data", false,-1, 31,0);
    tracep->declBus(c+51,"ex_rs2_data", false,-1, 31,0);
    tracep->declBus(c+52,"ex_rs1", false,-1, 4,0);
    tracep->declBus(c+53,"ex_rs2", false,-1, 4,0);
    tracep->declBus(c+54,"ex_rd", false,-1, 4,0);
    tracep->declBus(c+55,"ex_imm", false,-1, 31,0);
    tracep->declBus(c+59,"ex_alu_op", false,-1, 3,0);
    tracep->declBit(c+60,"ex_use_imm", false,-1);
    tracep->declBit(c+61,"ex_branch", false,-1);
    tracep->declBit(c+62,"ex_jump", false,-1);
    tracep->declBit(c+63,"ex_is_jalr", false,-1);
    tracep->declBit(c+56,"ex_reg_wen", false,-1);
    tracep->declBit(c+57,"ex_mem_wen", false,-1);
    tracep->declBit(c+58,"ex_mem_ren", false,-1);
    tracep->declBus(c+64,"ex_mem_type", false,-1, 2,0);
    tracep->declBit(c+65,"ex_mem_unsigned", false,-1);
    tracep->declBus(c+66,"ex_wb_sel", false,-1, 1,0);
    tracep->declBit(c+67,"ex_csr_ren", false,-1);
    tracep->declBit(c+68,"ex_csr_wen", false,-1);
    tracep->declBus(c+69,"ex_csr_addr", false,-1, 11,0);
    tracep->declBus(c+72,"ex_csr_op", false,-1, 1,0);
    tracep->declBit(c+71,"ex_csr_imm", false,-1);
    tracep->declBus(c+73,"forward_a", false,-1, 1,0);
    tracep->declBus(c+74,"forward_b", false,-1, 1,0);
    tracep->declBus(c+83,"mem_alu_result", false,-1, 31,0);
    tracep->declBus(c+45,"wb_data", false,-1, 31,0);
    tracep->declBus(c+75,"alu_result", false,-1, 31,0);
    tracep->declBit(c+76,"branch_taken", false,-1);
    tracep->declBus(c+77,"store_data", false,-1, 31,0);
    tracep->declBus(c+78,"branch_target", false,-1, 31,0);
    tracep->declBus(c+80,"csr_write_data", false,-1, 31,0);
    tracep->declBus(c+221,"ALU_ADD", false,-1, 3,0);
    tracep->declBus(c+222,"ALU_SUB", false,-1, 3,0);
    tracep->declBus(c+223,"ALU_AND", false,-1, 3,0);
    tracep->declBus(c+224,"ALU_OR", false,-1, 3,0);
    tracep->declBus(c+225,"ALU_XOR", false,-1, 3,0);
    tracep->declBus(c+226,"ALU_SLL", false,-1, 3,0);
    tracep->declBus(c+227,"ALU_SRL", false,-1, 3,0);
    tracep->declBus(c+228,"ALU_SRA", false,-1, 3,0);
    tracep->declBus(c+229,"ALU_SLT", false,-1, 3,0);
    tracep->declBus(c+230,"ALU_SLTU", false,-1, 3,0);
    tracep->declBus(c+233,"ALU_LUI", false,-1, 3,0);
    tracep->declBus(c+231,"ALU_COPY_A", false,-1, 3,0);
    tracep->declBus(c+234,"ALU_COPY_B", false,-1, 3,0);
    tracep->declBus(c+132,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+77,"forwarded_rs2_data", false,-1, 31,0);
    tracep->declBus(c+133,"alu_src2", false,-1, 31,0);
    tracep->declBit(c+134,"is_auipc", false,-1);
    tracep->declBit(c+135,"is_jal", false,-1);
    tracep->declBus(c+136,"final_alu_src1", false,-1, 31,0);
    tracep->declBus(c+75,"alu_result_reg", false,-1, 31,0);
    tracep->declBus(c+78,"branch_target_reg", false,-1, 31,0);
    tracep->declBus(c+79,"funct3", false,-1, 2,0);
    tracep->declBit(c+76,"branch_taken_reg", false,-1);
    tracep->declBus(c+80,"csr_write_data_reg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("forwarding_unit ");
    tracep->declBus(c+52,"ex_rs1", false,-1, 4,0);
    tracep->declBus(c+53,"ex_rs2", false,-1, 4,0);
    tracep->declBus(c+87,"mem_rd", false,-1, 4,0);
    tracep->declBit(c+88,"mem_reg_wen", false,-1);
    tracep->declBus(c+46,"wb_rd", false,-1, 4,0);
    tracep->declBit(c+107,"wb_reg_wen", false,-1);
    tracep->declBus(c+73,"forward_a", false,-1, 1,0);
    tracep->declBus(c+74,"forward_b", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("hazard_unit ");
    tracep->declBus(c+22,"id_rs1", false,-1, 4,0);
    tracep->declBus(c+23,"id_rs2", false,-1, 4,0);
    tracep->declBus(c+54,"ex_rd", false,-1, 4,0);
    tracep->declBit(c+58,"ex_mem_read", false,-1);
    tracep->declBit(c+76,"ex_branch_taken", false,-1);
    tracep->declBit(c+62,"ex_jump", false,-1);
    tracep->declBit(c+6,"pc_stall", false,-1);
    tracep->declBit(c+6,"ifid_stall", false,-1);
    tracep->declBit(c+6,"idex_bubble", false,-1);
    tracep->declBit(c+10,"ifid_flush", false,-1);
    tracep->declBit(c+10,"if_flush", false,-1);
    tracep->declBit(c+6,"load_use_hazard", false,-1);
    tracep->declBit(c+10,"control_hazard", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+20,"id_pc", false,-1, 31,0);
    tracep->declBus(c+21,"id_instr", false,-1, 31,0);
    tracep->declBus(c+25,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+26,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+22,"rs1", false,-1, 4,0);
    tracep->declBus(c+23,"rs2", false,-1, 4,0);
    tracep->declBus(c+24,"rd", false,-1, 4,0);
    tracep->declBus(c+27,"imm", false,-1, 31,0);
    tracep->declBit(c+28,"reg_wen", false,-1);
    tracep->declBit(c+29,"mem_wen", false,-1);
    tracep->declBit(c+30,"mem_ren", false,-1);
    tracep->declBus(c+31,"alu_op", false,-1, 3,0);
    tracep->declBit(c+32,"use_imm", false,-1);
    tracep->declBit(c+33,"branch", false,-1);
    tracep->declBit(c+34,"jump", false,-1);
    tracep->declBit(c+35,"is_jalr", false,-1);
    tracep->declBus(c+36,"mem_type", false,-1, 2,0);
    tracep->declBit(c+37,"mem_unsigned", false,-1);
    tracep->declBus(c+38,"wb_sel", false,-1, 1,0);
    tracep->declBit(c+39,"csr_ren", false,-1);
    tracep->declBit(c+40,"csr_wen", false,-1);
    tracep->declBus(c+41,"csr_addr", false,-1, 11,0);
    tracep->declBus(c+43,"csr_op", false,-1, 1,0);
    tracep->declBit(c+44,"csr_imm", false,-1);
    tracep->declBit(c+42,"illegal_instr", false,-1);
    tracep->declBus(c+137,"opcode", false,-1, 6,0);
    tracep->declBus(c+138,"funct3", false,-1, 2,0);
    tracep->declBus(c+139,"funct7", false,-1, 6,0);
    tracep->declBus(c+41,"funct12", false,-1, 11,0);
    tracep->declBit(c+140,"is_ebreak", false,-1);
    tracep->declBit(c+141,"is_ecall", false,-1);
    tracep->declBit(c+142,"is_fence", false,-1);
    tracep->declBit(c+39,"is_csr", false,-1);
    tracep->declBit(c+143,"is_csrrw", false,-1);
    tracep->declBit(c+144,"is_csrrs", false,-1);
    tracep->declBit(c+145,"is_csrrc", false,-1);
    tracep->declBit(c+44,"is_csr_imm", false,-1);
    tracep->declBit(c+146,"is_r_type", false,-1);
    tracep->declBit(c+147,"is_i_type", false,-1);
    tracep->declBit(c+29,"is_s_type", false,-1);
    tracep->declBit(c+33,"is_b_type", false,-1);
    tracep->declBit(c+148,"is_u_type", false,-1);
    tracep->declBit(c+149,"is_j_type", false,-1);
    tracep->declBit(c+30,"is_load", false,-1);
    tracep->declBit(c+29,"is_store", false,-1);
    tracep->declBit(c+149,"is_jal", false,-1);
    tracep->declBit(c+150,"is_lui", false,-1);
    tracep->declBit(c+151,"is_auipc", false,-1);
    tracep->declBus(c+152,"i_imm", false,-1, 31,0);
    tracep->declBus(c+153,"s_imm", false,-1, 31,0);
    tracep->declBus(c+154,"b_imm", false,-1, 31,0);
    tracep->declBus(c+155,"u_imm", false,-1, 31,0);
    tracep->declBus(c+156,"j_imm", false,-1, 31,0);
    tracep->declBus(c+157,"csr_zimm", false,-1, 31,0);
    tracep->declBus(c+27,"imm_val", false,-1, 31,0);
    tracep->declBus(c+221,"ALU_ADD", false,-1, 3,0);
    tracep->declBus(c+222,"ALU_SUB", false,-1, 3,0);
    tracep->declBus(c+223,"ALU_AND", false,-1, 3,0);
    tracep->declBus(c+224,"ALU_OR", false,-1, 3,0);
    tracep->declBus(c+225,"ALU_XOR", false,-1, 3,0);
    tracep->declBus(c+226,"ALU_SLL", false,-1, 3,0);
    tracep->declBus(c+227,"ALU_SRL", false,-1, 3,0);
    tracep->declBus(c+228,"ALU_SRA", false,-1, 3,0);
    tracep->declBus(c+229,"ALU_SLT", false,-1, 3,0);
    tracep->declBus(c+230,"ALU_SLTU", false,-1, 3,0);
    tracep->declBus(c+233,"ALU_LUI", false,-1, 3,0);
    tracep->declBus(c+231,"ALU_COPY_A", false,-1, 3,0);
    tracep->declBus(c+234,"ALU_COPY_B", false,-1, 3,0);
    tracep->declBus(c+31,"alu_op_val", false,-1, 3,0);
    tracep->declBus(c+36,"mem_type_val", false,-1, 2,0);
    tracep->declBit(c+37,"mem_unsigned_val", false,-1);
    tracep->declBus(c+38,"wb_sel_val", false,-1, 1,0);
    tracep->declBus(c+43,"csr_op_val", false,-1, 1,0);
    tracep->declBit(c+42,"illegal_instr_reg", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+6,"stall", false,-1);
    tracep->declBit(c+76,"branch_taken", false,-1);
    tracep->declBus(c+78,"branch_target", false,-1, 31,0);
    tracep->declBus(c+18,"pc", false,-1, 31,0);
    tracep->declBus(c+19,"pc_plus4", false,-1, 31,0);
    tracep->declBus(c+196,"if_pc", false,-1, 31,0);
    tracep->declBus(c+196,"imem_addr", false,-1, 31,0);
    tracep->declBus(c+197,"imem_rdata", false,-1, 31,0);
    tracep->declBit(c+198,"imem_valid", false,-1);
    tracep->declBus(c+197,"if_instr", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("memu ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+81,"mem_pc", false,-1, 31,0);
    tracep->declBus(c+82,"mem_instr", false,-1, 31,0);
    tracep->declBus(c+83,"mem_alu_result", false,-1, 31,0);
    tracep->declBus(c+84,"mem_rs2_data", false,-1, 31,0);
    tracep->declBus(c+87,"mem_rd", false,-1, 4,0);
    tracep->declBit(c+88,"mem_reg_wen", false,-1);
    tracep->declBit(c+89,"mem_mem_wen", false,-1);
    tracep->declBit(c+90,"mem_mem_ren", false,-1);
    tracep->declBus(c+93,"mem_mem_type", false,-1, 2,0);
    tracep->declBit(c+94,"mem_mem_unsigned", false,-1);
    tracep->declBus(c+95,"mem_wb_sel", false,-1, 1,0);
    tracep->declBus(c+102,"mem_csr_rdata", false,-1, 31,0);
    tracep->declBus(c+200,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+199,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+201,"dmem_wdata", false,-1, 31,0);
    tracep->declBus(c+203,"dmem_wen", false,-1, 3,0);
    tracep->declBit(c+202,"dmem_valid", false,-1);
    tracep->declBus(c+204,"mem_read_data", false,-1, 31,0);
    tracep->declBus(c+205,"wb_data", false,-1, 31,0);
    tracep->declBus(c+158,"mem_funct3", false,-1, 2,0);
    tracep->declBus(c+235,"BYTE", false,-1, 1,0);
    tracep->declBus(c+236,"HALF", false,-1, 1,0);
    tracep->declBus(c+237,"WORD", false,-1, 1,0);
    tracep->declBus(c+159,"byte_en", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+6,"stall", false,-1);
    tracep->declBit(c+76,"branch_taken", false,-1);
    tracep->declBus(c+78,"branch_target", false,-1, 31,0);
    tracep->declBus(c+19,"pc_plus4", false,-1, 31,0);
    tracep->declBit(c+15,"exception_redirect", false,-1);
    tracep->declBus(c+16,"exception_target", false,-1, 31,0);
    tracep->declBus(c+18,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pipe_reg_ex_mem ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+207,"stall", false,-1);
    tracep->declBit(c+9,"flush", false,-1);
    tracep->declBus(c+48,"ex_pc", false,-1, 31,0);
    tracep->declBus(c+49,"ex_instr", false,-1, 31,0);
    tracep->declBus(c+75,"ex_alu_result", false,-1, 31,0);
    tracep->declBus(c+77,"ex_rs2_data", false,-1, 31,0);
    tracep->declBus(c+52,"ex_rs1", false,-1, 4,0);
    tracep->declBus(c+53,"ex_rs2", false,-1, 4,0);
    tracep->declBus(c+54,"ex_rd", false,-1, 4,0);
    tracep->declBit(c+56,"ex_reg_wen", false,-1);
    tracep->declBit(c+57,"ex_mem_wen", false,-1);
    tracep->declBit(c+58,"ex_mem_ren", false,-1);
    tracep->declBit(c+76,"ex_branch_taken", false,-1);
    tracep->declBus(c+79,"ex_funct3", false,-1, 2,0);
    tracep->declBus(c+64,"ex_mem_type", false,-1, 2,0);
    tracep->declBit(c+65,"ex_mem_unsigned", false,-1);
    tracep->declBus(c+66,"ex_wb_sel", false,-1, 1,0);
    tracep->declBit(c+67,"ex_csr_ren", false,-1);
    tracep->declBit(c+68,"ex_csr_wen", false,-1);
    tracep->declBus(c+69,"ex_csr_addr", false,-1, 11,0);
    tracep->declBus(c+72,"ex_csr_op", false,-1, 1,0);
    tracep->declBit(c+71,"ex_csr_imm", false,-1);
    tracep->declBus(c+80,"ex_csr_write_data", false,-1, 31,0);
    tracep->declBus(c+81,"mem_pc", false,-1, 31,0);
    tracep->declBus(c+82,"mem_instr", false,-1, 31,0);
    tracep->declBus(c+83,"mem_alu_result", false,-1, 31,0);
    tracep->declBus(c+84,"mem_rs2_data", false,-1, 31,0);
    tracep->declBus(c+85,"mem_rs1", false,-1, 4,0);
    tracep->declBus(c+86,"mem_rs2", false,-1, 4,0);
    tracep->declBus(c+87,"mem_rd", false,-1, 4,0);
    tracep->declBit(c+88,"mem_reg_wen", false,-1);
    tracep->declBit(c+89,"mem_mem_wen", false,-1);
    tracep->declBit(c+90,"mem_mem_ren", false,-1);
    tracep->declBit(c+91,"mem_branch_taken", false,-1);
    tracep->declBus(c+92,"mem_funct3", false,-1, 2,0);
    tracep->declBus(c+93,"mem_mem_type", false,-1, 2,0);
    tracep->declBit(c+94,"mem_mem_unsigned", false,-1);
    tracep->declBus(c+95,"mem_wb_sel", false,-1, 1,0);
    tracep->declBit(c+96,"mem_csr_ren", false,-1);
    tracep->declBit(c+97,"mem_csr_wen", false,-1);
    tracep->declBus(c+98,"mem_csr_addr", false,-1, 11,0);
    tracep->declBus(c+99,"mem_csr_op", false,-1, 1,0);
    tracep->declBit(c+100,"mem_csr_imm", false,-1);
    tracep->declBus(c+101,"mem_csr_write_data", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pipe_reg_id_ex ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+207,"stall", false,-1);
    tracep->declBit(c+8,"flush", false,-1);
    tracep->declBit(c+6,"bubble", false,-1);
    tracep->declBus(c+20,"id_pc", false,-1, 31,0);
    tracep->declBus(c+21,"id_instr", false,-1, 31,0);
    tracep->declBus(c+25,"id_rs1_data", false,-1, 31,0);
    tracep->declBus(c+26,"id_rs2_data", false,-1, 31,0);
    tracep->declBus(c+22,"id_rs1", false,-1, 4,0);
    tracep->declBus(c+23,"id_rs2", false,-1, 4,0);
    tracep->declBus(c+24,"id_rd", false,-1, 4,0);
    tracep->declBus(c+27,"id_imm", false,-1, 31,0);
    tracep->declBit(c+28,"id_reg_wen", false,-1);
    tracep->declBit(c+29,"id_mem_wen", false,-1);
    tracep->declBit(c+30,"id_mem_ren", false,-1);
    tracep->declBus(c+31,"id_alu_op", false,-1, 3,0);
    tracep->declBit(c+32,"id_use_imm", false,-1);
    tracep->declBit(c+33,"id_branch", false,-1);
    tracep->declBit(c+34,"id_jump", false,-1);
    tracep->declBit(c+35,"id_is_jalr", false,-1);
    tracep->declBus(c+36,"id_mem_type", false,-1, 2,0);
    tracep->declBit(c+37,"id_mem_unsigned", false,-1);
    tracep->declBus(c+38,"id_wb_sel", false,-1, 1,0);
    tracep->declBit(c+39,"id_csr_ren", false,-1);
    tracep->declBit(c+40,"id_csr_wen", false,-1);
    tracep->declBus(c+41,"id_csr_addr", false,-1, 11,0);
    tracep->declBus(c+43,"id_csr_op", false,-1, 1,0);
    tracep->declBit(c+44,"id_csr_imm", false,-1);
    tracep->declBit(c+42,"id_illegal_instr", false,-1);
    tracep->declBus(c+48,"ex_pc", false,-1, 31,0);
    tracep->declBus(c+49,"ex_instr", false,-1, 31,0);
    tracep->declBus(c+50,"ex_rs1_data", false,-1, 31,0);
    tracep->declBus(c+51,"ex_rs2_data", false,-1, 31,0);
    tracep->declBus(c+52,"ex_rs1", false,-1, 4,0);
    tracep->declBus(c+53,"ex_rs2", false,-1, 4,0);
    tracep->declBus(c+54,"ex_rd", false,-1, 4,0);
    tracep->declBus(c+55,"ex_imm", false,-1, 31,0);
    tracep->declBit(c+56,"ex_reg_wen", false,-1);
    tracep->declBit(c+57,"ex_mem_wen", false,-1);
    tracep->declBit(c+58,"ex_mem_ren", false,-1);
    tracep->declBus(c+59,"ex_alu_op", false,-1, 3,0);
    tracep->declBit(c+60,"ex_use_imm", false,-1);
    tracep->declBit(c+61,"ex_branch", false,-1);
    tracep->declBit(c+62,"ex_jump", false,-1);
    tracep->declBit(c+63,"ex_is_jalr", false,-1);
    tracep->declBus(c+64,"ex_mem_type", false,-1, 2,0);
    tracep->declBit(c+65,"ex_mem_unsigned", false,-1);
    tracep->declBus(c+66,"ex_wb_sel", false,-1, 1,0);
    tracep->declBit(c+67,"ex_csr_ren", false,-1);
    tracep->declBit(c+68,"ex_csr_wen", false,-1);
    tracep->declBus(c+69,"ex_csr_addr", false,-1, 11,0);
    tracep->declBus(c+72,"ex_csr_op", false,-1, 1,0);
    tracep->declBit(c+71,"ex_csr_imm", false,-1);
    tracep->declBit(c+70,"ex_illegal_instr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pipe_reg_if_id ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+6,"stall", false,-1);
    tracep->declBit(c+7,"flush", false,-1);
    tracep->declBus(c+196,"if_pc", false,-1, 31,0);
    tracep->declBus(c+197,"if_instr", false,-1, 31,0);
    tracep->declBus(c+20,"id_pc", false,-1, 31,0);
    tracep->declBus(c+21,"id_instr", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pipe_reg_mem_wb ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBit(c+207,"stall", false,-1);
    tracep->declBit(c+207,"flush", false,-1);
    tracep->declBus(c+81,"mem_pc", false,-1, 31,0);
    tracep->declBus(c+82,"mem_instr", false,-1, 31,0);
    tracep->declBus(c+83,"mem_alu_result", false,-1, 31,0);
    tracep->declBus(c+204,"mem_mem_rdata", false,-1, 31,0);
    tracep->declBus(c+87,"mem_rd", false,-1, 4,0);
    tracep->declBit(c+88,"mem_reg_wen", false,-1);
    tracep->declBit(c+90,"mem_mem_ren", false,-1);
    tracep->declBus(c+95,"mem_wb_sel", false,-1, 1,0);
    tracep->declBit(c+94,"mem_mem_unsigned", false,-1);
    tracep->declBus(c+102,"mem_csr_rdata", false,-1, 31,0);
    tracep->declBit(c+96,"mem_csr_ren", false,-1);
    tracep->declBit(c+97,"mem_csr_wen", false,-1);
    tracep->declBus(c+98,"mem_csr_addr", false,-1, 11,0);
    tracep->declBus(c+99,"mem_csr_op", false,-1, 1,0);
    tracep->declBit(c+100,"mem_csr_imm", false,-1);
    tracep->declBus(c+101,"mem_csr_write_data", false,-1, 31,0);
    tracep->declBus(c+103,"wb_pc", false,-1, 31,0);
    tracep->declBus(c+104,"wb_instr", false,-1, 31,0);
    tracep->declBus(c+105,"wb_alu_result", false,-1, 31,0);
    tracep->declBus(c+106,"wb_mem_rdata", false,-1, 31,0);
    tracep->declBus(c+46,"wb_rd", false,-1, 4,0);
    tracep->declBit(c+107,"wb_reg_wen", false,-1);
    tracep->declBit(c+108,"wb_mem_ren", false,-1);
    tracep->declBus(c+109,"wb_wb_sel", false,-1, 1,0);
    tracep->declBit(c+110,"wb_mem_unsigned", false,-1);
    tracep->declBus(c+111,"wb_csr_rdata", false,-1, 31,0);
    tracep->declBit(c+112,"wb_csr_ren", false,-1);
    tracep->declBit(c+113,"wb_csr_wen", false,-1);
    tracep->declBus(c+114,"wb_csr_addr", false,-1, 11,0);
    tracep->declBus(c+115,"wb_csr_op", false,-1, 1,0);
    tracep->declBit(c+116,"wb_csr_imm", false,-1);
    tracep->declBus(c+117,"wb_csr_write_data", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+22,"rs1", false,-1, 4,0);
    tracep->declBus(c+23,"rs2", false,-1, 4,0);
    tracep->declBus(c+46,"rd", false,-1, 4,0);
    tracep->declBit(c+47,"we", false,-1);
    tracep->declBus(c+45,"wdata", false,-1, 31,0);
    tracep->declBus(c+25,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+26,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+160,"a0_value", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+161+i*1,"registers", true,(i+0), 31,0);
    }
    tracep->declBus(c+193,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("wbu ");
    tracep->declBit(c+194,"clk", false,-1);
    tracep->declBit(c+195,"rst", false,-1);
    tracep->declBus(c+103,"wb_pc", false,-1, 31,0);
    tracep->declBus(c+104,"wb_instr", false,-1, 31,0);
    tracep->declBus(c+105,"wb_alu_result", false,-1, 31,0);
    tracep->declBus(c+106,"wb_mem_rdata", false,-1, 31,0);
    tracep->declBus(c+46,"wb_rd", false,-1, 4,0);
    tracep->declBit(c+107,"wb_reg_wen", false,-1);
    tracep->declBus(c+109,"wb_wb_sel", false,-1, 1,0);
    tracep->declBit(c+110,"wb_mem_unsigned", false,-1);
    tracep->declBus(c+111,"wb_csr_rdata", false,-1, 31,0);
    tracep->declBus(c+45,"wb_data", false,-1, 31,0);
    tracep->declBus(c+46,"wb_rd_out", false,-1, 4,0);
    tracep->declBit(c+47,"wb_reg_wen_out", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__is_ecall));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__is_ebreak));
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__regfile__DOT__registers
                            [0xaU]),32);
    bufp->fullBit(oldp+4,(vlSelf->top__DOT__dpi_system__DOT__terminate_reg));
    bufp->fullBit(oldp+5,(vlSelf->top__DOT__wb_valid));
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__hazard_unit__DOT__load_use_hazard));
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__flush_if));
    bufp->fullBit(oldp+8,(vlSelf->top__DOT__flush_ex));
    bufp->fullBit(oldp+9,(vlSelf->top__DOT__pipeline_flush_exc));
    bufp->fullBit(oldp+10,(((IData)(vlSelf->top__DOT__ex_jump) 
                            | (IData)(vlSelf->top__DOT__exu__DOT__branch_taken_reg))));
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__exception_valid));
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__exception_code),4);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__exception_pc),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__exception_val),32);
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__exception_redirect));
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__exception_target),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__csr_file__DOT__mtvec),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+19,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__id_pc),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__id_instr),32);
    bufp->fullCData(oldp+22,((0x1fU & (vlSelf->top__DOT__id_instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+23,((0x1fU & (vlSelf->top__DOT__id_instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+24,((0x1fU & (vlSelf->top__DOT__id_instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+25,(((0U == (0x1fU & (vlSelf->top__DOT__id_instr 
                                               >> 0xfU)))
                               ? 0U : vlSelf->top__DOT__regfile__DOT__registers
                              [(0x1fU & (vlSelf->top__DOT__id_instr 
                                         >> 0xfU))])),32);
    bufp->fullIData(oldp+26,(((0U == (0x1fU & (vlSelf->top__DOT__id_instr 
                                               >> 0x14U)))
                               ? 0U : vlSelf->top__DOT__regfile__DOT__registers
                              [(0x1fU & (vlSelf->top__DOT__id_instr 
                                         >> 0x14U))])),32);
    bufp->fullIData(oldp+27,(((IData)(vlSelf->top__DOT__idu__DOT__is_i_type)
                               ? (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                   & (IData)(vlSelf->top__DOT__idu__DOT__is_csr_imm))
                                   ? (0x1fU & (vlSelf->top__DOT__id_instr 
                                               >> 0xfU))
                                   : (((- (IData)((vlSelf->top__DOT__id_instr 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (vlSelf->top__DOT__id_instr 
                                                   >> 0x14U)))
                               : ((0x23U == (0x7fU 
                                             & vlSelf->top__DOT__id_instr))
                                   ? (((- (IData)((vlSelf->top__DOT__id_instr 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlSelf->top__DOT__id_instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelf->top__DOT__id_instr 
                                                         >> 7U))))
                                   : ((0x63U == (0x7fU 
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
                                           ? (0xfffff000U 
                                              & vlSelf->top__DOT__id_instr)
                                           : ((0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->top__DOT__id_instr))
                                               ? ((
                                                   (- (IData)(
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
                                               : 0U)))))),32);
    bufp->fullBit(oldp+28,(((((0x33U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                              | ((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                                 | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                    | (IData)(vlSelf->top__DOT__id_jump)))) 
                             | (IData)(vlSelf->top__DOT__idu__DOT__is_csr)) 
                            & (0U != (0x1fU & (vlSelf->top__DOT__id_instr 
                                               >> 7U))))));
    bufp->fullBit(oldp+29,((0x23U == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullBit(oldp+30,((3U == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullCData(oldp+31,(vlSelf->top__DOT__idu__DOT__alu_op_val),4);
    bufp->fullBit(oldp+32,(((IData)(vlSelf->top__DOT__idu__DOT__is_i_type) 
                            | ((0x23U == (0x7fU & vlSelf->top__DOT__id_instr)) 
                               | ((IData)(vlSelf->top__DOT__idu__DOT__is_u_type) 
                                  | (0x6fU == (0x7fU 
                                               & vlSelf->top__DOT__id_instr)))))));
    bufp->fullBit(oldp+33,((0x63U == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullBit(oldp+34,(vlSelf->top__DOT__id_jump));
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__id_is_jalr));
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__idu__DOT__mem_type_val),3);
    bufp->fullBit(oldp+37,(vlSelf->top__DOT__idu__DOT__mem_unsigned_val));
    bufp->fullCData(oldp+38,(((3U == (0x7fU & vlSelf->top__DOT__id_instr))
                               ? 1U : ((IData)(vlSelf->top__DOT__id_jump)
                                        ? 2U : ((IData)(vlSelf->top__DOT__idu__DOT__is_csr)
                                                 ? 3U
                                                 : 0U)))),2);
    bufp->fullBit(oldp+39,(vlSelf->top__DOT__idu__DOT__is_csr));
    bufp->fullBit(oldp+40,(((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                            & (IData)(((0U != (0xf8000U 
                                               & vlSelf->top__DOT__id_instr)) 
                                       | (IData)(vlSelf->top__DOT__idu__DOT__is_csrrw))))));
    bufp->fullSData(oldp+41,((vlSelf->top__DOT__id_instr 
                              >> 0x14U)),12);
    bufp->fullBit(oldp+42,(vlSelf->top__DOT__idu__DOT__illegal_instr_reg));
    bufp->fullCData(oldp+43,(((IData)(vlSelf->top__DOT__idu__DOT__is_csrrw)
                               ? 0U : (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                        & (0x2000U 
                                           == (0x3000U 
                                               & vlSelf->top__DOT__id_instr)))
                                        ? 1U : (((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                                                 & (0x3000U 
                                                    == 
                                                    (0x3000U 
                                                     & vlSelf->top__DOT__id_instr)))
                                                 ? 2U
                                                 : 0U)))),2);
    bufp->fullBit(oldp+44,(vlSelf->top__DOT__idu__DOT__is_csr_imm));
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__wb_data),32);
    bufp->fullCData(oldp+46,(vlSelf->top__DOT__wb_rd),5);
    bufp->fullBit(oldp+47,(((IData)(vlSelf->top__DOT__wb_reg_wen) 
                            & (0U != (IData)(vlSelf->top__DOT__wb_rd)))));
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__ex_pc),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__ex_instr),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__ex_rs1_data),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__ex_rs2_data),32);
    bufp->fullCData(oldp+52,(vlSelf->top__DOT__ex_rs1),5);
    bufp->fullCData(oldp+53,(vlSelf->top__DOT__ex_rs2),5);
    bufp->fullCData(oldp+54,(vlSelf->top__DOT__ex_rd),5);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__ex_imm),32);
    bufp->fullBit(oldp+56,(vlSelf->top__DOT__ex_reg_wen));
    bufp->fullBit(oldp+57,(vlSelf->top__DOT__ex_mem_wen));
    bufp->fullBit(oldp+58,(vlSelf->top__DOT__ex_mem_ren));
    bufp->fullCData(oldp+59,(vlSelf->top__DOT__ex_alu_op),4);
    bufp->fullBit(oldp+60,(vlSelf->top__DOT__ex_use_imm));
    bufp->fullBit(oldp+61,(vlSelf->top__DOT__ex_branch));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__ex_jump));
    bufp->fullBit(oldp+63,(vlSelf->top__DOT__ex_is_jalr));
    bufp->fullCData(oldp+64,(vlSelf->top__DOT__ex_mem_type),3);
    bufp->fullBit(oldp+65,(vlSelf->top__DOT__ex_mem_unsigned));
    bufp->fullCData(oldp+66,(vlSelf->top__DOT__ex_wb_sel),2);
    bufp->fullBit(oldp+67,(vlSelf->top__DOT__ex_csr_ren));
    bufp->fullBit(oldp+68,(vlSelf->top__DOT__ex_csr_wen));
    bufp->fullSData(oldp+69,(vlSelf->top__DOT__ex_csr_addr),12);
    bufp->fullBit(oldp+70,(vlSelf->top__DOT__ex_illegal_instr));
    bufp->fullBit(oldp+71,(vlSelf->top__DOT__ex_csr_imm));
    bufp->fullCData(oldp+72,(vlSelf->top__DOT__ex_csr_op),2);
    bufp->fullCData(oldp+73,(vlSelf->top__DOT__forward_a),2);
    bufp->fullCData(oldp+74,(vlSelf->top__DOT__forward_b),2);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__exu__DOT__alu_result_reg),32);
    bufp->fullBit(oldp+76,(vlSelf->top__DOT__exu__DOT__branch_taken_reg));
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__exu__DOT__forwarded_rs2_data),32);
    bufp->fullIData(oldp+78,(((IData)(vlSelf->top__DOT__ex_is_jalr)
                               ? (0xfffffffeU & (vlSelf->top__DOT__ex_imm 
                                                 + vlSelf->top__DOT__exu__DOT__alu_src1))
                               : (vlSelf->top__DOT__ex_imm 
                                  + vlSelf->top__DOT__ex_pc))),32);
    bufp->fullCData(oldp+79,((7U & (vlSelf->top__DOT__ex_instr 
                                    >> 0xcU))),3);
    bufp->fullIData(oldp+80,(((IData)(vlSelf->top__DOT__ex_csr_imm)
                               ? vlSelf->top__DOT__ex_imm
                               : vlSelf->top__DOT__exu__DOT__alu_src1)),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__mem_pc),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__mem_instr),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__mem_alu_result),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__mem_rs2_data),32);
    bufp->fullCData(oldp+85,(vlSelf->top__DOT__mem_rs1),5);
    bufp->fullCData(oldp+86,(vlSelf->top__DOT__mem_rs2),5);
    bufp->fullCData(oldp+87,(vlSelf->top__DOT__mem_rd),5);
    bufp->fullBit(oldp+88,(vlSelf->top__DOT__mem_reg_wen));
    bufp->fullBit(oldp+89,(vlSelf->top__DOT__mem_mem_wen));
    bufp->fullBit(oldp+90,(vlSelf->top__DOT__mem_mem_ren));
    bufp->fullBit(oldp+91,(vlSelf->top__DOT__mem_branch_taken));
    bufp->fullCData(oldp+92,(vlSelf->top__DOT__mem_funct3),3);
    bufp->fullCData(oldp+93,(vlSelf->top__DOT__mem_mem_type),3);
    bufp->fullBit(oldp+94,(vlSelf->top__DOT__mem_mem_unsigned));
    bufp->fullCData(oldp+95,(vlSelf->top__DOT__mem_wb_sel),2);
    bufp->fullBit(oldp+96,(vlSelf->top__DOT__mem_csr_ren));
    bufp->fullBit(oldp+97,(vlSelf->top__DOT__mem_csr_wen));
    bufp->fullSData(oldp+98,(vlSelf->top__DOT__mem_csr_addr),12);
    bufp->fullCData(oldp+99,(vlSelf->top__DOT__mem_csr_op),2);
    bufp->fullBit(oldp+100,(vlSelf->top__DOT__mem_csr_imm));
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__mem_csr_write_data),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__mem_csr_rdata),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__wb_pc),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__wb_instr),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__wb_alu_result),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__wb_mem_rdata),32);
    bufp->fullBit(oldp+107,(vlSelf->top__DOT__wb_reg_wen));
    bufp->fullBit(oldp+108,(vlSelf->top__DOT__wb_mem_ren));
    bufp->fullCData(oldp+109,(vlSelf->top__DOT__wb_wb_sel),2);
    bufp->fullBit(oldp+110,(vlSelf->top__DOT__wb_mem_unsigned));
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__wb_csr_rdata),32);
    bufp->fullBit(oldp+112,(vlSelf->top__DOT__wb_csr_ren));
    bufp->fullBit(oldp+113,(vlSelf->top__DOT__wb_csr_wen));
    bufp->fullSData(oldp+114,(vlSelf->top__DOT__wb_csr_addr),12);
    bufp->fullCData(oldp+115,(vlSelf->top__DOT__wb_csr_op),2);
    bufp->fullBit(oldp+116,(vlSelf->top__DOT__wb_csr_imm));
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__wb_csr_write_data),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__csr_file__DOT__mstatus),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__csr_file__DOT__misa),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__csr_file__DOT__mscratch),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__csr_file__DOT__mepc),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__csr_file__DOT__mcause),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__csr_file__DOT__mtval),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__csr_file__DOT__mcycle),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__csr_file__DOT__mcycleh),32);
    bufp->fullBit(oldp+126,(vlSelf->top__DOT__dpi_system__DOT__ecall_handled));
    bufp->fullBit(oldp+127,(vlSelf->top__DOT__dpi_system__DOT__ebreak_handled));
    bufp->fullBit(oldp+128,(vlSelf->top__DOT__exception_handler__DOT__exception_detected));
    bufp->fullCData(oldp+129,(vlSelf->top__DOT__exception_handler__DOT__detected_exception_code),4);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__exception_handler__DOT__detected_exception_val),32);
    bufp->fullBit(oldp+131,(vlSelf->top__DOT__exception_handler__DOT__handling_exception));
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__exu__DOT__alu_src1),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__exu__DOT__alu_src2),32);
    bufp->fullBit(oldp+134,((0x17U == (0x7fU & vlSelf->top__DOT__ex_instr))));
    bufp->fullBit(oldp+135,((0x6fU == (0x7fU & vlSelf->top__DOT__ex_instr))));
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__exu__DOT__final_alu_src1),32);
    bufp->fullCData(oldp+137,((0x7fU & vlSelf->top__DOT__id_instr)),7);
    bufp->fullCData(oldp+138,((7U & (vlSelf->top__DOT__id_instr 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+139,((vlSelf->top__DOT__id_instr 
                               >> 0x19U)),7);
    bufp->fullBit(oldp+140,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0) 
                             & (1U == (vlSelf->top__DOT__id_instr 
                                       >> 0x14U)))));
    bufp->fullBit(oldp+141,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h04c5b6ec__0) 
                             & (0U == (vlSelf->top__DOT__id_instr 
                                       >> 0x14U)))));
    bufp->fullBit(oldp+142,((0xfU == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullBit(oldp+143,(vlSelf->top__DOT__idu__DOT__is_csrrw));
    bufp->fullBit(oldp+144,(((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                             & (0x2000U == (0x3000U 
                                            & vlSelf->top__DOT__id_instr)))));
    bufp->fullBit(oldp+145,(((IData)(vlSelf->top__DOT__idu__DOT__is_csr) 
                             & (0x3000U == (0x3000U 
                                            & vlSelf->top__DOT__id_instr)))));
    bufp->fullBit(oldp+146,((0x33U == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullBit(oldp+147,(vlSelf->top__DOT__idu__DOT__is_i_type));
    bufp->fullBit(oldp+148,(vlSelf->top__DOT__idu__DOT__is_u_type));
    bufp->fullBit(oldp+149,((0x6fU == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullBit(oldp+150,((0x37U == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullBit(oldp+151,((0x17U == (0x7fU & vlSelf->top__DOT__id_instr))));
    bufp->fullIData(oldp+152,((((- (IData)((vlSelf->top__DOT__id_instr 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->top__DOT__id_instr 
                                            >> 0x14U))),32);
    bufp->fullIData(oldp+153,((((- (IData)((vlSelf->top__DOT__id_instr 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->top__DOT__id_instr 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->top__DOT__id_instr 
                                                  >> 7U))))),32);
    bufp->fullIData(oldp+154,((((- (IData)((vlSelf->top__DOT__id_instr 
                                            >> 0x1fU))) 
                                << 0xdU) | ((0x1000U 
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
                                                        >> 7U))))))),32);
    bufp->fullIData(oldp+155,((0xfffff000U & vlSelf->top__DOT__id_instr)),32);
    bufp->fullIData(oldp+156,((((- (IData)((vlSelf->top__DOT__id_instr 
                                            >> 0x1fU))) 
                                << 0x15U) | ((0x100000U 
                                              & (vlSelf->top__DOT__id_instr 
                                                 >> 0xbU)) 
                                             | ((0xff000U 
                                                 & vlSelf->top__DOT__id_instr) 
                                                | ((0x800U 
                                                    & (vlSelf->top__DOT__id_instr 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSelf->top__DOT__id_instr 
                                                         >> 0x14U))))))),32);
    bufp->fullIData(oldp+157,((0x1fU & (vlSelf->top__DOT__id_instr 
                                        >> 0xfU))),32);
    bufp->fullCData(oldp+158,((((IData)(vlSelf->top__DOT__mem_mem_unsigned) 
                                << 2U) | (3U & (IData)(vlSelf->top__DOT__mem_mem_type)))),3);
    bufp->fullCData(oldp+159,(vlSelf->top__DOT__memu__DOT__byte_en),4);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT__registers
                              [0xaU]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__regfile__DOT__registers[0]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regfile__DOT__registers[1]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__regfile__DOT__registers[2]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__regfile__DOT__registers[3]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__regfile__DOT__registers[4]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__regfile__DOT__registers[5]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__regfile__DOT__registers[6]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regfile__DOT__registers[7]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regfile__DOT__registers[8]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__regfile__DOT__registers[9]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__regfile__DOT__registers[10]),32);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__regfile__DOT__registers[11]),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__regfile__DOT__registers[12]),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__regfile__DOT__registers[13]),32);
    bufp->fullIData(oldp+175,(vlSelf->top__DOT__regfile__DOT__registers[14]),32);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__regfile__DOT__registers[15]),32);
    bufp->fullIData(oldp+177,(vlSelf->top__DOT__regfile__DOT__registers[16]),32);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__regfile__DOT__registers[17]),32);
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__regfile__DOT__registers[18]),32);
    bufp->fullIData(oldp+180,(vlSelf->top__DOT__regfile__DOT__registers[19]),32);
    bufp->fullIData(oldp+181,(vlSelf->top__DOT__regfile__DOT__registers[20]),32);
    bufp->fullIData(oldp+182,(vlSelf->top__DOT__regfile__DOT__registers[21]),32);
    bufp->fullIData(oldp+183,(vlSelf->top__DOT__regfile__DOT__registers[22]),32);
    bufp->fullIData(oldp+184,(vlSelf->top__DOT__regfile__DOT__registers[23]),32);
    bufp->fullIData(oldp+185,(vlSelf->top__DOT__regfile__DOT__registers[24]),32);
    bufp->fullIData(oldp+186,(vlSelf->top__DOT__regfile__DOT__registers[25]),32);
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__regfile__DOT__registers[26]),32);
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__regfile__DOT__registers[27]),32);
    bufp->fullIData(oldp+189,(vlSelf->top__DOT__regfile__DOT__registers[28]),32);
    bufp->fullIData(oldp+190,(vlSelf->top__DOT__regfile__DOT__registers[29]),32);
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__regfile__DOT__registers[30]),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__regfile__DOT__registers[31]),32);
    bufp->fullIData(oldp+193,(vlSelf->top__DOT__regfile__DOT__i),32);
    bufp->fullBit(oldp+194,(vlSelf->clk));
    bufp->fullBit(oldp+195,(vlSelf->rst));
    bufp->fullIData(oldp+196,(vlSelf->imem_addr),32);
    bufp->fullIData(oldp+197,(vlSelf->imem_rdata),32);
    bufp->fullBit(oldp+198,(vlSelf->imem_valid));
    bufp->fullIData(oldp+199,(vlSelf->dmem_addr),32);
    bufp->fullIData(oldp+200,(vlSelf->dmem_rdata),32);
    bufp->fullIData(oldp+201,(vlSelf->dmem_wdata),32);
    bufp->fullBit(oldp+202,(vlSelf->dmem_valid));
    bufp->fullCData(oldp+203,(vlSelf->dmem_wen),4);
    bufp->fullIData(oldp+204,(vlSelf->top__DOT__mem_read_data),32);
    bufp->fullIData(oldp+205,(((2U & (IData)(vlSelf->top__DOT__mem_wb_sel))
                                ? ((1U & (IData)(vlSelf->top__DOT__mem_wb_sel))
                                    ? vlSelf->top__DOT__mem_csr_rdata
                                    : ((IData)(4U) 
                                       + vlSelf->top__DOT__mem_pc))
                                : ((1U & (IData)(vlSelf->top__DOT__mem_wb_sel))
                                    ? vlSelf->top__DOT__mem_read_data
                                    : vlSelf->top__DOT__mem_alu_result))),32);
    bufp->fullIData(oldp+206,(0x80100000U),32);
    bufp->fullBit(oldp+207,(0U));
    bufp->fullSData(oldp+208,(0x300U),12);
    bufp->fullSData(oldp+209,(0x301U),12);
    bufp->fullSData(oldp+210,(0x302U),12);
    bufp->fullSData(oldp+211,(0x303U),12);
    bufp->fullSData(oldp+212,(0x304U),12);
    bufp->fullSData(oldp+213,(0x305U),12);
    bufp->fullSData(oldp+214,(0x340U),12);
    bufp->fullSData(oldp+215,(0x341U),12);
    bufp->fullSData(oldp+216,(0x342U),12);
    bufp->fullSData(oldp+217,(0x343U),12);
    bufp->fullSData(oldp+218,(0x344U),12);
    bufp->fullSData(oldp+219,(0xb00U),12);
    bufp->fullSData(oldp+220,(0xb80U),12);
    bufp->fullCData(oldp+221,(0U),4);
    bufp->fullCData(oldp+222,(1U),4);
    bufp->fullCData(oldp+223,(2U),4);
    bufp->fullCData(oldp+224,(3U),4);
    bufp->fullCData(oldp+225,(4U),4);
    bufp->fullCData(oldp+226,(5U),4);
    bufp->fullCData(oldp+227,(6U),4);
    bufp->fullCData(oldp+228,(7U),4);
    bufp->fullCData(oldp+229,(8U),4);
    bufp->fullCData(oldp+230,(9U),4);
    bufp->fullCData(oldp+231,(0xbU),4);
    bufp->fullBit(oldp+232,(1U));
    bufp->fullCData(oldp+233,(0xaU),4);
    bufp->fullCData(oldp+234,(0xcU),4);
    bufp->fullCData(oldp+235,(0U),2);
    bufp->fullCData(oldp+236,(1U),2);
    bufp->fullCData(oldp+237,(2U),2);
}
