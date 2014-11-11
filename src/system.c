#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/system.h"
#include "../include/opcodes.h"

void handle_opcode(system_t* system, uint16_t opcode) {
	switch(opcode & 0xF000) {
	case 0x0:
	  switch(opcode & 0x00FF) {
	  case 0xE0:
	    op_cls(system, opcode);
	    return;
	  case 0xEE:
	    op_ret(system, opcode);
	    return;
	  default:
	    op_sys(system, opcode);
	  }
	case 0x1:
	  op_jmp(system, opcode);
	  return;
	case 0x2:
	  op_call(system, opcode);
	  return;
	case 0x3:
	  op_seb(system, opcode);
	  return;
	case 0x4:
	  op_sneb(system, opcode);
	  return;
	case 0x5:
	  op_se(system, opcode);
	  return;
	case 0x6:
	  op_ldb(system, opcode);
	  return;
	case 0x7:
	  op_addb(system, opcode);
	  return;
	case 0x8:
	  switch(opcode & 0x000F) {
	  case 0x0:
	    op_ld(system, opcode);
	    return;
	  case 0x1:
	    op_or(system, opcode);
	    return;
	  case 0x2:
	    op_and(system, opcode);
	    return;
	  case 0x3:
	    op_xor(system, opcode);
	    return;
	  case 0x4:
	    op_add(system, opcode);
	    return;
	  case 0x5:
	    op_sub(system, opcode);
	    return;
	  case 0x6:
	    op_shr(system, opcode);
	    return;
	  case 0x7:
	    op_subn(system, opcode);
	    return;
	  case 0xE:
	    op_shl(system, opcode);
	    return;
	  }
	case 0x9:
	  op_sne(system, opcode);
	  return;
	case 0xA:
	  op_ldi(system, opcode);
	  return;
	case 0xB:
	  op_jmpo(system, opcode);
	  return;
	case 0xC:
	  op_rnd(system, opcode);
	  return;
	case 0xD:
	  op_drw(system, opcode);
	  return;
	case 0xE:
	  switch(opcode & 0x00FF) {
	  case 0x9E:
	    op_skp(system, opcode);
	    return;
	  case 0xA1:
	    op_sknp(system, opcode);
	    return;
	  }
	case 0xF:
	  switch(opcode & 0x00FF) {
	  case 0x07:
	    op_sdtv(system, opcode);
	    return;
	  case 0x0A:
	    op_rkp(system, opcode);
	    return;
	  case 0x15:
	    op_sdt(system, opcode);
	    return;
	  case 0x18:
	    op_sst(system, opcode);
	    return;
	  case 0x1E:
	    op_addi(system, opcode);
	    return;
	  case 0x29:
	    op_ldi(system, opcode);
	    return;
	  case 0x33:
	    op_ldix(system, opcode);
	    return;
	  case 0x55:
	    op_ldir(system, opcode);
	    return;
	  case 0x65:
	    op_rdrg(system, opcode);
	    return;
	  }
	}
}

void clear_screen(system_t* system) {
	memset(system->screen, 0, 64*32);
}

uint16_t get_opcode(system_t* system, int index) {
	uint16_t opcode;
	
	/* Join two bytes */
	opcode = system->memory[index];
	opcode <<= 8;
	opcode |= system->memory[index + 1];
	
	
	/* Reverse endianess */
	opcode = (opcode>>8) | (opcode<<8);
	
	return opcode;
}

uint16_t get_current_opcode(system_t* system) {
	return get_opcode(system, system->cpu->PC);
}

system_t* create_system(FILE *file) {
	system_t* system = calloc(1, sizeof(system_t));
	system->cpu = create_cpu();
	
	if(file) {
		fread(&system->memory[PROGRAM_START], 1, MEMORY_SIZE, file);
	}
	
	return system;
}

void init_system(system_t* system) {
	init_cpu(system->cpu);
	clear_screen(system);
}

void destroy_system(system_t* system) {
	if(system) {
		if(system->cpu) {
			destroy_cpu(system->cpu);
		}
		free(system);
	}
}

cpu_t* create_cpu() {
	cpu_t* cpu = calloc(1, sizeof(cpu_t));
	
	return cpu;
}

void init_cpu(cpu_t* cpu) {
	/* Zero out the general purpose registers */
	memset(cpu->V, 0, sizeof(cpu->V));
	/* Zero out the stack */
	memset(cpu->stack, 0, sizeof(cpu->stack));
	
	/* Init Registers */
	cpu->I  = 0xFFFF;		 /* Point to the top of the stack */
	cpu->PC = PROGRAM_START; /* 0x200 Program's start */
	cpu->SP = 0;			 /* Zero Stack Pointer */
	cpu->DT = 0;			 /* Zero Delay Timer */
	cpu->ST = 0;			 /* Zero Sound Timer */
}

void destroy_cpu(cpu_t* cpu) {
	if(cpu) {
		free(cpu);
	}
}

