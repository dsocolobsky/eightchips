#include <stdlib.h>

#include "../include/system.h"

system_t* create_system() {
	system_t* system = calloc(1, sizeof(system_t));
	system->cpu = create_cpu();
	
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

