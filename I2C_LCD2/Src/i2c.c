/*
 * i2c.c
 *
 *  Created on: Mar 31, 2025
 *      Author: sunbeam
 */

#include "i2c.h"


void i2cInit(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	GPIOB->MODER |= BV(2*6+1) | BV(2*7+1);
	GPIOB->MODER &= ~(BV(2*6) | BV(2*7));

	GPIOB->AFR[0] = (4 << (6*4)) | (4 << (4*7));

	GPIOB->PUPDR &= ~(BV(2*6) | BV(2*7) | BV(2*6+1) | BV(2*7+1));
	GPIOB->OTYPER |= BV(6) | (BV(7));
	RCC->APB1ENR |=RCC_APB1ENR_I2C1EN;
	DelayMs(100);

	I2C1->CR1|=I2C_CR1_SWRST;

	I2C1->CR1 =0;

	I2C1->CR2 |= 16 << I2C_CR2_FREQ_Pos;


	I2C1->CCR = 80;

	I2C1->CCR &= ~I2C_CCR_FS;

	I2C1->TRISE = 17;
	I2C1->CR1 |=I2C_CR1_ACK;
	I2C1->CR1 |= I2C_CR1_PE;

}
void i2cStart(void){
	I2C1->CR1 |=I2C_CR1_START;

	while(!(I2C1->SR1 & I2C_SR1_SB));

}


void i2cRepeatStart(void){
	i2cStart();
}


void i2cstop(void){

	I2C1->CR1  |=I2C_CR1_STOP;
	while(I2C1->SR2 & I2C_SR2_BUSY);
}



void i2cSendSlaveAddr(uint8_t addr){
I2C1->DR= addr;
while(!(I2C1->SR1 & I2C_SR1_ADDR));

(void)I2C1->SR1;
(void)I2C1->SR2;

}


void i2cSendData(uint8_t data){

	while(!(I2C1->SR1 & I2C_SR1_TXE));
	I2C1->DR = data;

	while(!(I2C1->SR1 & I2C_SR1_BTF));
}

uint8_t i2cRecvDataAck(void)
{
	I2C1->CR1 |=I2C_CR1_ACK | I2C_CR1_ACK_Pos;

	while(!(I2C1->SR1 & I2C_SR1_RXNE));

	return I2C1->DR;
}
uint8_t i2cRecvDataNAck(void){


	I2C1->CR1  &= ~(I2C_CR1_ACK | I2C_CR1_POS);

	while(!(I2C1->SR1 & I2C_SR1_RXNE));
return I2C1->DR;

}
void i2cwrite(uint8_t addr,uint8_t data)
{
	i2cStart();
	i2cSendSlaveAddr(addr);
	i2cSendData(data);
	i2cstop();



}

