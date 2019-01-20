# Embedded Firmware Testing

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/afe25c5f6f1a4dab8bebad314cf3ce6a)](https://app.codacy.com/project/pelco/firmware_testing/dashboard)
[![Build Status](https://travis-ci.org/pelco/firmware_testing.svg?branch=master)](https://travis-ci.org/pelco/firmware_testing)
[![Coverage Status](https://coveralls.io/repos/github/pelco/firmware_testing/badge.svg?branch=master)](https://coveralls.io/github/pelco/firmware_testing?branch=master)

## Description

The goal of this project is to show how to test an embedded firmware using [CppUTest](https://github.com/cpputest/cpputest) framework.

![embdev](https://github.com/pelco/firmware_testing/blob/master/img/EmbDevice.png)

An embedded system usually communicates with a many inner devices (e.g.: accelerometers, GPS modules, CAN controllers), but now with the IoT trend, they may also communicate with nearby devices (e.g.: fridge, microwaves, smartphones) and/or remote servers. Thus, testing software for embedded systems can sometimes be very painful.

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
4.  Go inside the code folder
    ```bash
    cd code
    ```

## Build Targets

1.  Build "firmware" (Source)
    ```bash
    make
    ```

2.  Run test cases
    ```bash
    make test
    ```

3.  Run coverage report
    ```bash
    make coverage
    ```

*Working on it....*

Features covered:

1.  Simple Unit Test
2.  Testing ISRs
3.  Testing Hardware Dependencies
