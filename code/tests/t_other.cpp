/**
 * This file has all unit tests for all functions in src/other.c
 */

#include "CppUTest/TestHarness.h"

extern "C" {
	#include "common.h"
}

TEST_GROUP(t_other)
{};

TEST(t_other, mem_leak_example)
{
  uint8_t ret = mem_leak_function();
  CHECK_EQUAL(1, ret);
}