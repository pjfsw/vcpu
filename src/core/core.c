#include <stdlib.h>
#include <stdio.h>

#include "core.h"

void core_init(Core *core, uint8_t *clock) {
    core->clock = clock;
}

void core_add_component(Core *core, Component *component) {
    if (core->component_count >= CORE_MAX_COMPONENT_COUNT) {
        fprintf(stderr, "Component count exceeded\n");
        return;
    }
    core->components[core->component_count] = component;
    core->component_count++;
}

static void _core_clock_components(Core *core) {
    int component_count = core->component_count;
    Component **components = core->components;
    for (int i = 0; i < component_count; i++) {
        components[i]->pre_clock(components[i]);        
    }
    for (int i = 0; i < component_count; i++) {
        components[i]->post_clock(components[i]);        
    }
}

void core_clock(Core *core) {
    *core->clock = 1;
    _core_clock_components(core);
    *core->clock = 0;
    _core_clock_components(core);
}

void core_destroy(Core *core) {
    free(core);
}
