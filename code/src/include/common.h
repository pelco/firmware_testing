
#ifndef _COMMON_H_
#define _COMMON_H_

#include <inttypes.h>

uint8_t calculator(char op, uint8_t val1, uint8_t val2);

/* I2C Hardware functions and slave registers */
#define I2C_SLAVE_ADDRESS   0x30    /* I2C slave address */
#define I2C_REG1            0x0A    /* Register 1 offset */
#define I2C_REG2            0x0B    /* Register 2 offset */
#define I2C_REG3            0x0C    /* Register 3 offset */
#define I2C_START_DEV       0x01    /* Slave init value */
#define DEVICE_READY        0x10    /* Device ready */

uint8_t i2c_read(uint8_t address, uint8_t reg_addr);
uint8_t i2c_write(uint8_t address, uint8_t reg_addr, uint8_t value);

/* Other Examples */
uint8_t mem_leak_function(void);
void ISR(void);
void wait_for_ISR_func(void);

#ifdef TEST_MAIN
/**
 * These functions are only used in the CppUTest framework so that we
 * can to test them.
 */
void init_device(void);
uint32_t test_main(void);
#endif

#endif
