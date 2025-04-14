`ifndef DEFINES_V
`define DEFINES_V

        // 操作码定义
`define OPCODE_R_TYPE     7'b0110011
`define OPCODE_I_TYPE     7'b0010011
`define OPCODE_LOAD       7'b0000011
`define OPCODE_STORE      7'b0100011
`define OPCODE_BRANCH     7'b1100011
`define OPCODE_JAL        7'b1101111
`define OPCODE_JALR       7'b1100111
`define OPCODE_LUI        7'b0110111
`define OPCODE_AUIPC      7'b0010111
`define OPCODE_SYSTEM     7'b1110011

        // ALU 操作定义
`define ALU_ADD     4'b0000
`define ALU_SUB     4'b0001
`define ALU_SLL     4'b0010
`define ALU_SLT     4'b0011
`define ALU_SLTU    4'b0100
`define ALU_XOR     4'b0101
`define ALU_SRL     4'b0110
`define ALU_SRA     4'b0111
`define ALU_OR      4'b1000
`define ALU_AND     4'b1001
`define ALU_MUL     4'b1010
`define ALU_MULH    4'b1011
`define ALU_DIV     4'b1100
`define ALU_DIVU    4'b1101
`define ALU_REM     4'b1110
`define ALU_REMU    4'b1111

        // 指令类型定义
`define TYPE_R      3'b000
`define TYPE_I      3'b001
`define TYPE_S      3'b010
`define TYPE_B      3'b011
`define TYPE_U      3'b100
`define TYPE_J      3'b101

`endif
