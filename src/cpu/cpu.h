#ifndef _CPU_H_
#define _CPU_H_

#include <stdint.h>

#include "core.h"

typedef struct {
    uint32_t cycle;
    Core *core;
} Cpu;

Cpu *cpu_create(Core *core);

int cpu_next(Cpu *cpu);

void cpu_destroy(Cpu *cpu);

#endif