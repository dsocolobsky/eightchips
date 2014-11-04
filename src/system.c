#include <stdlib.h>
#include <stdio.h>

#include "../include/system.h"

void handle_opcode(system_t* system, uint16_t opcode) {
	uint16_t instruction = opcode & 0xF000;
	printf("Opcode: %x | Instruction: %x\n", opcode, instruction);
	/*switch(opcode) {
		
	}*/
}

system_t* create_system(FILE *file, int filesize) {
	system_t* system = calloc(1, sizeof(system_t));
	system->cpu = create_cpu();
	system->rombuffer = calloc(1, sizeof(char)*filesize);
	fread(system->rombuffer, sizeof(system->rombuffer), 1, file);
	
	return system;
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

void destroy_cpu(cpu_t* cpu) {
	if(cpu) {
		free(cpu);
	}
}

