/*
 * sytick.c
 *
 *  Created on: Apr 5, 2025
 *      Author: sunbeam
 */

#include "systick.h"
volatile uint32_t ticks;

void SysTick_Handler(void) {
		ticks++;
	}

	void SysTickDelayMs(uint32_t ms){
		uint32_t now = ticks;
		uint32_t end_time=now+ms;
		while(ticks<end_time);

	}
