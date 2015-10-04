#ifndef _MAIN_H
#define _MAIN_H


#include "AT89C51RC2.h" // DEFINES SFR'S OF PROCESSOR

#define OSC_FREQ 		((uint32_t) 18432000) 	// <- UL?
#define OSC_PER_INST  	(12) 					//CLOCK DIVISION
#define BAUD_RATE 		9600
#define NULL 			0


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;



#endif



