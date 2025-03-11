#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


#include "lcd.h"
#include "adc.h"
#include "solder.h"
#include "button.h"
int adc_value;

//int encode;
int encode_value;
unsigned char i;
unsigned butcount, butstate;
#endif /* MAIN_H_ */