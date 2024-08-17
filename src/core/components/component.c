#include "component.h"

#include <string.h>
#include <stdio.h>

void component_init(Component *component, char *name, ClockFunc pre_clock, ClockFunc post_clock) {
    if (strlen(name) > COMPONENT_NAME_LENGTH) {
        fprintf(stderr, "Component name '%s' exceeds maximum length of %d characters, truncating!\n", name, COMPONENT_NAME_LENGTH);
    }
    strncpy(component->name, name, COMPONENT_NAME_LENGTH);
    component->pre_clock = pre_clock;
    component->post_clock = post_clock;
}