#include "main.h"
#include "port.h"
#include <stdio.h>
#include "uart.h"
#include "memory_test.h"
#include "print_bytes.h"
#include "hardware_delay.h"
#include "lcd.h"
#include "spi.h"
#include "SDcard.h"
void main(void)
{
	uint8_t error_flag;

	LED3=0;
	UART_Init();
	LCD_Init();
	SPI_master_init(400000); // Set clock rate to that speed in Hz
	error_flag = SDcard_init();
	

	while(1)
	{
		LED1 = 0;
		LED4 = 0;
		if(error_flag != NO_ERRORS)
		{
			LED4 = 0;
		}
		else
		{
			LED4 = 1;
		}
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

