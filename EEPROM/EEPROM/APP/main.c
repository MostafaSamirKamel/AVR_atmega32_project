/*
 * EEPROM.c
 *
 * Created: 2/26/2025 10:00:48 PM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
/* Include Header Files From LIB */
#include "../LIB/STD_TYPES.h"
/* Include Header Files From MCAL Layer */
#include "../MCAL/EEPROM/EEPROM_Interface.h"


int main(void)
{
	EEPROM_voidWrite_eeprom(L30,10);
	_delay_ms(1000);
	EEPROM_voidWrite_eeprom(L31,6);
	EEPROM_voidWrite_eeprom(L32,4);
	_delay_ms(1000);
	EEPROM_voidWrite_eeprom(L33,5);
	
	//EEPROM_voidWrite_eeprom(L15,3);
    
	
    while (1) 
    {
    }
}

