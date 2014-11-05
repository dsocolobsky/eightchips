#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/system.h"

void handle_opcode(system_t* system, uint16_t opcode) {
	uint16_t instruction = opcode & 0xF000;
	printf("Opcode: %x | Instruction: %x\n", opcode, instruction);
	/*switch(opcode) {
		
	}*/
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

