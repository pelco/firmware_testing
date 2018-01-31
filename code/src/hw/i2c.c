/**
 * This file implements the i2c hardware functions and are provided by the
 * SoC vendor. This type of functions (architecture specific) make embedded
 * systems debugging difficult and painful.
 * These functions are mocked in tests/mocks/i2c_mock.cpp by the CppUTest
 * framework and therefore never called.
 */

#include <stdio.h>
#include "common.h"

/**
 * This implements i2c read hw function.
 */
uint8_t i2c_read(uint8_t address)
{
    printf("I2C read at address 0x%x\n", address);
    return 0;
}

/**
 * This implements i2c write hw function.
 */
uint8_t i2c_write(uint8_t value, uint8_t address)
{
    printf("I2C write value 0x%x at address 0x%x\n", value, address);
    return 0;
}
