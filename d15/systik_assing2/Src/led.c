/*
 * led.c
 *
 *  Created on: Apr 5, 2025
 *      Author: sunbeam
 */
#include"led.h"
void LedInit(uint32_t pin){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= BV(pin*2);
	GPIOD->MODER &= ~BV(pin*2 + 1);
	GPIOD->PUPDR &= ~(BV(pin*2) | BV(pin*2 + 1));
	GPIOD->OSPEEDR &= ~(BV(pin*2) | BV(pin*2 + 1));
	GPIOD->OTYPER &= ~BV(pin);

}

void LedOn (uint32_t pin){
	GPIOD->BSRR |= BV(pin);

}

void LedOff(uint32_t pin) {
	GPIOD->BSRR |= BV(pin + 16);

}

void LedBlink(uint32_t pin, uint32_t ms ) {
	LedOn(pin);
	DelayMs(ms);
	LedOff(pin);

}

void LedToggle(uint32_t pin) {
	GPIOD->ODR ^= BV(pin);
}
