#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>

typedef struct {
    uint32_t size;
    uint32_t *contents;
} Memory;


#endif 