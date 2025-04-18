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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber );
void SEGMENT_COMCATH_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_u8Number );
void SEGMENT_COMANOD_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_u8Number );


void SEGMENT_voidInitSegmentBCD ( u8 Copy_u8PortNumber, u8 Copy_u8Niblle);
void SEGMENT_voidPrintNumberBCD ( u8 Copy_u8PortNumber ,u8 Copy_u8Niblle , u8 Copy_u8Number );


#endif /* 7SEGMENT_INTERFACE_H_ */