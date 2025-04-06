#include<stm32f407xx.h>

#define BV(n) (1<<(n))

void gpio_init(void);
void led_on(int num1,int num2);
void led_off(int num1,int num2);
