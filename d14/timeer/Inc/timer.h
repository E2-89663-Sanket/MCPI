/*
 * timer.h
 *
 *  Created on: Apr 3, 2025
 *      Author: sunbeam
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stm32f4xx.h>

#define PClK     16000000
#define TIM_PR    16000

void TimerInit(void);
void TimerDelayMs(uint32_t ms);

#endif /* TIMER_H_ */
