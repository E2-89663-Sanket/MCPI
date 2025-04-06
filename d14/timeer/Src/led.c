/*
 * led.c
 *
 *  Created on: Mar 22, 2025
 *      Author: sunbeam
 */

#include"led.h"
void led_init(uint8_t pin)
{
	RCC->AHB1ENR |=BV(GPIOD_CLK_EN);
	LED_GPIO->MODER &= ~BV(pin*2+1);
	LED_GPIO->MODER |= BV(pin *2);

	LED_GPIO->OTYPER &=~BV(pin);

	LED_GPIO->OSPEEDR &= ~(BV(pin*2) | BV(pin*2+1));
	LED_GPIO->PUPDR &= ~BV(pin);
}
void led_on(uint8_t pin){
	LED_GPIO->ODR |= BV(pin);
}
void led_off(uint8_t pin){
   LED_GPIO->ODR &= ~(BV(pin));
}
void led_toggle(uint8_t pin){

    LED_GPIO->ODR ^= (BV(pin));


}
