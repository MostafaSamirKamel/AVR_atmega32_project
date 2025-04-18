/*===================================================================================================*/
/*  File        : 7Segment_Program.c                                                                      */
/*  Description : This file includes 7Segment Driver implementations for Atmega32                         */
/*  Author      : Mostafa Samir Kamel. Embedded SW Engineer                                            */
/*  Date        : 2/18/2025                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                                        */
/*  Git account : https://github.com/MostafaSamir0                                                   */
/*  mail        : mostafasameer858@gmil.com                                                           */
/*===================================================================================================*/


/* Include Header Files From LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header Files From MCAL Layer */
#include "DIO_Interface.h"
#include "DIO_Private.h"

/* Include My own Header Files*/
#include "SevenSegment_Interface.h"



void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber )
{
	switch(Copy_u8PortNumber)
	{
		case PORTA :    DDRA_REG = 0xff ;   break;
		case PORTB :    DDRB_REG = 0xff ;   break;
		case PORTC :    DDRC_REG = 0xff ;   break;
		case PORTD :    DDRD_REG = 0xff ;   break;
		default    :                        break;
	}
}

void SEGMENT_COMCATH_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_u8Number )
{
	// Corrected values for Common Cathode 7-segment display
	u8 Arr[] = {
		0x3F, // 0
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7 
		0x7F, // 8
		0x6F, // 9
		0x77, // A
		0x7C, // B 
		0x39, // C
		0x5E, // D 
		0x79, // E
		0x71  // F
	};

	// Prevent out-of-bounds memory access
	if (Copy_u8Number < 16)
	{
		DIO_voidSetPortValue(Copy_u8PortNumber, Arr[Copy_u8Number]);
	}
	else
	{
		DIO_voidSetPortValue(Copy_u8PortNumber, 0x00);
	}
}



void SEGMENT_COMANOD_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_u8Number )
{
	// Corrected values for Common Cathode 7-segment display
	u8 Arr[] = {
		~0x3F, // 0
		~0x06, // 1
		~0x5B, // 2
		~0x4F, // 3
		~0x66, // 4
		~0x6D, // 5
		~0x7D, // 6
		~0x07, // 7
		~0x7F, // 8
		~0x6F, // 9
		~0x77, // A
		~0x7C, // B
		~0x39, // C
		~0x5E, // D
		~0x79, // E
		~0x71  // F
	};

	// Prevent out-of-bounds memory access
	if (Copy_u8Number < 16)
	{
		DIO_voidSetPortValue(Copy_u8PortNumber, Arr[Copy_u8Number]);
	}
	else
	{
		DIO_voidSetPortValue(Copy_u8PortNumber, 0x00);
	}
}


void SEGMENT_voidInitSegmentBCD (u8 Copy_u8PortNumber, u8 Copy_u8Nibble)
{
	// Initialize only the required nibble as output
	DIO_voidSetNibbleDirection(Copy_u8PortNumber, Copy_u8Nibble, 1);
}

void SEGMENT_voidPrintNumberBCD (u8 Copy_u8PortNumber, u8 Copy_u8Nibble, u8 Copy_u8Number)
{
	// Ensure the number is in valid BCD range (0-9)
	if (Copy_u8Number < 10)
	{
		DIO_voidSetNibbleValue(Copy_u8PortNumber, Copy_u8Nibble, Copy_u8Number);
	}
	else
	{
		DIO_voidSetNibbleValue(Copy_u8PortNumber, Copy_u8Nibble, 0x00);
	}
}

