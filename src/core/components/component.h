#ifndef _COMPONENT_H_
#define _COMPONENT_H_


#define COMPONENT_NAME_LENGTH 7

struct _Component;

typedef void (*ClockFunc)(struct _Component *component);

typedef struct _Component {
    ClockFunc pre_clock;
    ClockFunc post_clock;
    char name[COMPONENT_NAME_LENGTH+1];
} Component;

void component_init(Component *component, char *name, ClockFunc pre_clock, ClockFunc post_clock);

#endif