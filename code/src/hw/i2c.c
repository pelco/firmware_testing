/**
 * This file implements i2c hardware functions. These funcions are hardware
 * specific and are supplied by the vendor SoC vendor.
 * These functions are hard
 */

#include <stdio.h>
#include "common.h"

/**
 * 
 * This implements i2c read hw function. The function is never called
 * in the unit test because it's mocked by the CppUTest framework.
 */
uint8_t i2c_read(uint8_t address)
{
    printf("I2C read at address 0x%x\n", address);
    return 0;
}

/**
 * I2C Write implements a hardware function that is never called in the
 * unit test. They are mocked by the CppUTest Framework.
 */
uint8_t i2c_write(uint8_t value, uint8_t address)
{
    printf("I2C write value 0x%x at address 0x%x\n", value, address);
    return 0;
}
