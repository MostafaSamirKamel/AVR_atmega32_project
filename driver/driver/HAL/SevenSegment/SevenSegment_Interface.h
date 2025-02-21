/*===================================================================================================*/
/*  File        : 7Segment_Interface.h                                                                    */
/*  Description : This interface file includes 7Segment Driver prototypes and declarations for Atmega32   */
/*  Author      : Mostafa Samir Kamel. Embedded SW Engineer                                            */
/*  Date        : 2/18/2025                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                                        */
/*  Git account : https://github.com/MostafaSamir0                                                   */
/*  mail        : mostafasameer858@gmil.com                                                           */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef SEVENSEGMENT_INTERFACE_H_
#define SEVENSEGMENT_INTERFACE_H_

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Segment Polarity */
#define COMMON_ANODE               0
#define COMMON_CATHODE             1

/*****************************************************************************************************/
/* Function Name : SEGMENT_voidInitSegmentPort                                                       */
/* Description : Initialize one 7-Segment on specific Port ant make it direction as OUTPUT           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber );
/*****************************************************************************************************/
/* Function Name : SEGMENT_voidPrintNumber                                                           */
/* Description : Print Number from 0 to 9 at the 7-Segment                                           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument2: Copy_SegmentPolarity { COMMON_ANODE , COMMON_CATHODE }                            */
/* Fun. Argument3: Copy_u8Number { 0,1,2,3,4,5,6,7,8,9 }                                             */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void SEGMENT_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number );

void SEGMENT_voidPrintNumberBCD ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity ,u8 Copy_u8Niblle , u8 Copy_u8Number );
void SEGMENT_voidInitSegmentBCD ( u8 Copy_u8PortNumber, u8 Copy_u8Niblle);

#endif /* 7SEGMENT_INTERFACE_H_ */