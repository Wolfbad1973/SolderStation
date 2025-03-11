
#include "main.h"
//----------------------------------------
void port_ini(void)
{
	PORTD=0x00;
	DDRD=0xFF;
}
//----------------------------------------
int main(void)
{
	float n;
	port_ini(); //Инициализируем порты
	LCD_ini();  //Инициализируем дисплей
	ADC_Init(); //Инициализируем АЦП
	clearlcd(); //Очистим дисплей
	SOLDER_init();
	BUTTON_init();

	while(1)
	{
		//int adc_value = 0;
		adc_value = ADC_convert(); //Вызовем преобразование
		BUTTON_out();
		setpos(0,0);
		sendcharlcd('R');
		sendcharlcd('E');
		sendcharlcd('A');
		sendcharlcd('L');
		sendcharlcd(' ');
		sendcharlcd(adc_value/1000+0x30);//Преобразуем число в код числа
		sendcharlcd((adc_value%1000)/100+0x30);//Преобразуем число в код числа
		sendcharlcd((adc_value%100)/10+0x30);//Преобразуем число в код числа
		sendcharlcd(adc_value%10+0x30);//Преобразуем число в код числа
		sendcharlcd('C');
		setpos(12,0);
		n= (float) adc_value / 400;
		sendcharlcd((unsigned char) n +0x30);//Преобразуем число в код числа
		sendcharlcd('.');//Преобразуем число в код числа
		sendcharlcd(((unsigned char) (n*10))%10 +0x30);//Преобразуем число в код числа
		sendcharlcd(((unsigned char) (n*100))%10 +0x30);//Преобразуем число в код числа
		setpos(0,1);
		sendcharlcd('S');
		sendcharlcd('E');
		sendcharlcd('T');
		sendcharlcd(' ');
		sendcharlcd(' ');
		sendcharlcd(encode_value/1000+0x30);//Преобразуем число в код числа
		sendcharlcd((encode_value%1000)/100+0x30);//Преобразуем число в код числа
		sendcharlcd((encode_value%100)/10+0x30);//Преобразуем число в код числа
		sendcharlcd(encode_value%10+0x30);//Преобразуем число в код числа
		sendcharlcd('C');
		SOLDER_out();
		_delay_ms(50);
	}
}

