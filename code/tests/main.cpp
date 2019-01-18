/**
 * This file is the main test file used by the CppUTest framework.
 */

#include "CppUTest/CommandLineTestRunner.h"
 
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
