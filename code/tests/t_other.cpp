/**
 * This file has all unit tests for all functions in src/other.c
 */

#include "CppUTest/TestHarness.h"
#include <thread>

extern "C" {
    #include <unistd.h>
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

/**
 * Test function that is leaking memory.
 * Change memory leak definition CPPUTEST_USE_MEM_LEAK_DETECTION=N to
 * CPPUTEST_USE_MEM_LEAK_DETECTION=Y in the MakefileCppUTest.mk file.
 * Then Run: make test
 */
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

/**
 * Thread that calls ISR function after some microseconds.
 */
void call_ISR(uint32_t usec)
{
    usleep(usec);
    ISR();
}
/**
 * This test example shows how to test specific function that depends
 * on a ISR to happen in order to continue it's execution.
 */
TEST(t_other, wait_for_ISR_func)
{
  /* Call ISR after 10 usec */
  std::thread first (call_ISR, 10);

  wait_for_ISR_func();
  CHECK_EQUAL(0, brick_code);

  first.join();
}
