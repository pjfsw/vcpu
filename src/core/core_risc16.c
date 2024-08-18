#include <stdlib.h>

#include "core_risc16.h"
#include "core_components.h"

Core *core_risc16_create(uint8_t *clock) {
    Core *core = calloc(1, sizeof(Core));
    core_init(core, clock);
    Counter *counter = counter_create("CNTR", 8, clock);    
    core_add_component(core, (Component*)counter);
    Register *ir = register_create("IR", counter_output(counter), clock);
    core_add_component(core, (Component*)ir);
    return core;
}
