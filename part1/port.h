#ifndef _PORT_H
#define _PORT_H
#include "main.h"


// Port 0
sfr LCD_MODULE_DATA_PORT = 0X80; // PORT 0
sfr LCD_DATA_OUT = 0X80;

// Port 1
sbit P1_0 = P1^0; // unused
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;

// Port 2
sbit SW1 = P2^0;
sbit SW2 = P2^1;
sbit SW3 = P2^2;
sbit SW4 = P2^3;
sbit LED1 = P2^4;
sbit LED2 = P2^5;
sbit LED3 = P2^6;
sbit LED4 = P2^7;

// Port 3
sbit TxD_PIN = P3^1;
sbit RxD_PIN = P3^0;
sbit P3_2 = P3^2;
sbit P3_3 = P3^3; // pins that are not used
sbit P3_4 = P3^4;
sbit P3_5 = P3^5;
sbit RS = P3^6;
sbit E = P3^7;

#endif
