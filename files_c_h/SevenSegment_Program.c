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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"

/* Include My own Header Files*/
#include "SevenSegment/SevenSegment_Interface.h"
#include "SevenSegment/SevenSegment_Private.h"

u8 Common_Anode_Arr[]  = {ZERO_A,ONE_A,TWO_A,THREE_A,FOUR_A,FIVE_A,SIX_A,SEVEN_A,EIGHT_A,NINE_A,A_A,B_A,C_A,D_A,E_A,F_A} ;
u8 Common_Cathode_Arr[]= {ZERO_C,ONE_C,TWO_C,THREE_C,FOUR_C,FIVE_C,SIX_C,SEVEN_C,EIGHT_C,NINE_C,A_C,B_C,C_C,D_C,E_C,F_C} ;
u8 BCD_Arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f}; //Common_Cathode 

/*======================================================================================================================*/
/***********************************     M.Samir 7_SEGMENT Functions Implementation     *********************************/
/*======================================================================================================================*/
/********************************************    SEGMENT_voidInitSegmentPort       **************************************/
/********************************************    SEGMENT_voidPrintNumber           **************************************/
/*======================================================================================================================*/




/*****************************************************************************************************/
/* Function Name : SEGMENT_voidInitSegmentPort                                                       */
/* Description : Initialize one 7-Segment on specific Port ant make it direction as OUTPUT           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber )
{
	switch(Copy_u8PortNumber)
	{
		case PORTA :   DIO_voidSetPortDirection (PORTA,OUTPUT);    break;
		case PORTB :   DIO_voidSetPortDirection (PORTB,OUTPUT);    break;
		case PORTC :   DIO_voidSetPortDirection (PORTC,OUTPUT);    break;
		case PORTD :   DIO_voidSetPortDirection (PORTD,OUTPUT);    break;
		default    :                                               break;
	}
}
/*****************************************************************************************************/
/* Function Name : SEGMENT_voidPrintNumber                                                           */
/* Description : Print Number from 0 to 9 at the 7-Segment                                           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument2: Copy_SegmentPolarity { COMMON_ANODE , COMMON_CATHODE }                            */
/* Fun. Argument3: Copy_u8Number { 0,1,2,3,4,5,6,7,8,9 }                                             */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void SEGMENT_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number )
{
	switch ( Copy_SegmentPolarity )
	{
		case COMMON_ANODE   :   switch(Copy_u8PortNumber)
		{
			case PORTA :   DIO_voidSetPortValue (PORTA,Common_Anode_Arr[Copy_u8Number]);    break;
			case PORTB :   DIO_voidSetPortValue (PORTB,Common_Anode_Arr[Copy_u8Number]);    break;
			case PORTC :   DIO_voidSetPortValue (PORTC,Common_Anode_Arr[Copy_u8Number]);    break;
			case PORTD :   DIO_voidSetPortValue (PORTD,Common_Anode_Arr[Copy_u8Number]);    break;
			default    :                                                                    break;
		}
		break;
		case COMMON_CATHODE :   switch(Copy_u8PortNumber)
		{
			case PORTA :   DIO_voidSetPortValue (PORTA,Common_Cathode_Arr[Copy_u8Number]);    break;
			case PORTB :   DIO_voidSetPortValue (PORTB,Common_Cathode_Arr[Copy_u8Number]);    break;
			case PORTC :   DIO_voidSetPortValue (PORTC,Common_Cathode_Arr[Copy_u8Number]);    break;
			case PORTD :   DIO_voidSetPortValue (PORTD,Common_Cathode_Arr[Copy_u8Number]);    break;
			default    :                                                                      break;
		}
		break;
		default             :   break;
	}
	
}

void SEGMENT_voidInitSegmentBCD ( u8 Copy_u8PortNumber, u8 Copy_u8Niblle)
{
	DIO_voidSetNibbleDirection(Copy_u8PortNumber,Copy_u8Niblle,HIGH);
}


void SEGMENT_voidPrintNumberBCD ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity ,u8 Copy_u8Niblle , u8 Copy_u8Number )
{
	switch ( Copy_SegmentPolarity )
	{
		case COMMON_ANODE   :   switch(Copy_u8PortNumber)
		{
			case PORTA :  DIO_voidSetNibbleValue(PORTA,Copy_u8Niblle,~BCD_Arr[Copy_u8PortNumber]);     break;
			case PORTB :  DIO_voidSetNibbleValue(PORTB,Copy_u8Niblle,~BCD_Arr[Copy_u8PortNumber]);     break;
			case PORTC :  DIO_voidSetNibbleValue(PORTC,Copy_u8Niblle,~BCD_Arr[Copy_u8PortNumber]);     break;
			case PORTD :  DIO_voidSetNibbleValue(PORTD,Copy_u8Niblle,~BCD_Arr[Copy_u8PortNumber]);     break;
			default    :                                                                    break;
		}
		break;
		case COMMON_CATHODE :   switch(Copy_u8PortNumber)
		{
			case PORTA :  DIO_voidSetNibbleValue(PORTA,Copy_u8Niblle,BCD_Arr[Copy_u8PortNumber])   ;  break;
			case PORTB :  DIO_voidSetNibbleValue(PORTB,Copy_u8Niblle,BCD_Arr[Copy_u8PortNumber])  ;   break;
			case PORTC :  DIO_voidSetNibbleValue(PORTC,Copy_u8Niblle,BCD_Arr[Copy_u8PortNumber]) ;    break;
			case PORTD :  DIO_voidSetNibbleValue(PORTD,Copy_u8Niblle,BCD_Arr[Copy_u8PortNumber]);     break;
			default    :                                                                    break;
		}
		break;
		default             :   break;
	}
	
}