#include "../include/cpu.h"

cpu_t* create_cpu() {
	cpu_t* cpu = calloc(1, sizeof(cpu_t));
	
	return cpu;
}

void destroy_cpu(cpu_t* cpu) {
	if(cpu) {
		free(cpu);
	}
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
