/**
 * This file has all unit tests for all functions in src/other.c
 */

#include "CppUTest/TestHarness.h"

extern "C" {
	#include "common.h"
}

extern uint8_t brick_code;

TEST_GROUP(t_other)
{
    /* Stuff to do before each test */
    void setup()
    {
        /* Restore original state */
        brick_code = 1;
    }
    /* Stuff to do after each test */
    void teardown(){}
};

/* */
TEST(t_other, mem_leak_example)
{
  uint8_t ret = mem_leak_function();
  CHECK_EQUAL(1, ret);
}

/* Test example calling an ISR */
TEST(t_other, _ISR_)
{
  /* Check init conditions */
  CHECK_EQUAL(1, brick_code);
  ISR();
  CHECK_EQUAL(0, brick_code);
}