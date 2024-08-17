#include "cpu.h"

#include <stdlib.h>
#include <stdio.h>

Cpu *cpu_create(Core *core) {
    Cpu *cpu = calloc(1, sizeof(Cpu));
    cpu->core = core;
    cpu->cycle = 0;
    return cpu;
}

int cpu_next(Cpu *cpu) {
    core_clock(cpu->core);
    printf("Cycle %d\n", cpu->cycle);
    cpu->cycle++;    
    return 0;
}

void cpu_destroy(Cpu *cpu) {
    free(cpu);
}


