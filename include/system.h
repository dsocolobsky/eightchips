#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

#define MEMORY_SIZE 4096

typedef struct cpu_t {
	/* Registers */
	uint8_t  V[16];		/* General Purpose Registers */
	uint16_t stack[16]; /* Stack Array				 */
	uint16_t I;			/* Memory Address Register	 */
	uint16_t PC;		/* Program Counter			 */
	uint16_t SP;		/* Stack Pointer			 */
	uint8_t  DT;		/* Delay Timer				 */
	uint8_t  ST;		/* Sound Timer				 */
} cpu_t;

typedef struct system_h {
	cpu_t* cpu;
	uint8_t memory[MEMORY_SIZE];
} system_t;

cpu_t* create_cpu();
void destroy_cpu(cpu_t* cpu);

system_t* create_system();
void destroy_system(system_t* system);

#endif
