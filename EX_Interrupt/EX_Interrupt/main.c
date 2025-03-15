/*
 * EX_Interrupt.c
 *
 * Created: 3/9/2025 11:44:35 PM
 * Author : Mostafa Samir
 */ 

#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "EX_Interrupt_Interface.h"
#include "EX_Interrupt_Private.h"
#include "DIO_Interface.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"

int main(void)
{
    DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	
	Enterrupt_GlobalEnable();
	
	EX_INT_voidEnable(INT0,RisingEdge);
	EX_INT_voidEnable(INT1,AnyChange);
	EX_INT_voidEnable(INT2,FallingEdge);
	
    while (1) 
    {
		DIO_voidSetPinValue(PORTC,PIN0,HIGH);
		DIO_voidSetPinValue(PORTC,PIN1,HIGH);
		DIO_voidSetPinValue(PORTC,PIN2,HIGH);
    }
}

ISR(INT0_vect)
{
	DIO_voidSetPinValue(PORTC,PIN0,LOW);
	_delay_ms(2000);
	
}

ISR(INT1_vect)
{
	DIO_voidSetPinValue(PORTC,PIN1,LOW);
	_delay_ms(2000);
}

ISR(INT2_vect)
{
	DIO_voidSetPinValue(PORTC,PIN2,LOW);
	_delay_ms(2000);
}



