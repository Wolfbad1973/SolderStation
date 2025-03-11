#include "solder.h"

void SOLDER_init(void)
{
	DDRB |= (1<<PB0);
	
}

void SOLDER_out(void)
{
	if(adc_value < 1023)
	{
		PORTB |= (1<<PB0);
		//	_delay_ms(500);
	}
	if(adc_value > encode_value)//сравниваем число из регистра АЦП с числом заданым кнопками.
	{
		PORTB &= ~(1<<PB0);
		//_delay_ms(5);
	}
}


