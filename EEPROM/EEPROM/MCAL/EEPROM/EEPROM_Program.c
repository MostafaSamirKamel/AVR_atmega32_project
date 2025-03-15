/*
 * EEPROM_Program.c
 *
 * Created: 2/26/2025 10:02:04 PM
 *  Author: Mostafa Samir
 */ 

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"

u8 EEPROM_u8Read_eeprom(u16 Copy_u16Address)
{
	/* wait for completion of  write operation */
	while(GET_BIT(EECR_REG,EEWE_BIT)==1);
	
	/*set up address register*/
	EEARL_REG = (u8)Copy_u16Address;
	EEARH_REG = (u8)(Copy_u16Address>>8);
	
	/*start EEPROM read by setting EERE*/
	SET_BIT(EECR_REG,EERE_BIT);
	
	/*return data from data register*/
	return EEDR_REG ;

}

void EEPROM_voidWrite_eeprom(u16 Copy_u16Address, u8 Copy_u16DATA)
{
	/* wait for completion of  write operation */
	while(GET_BIT(EECR_REG,EEWE_BIT)==1);
	
	/*set up address register*/
	EEARL_REG = (u8)Copy_u16Address;
	EEARH_REG = (u8)(Copy_u16Address>>8);
	
	
	/*set up data register*/
	EEDR_REG = Copy_u16DATA ;
	
	
	/*write logical one to EEMWE*/
	SET_BIT(EECR_REG,EEMWE_BIT);
	
	
	/*start EEPROM write by setting EEWE*/
	SET_BIT(EECR_REG,EEWE_BIT);
	
	
	/* wait for completion of  write operation */
	while(GET_BIT(EECR_REG,EEWE_BIT)==1);

}