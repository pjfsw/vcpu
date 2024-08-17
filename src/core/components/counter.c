#include "counter.h"

#include <stdlib.h>

Counter *counter_create(char *name, int width, uint8_t *clock) {
    Counter *cnt = calloc(1, sizeof(Counter));
    component_init((Component*)cnt, name, counter_pre_clock, counter_post_clock);
    cnt->clock = clock;
    cnt->outputs = calloc(width, sizeof(uint8_t));
    cnt->mask = (1<<width)-1;
    cnt->width = width;
    return cnt;
}

void counter_pre_clock(Component *component) {
    Counter *cnt = (Counter*)component;
    uint8_t clock = *cnt->clock;
    if (clock && !cnt->last_clock) {
        cnt->value = (cnt->value + 1) & cnt->mask;
        cnt->has_new_value = true;
    }
    cnt->last_clock = clock;
}

void counter_post_clock(Component *component) {
    Counter *cnt = (Counter*)component;
    if (cnt->has_new_value) {
        for (int i = 0; i < cnt->width; i++) {
            cnt->outputs[i] = cnt->value & (1<<i);
        }
        cnt->has_new_value = false;
    }
}

void counter_destroy(Counter *counter) {
    free(counter->outputs);
    free(counter);
}
