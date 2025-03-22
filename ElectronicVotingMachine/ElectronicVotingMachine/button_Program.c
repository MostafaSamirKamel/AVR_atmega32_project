/*===================================================================================================*/
/*  File        : button_Program.c                                                                      */
/*  Description : This file includes button Driver implementations for Atmega32                         */
/*  Author      : MostafaSamirKamel. Embedded SW Engineer                                            */
/*  Date        : 2/18/2025                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                                        */
/*  Git account : https://github.com/MostafaSamir0                                                   */
/*  mail        : mostafasameer858@gmil.com                                                           */
/*===================================================================================================*/


/* Include Header Files From LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include My own Header Files*/
#include "button_Interface.h"

/* Include Header Files From MCAL Layer */
#include "DIO_Interface.h"


void BUTTON_voidInit_button_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
	{
		// Do Nothing
	}
	else
	{
		DIO_voidSetPinDirection (Copy_u8PortNumber,Copy_u8PinNumber,INPUT);
	}
}

void BUTTON_voidInit_8buttons_Port ( u8 Copy_u8PortNumber)
{
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD )
	{
		// Do Nothing
	}
	else
	{
		DIO_voidSetPortDirection ( Copy_u8PortNumber, INPUT );
	}
}

u8 BUTTON_u8Get_button_Pin(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
	// local Variable
	 u8 Local_u8Variable;
	
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
	{
		// Do Nothing
	}
	else
	{
		Local_u8Variable = DIO_u8GetPinValue(Copy_u8PortNumber,Copy_u8PinNumber);
	}
	
	return Local_u8Variable ;
}

u8 BUTTON_u8Get_8buttons_Port (u8 Copy_u8PortNumber)
{
	u8 Local_u8Variable;
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD )
	{
		// Do Nothing
	}
	else
	{
		Local_u8Variable = DIO_u8GetPortValue (Copy_u8PortNumber );
	}
}


void BUTTON_voidInit_button_pullup_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
	{
		// Do Nothing
	}
	else
	{
		DIO_voidSetPinDirection (Copy_u8PortNumber,Copy_u8PinNumber,INPUT);
		DIO_voidConfig_Pull_Up_Pin(Copy_u8PortNumber,Copy_u8PinNumber,ON);
	}
}