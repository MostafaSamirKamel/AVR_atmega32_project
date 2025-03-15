/*
 * Relay.c
 *
 * Created: 2/23/2025 6:31:13 PM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
/* Include Header Files From LIB */
#include "../LIB/STD_TYPES.h"
/* Include Header Files From MCAL Layer */
#include "../MCAL/DIO/DIO_Interface.h"
/* Include Header Files From HAL Layer */
#include "../HAL/BUTTON/button_Interface.h"
#include "../HAL/RELAY/Relay_Interface.h"

int main(void)
{
	RELAY_voidInit_relay_Pin(PORTD,PIN2);
	BUTTON_voidInit_button_Pin(PORTD,PIN7);
	
	u8 button_val ;
    
    while (1) 
    {
		button_val = BUTTON_u8Get_button_Pin(PORTD,PIN7);
		
		if (button_val == 0)
		{
			RELAY_voidStatus_relay_Pin(PORTD,PIN2,ON);
		}
		else{
			RELAY_voidStatus_relay_Pin(PORTD,PIN2,OFF);
		}
			
    }
}

