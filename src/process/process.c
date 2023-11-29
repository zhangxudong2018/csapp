#include <stdlib.h>
#include "headers/interrupt.h"

// We must call this function VERY VERY CAREFULLY
int KERNEL_free(void *ptr) {
    int stack_lower_bound = 100;
    if ((uint64_t)stack_lower_bound > (uint64_t)ptr)
    {
        // ptr is pointing to the area in simulator's heap
        free(ptr);
        return 1;
    }
    // ptr is a pointer in previous stack
    return 0;
}