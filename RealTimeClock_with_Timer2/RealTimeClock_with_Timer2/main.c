/*
 * RealTimeClock_with_Timer2.c
 * Author : Mostafa Samir
 * Created: 4/21/2025 10:30:23 PM
 * Purpose: A Real-Time Clock with Timer2, displaying hours, minutes, and seconds
 *          on a 7-segment display and allowing the user to set the time.
 */

#define F_CPU 8000000UL  // Clock speed of 8MHz
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Timer2_Interface.h"
#include "SevenSegment_Interface.h"
#include "KeyPad_Interface.h"
#include "LCD_Interface.h"

// Global variables for time counters
vu8 seconds_counter = 0;
u8 minutes_counter = 0;
u8 hours_counter = 0;
u8 value;
u8 first_digit;
u8 second_digit;

// Function prototypes for modularity
void initHardware();
void setTime();
void displayTime();
void updateTime();
u8 getTimeInput();

// Main function
int main(void)
{
    initHardware();  // Initialize hardware components
    
    LCD_voidWriteString("Press 1 TO");
    LCD_voidGoTo_XY(LINE_2, 0);
    LCD_voidWriteString("Set Clock");

    while (1)
    {
        value = KPAD_u8GetPressedKey();
        if (value != NOTPRESSED)
        {
            if (value == '1')
            {
                setTime();  // Set the clock time
            }
            else
            {
                LCD_voidClearDisplay();
                LCD_voidWriteString("Wrong Choice");
                _delay_ms(1000);
                LCD_voidClearDisplay();
                LCD_voidWriteString("Press 1 TO");
                LCD_voidGoTo_XY(LINE_2, 0);
                LCD_voidWriteString("Set Clock");
            }
        }
        
        displayTime();  // Display the current time on 7-segment displays
        updateTime();   // Update the time counters
    }
}

// Function to initialize hardware components
void initHardware(void)
{
    LCD_voidInit();
    KPAD_voidInit();
    TIMER2_voidInit();
    SEGMENT_voidInitSegmentPort(PORTD);
    
    // Set the direction of pins for 7-segment display control
    for (u8 i = 0; i < 6; i++)
    {
        DIO_voidSetPinDirection(PORTC, PIN0 + i, HIGH);
    }
}

// Function to set the time (hours, minutes, seconds) from keypad input
void setTime(void)
{
    // Get hours input
    LCD_voidClearDisplay();
    LCD_voidWriteString("Hours = --");
    LCD_voidGoTo_XY(LINE_1, 8);
    _delay_ms(100);
    hours_counter = getTimeInput();
    
    // Get minutes input
    LCD_voidClearDisplay();
    LCD_voidWriteString("Minutes = --");
    LCD_voidGoTo_XY(LINE_1, 10);
    _delay_ms(100);
    minutes_counter = getTimeInput();
    
    // Get seconds input
    LCD_voidClearDisplay();
    LCD_voidWriteString("Seconds = --");
    LCD_voidGoTo_XY(LINE_1, 10);
    _delay_ms(100);
    seconds_counter = getTimeInput();
    
    // Reset the display prompt
    LCD_voidClearDisplay();
    LCD_voidWriteString("Press 1 TO");
    LCD_voidGoTo_XY(LINE_2, 0);
    LCD_voidWriteString("Set Clock");
}

// function to get time input (hours, minutes, seconds)
u8 getTimeInput(void)
{
    u8 first_digit, second_digit;
    
    // Get first digit
    do
    {
        first_digit = KPAD_u8GetPressedKey();
    } while (first_digit == NOTPRESSED);
    LCD_voidWriteChar(first_digit);
    _delay_ms(100);
    
    // Get second digit
    do
    {
        second_digit = KPAD_u8GetPressedKey();
    } while (second_digit == NOTPRESSED);
    LCD_voidWriteChar(second_digit);
    _delay_ms(100);
    
    return (10 * (first_digit - '0')) + (second_digit - '0');
}

// Function to display the current time on the 7-segment displays
void displayTime(void)
{
    // Display seconds
    DIO_voidSetPinValue(PORTC, PIN0, LOW);
    DIO_voidSetPinValue(PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(PORTC, PIN3, HIGH);
	DIO_voidSetPinValue(PORTC, PIN4, HIGH);
	DIO_voidSetPinValue(PORTC, PIN5, HIGH);
    SEGMENT_COMCATH_voidPrintNumber(PORTD, seconds_counter % 10);
    _delay_ms(1);

    DIO_voidSetPinValue(PORTC, PIN0, HIGH);
    DIO_voidSetPinValue(PORTC, PIN1, LOW);
	DIO_voidSetPinValue(PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(PORTC, PIN3, HIGH);
	DIO_voidSetPinValue(PORTC, PIN4, HIGH);
	DIO_voidSetPinValue(PORTC, PIN5, HIGH);
    SEGMENT_COMCATH_voidPrintNumber(PORTD, seconds_counter / 10);
    _delay_ms(1);

    // Display minutes
	DIO_voidSetPinValue(PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(PORTC, PIN1, HIGH);
    DIO_voidSetPinValue(PORTC, PIN2, LOW);
	DIO_voidSetPinValue(PORTC, PIN3, HIGH);
	DIO_voidSetPinValue(PORTC, PIN4, HIGH);
	DIO_voidSetPinValue(PORTC, PIN5, HIGH);
    SEGMENT_COMCATH_voidPrintNumber(PORTD, minutes_counter % 10);
    _delay_ms(1);
	
	DIO_voidSetPinValue(PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(PORTC, PIN1, HIGH);
    DIO_voidSetPinValue(PORTC, PIN2, HIGH);
    DIO_voidSetPinValue(PORTC, PIN3, LOW);
	DIO_voidSetPinValue(PORTC, PIN4, HIGH);
	DIO_voidSetPinValue(PORTC, PIN5, HIGH);
    SEGMENT_COMCATH_voidPrintNumber(PORTD, minutes_counter / 10);
    _delay_ms(1);

    // Display hours
	DIO_voidSetPinValue(PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(PORTC, PIN3, HIGH);
    DIO_voidSetPinValue(PORTC, PIN4, LOW);
	DIO_voidSetPinValue(PORTC, PIN5, HIGH);
    SEGMENT_COMCATH_voidPrintNumber(PORTD, hours_counter % 10);
    _delay_ms(1);
	
	DIO_voidSetPinValue(PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(PORTC, PIN3, HIGH);
    DIO_voidSetPinValue(PORTC, PIN4, HIGH);
    DIO_voidSetPinValue(PORTC, PIN5, LOW);
    SEGMENT_COMCATH_voidPrintNumber(PORTD, hours_counter / 10);
    _delay_ms(1);
}

// Function to update the time counters (seconds, minutes, hours)
void updateTime(void)
{
    if (seconds_counter == 60)
    {
        seconds_counter = 0;
        minutes_counter++;
    }
    if (minutes_counter == 60)
    {
        minutes_counter = 0;
        hours_counter++;
    }
    if (hours_counter == 24)
    {
        hours_counter = 0;
    }
}

// TIMER2 Overflow Interrupt Handler - called every 1 second
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	seconds_counter++; // Increment seconds counter every overflow
}
