#include "main.h"
#include "port.h"
#include <stdio.h>
#include "uart.h"
#include "memory_test.h"
#include "print_bytes.h"
#include "hardware_delay.h"
#include "lcd.h"
#include "spi.h"
void main(void)
{
	
//	uint8_t *pntr;
	LED3=0;
	UART_Init();
	LCD_Init();


//	pntr = xdata_memory_init();
	
	//pntr = code_memory_init();
//	print_memory(pntr, 37);
	//LCD_Print(11, "Hello World");
//	LCD_Write(1, 'U');
	while(1)
	{
		LED1 = 0;
		LED4 = 0;

		delay_ms(1000);
		LED1 = 1;
		LED4 = 1;
		LCD_Write(COMMAND, LINE1);
		LCD_Print(16, "Coltons and Matt");
		LCD_Write(COMMAND, LINE2);
		LCD_Print(15, "hews LCD Works!");
		delay_ms(3000);
		LCD_Clear();
	}

}

