#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdint.h>
#include <stdbool.h>
#include "component.h"

typedef struct {
    Component component;
    uint8_t *outputs;
    uint8_t *clock;
    uint32_t mask;
    int width;
    uint8_t value;
    bool has_new_value;
    uint8_t last_clock;
} Counter;

Counter *counter_create(char *name, int width, uint8_t *clock);

void counter_pre_clock(Component *component);

void counter_post_clock(Component *component);

void counter_destroy(Counter *counter);

#endif