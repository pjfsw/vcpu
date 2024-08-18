#include "register.h"
#include <stdlib.h>
#include <stdio.h>

Register *register_create(char *name, uint8_t *input, uint8_t *clock) {
    Register *reg = calloc(1, sizeof(Register));
    component_init((Component*)reg, name, register_pre_clock, register_post_clock);
    reg->input = input;
    reg->clock = clock;
    return reg;
}


void register_pre_clock(Component *component) {
    Register *reg = (Register*)component;
    uint8_t clock = *reg->clock;
    if (clock && !reg->last_clock) {
        reg->next_value = *reg->input;
        reg->have_new_value = true;        
        printf("Register[%s] New Value: %d\n", reg->component.name, reg->next_value);

    }
    reg->last_clock = clock;
}

void register_post_clock(Component *component) {
    Register *reg = (Register*)component;
    if (reg->have_new_value) {
        reg->output = reg->next_value;
        reg->have_new_value = false;
    }
}

uint8_t *register_output(Register *reg) {
    return &reg->output;
}

void register_destroy(Register *reg) {
    free(reg);
}