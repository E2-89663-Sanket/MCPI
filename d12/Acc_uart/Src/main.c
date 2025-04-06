/*
#include <stdint.h>
	#include <stdio.h>
	#include "uart.h"

	#if !defined(__SOFT_FP__) && defined(__ARM_FP)
	  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
	#endif

	int main(void) {
		UartInit(9600);
		UartPuts("DESD @ Sunbeam.\r\n");
		UartPuts("God Bless You!!\r\n");
		UartPuts("ALL THE BEST!\r\n");
	}
		AccelRead(&accel);
		sprintf(str, "%d, %d      ", accel.x, accel.y);
		LcdPuts(LCD_LINE1, str);
		sprintf(str, "ACCEL %d      ", accel.z);
		LcdPuts(LCD_LINE2, str);
		DelayMs(1000);
	}
}
*/
#include <stdint.h>
#include <stdio.h>
#include "accel.h"
#include "uart.h"
//#include "lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
		//UartInit(9600);
		//UartPuts("Me hu Unhoni\r\n");
		//UartPuts("God Bless You!!\r\n");
		//UartPuts("ALL THE BEST!\r\n");
		char str[50];
		AccelInit();
		AccelData_t accel;
		AccelRead(&accel);
		UartInit(9600);
		while(AccelWaitForChange())
		{
		sprintf(str,"x=%d, y=%d z=%d ",accel.x, accel.y, accel.z);
		UartPuts("Sanket");
		UartPuts(str);
		}

}

