#include<stm32f407xx.h>

#define BV(n) (1<<(n))

void gpio_init(void);
void led_on(uint8_t num);
void led_off(uint8_t num);
void all_led_on(uint8_t num);
