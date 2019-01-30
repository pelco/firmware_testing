# Testing Embedded Firmware

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/afe25c5f6f1a4dab8bebad314cf3ce6a)](https://app.codacy.com/project/pelco/firmware_testing/dashboard)
[![Build Status](https://travis-ci.org/pelco/firmware_testing.svg?branch=master)](https://travis-ci.org/pelco/firmware_testing)
[![Coverage Status](https://coveralls.io/repos/github/pelco/firmware_testing/badge.svg?branch=master)](https://coveralls.io/github/pelco/firmware_testing?branch=master)
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](https://github.com/pelco/firmware_testing/raw/master/LICENSE)

## Description

Open source project that uses [CppUTest](https://github.com/cpputest/cpputest) framework to test firmware for embedded systems. The project covers some firmware examples that are usually hard to test, including:

1.  Simple API unit test
2.  Memory Leaks test
3.  API unit test with ISR (interrupt service routines) dependencies
4.  API unit test with hardware dependencies
5.  Test/Run main firmware

![](https://github.com/pelco/firmware_testing/blob/master/img/EmbDevice.png)

Usually, an embedded system communicates with many inner devices, such as accelerometers, GPS modules, CAN controllers, RFID readers or Touchscreen+LCD modules. Now, with the IoT trend, they may also communicate with remote servers and/or nearby devices like smartphones, TVs, smartwatches or even your fridge and microwave! Thus, testing software for embedded systems can sometimes be very painful.

The goal is to show how to remove these hardware/devices dependencies and test/run code on a host machine using [CppUTest](https://github.com/cpputest/cpputest) framework.

## Get Started

1.  You will need to install the following tools:
    ```bash
    sudo apt install git gcc g++ libtool autoconf
    ```

2.  Download this repository
    ```bash
    git clone https://github.com/pelco/firmware_testing.git
    ```

3.  Run setup.sh script (will create tools folder, get [CppUTest](https://github.com/cpputest/cpputest) and [LCOV](https://github.com/linux-test-project/lcov))
    ```bash
    cd firmware_testing
    ./setup.sh
    ```

4.  Go inside the code folder to get started
    ```bash
    cd code
    ```

## Folder Structure
```bash
tree -d
```

Output:
```bash
.
├── src             -> Firmware source code
│   ├── hw          -> Hardware/Target specific code
│   └── include     -> Header files
└── tests           -> Test cases
    └── mocks       -> Mocks
```

## Build Targets

1.  Build "firmware" (Source)

    ```bash
    make
    ```

    The command will build the main firmware located at **src/main.c** and create **src/run_this_firmware** binary.
    ```bash
    ./src/run_this_firmware
    ```

    Output:
    ```bash
    Hello World from Firmware
    I2C write value 0x1 to reg 0xa at slave 0x30
    I2C read reg 0x30 from slave 0xb
    I2C write value 0x1 to reg 0xa at slave 0x30
    ```

2.  Run test cases

    The next command will build [CppUTest](https://github.com/cpputest/cpputest) and run all test cases in **tests/t_*.cpp** files.
    ```bash
    make test
    ```

    The command will also build and run the test binary file located  **tests/test_firmware**.
    Output:
    ```bash
    ...
    OK (12 tests, 12 ran, 20 checks, 0 ignored, 0 filtered out, 1 ms)
    ```

3.  Run coverage report

    This command will run all test cases and generate a firmware coverage report. 
    ```bash
    make coverage
    ```

    A **coverage** folder should have been created and you can access the result by open **coverageTest.html/index.html** with your browser:

    ![](https://github.com/pelco/firmware_testing/blob/master/img/lcovRep.png)

## Features Covered

### Simple Unit Test

In **src/math.c** file has a simple calculator API that implements addition and subtraction operations. 

math.c:

```C
uint8_t calculator(char op, uint8_t val1, uint8_t val2)
{
    uint8_t result = 0;

    switch (op) {
        case '+':
            result = (uint8_t)(val1 + val2);
            break;
        case '-':
            result = (uint8_t)(val1 - val2);
            break;
        default:
            break;
    }

    return result;
}
```

The test cases are implemented in **tests/t_math.cpp** and cover:
- All switch cases;
- Return overflow;

### Memory Leaks

In **src/other.c** file is implemented a function that is leaking memory. 

other.c:

```C
uint8_t mem_leak_function(void)
{
    uint8_t *ptr;
    ptr = malloc(1);

    (void)(ptr);

    // free(ptr);
    return 1;
}
```

By default memory leak detection is turned off. To enable memory leak detection change `CPPUTEST_USE_MEM_LEAK_DETECTION=N` to `CPPUTEST_USE_MEM_LEAK_DETECTION=Y` in **MakefileCppUTest.mk** file. 
Then build and run test cases again.

The test cases are implemented in **tests/t_other.cpp**.

### Testing ISRs

In **src/other.c** is also implemented a function (wait_for_ISR_func()) that depends on a ISR() (interrupt service routines) to happen in order for the firmware function continue it's execution.

other.c:

```C
volatile uint8_t brick_code = 1;

void ISR(void)
{
    brick_code = 0;
}

void wait_for_ISR_func(void)
{
    while (brick_code) {
        //printf(" Stuck forever here\n");
    };
    printf(" -> Out of the loop");
}

```

The test cases are implemented in **tests/t_other.cpp** and show how to handle these cases.

### Testing Hardware Dependencies

In **src/main.c** is implemented the main firmware code.

main.c:

```C
uint32_t main(void)
{
    printf(" Hello World from Firmware\n");

    uint8_t reg = 0;

    init_device(); /* Configure i2c device */

    reg = i2c_read(I2C_SLAVE_ADDRESS, I2C_REG2);
    if (reg == DEVICE_READY) {
        i2c_read(I2C_SLAVE_ADDRESS, I2C_REG3);
    } else {
        init_device(); /* Reconfigure device if it's not ready */
    }

    return 0;
}
```

This main firmware code has some hardware dependencies (i2c) that are usually painful to get it running on a host machine.
The test cases show how to get this main function running and how to handle this dependencies.

These hardware dependencies are mocked in **tests/mocks/i2c_mock.cpp** and the main test cases are implemented in **tests/t_main.cpp**.
