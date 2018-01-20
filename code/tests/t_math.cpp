
#include "CppUTest/TestHarness.h"

extern "C" {
	#include "common.h"
}

TEST_GROUP(t_code)
{};

/* Test covers addition case */
TEST(t_code, calc_plus)
{
  uint8_t ret = calculator('+', 2, 8);
  CHECK_EQUAL(10, ret);
}

/* Test Covers subtraction case */
TEST(t_code, calc_minus)
{
  uint8_t ret = calculator('-', 5, 5);
  CHECK_EQUAL(0, ret);
}

/* Covers over loop use case when user
 *  doesnt know what he is doing. */
TEST(t_code, calc_overloop)
{
  uint8_t ret = calculator('+', 200, 56);
  CHECK_EQUAL(0, ret);

  ret = calculator('+', 200, 57);
  CHECK_EQUAL(1, ret);

  ret = calculator('-', 0, 1);
  CHECK_EQUAL(255, ret);
}