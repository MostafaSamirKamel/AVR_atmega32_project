/*
 * Temp_ADC.c
 *
 * Created: 4/8/2025 12:26:17 AM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"


int main(void)
{
    LCD_voidInit();
	ADC_voidInit();
	
	RELAY_voidInit_relay_Pin(PORTC,PIN0);
	RELAY_voidInit_relay_Pin(PORTC,PIN1);
	
	u16 DigitalValue = 0;
	f32 AnalogValue = 0;
	s16 TempValue = 0;
	
	
	LCD_voidWriteString("Temp = ");
	
	while (1)
	{
		DigitalValue = ADC_u16Read();
		AnalogValue  = DigitalValue  * 2.5;	
		
		if (AnalogValue >= 1000)
		{
			TempValue = (AnalogValue - 1000) / 10 ;
	
			LCD_voidGoTo_XY(LINE_1,7);
			LCD_voidWriteNumber(TempValue);
			LCD_voidWriteChar(0xDF);	
			
			if (TempValue > 20)
			{
				RELAY_voidStatus_relay_Pin(PORTC,PIN1,ON);
				RELAY_voidStatus_relay_Pin(PORTC,PIN0,OFF);
				
			}
			else if (TempValue < 10)
			{
				RELAY_voidStatus_relay_Pin(PORTC,PIN0,ON);
				RELAY_voidStatus_relay_Pin(PORTC,PIN1,OFF);
			}
			else{
				RELAY_voidStatus_relay_Pin(PORTC,PIN0,OFF);
				RELAY_voidStatus_relay_Pin(PORTC,PIN1,OFF);
			}
		} 
		else
		{
			TempValue = (1000 - AnalogValue) / 10 ;
			
			LCD_voidGoTo_XY(LINE_1,7);
			LCD_voidWriteChar('-');
			LCD_voidGoTo_XY(LINE_1,8);
			LCD_voidWriteNumber(TempValue);
			LCD_voidWriteChar(0xDF);
			
			if (TempValue >= 0)
			{
				RELAY_voidStatus_relay_Pin(PORTC,PIN0,ON);
			}
			else{
				RELAY_voidStatus_relay_Pin(PORTC,PIN0,OFF);
			}
		
		}

	}
}

