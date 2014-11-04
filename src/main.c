#include <stdio.h>
#include "../include/main.h"
#include "../include/system.h"

int main(int argc, char* argv[]) {
	printf("eightchips version: %f\n", VERSION_NUMBER);
	
	system_t* system = create_system();
	destroy_system(system);
	
	return 0;
}
