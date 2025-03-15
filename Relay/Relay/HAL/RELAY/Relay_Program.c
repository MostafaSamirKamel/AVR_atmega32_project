/*
 * Relay_Program.c
 *
 * Created: 2/23/2025 7:22:14 PM
 *  Author: Mostafa Samir
 */ 



/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "Relay_Interface.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"




void RELAY_voidInit_relay_Pin( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
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

void RELAY_voidStatus_relay_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status )
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

void RELAY_voidToggle_relay_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
	/* i/p validation */
	if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
	{
		// Do Nothing
	}
	else
	{
		DIO_voidTogglePinValue ( Copy_u8PortNumber, Copy_u8PinNumber );
	}
}
