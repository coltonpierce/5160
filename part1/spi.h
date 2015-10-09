#ifndef _SPI_H
#define _SPI_H

uint8_t SPI_transfer(uint8_t data_input, uint8_t *data_output);

uint8_t send_command(uint8_t cmd, uint32_t argum);

uint8_t get_response(uint8_t num_bytes, uint8_t *array_out);



#endif





