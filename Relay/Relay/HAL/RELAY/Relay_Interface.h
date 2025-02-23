/*
 * Relay_Interface.h
 *
 * Created: 2/23/2025 7:21:48 PM
 *  Author: Mostafa Samir
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_


/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void RELAY_voidInit_relay_Pin( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );

void RELAY_voidStatus_relay_Pin( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status );

void RELAY_voidToggle_relay_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );

#endif /* RELAY_INTERFACE_H_ */