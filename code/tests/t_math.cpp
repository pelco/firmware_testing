/**
 * This file has all unit tests for all functions in src/math.c
 */

#include "CppUTest/TestHarness.h"

extern "C" {
	#include "common.h"
}

TEST_GROUP(t_math)
{};

/* Test covers addition case */
TEST(t_math, calc_plus)
{
  uint8_t ret = calculator('+', 2, 8);
  CHECK_EQUAL(10, ret);
}

/* Test covers subtraction case */
TEST(t_math, calc_minus)
{
  uint8_t ret = calculator('-', 5, 5);
  CHECK_EQUAL(0, ret);
}

/* Tests covers default case */
TEST(t_math, calc_default_mul)
{
  uint8_t ret = calculator('*', 1, 5);
  CHECK_EQUAL(0, ret);
}
TEST(t_math, calc_default_div)
{
  uint8_t ret = calculator('/', 1, 5);
  CHECK_EQUAL(0, ret);
}

/* Test covers integer overflow case for addition operations */
TEST(t_math, calc_ret_overflow_add)
{
  uint8_t ret = calculator('+', 200, 56);
  CHECK_EQUAL(0, ret);

  ret = calculator('+', 200, 57);
  CHECK_EQUAL(1, ret);
}

/* Test covers integer overflow case for subtraction operations */
TEST(t_math, calc_ret_overflow_minus)
{
  uint8_t ret = calculator('-', 0, 1);
  CHECK_EQUAL(255, ret);
}
