/**
 * This is the main file with firmware code. This code has hardware dependencies
 * (i2c) that are usually painful get it running in a host machine.
 */

#include <stdio.h>
#include "common.h"

/**
 * I2C device configuration
 */
void init_device(void)
{
    /* Start device */
    i2c_write(I2C_SLAVE_ADDRESS, I2C_REG1, I2C_START_DEV);
}

/** 
 * TEST_MAIN macro allows to test firmware code in tests/t_main.cpp
 */
#ifdef TEST_MAIN
uint32_t test_main(void)
#else
uint32_t main(void)
#endif
{
    printf(" Hello World from Firmware\n");

    uint8_t reg = 0;

    init_device(); /* Configure i2c device */

    /**
     * Use case: Firmware tries to read I2C_REG2, if successful it
     * will read I2C_REG3, otherwise tries to configure device again.
     *
     * This type of use cases are painful to simulate and requires developers
     * to create complex stubs that satisfy every case.
     *
     * Mocks allows developers to easily simulate/control these cases.
     * Check tests/t_main.cpp.
     */
    reg = i2c_read(I2C_SLAVE_ADDRESS, I2C_REG2);
    if (reg == DEVICE_READY) {
        i2c_read(I2C_SLAVE_ADDRESS, I2C_REG3);
    } else {
        init_device(); /* Reconfigure device if it's not ready */
    }

    return 0;
}
