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

TEST(t_main, i2c_start)
{
    mock().expectOneCall("i2c_read").withParameter("address", I2C_SLAVE_ADDRESS).andReturnValue(6);

    init_device();
}