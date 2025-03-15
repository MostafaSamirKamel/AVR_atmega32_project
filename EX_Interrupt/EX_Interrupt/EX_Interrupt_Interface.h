/*
 * EX_Interrupt_Interface.h
 *
 * Created: 3/9/2025 11:46:33 PM
 *  Author: Mostafa Samir
 */ 


#ifndef EX_INTERRUPT_INTERFACE_H_
#define EX_INTERRUPT_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"


// INT STATUS
#define RisingEdge     1
#define FallingEdge    2
#define LowLevel       3
#define AnyChange      4





void Enterrupt_GlobalEnable();
void Enterrupt_GlobalDisable();


void EX_INT_voidEnable(u8 Copy_INTNumber , u8 Copy_INTStatus);
void EX_INT_voidDisable ( u8 Copy_u8INTNumber );




#endif /* EX_INTERRUPT_INTERFACE_H_ */