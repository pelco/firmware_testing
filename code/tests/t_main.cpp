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
        mock().clear();             /* Will report memory leak if metadata 
                                        is not deleted */
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