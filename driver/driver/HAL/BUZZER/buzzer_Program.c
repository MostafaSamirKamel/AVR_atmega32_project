/*===================================================================================================*/
/*  File        : buzzer_Program.c                                                                      */
/*  Description : This file includes buzzer Driver implementations for Atmega32                         */
/*  Author      : MostafaSamirKamel. Embedded SW Engineer                                            */
/*  Date        : 2/18/2025                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                                        */
/*  Git account : https://github.com/MostafaSamir0                                                   */
/*  mail        : mostafasameer858@gmil.com                                                           */
/*===================================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "buzzer_Interface.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"

void BUZZER_voidInit_buzzer_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
	{
		// Do Nothing
	}
	else
	{
		DIO_voidSetPinDirection (Copy_u8PortNumber,Copy_u8PinNumber,OUTPUT);
	}
}

void BUZZER_voidStatus_buzzer_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status )
{
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
	{
		// Do Nothing
	}
	else
	{
		switch(Copy_u8Status)
		{
			case ON  :   DIO_voidSetPinValue ( Copy_u8PortNumber, Copy_u8PinNumber, HIGH );     break;
			case OFF :   DIO_voidSetPinValue ( Copy_u8PortNumber, Copy_u8PinNumber, LOW  );     break;
			default  :                                                                          break;
		}
	}
}