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

/**
 * This example shows how to launch interrupts service routines
 * to mimic firmware behaviour
 */
volatile uint8_t brick_code = 1;

void ISR(void)
{
    brick_code = 0;
}

void wait_for_ISR_func(void)
{
    while(brick_code){
        //printf(" Stuck forever here\n");
    };
    printf(" -> Out of the loop");
}