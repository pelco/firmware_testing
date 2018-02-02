
#ifndef _COMMON_H_
#define _COMMON_H_

#include <inttypes.h>

uint8_t calculator(char op, uint8_t val1, uint8_t val2);

/* Hardware functions from hw/i2c.c */
uint8_t i2c_read(uint8_t address);
uint8_t i2c_write(uint8_t address, uint8_t value);

#endif
