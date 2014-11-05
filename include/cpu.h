#ifndef CPU_H
#define CPU_H

#include "system.h"

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

cpu_t* create_cpu();
void destroy_cpu(cpu_t* cpu);

uint16_t get_opcode(system_t* system, int index);
uint16_t get_current_opcode(system_t* system);

#endif
