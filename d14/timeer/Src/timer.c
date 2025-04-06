/*
 * timer.c
 *
 *  Created on: Apr 3, 2025
 *      Author: sunbeam
 */

#include "timer.h"
void TimerInit(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;

	TIM7->PSC= TIM_PR-1;


}
void TimerDelayMs(uint32_t ms){


	uint32_t cnt = (PClK/ 1000) * ms / TIM_PR;

		TIM7->ARR = cnt-1;

		TIM7->CNT = 0;

		TIM7->CR1 |= TIM_CR1_CEN;

		while(!(TIM7->SR & TIM_SR_UIF));

		TIM7->SR &= ~TIM_SR_UIF;

		TIM7->CR1 &= ~TIM_CR1_CEN;


}
