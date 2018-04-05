/**
 * This file contains mock functions of src/hw/i2c.c file. Mocking allows us to
 * use these functions in the test framework to test firmware with hardware
 * dependencies and define which execution path we want to take.
 */

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
    #include "common.h"
}

/**
 * I2c read mock function
 */
uint8_t i2c_read(uint8_t address, uint8_t reg_addr)
{
    return (uint8_t)
            mock().actualCall("i2c_read")
            .withParameter("address", address)
            .withParameter("reg_addr", reg_addr)
            .returnUnsignedIntValueOrDefault(0);
}

/**
 * I2c read write function
 */
uint8_t i2c_write(uint8_t address, uint8_t reg_addr, uint8_t value)
{
    return (uint8_t)
            mock().actualCall("i2c_write")
            .withParameter("address", address)
            .withParameter("reg_addr", reg_addr)
            .withParameter("value", value)
            .returnUnsignedIntValueOrDefault(0);
}
