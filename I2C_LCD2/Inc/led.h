/*
 * led.h
 *
 *  Created on: Apr 1, 2025
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_
#include "stm32f4xx.h"
#include "i2c.h"
#define LCD_SLAVE_ADDR_W	0x4E
#define LCD_SLAVE_ADDR_R	0x4F
void LcdInit(void);
void LcdWriteNIbble(uint8_t rs,uint8_t data);
void LcdWriteByte(uint8_t rs,uint8_t data);
void LcdPuts(uint8_t line, char * str);


#define LCD_CMD               0
#define LCD_DATA               1
#define LCD_LINE1              0X80
#define LCD_LINE2              0XC0
#define LCD_CLEAR              0X01
#define LCD_ENTRYMODE          0X06
#define LCD_DISPOFF            0X08
#define LCD_DISPON             0X0C
#define LCD_FNSET_1LINE        0X20

#define LCD_FNSET_2LINE        0X28
#define LCD_FNSET_2LINE        0X28
#define LCD_SHIFT              0X18

#define LCD_RS_Pos		0
#define LCD_RW_Pos		1
#define LCD_EN_Pos		2
#define LCD_BL_Pos		3

#endif /* LED_H_ */
