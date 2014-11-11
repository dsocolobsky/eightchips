#ifndef OPCODES_H
#define OPCODES_H

#include "system.h"

/* System Opcodes (0x0) */
void op_cls(system_t* system, uint16_t opcode);
void op_ret(system_t* system, uint16_t opcode);
void op_sys(system_t* system, uint16_t opcode);

void op_jmp(system_t* system, uint16_t opcode);
void op_call(system_t* system, uint16_t opcode);
void op_seb(system_t* system, uint16_t opcode);
void op_sneb(system_t* system, uint16_t opcode);
void op_se(system_t* system, uint16_t opcode);
void op_ldb(system_t* system, uint16_t opcode);
void op_addb(system_t* system, uint16_t opcode);

/* Logical Opcodes (0x8) */
void op_ld(system_t* system, uint16_t opcode);
void op_or(system_t* system, uint16_t opcode);
void op_and(system_t* system, uint16_t opcode);
void op_xor(system_t* system, uint16_t opcode);
void op_add(system_t* system, uint16_t opcode);
void op_sub(system_t* system, uint16_t opcode);
void op_shr(system_t* system, uint16_t opcode);
void op_subn(system_t* system, uint16_t opcode);
void op_shl(system_t* system, uint16_t opcode);

void op_sne(system_t* system, uint16_t opcode);
void op_ldi(system_t* system, uint16_t opcode);
void op_jmpo(system_t* system, uint16_t opcode);
void op_rnd(system_t* system, uint16_t opcode);
void op_drw(system_t* system, uint16_t opcode);
void op_skp(system_t* system, uint16_t opcode);
void op_sknp(system_t* system, uint16_t opcode);
void op_sdtv(system_t* system, uint16_t opcode);
void op_rkp(system_t* system, uint16_t opcode);

/* Special Opcodes (0xF) */
void op_sdt(system_t* system, uint16_t opcode);
void op_sst(system_t* system, uint16_t opcode);
void op_addi(system_t* system, uint16_t opcode);
void op_ldis(system_t* system, uint16_t opcode);
void op_ldix(system_t* system, uint16_t opcode);
void op_ldir(system_t* system, uint16_t opcode);
void op_rdrg(system_t* system, uint16_t opcode);

#endif
