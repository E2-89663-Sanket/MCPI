/*
 * i2c.h
 *
 *  Created on: Mar 31, 2025
 *      Author: sunbeam
 */

#ifndef I2C_H_
#define I2C_H_
#include "stm32f4xx.h"
void i2cInit(void);
void i2cStart(void);
void i2cRepeatStart(void);
void i2cstop(void);
void i2cSendSlaveAddr(uint8_t addr);
void i2cSendData(uint8_t data);

uint8_t i2cRecvDataAck(void);
uint8_t i2cRecvDataNAck(void);

void i2cwrite(uint8_t addr,uint8_t data);



#endif /* I2C_H_ */
