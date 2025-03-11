#include "button.h"

void BUTTON_init(void)
{
	// Настройка входа PB1 на вход
	DDRB &= ~(1 << PB1);
	// Настройка входа PB2 на вход
	DDRB &= ~(1 << PB2);
	PORTB |= (1 << PB1);
	PORTB |= (1 << PB2);
	
}

void BUTTON_out(void)
{
	static int encode = 500;
//	_delay_ms(10);
  if (!(PINB & (1 << PB1))) 

  {
	encode++;
  }

//  else
	if (!(PINB & (1 << PB2)))
  {
	encode--;
  }
	
	encode_value = encode;
//	_delay_ms(10);
}


