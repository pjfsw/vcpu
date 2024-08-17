#include "register.h"
#include <stdlib.h>

Register *register_create(char *name, uint8_t **inputs, uint8_t *clock) {
    Register *reg = calloc(1, sizeof(Register));
    component_init((Component*)reg, name, register_pre_clock, register_post_clock);
    for (int i = 0;i < 8; i++) {
        reg->inputs[i] = inputs[i];
    }
    reg->clock = clock;
    return reg;
}


void register_pre_clock(Component *component) {
    Register *reg = (Register*)component;
    uint8_t clock = *reg->clock;
    if (clock && !reg->last_clock) {
        for (int i = 0; i < 8; i++) {
            reg->next_value[i] = *reg->inputs[i];
        }
        reg->have_new_value = true;        
    }
    reg->last_clock = clock;
}

void register_post_clock(Component *component) {
    Register *reg = (Register*)component;
    if (reg->have_new_value) {
        for (int i = 0; i < 8; i++) {
            reg->values[i] = reg->next_value[i];
        }
        reg->have_new_value = false;
    }
}

void register_destroy(Register *reg) {
    free(reg);
}