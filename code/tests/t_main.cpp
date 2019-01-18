/**
 * This file has all unit tests for all functions in src/main.c
 */

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
	#include "common.h"
}

TEST_GROUP(t_main)
{
    /* Stuff to do before each test */
    void setup()
    { }

    /* Stuff to do after each test */
    void teardown()
    {
        mock().checkExpectations(); /* Check mock expectations */
        mock().clear();             /* Delete metadata */
    }

};

/* Test checks correct call of init_device */
TEST(t_main, init_device_call)
{
    mock().expectOneCall("i2c_write").withParameter("address", I2C_SLAVE_ADDRESS)
                                     .withParameter("reg_addr", I2C_REG1)
                                     .withParameter("value", I2C_START_DEV)
                                     .andReturnValue(0);
    init_device();
}

/**
 * Test reconfiguration case, when device does not respond to
 * first i2c_read call.
 */
TEST(t_main, check_reconfigure_behaviour)
{
    /**
     * Expect two i2c_write calls with the same parameters:
     *  - One is done at the beggining of main function by the init_device();
     *  - Another is done in the else condition also by init_device();
     */
    mock().expectNCalls(2, "i2c_write")
        .withParameter("address", I2C_SLAVE_ADDRESS)
        .withParameter("reg_addr", I2C_REG1)
        .withParameter("value", I2C_START_DEV)
        .andReturnValue(0);

    /* Expect one i2c_read call and return 0 */
    mock().expectOneCall("i2c_read")
        .withParameter("address", I2C_SLAVE_ADDRESS)
        .withParameter("reg_addr", I2C_REG2)
        .andReturnValue(0); /* Will force firmware to enter else condition */

    /* Run main firmware function */
    uint32_t ret = test_main();
    CHECK_EQUAL(0, ret);
}

/**
 * Test device behaviour when it's ready to be read by the firmware.
 */
TEST(t_main, check_device_ready)
{
    /* Expect one i2w_write call. Ignore parameters */
    mock().expectOneCall("i2c_write")
        .ignoreOtherParameters()
        .andReturnValue(0);

    /* Expect i2c_read call and return DEVICE_READYE */
    mock().expectOneCall("i2c_read")
        .withParameter("address", I2C_SLAVE_ADDRESS)
        .withParameter("reg_addr", I2C_REG2)
        .andReturnValue(DEVICE_READY);

    /* Expect second i2c_read call with reg_addr of I2C_REG3 */
    mock().expectOneCall("i2c_read")
        .withParameter("address", I2C_SLAVE_ADDRESS)
        .withParameter("reg_addr", I2C_REG3)
        .andReturnValue(0);

    /* Run main firmware function */
    uint32_t ret = test_main();
    CHECK_EQUAL(0, ret);
}
