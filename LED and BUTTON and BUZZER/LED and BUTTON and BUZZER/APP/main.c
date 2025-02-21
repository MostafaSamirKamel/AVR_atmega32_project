/*
 * LED and BUTTON and BUZZER.c
 *
 * Created: 2/20/2025 6:09:54 PM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
/* Include Header Files From LIB */
#include "../LIB/STD_TYPES.h"
/* Include Header Files From MCAL Layer */
#include "../MCAL/DIO/DIO_Interface.h"
/* Include Header Files From HAL Layer */
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/BUTTON/button_Interface.h"
#include "../HAL/BUZZER/buzzer_Interface.h"

//U1
/*
int main(void)
{
    LED_voidInit_8Leds_Port(PORTC);
    while (1) 
    {
		s8 i =0;
		for (i=0;i<=7;i++)
		{
			LED_voidStatus_Led_Pin(PORTC,i,ON);
			_delay_ms(500);
		}
		for(i=7;i>=0;i--)
		{
			LED_voidStatus_Led_Pin(PORTC,i,OFF);
			_delay_ms(500);
		}
    }
}
*/


//U2
/*
int main(void)
{
	LED_voidInit_Led_Pin(PORTC,PIN4);
	LED_voidInit_Led_Pin(PORTD,PIN2);
	
	while (1)
	{
		LED_voidStatus_Led_Pin(PORTD,PIN2,ON);
		LED_voidStatus_Led_Pin(PORTC,PIN4,OFF);
		_delay_ms(500);
		LED_voidStatus_Led_Pin(PORTD,PIN2,OFF);
		LED_voidStatus_Led_Pin(PORTC,PIN4,ON);
		_delay_ms(500);
	}
}
*/



//U3

int main(void)
{
	BUTTON_voidInit_button_pullup_Pin(PORTD,PIN7);
	LED_voidInit_Led_Pin(PORTC,PIN1);
	
	
	BUTTON_voidInit_button_pullup_Pin(PORTB,PIN4);
	BUZZER_voidInit_buzzer_Pin(PORTA,PIN0);
	
	u8 button_val1;
	u8 button_val2;
	
	while (1)
	{
		//led bu button
		button_val1 = BUTTON_u8Get_button_Pin(PORTD,PIN7);
		
		if(button_val1 == 0)
		{
			LED_voidStatus_Led_Pin(PORTC,PIN1,ON);
		}
		else{
			LED_voidStatus_Led_Pin(PORTC,PIN1,OFF);
		}
		
		// buzzer by button
		button_val2 = BUTTON_u8Get_button_Pin(PORTB,PIN4);
		
		if(button_val2 == 0)
		{
			BUZZER_voidStatus_buzzer_Pin(PORTA,PIN0,ON);
		}
		else{
			BUZZER_voidStatus_buzzer_Pin(PORTA,PIN0,OFF);
		}
		
		
	}
}




//U4

int main(void)
{
	BUTTON_voidInit_button_pullup_Pin(PORTC,PIN2);
	LED_voidInit_Led_Pin(PORTC,PIN3);
	
	
	u8 button_val, button_prev = 1;  // Initialize button_prev to 1 (unpressed)
	
	while (1)
	{
		button_val = BUTTON_u8Get_button_Pin(PORTC, PIN2);
		
		if (button_val == 0 && button_prev == 1)  // Detecting button press transition
		{
			LED_voidToggle_Led_Pin(PORTC, PIN3);
			_delay_ms(50);  // Simple debounce delay
		}
		
		button_prev = button_val;  // Update previous button state
	}
}
