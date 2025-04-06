
#include "led.h"

void LcdInit(void){

	i2cInit();

	DelayMs(20);
	LcdWriteNIbble(LCD_CMD,0x03);
	DelayMs(5);
	LcdWriteNIbble(LCD_CMD,0x03);
	DelayMs(1);
	LcdWriteNIbble(LCD_CMD,0x03);
	DelayMs(1);
	LcdWriteNIbble(LCD_CMD,0x02);
	DelayMs(1);
	LcdWriteByte(LCD_CMD, LCD_FNSET_2LINE);
	LcdWriteByte(LCD_CMD, LCD_DISPOFF);

	LcdWriteByte(LCD_CMD, LCD_CLEAR);

	LcdWriteByte(LCD_CMD, LCD_ENTRYMODE);
	LcdWriteByte(LCD_CMD, LCD_DISPON);


}
void LcdWriteNIbble(uint8_t rs,uint8_t data)
{
	uint8_t rsFlag = rs== LCD_DATA ? BV(LCD_RS_Pos) : 0;
	uint8_t val= (data << 4) | rsFlag | BV(LCD_BL_Pos) | BV(LCD_EN_Pos);
	i2cwrite(LCD_SLAVE_ADDR_W, val);
     DelayMs(1);
     val = (data << 4) | rsFlag | BV(LCD_BL_Pos);
     i2cwrite(LCD_SLAVE_ADDR_W, val);

}
void LcdWriteByte(uint8_t rs,uint8_t data){


	uint8_t high = data >> 4,low = data & 0x0F;
	LcdWriteNIbble(rs, high);
	LcdWriteNIbble(rs, low);
	DelayMs(1);

}
void LcdPuts(uint8_t line, char * str){

	LcdWriteByte(LCD_CMD, line);
	for(int i=0; str[i] != '\0'; i++)
			LcdWriteByte(LCD_DATA, str[i]);

}
