# Embedded Firmware Testing  :boom:

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/afe25c5f6f1a4dab8bebad314cf3ce6a)](https://app.codacy.com/project/pelco/firmware_testing/dashboard)
[![Build Status](https://travis-ci.org/pelco/firmware_testing.svg?branch=master)](https://travis-ci.org/pelco/firmware_testing)
[![Coverage Status](https://coveralls.io/repos/github/pelco/firmware_testing/badge.svg?branch=master)](https://coveralls.io/github/pelco/firmware_testing?branch=master)

## Description

The goal of this project is to show how to test an embedded firmware using [CppUTest](https://github.com/cpputest/cpputest) framework.

![embeddedDevice](https://github.com/pelco/firmware_testing/blob/master/img/EmbDevice.png)

Usually, an embedded system communicates with many inner devices, such as accelerometers, GPS modules, CAN controllers, RFID readers or Touchscreen+LCD modules. Now, with the IoT trend, they may also communicate with remote servers and/or nearby devices like smartphones, TVs, smartwatches or even your fridge and microwave! Thus, testing software for embedded systems can sometimes be very painful.

The goal is to show how to remove these hardware/devices dependencies and test/run code on a host machine using [CppUTest](https://github.com/cpputest/cpputest) framework.

## Get Started

1.  You will need to install the following tools:
    ```bash
    $ sudo apt install git gcc g++ libtool autoconf
    ```

2.  Download this repository
    ```bash
    $ git clone https://github.com/pelco/firmware_testing.git
    ```

3.  Run setup.sh script (will create tools folder, get [CppUTest](https://github.com/cpputest/cpputest) and [LCOV](https://github.com/linux-test-project/lcov))
    ```bash
    $ cd firmware_testing
    $ ./setup.sh
    ```
4.  Go inside the code folder to get started
    ```bash
    $ cd code
    ```

## Build Targets

1.  Build "firmware" (Source)
    ```bash
    $ make
    ```
    This command will build the main firmware located at **src/main.c** and create **src/run_this_firmware** binary.
    Note that currently this piece of code doesn't actually has any hardware dependency so it should build and run on any machine.
     ```bash
    $ ./src/run_this_firmware
    Hello World from Firmware
    I2C write value 0x1 to reg 0xa at slave 0x30
    I2C read from slave 0x30 at reg 0xb
    I2C write value 0x1 to reg 0xa at slave 0x30
    ```
    The I2C hardware functions are located at **src/hw/i2c.c**. You will notice in the next commands that the I2C prints (hardware operations) will not be printed.
    If you add hardware specific code to this file, this build will fail but the test and coverage will continue to work.

2.  Run test cases
    ```bash
    $ make test
    ...
    TEST(t_main, check_device_ready) Hello World from Firmware - 0 ms
    TEST(t_main, check_reconfigure_behaviour) Hello World from Firmware - 0 ms
    ...
    OK (12 tests, 12 ran, 20 checks, 0 ignored, 0 filtered out, 1 ms)
    ```
    Note that the two test above did not printed any I2C message.

3.  Run coverage report
    ```bash
    make coverage
    ```

*Working on it....*

Features covered:

1.  Simple Unit Test
2.  Testing ISRs
3.  Testing Hardware Dependencies
