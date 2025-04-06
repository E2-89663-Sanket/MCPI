#include"led.h"

void gpio_init(void)
{
	    RCC->AHB1ENR|=BV(3);
		GPIOD->MODER&=~(BV(25)|BV(27)|BV(29)|BV(31));
		GPIOD->MODER|=(BV(24)|BV(26)|BV(28)|BV(30));

		GPIOD->OTYPER&=~(BV(15)|BV(14)|BV(13)|BV(12));

		GPIOD->OSPEEDR&=~(BV(25)|BV(27)|BV(29)|BV(31));
		GPIOD->OSPEEDR&=~(BV(24)|BV(26)|BV(28)|BV(30));

		GPIOD->PUPDR&=~(BV(25)|BV(27)|BV(29)|BV(31));
		GPIOD->PUPDR&=~(BV(24)|BV(26)|BV(28)|BV(30));

}

	void led_on(int num1,int num2)
	{
		GPIOD->ODR|=BV(num1)|BV(num2);
	}
	void led_off(int num1,int num2)
		{
			GPIOD->ODR&=~(BV(num1)|BV(num2));
		}
