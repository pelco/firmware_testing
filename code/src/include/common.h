
#ifndef _COMMON_H_
#define _COMMON_H_

#include <inttypes.h>

uint8_t calculator(char op, uint8_t val1, uint8_t val2);

/* I2C Hardware functions and slave registers */
const uint8_t I2C_SLAVE_ADDRESS = 0x30;
const uint8_t I2C_REG1 = 0x0A;
const uint8_t I2C_REG2 = 0x0B;

uint8_t i2c_read(uint8_t address, uint8_t reg_addr);
uint8_t i2c_write(uint8_t address, uint8_t value);

#endif
