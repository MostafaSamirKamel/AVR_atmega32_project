/*
 * Safe.c
 *
 * Created: 3/23/2025 8:24:59 PM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"
#include "EEPROM_Interface.h"

#define  FALSE      0
#define  TRUE       1
#define  MAX_TRIES  2
#define  PassWordCont   6  
u8 Password_arr[6];

int main(void)
{
    
    LCD_voidInit();
    KPAD_voidInit();
	
    LCD_voidWriteString("Safe Project");
    LCD_voidGoTo_XY(LINE_2,0);
    LCD_voidWriteString("Eng/MostafaSamir");
    _delay_ms(2000);
    LCD_voidClearDisplay();
	
	
    u8 PressValue = NotPressed;
	u8 opened = FALSE ; 
	u8 tries = MAX_TRIES ;
	u8 I ;
	
	if (EEPROM_u8Read_eeprom(L0) == Default )
	{
		LCD_voidWriteString("SET NEW PASSWORD");
		
		for (I = 0; I < PassWordCont; I++)
		{
			do 
			{
				PressValue = KPAD_u8GetPressedKey();
			} while (PressValue == NotPressed);
			
			LCD_voidGoTo_XY(LINE_2, I);
			LCD_voidWriteChar(PressValue);
			_delay_ms(500);
			LCD_voidGoTo_XY(LINE_2, I);
			LCD_voidWriteChar('*');
			
			EEPROM_voidWrite_eeprom(L1 + I, PressValue);
			
		}
		EEPROM_voidWrite_eeprom(L0, 0x00);
		
		LCD_voidClearDisplay();
		LCD_voidWriteString("PASSWORD HAS");
		LCD_voidGoTo_XY(LINE_2, 0);
		LCD_voidWriteString("BEEN SET");
		_delay_ms(1000);
	}

    while (opened == FALSE)
    {
		LCD_voidClearDisplay();
		LCD_voidWriteString("CHEK PASSWORD");
		for (I = 0; I < PassWordCont; I++)
		{
			do 
			{
				Password_arr[I] = KPAD_u8GetPressedKey();
			} while ( Password_arr[I] == NotPressed);
			
			LCD_voidGoTo_XY(LINE_2,I);
			LCD_voidWriteChar(Password_arr[I]);
			_delay_ms(500);
			LCD_voidGoTo_XY(LINE_2,I);
			LCD_voidWriteChar('*');		
		}
		
		if (EEPROM_u8Read_eeprom(L1) == Password_arr[0] && EEPROM_u8Read_eeprom(L2) == Password_arr[1] && EEPROM_u8Read_eeprom(L3) == Password_arr[2] && EEPROM_u8Read_eeprom(L4) == Password_arr[3] && EEPROM_u8Read_eeprom(L5) == Password_arr[4] && EEPROM_u8Read_eeprom(L6) == Password_arr[5])
		{
			LCD_voidClearDisplay();
			LCD_voidWriteString("RIGHT PASSWORD");
			LCD_voidGoTo_XY(LINE_2,0);
			LCD_voidWriteString("Safe OPENED");
			
			opened = TRUE;
		}
		else
		{
			tries = tries -1;
			
			if (tries > 0)
			{
				LCD_voidClearDisplay();
				LCD_voidWriteString("WRONG PASSWORD");
				LCD_voidGoTo_XY(LINE_2,0);
				LCD_voidWriteString("TRIES LEFT : ");
				LCD_voidWriteNumber(tries);
				_delay_ms(1000);
			} 
			else
			{
				LCD_voidClearDisplay();
				LCD_voidWriteString("WRONG PASSWORD");
				LCD_voidGoTo_XY(LINE_2,0);
				LCD_voidWriteString("SAFE CLOSED");
				
				
				opened = TRUE;
				if (opened == TRUE)
				{
					LCD_voidClearDisplay();
					LCD_voidWriteString("WAIT 5 SECOND");
					LCD_voidGoTo_XY(LINE_2,0);
					for (I = 0; I <=4; I++)
					{
						LCD_voidWriteNumber(I+1);
						_delay_ms(1000);
					}
				}
				opened = FALSE;
				
			}
			
		}
   
    }
}
