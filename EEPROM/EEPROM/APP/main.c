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
	
	EEPROM_voidWrite_eeprom(L0,0);
	EEPROM_voidWrite_eeprom(L1,1);
	EEPROM_voidWrite_eeprom(L2,2);
	EEPROM_voidWrite_eeprom(L3,3);
	
	
	
	
    while (1) 
    {
    }
}

