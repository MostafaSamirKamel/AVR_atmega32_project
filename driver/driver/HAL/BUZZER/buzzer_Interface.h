/*===================================================================================================*/
/*  File        : buzzer_Interface.h                                                                    */
/*  Description : This interface file includes buzzer Driver prototypes and declarations for Atmega32   */
/*  Author      : Mostafa Samir Kamel. Embedded SW Engineer                                            */
/*  Date        : 2/18/2025                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                                        */
/*  Git account : https://github.com/MostafaSamir0                                                   */
/*  mail        : mostafasameer858@gmil.com                                                           */
/*===================================================================================================*/


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void BUZZER_voidInit_buzzer_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );

void BUZZER_voidStatus_buzzer_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status );


#endif /* BUZZER_INTERFACE_H_ */