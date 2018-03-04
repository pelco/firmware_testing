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
     * Change memory leak definition CPPUTEST_USE_MEM_LEAK_DETECTION=N to
     * CPPUTEST_USE_MEM_LEAK_DETECTION=Y in the MakefileCppUTest.mk file.
     * Then Run: make test
     */
    // free(ptr);
    return 1;
}