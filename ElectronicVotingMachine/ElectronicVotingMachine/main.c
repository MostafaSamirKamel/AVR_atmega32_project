/*
 * ElectronicVotingMachine.c
 *
 * Created: 3/17/2025 11:46:32 PM
 * Author : Mostafa Samir
 */

#define F_CPU 8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "button_Interface.h"
#include "LED_Interface.h"

u8 c1 = 0;
u8 c2 = 0;
u8 c3 = 0;
u8 c4 = 0;

int main(void)
{
    LCD_voidInit();
    
    DIO_voidSetPinDirection(PORTB, PIN0,OUTPUT);    // LED for Candidate A
    DIO_voidSetPinDirection(PORTB, PIN1,OUTPUT);    // LED for Candidate B
    DIO_voidSetPinDirection(PORTB, PIN2,OUTPUT);    // LED for Candidate C
    DIO_voidSetPinDirection(PORTB, PIN3,OUTPUT);    // LED for Candidate D

    DIO_voidSetPinDirection(PORTD, PIN0,INPUT);  // Vote A button
    DIO_voidSetPinDirection(PORTD, PIN1,INPUT);  // Vote B button
    DIO_voidSetPinDirection(PORTD, PIN2,INPUT);  // Vote C button
    DIO_voidSetPinDirection(PORTD, PIN3,INPUT);  // Vote D button
    DIO_voidSetPinDirection(PORTD, PIN4,INPUT);  // Reset button    
    
    LCD_voidWriteString("Electronic");
    LCD_voidGoTo_XY(LINE_2, 0);
    LCD_voidWriteString("Voting Machine");
    _delay_ms(2000);
    LCD_voidClearDisplay();
    _delay_ms(250);

    // Initial display
    LCD_voidGoTo_XY(LINE_1, 0);
    LCD_voidWriteString("A = 0");
    LCD_voidGoTo_XY(LINE_1, 10);
    LCD_voidWriteString("B = 0");
    LCD_voidGoTo_XY(LINE_2, 0);
    LCD_voidWriteString("C = 0");
    LCD_voidGoTo_XY(LINE_2, 10);
    LCD_voidWriteString("D = 0");
    
    u8 RB1, RB2, RB3, RB4, RB5;

    while (1)
    {
        RB1 = BUTTON_u8Get_button_Pin(PORTD, PIN0);
        RB2 = BUTTON_u8Get_button_Pin(PORTD, PIN1);
        RB3 = BUTTON_u8Get_button_Pin(PORTD, PIN2);
        RB4 = BUTTON_u8Get_button_Pin(PORTD, PIN3);
        RB5 = BUTTON_u8Get_button_Pin(PORTD, PIN4);
        
        if (RB1 == 1)   // Button for Candidate A
        {
            c1++;
            DIO_voidSetPinValue(PORTB, PIN0, HIGH);  // Turn on LED for Candidate A
            LCD_voidGoTo_XY(LINE_1, 4);
            LCD_voidWriteNumber(c1);
            _delay_ms(100);                          // Small delay to prevent multiple rapid counts
            DIO_voidSetPinValue(PORTB, PIN0, LOW);   // Turn off LED after the click
        }
        else if (RB2 == 1)  // Button for Candidate B
        {
            c2++;
            DIO_voidSetPinValue(PORTB, PIN1, HIGH);  // Turn on LED for Candidate B
            LCD_voidGoTo_XY(LINE_1, 14);
            LCD_voidWriteNumber(c2);
            _delay_ms(100);
            DIO_voidSetPinValue(PORTB, PIN1, LOW);   // Turn off LED after the click
        }
        else if (RB3 == 1)  // Button for Candidate C
        {
            c3++;
            DIO_voidSetPinValue(PORTB, PIN2, HIGH);  // Turn on LED for Candidate C
            LCD_voidGoTo_XY(LINE_2, 4);
            LCD_voidWriteNumber(c3);
            _delay_ms(100);
            DIO_voidSetPinValue(PORTB, PIN2, LOW);   // Turn off LED after the click
        }
        else if (RB4 == 1)  // Button for Candidate D
        {
            c4++;
            DIO_voidSetPinValue(PORTB, PIN3, HIGH);  // Turn on LED for Candidate D
            LCD_voidGoTo_XY(LINE_2, 14);
            LCD_voidWriteNumber(c4);
            _delay_ms(100);
            DIO_voidSetPinValue(PORTB, PIN3, LOW);   // Turn off LED after the click
        }
        else if (RB5 == 1)  // Reset Button
        {
			DIO_voidSetPinValue(PORTB, PIN0, HIGH);
			DIO_voidSetPinValue(PORTB, PIN1, HIGH);
			DIO_voidSetPinValue(PORTB, PIN2, HIGH);
			DIO_voidSetPinValue(PORTB, PIN3, HIGH);
			
			
			
            // Reset vote counts
            c1 = 0;
            c2 = 0;
            c3 = 0;
            c4 = 0;
            
			LCD_voidClearDisplay();
            LCD_voidGoTo_XY(LINE_1, 0);
            LCD_voidWriteString("A = 0");
            LCD_voidGoTo_XY(LINE_1, 10);
            LCD_voidWriteString("B = 0");
            LCD_voidGoTo_XY(LINE_2, 0);
            LCD_voidWriteString("C = 0");
            LCD_voidGoTo_XY(LINE_2, 10);
            LCD_voidWriteString("D = 0");
			
			_delay_ms(100);
			DIO_voidSetPinValue(PORTB, PIN0, LOW);
			DIO_voidSetPinValue(PORTB, PIN1, LOW);
			DIO_voidSetPinValue(PORTB, PIN2, LOW);
			DIO_voidSetPinValue(PORTB, PIN3, LOW);
        }
        _delay_ms(200); 
    }
}
