#include "counter.h"

#include <stdlib.h>
#include <stdio.h>

Counter *counter_create(char *name, int width, uint8_t *clock) {
    Counter *cnt = calloc(1, sizeof(Counter));
    component_init((Component*)cnt, name, counter_pre_clock, counter_post_clock);
    cnt->clock = clock;
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
        printf("Counter[%s] New Value: %d\n", cnt->component.name, cnt->value);
    }

    cnt->last_clock = clock;
}

void counter_post_clock(Component *component) {
    Counter *cnt = (Counter*)component;
    if (cnt->has_new_value) {
        cnt->output = cnt->value;
        cnt->has_new_value = false;
    }
}

uint8_t *counter_output(Counter *counter) {
    return &counter->output;
}

void counter_destroy(Counter *counter) {
    free(counter);
}
