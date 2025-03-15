/*
 * EX_Interrupt.c
 *
 * Created: 3/9/2025 11:45:44 PM
 *  Author: Mostafa Samir
 */ 

#include "EX_Interrupt_Config.h"
#include "EX_Interrupt_Private.h"
#include "EX_Interrupt_Interface.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*
INT0 
				ISC01	ISC00	
RisingEdge		  1       1
FallingEdge		  1       0
LowLevel          0       0
AnyChange         0       1


INT1
				ISC11	ISC10
RisingEdge		  1       1
FallingEdge		  1       0
LowLevel          0       0
AnyChange         0       1

INT2
				ISC2
RisingEdge		  1       
FallingEdge		  0      

*/

void Enterrupt_GlobalEnable()
{
	SET_BIT(SREG_REG,GINT);
}

void Enterrupt_GlobalDisable()
{
	CLEAR_BIT(SREG_REG,GINT);
}

void EX_INT_voidEnable(u8 Copy_INTNumber , u8 Copy_INTStatus)
{
	switch(Copy_INTNumber)
	{
		case INT0 : SET_BIT(GICR_REG,INT0);  //enable external interrupt 0
		switch(Copy_INTStatus)
		{
			case RisingEdge  : SET_BIT(MCUCR_REG,ISC01);    SET_BIT(MCUCR_REG,ISC00);    break;
			case FallingEdge : SET_BIT(MCUCR_REG,ISC01);    CLEAR_BIT(MCUCR_REG,ISC00);  break;
			case LowLevel    : CLEAR_BIT(MCUCR_REG,ISC01);  CLEAR_BIT(MCUCR_REG,ISC00);  break;
			case AnyChange   : CLEAR_BIT(MCUCR_REG,ISC01);  SET_BIT(MCUCR_REG,ISC00);    break;
			default: break;
		}break;
		
		case INT1 : SET_BIT(GICR_REG,INT1);  //enable external interrupt 1
		switch(Copy_INTStatus)
		{
			case RisingEdge  : SET_BIT(MCUCR_REG,ISC11);    SET_BIT(MCUCR_REG,ISC10);    break;
			case FallingEdge : SET_BIT(MCUCR_REG,ISC11);    CLEAR_BIT(MCUCR_REG,ISC10);  break;
			case LowLevel    : CLEAR_BIT(MCUCR_REG,ISC11);  CLEAR_BIT(MCUCR_REG,ISC10);  break;
			case AnyChange   : CLEAR_BIT(MCUCR_REG,ISC11);  SET_BIT(MCUCR_REG,ISC10);    break;
			default: break;
		}break;
		
		case INT2 : SET_BIT(GICR_REG,INT2);  //enable external interrupt 2
		switch(Copy_INTStatus)
		{
			case RisingEdge  : SET_BIT(MCUCSR_REG,ISC2);     break;
			case FallingEdge : CLEAR_BIT(MCUCSR_REG,ISC2);   break;
			default: break;
		}break;
		
		default: break;
		
	}
}


void EX_INT_voidDisable ( u8 Copy_u8INTNumber )
{
	switch ( Copy_u8INTNumber )
	{
		case INT0 :     CLEAR_BIT(GICR_REG,INT0);   break;    
		case INT1 :     CLEAR_BIT(GICR_REG,INT1);   break;    
		case INT2 :     CLEAR_BIT(GICR_REG,INT2);   break;   
		default   :   break;
	}
}


