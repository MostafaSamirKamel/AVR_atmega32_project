/*
 * Counter_withSevenSegment_and_Timer0(CTC Mode).c
 *
 * Created: 4/18/2025 11:38:29 PM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "Timer0_Inerface.h"
#include "SevenSegment_Interface.h"

vu8 conut_1sec = 0;
vu8 count_10ms = 0;
u8 counter_7seg = 0 ;

int main(void)
{
	TIMER0_voidInit();
	SEGMENT_voidInitSegmentPort(PORTC);
	
	DIO_voidSetPinDirection(PORTD,PIN0,HIGH); // A
	DIO_voidSetPinDirection(PORTD,PIN1,HIGH); // A
	
    while (1) 
    {
		DIO_voidSetPinValue(PORTD,PIN0,LOW);
		DIO_voidSetPinValue(PORTD,PIN1,HIGH);
		SEGMENT_COMCATH_voidPrintNumber(PORTC,counter_7seg % 10);
		
		while(count_10ms == 0);
		count_10ms = 0;
		
		DIO_voidSetPinValue(PORTD,PIN0,HIGH);
		DIO_voidSetPinValue(PORTD,PIN1,LOW);
		SEGMENT_COMCATH_voidPrintNumber(PORTC,counter_7seg / 10);
		
		while(count_10ms == 0);
		count_10ms = 0;
		
		if (conut_1sec >= 100)
		{
			conut_1sec = 0;
			counter_7seg++;
			if (counter_7seg > 30)
			{
				counter_7seg = 0;
			}
		}
		
    }
}


// TIMER0_COMP_vect -> VECTOR(10)
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	conut_1sec++ ;
	count_10ms = 1;
}

