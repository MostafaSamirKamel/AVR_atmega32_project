/*===================================================================================================*/
/*  File        : button_Interface.h                                                                    */
/*  Description : This interface file includes button Driver prototypes and declarations for Atmega32   */
/*  Author      : Mostafa Samir Kamel. Embedded SW Engineer                                            */
/*  Date        : 2/18/2025                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                                        */
/*  Git account : https://github.com/MostafaSamir0                                                   */
/*  mail        : mostafasameer858@gmil.com                                                           */
/*===================================================================================================*/


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

/* Include Header Files From LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


void BUTTON_voidInit_button_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );

void BUTTON_voidInit_8buttons_Port ( u8 Copy_u8PortNumber);

u8 BUTTON_u8Get_button_Pin(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );

u8 BUTTON_u8Get_8buttons_Port (u8 Copy_u8PortNumber);

void BUTTON_voidInit_button_pullup_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );

#endif /* BUTTON_INTERFACE_H_ */