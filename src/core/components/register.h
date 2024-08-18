#ifndef _REGISTER_H_
#define _REGISTER_H_

#include <stdint.h>
#include <stdbool.h>

#include "component.h"

typedef struct {
    Component component;
    uint8_t *input;
    uint8_t *clock;
    uint8_t output;
    uint8_t last_clock;
    uint8_t next_value;
    bool have_new_value;
} Register;

Register *register_create(char *name, uint8_t *input, uint8_t *clock);

void register_pre_clock(Component *component);

void register_post_clock(Component *component);

uint8_t *register_output(Register *reg);

void register_destroy(Register *reg);
 
#endif