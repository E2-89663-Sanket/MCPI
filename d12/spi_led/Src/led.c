/*
 * led.c
 *
 *  Created on: Mar 21, 2025
 *      Author: sunbeam
 */

#include"led.h"


void led_init(uint8_t pin)
{
	// clock enable
	RCC->AHB1ENR |= BV(GPIOD_CLK_EN);
	// mode - GPIO output
	LED_GPIO->MODER &= ~BV(pin * 2 + 1);
	LED_GPIO->MODER |= BV(pin * 2);
	// type - push pull
	LED_GPIO->OTYPER &= ~BV(pin);
	// speed  - low
	LED_GPIO->OSPEEDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// pull up/down - no
	LED_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
}
void led_on(uint8_t pin)
{
	LED_GPIO->ODR |= BV(pin);
}
void led_off(uint8_t pin)
{
	LED_GPIO->ODR &= ~BV(pin);
}
void led_toggle(uint8_t pin)
{
	LED_GPIO->ODR ^= BV(pin);
}

