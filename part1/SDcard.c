#include "main.h"
#include "port.h"
#include "SDcard.h"
#include "spi.h"

uint8_t SDcard_init()
{
	uint8_t return_value[5];
	uint8_t error_flag, error_status, index, timeout;
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
		if(return_value[0] != 0x01)
		{
			error_flag = WRONG_RESPONCE;
		}
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
	if(return_value[0] == 0x05)
		error_flag = WRONG_RESPONCE;
	else if(return_value[0] != 0x01)
		error_flag = FAIL_SDINIT;
	ncs = 1;
	
	
	
	// SEND CMD58
	if(error_flag == NO_ERRORS)
	{
		ncs = 0;
		error_flag = send_command(58, 0);
	}
	if(error_flag == NO_ERRORS)
	{
		error_flag = get_response(5, return_value);
	}
	if(return_value[0] == 0x01)
	{
		error_flag = WRONG_RESPONCE;
	}
//	voltage_range = return_value[2];
	
	
	// Send ACMD41
	if(error_flag == NO_ERRORS)
	{
		ncs = 0;
		error_flag = send_command(55, 0);
	}
	if(error_flag == NO_ERRORS)
	{
		timeout = 0;
		do
		{
			error_flag = get_response(1, return_value);
			timeout++;
		}while(!(error_flag == 0x01 || error_flag == 0x00) && timeout != 0);
		if(timeout == 0)
			error_flag = TIMEOUT_ERROR;			
	}
	timeout = 0;
	if(error_flag == NO_ERRORS)
	{
		do
		{
			error_flag = send_command(41, ACMD41_argum);
			if(error_flag == NO_ERRORS)
			{
				error_flag = get_response(1, return_value);
			}
			timeout++;
		}while(return_value[0] != 0x00 && timeout != 0 && error_flag == NO_ERRORS);
		if(timeout == 0)
		{
			error_flag = TIMEOUT_ERROR;
		}
	}
	ncs = 1;
	
	
	// Send CMD51
	if(error_flag == NO_ERRORS)
	{
		ncs = 0;
		error_flag = send_command(58, 0);
	}
	if(error_flag == NO_ERRORS)
	{
		error_flag = get_response(5, return_value);
	}
	
	ncs = 1;
	if(return_value[1] & 0xC0) //bit 31 and 30 are set
	{
		//High Capacity
	}
	else if(return_value[1] & 0x80) // only bit 31 is set
	{
		//Standard Capacity
		error_flag = WRONG_SDCARD;
	}
	else
	{
		error_flag = WRONG_RESPONCE;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	if(error_flag != NO_ERRORS) // LED4 is the error light and this should also be redundent.
	{
		LED4 = 0;
	}
	ncs = 1; // should not be needed but just in case
	
	
		
	
	
	return error_flag; 
}
