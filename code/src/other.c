/**
 * This file has other examples that can be useful for developers.
 */

#include <stdio.h>
#include <stdlib.h> 
#include "common.h"

/**
 * Example shows function that is leaking memory
 */
uint8_t mem_leak_function(void)
{
    uint8_t *ptr;
    ptr = malloc (1);

    (void)(ptr);

    /**
     * Run: make test_ml
     */
    // free(ptr);
    return 1;
}