#ifndef _CORE_H
#define _CORE_H

#include "core_components.h"

#define CORE_MAX_COMPONENT_COUNT 1024

typedef struct {
    int component_count;
    Component *components[CORE_MAX_COMPONENT_COUNT];
} Core;

void core_add_component(Core *core, Component *component);

void core_clock(Core *core);

void core_destroy(Core *core);

#endif