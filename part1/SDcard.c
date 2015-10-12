#include "main.h"
#include "port.h"
#include "SDcard.h"
#include "spi.h"

uint8_t SDcard_init()
{
	uint8_t return_value[5];
	uint8_t error_flag, error_status, index;
	uint32_t ACMD41_argum = 0x40000000;
	
	
	
	ncs = 1;
	for(index = 0; index < 10; index++)
	{
		SPI_transfer(0xFF, return_value);
	}
	
	
	// Send CMD0
	ncs = 0;
	error_flag = send_command(CMD0, 0);
	if(error_flag == NO_ERRORS)
	{
		error_flag = get_response(1, return_value);
	}
	if(error_flag == NO_ERRORS)
	{
		if(return_value != 0x01)
		{
			error_flag = WRONG_RESPONCE;
		}
	}
	if(error_flag != NO_ERRORS)
	{
		LED4 = 0;
	}
	ncs = 1;
	
	
	
	// Send CMD8
	if(error_flag == NO_ERRORS)
	{
		ncs = 0;
		error_flag = send_command(CMD8, 0x000001AA);
	}
	if(error_flag == NO_ERRORS)
	{
		error_flag = get_response(5, return_value);
	}
	if(error_flag != NO_ERRORS)
	{
		LED4 = 0;
	}
	ncs = 1;
	
	
		
	
	
	return error_flag; 
}
