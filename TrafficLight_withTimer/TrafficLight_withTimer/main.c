/*
 * TrafficLight_withTimer.c
 *
 * Created: 4/18/2025 2:18:14 AM
 * Author : Mostafa Samir
 */

#define F_CPU 8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"
#include "Timer0_Inerface.h"

vu8 count_interrupt;
u8 count_red = 10;
u8 count_yellow = 5;
u8 count_green = 10;

// Custom Characters
u8 Car_Pattern[8] = {
	0b00000,
	0b01110,
	0b10101,
	0b11111,
	0b01110,
	0b01010,
	0b10001,
	0b00000
};

u8 Stop_Pattern[8] = {
	0b01110,
	0b10001,
	0b10101,
	0b10101,
	0b10101,
	0b10001,
	0b01110,
	0b00000
};

u8 Warn_Pattern[8] = {
	0b00100,
	0b01110,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b01010,
	0b10001
};

int main(void)
{
	LCD_voidInit();
	TIMER0_voidInit();

	// Load custom patterns into CGRAM
	LCD_voidDrawPattern(0, Car_Pattern);
	LCD_voidDrawPattern(1, Stop_Pattern);
	LCD_voidDrawPattern(2, Warn_Pattern);

	// LED Pins
	LED_voidInit_Led_Pin(PORTB, PIN0); // Red
	LED_voidInit_Led_Pin(PORTB, PIN1); // Yellow
	LED_voidInit_Led_Pin(PORTB, PIN2); // Green

	while (1)
	{
		// ========== GREEN PHASE ==========
		count_green = 10;
		LCD_voidClearDisplay();
		LCD_voidShowPattern(0, LINE_1, 5); // Car icon
		LCD_voidGoTo_XY(LINE_1, 7);
		LCD_voidWriteString("Go");
		LCD_voidGoTo_XY(LINE_2, 1);
		LCD_voidWriteString("Remain    sec");

		while (count_green > 0)
		{
			if (count_interrupt >= 100)
			{
				count_green--;
				LCD_voidGoTo_XY(LINE_2, 8); 
				LCD_voidWriteNumber(count_green);
				
				if (count_green < 10)
				{
					LCD_voidClearGrid(LINE_2, 9);
				}
				
				count_interrupt = 0;
			}
			LED_voidStatus_Led_Pin(PORTB, PIN2, ON); // Green ON
		}
		LED_voidStatus_Led_Pin(PORTB, PIN2, OFF); // Green OFF

		// ========== YELLOW (READY TO STOP) ==========
		count_yellow = 5;
		LCD_voidClearDisplay();
		LCD_voidShowPattern(2, LINE_1, 4); // Warn icon
		LCD_voidGoTo_XY(LINE_1, 6);
		LCD_voidWriteString("Ready");
		LCD_voidGoTo_XY(LINE_2, 1);
		LCD_voidWriteString("Remain    sec");

		while (count_yellow > 0)
		{
			if (count_interrupt >= 100)
			{
				count_yellow--;
				LCD_voidGoTo_XY(LINE_2, 8); 
				LCD_voidWriteNumber(count_yellow);

				if (count_yellow < 10)
				{
					LCD_voidClearGrid(LINE_2, 9);
				}

				count_interrupt = 0;
			}
			LED_voidStatus_Led_Pin(PORTB, PIN1, ON); // Yellow ON
		}
		LED_voidStatus_Led_Pin(PORTB, PIN1, OFF); // Yellow OFF

		// ========== RED PHASE ==========
		count_red = 10;
		LCD_voidClearDisplay();
		LCD_voidShowPattern(1, LINE_1, 5); // Stop icon
		LCD_voidGoTo_XY(LINE_1, 7);
		LCD_voidWriteString("Stop");
		LCD_voidGoTo_XY(LINE_2, 1);
		LCD_voidWriteString("Remain    sec");

		while (count_red > 0)
		{
			if (count_interrupt >= 100)
			{
				count_red--;
				LCD_voidGoTo_XY(LINE_2, 8); 
				LCD_voidWriteNumber(count_red);
				
				if (count_red < 10)
				{
					LCD_voidClearGrid(LINE_2, 9);
				}
				
				count_interrupt = 0;
			}
			LED_voidStatus_Led_Pin(PORTB, PIN0, ON); // Red ON
		}
		LED_voidStatus_Led_Pin(PORTB, PIN0, OFF); // Red OFF

		// ========== YELLOW (READY TO GO) ==========
		count_yellow = 5;
		LCD_voidClearDisplay();
		LCD_voidShowPattern(2, LINE_1, 4); // Warn icon
		LCD_voidGoTo_XY(LINE_1, 6);
		LCD_voidWriteString("Ready");
		LCD_voidGoTo_XY(LINE_2, 1);
		LCD_voidWriteString("Remain    sec");

		while (count_yellow > 0)
		{
			if (count_interrupt >= 100)
			{
				count_yellow--;
				LCD_voidGoTo_XY(LINE_2, 8); 
				LCD_voidWriteNumber(count_yellow);

				if (count_yellow < 10)
				{
					LCD_voidClearGrid(LINE_2, 9);
				}

				count_interrupt = 0;
			}
			LED_voidStatus_Led_Pin(PORTB, PIN1, ON); // Yellow ON
		}
		LED_voidStatus_Led_Pin(PORTB, PIN1, OFF); // Yellow OFF
	}
}

// TIMER0_COMP_vect -> VECTOR(10)
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	count_interrupt++;
}
