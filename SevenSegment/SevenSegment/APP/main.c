/*
 * SevenSegment.c
 *
 * Created: 2/20/2025 11:27:19 PM
 * Author : Mostafa Samir
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
/* Include Header Files From LIB */
#include "../LIB/STD_TYPES.h"
/* Include Header Files From MCAL Layer */
#include "../MCAL/DIO/DIO_Interface.h"
/* Include Header Files From HAL Layer */
#include "../HAL/BUTTON/button_Interface.h"
#include "../HAL/SevenSegment/SevenSegment_Interface.h"


// U1
/*
int main(void)
{
	SEGMENT_voidInitSegmentPort(PORTD);
	SEGMENT_voidInitSegmentPort(PORTC);

	u8 counter = 0;
	
	while (1)
	{
		for (counter=0;counter<=15;counter++)
		{
			SEGMENT_COMCATH_voidPrintNumber(PORTD,counter);
			SEGMENT_COMANOD_voidPrintNumber(PORTC,counter);
			_delay_ms(1000);
		}
	}	
}
*/


// U2

int main(void)
{
	
	SEGMENT_voidInitSegmentPort(PORTC);
	BUTTON_voidInit_button_pullup_Pin(PORTD,PIN7);

	u8 counter = 0;
	u8 button_val;
	
	while (1)
	{
		button_val = BUTTON_u8Get_button_Pin(PORTD,PIN7);
		
		if (button_val == 0)
		{
			counter++;
		}
		if (counter > 9)
		{
			counter = 0;
		}
		SEGMENT_COMCATH_voidPrintNumber(PORTC,counter);
		_delay_ms(250);
	}
}




// U3
/*
int main(void)
{
	
	SEGMENT_voidInitSegmentBCD(PORTD,LOW_NIBBLE);
	
	u8 counter = 0;
	
	
	while (1)
	{
		for(counter=0;counter<=9;counter++)
		{
			SEGMENT_voidPrintNumberBCD(PORTD,LOW_NIBBLE,counter);
			_delay_ms(1000);
		}

	}
}
*/



// U4
/*
int main(void)
{
	
	SEGMENT_voidInitSegmentBCD(PORTC,LOW_NIBBLE);
	SEGMENT_voidInitSegmentBCD(PORTD,HIGH_NIBBLE);
	
	u8 counter = 0;
	
	
	while (1)
	{
		for(counter=0;counter<=9;counter++)
		{
			SEGMENT_voidPrintNumberBCD(PORTC,LOW_NIBBLE,counter);
			SEGMENT_voidPrintNumberBCD(PORTD,HIGH_NIBBLE,counter);
			_delay_ms(1000);
		}

	}
}
*/