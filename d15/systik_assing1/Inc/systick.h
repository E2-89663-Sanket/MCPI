/*
 * systick.h
 *
 *  Created on: Apr 5, 2025
 *      Author: sunbeam
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
#include "stm32f4xx.h"
void SysTick_Handler(void);
void SysTickDelayMs(uint32_t ms);

#endif /* SYSTICK_H_ */
