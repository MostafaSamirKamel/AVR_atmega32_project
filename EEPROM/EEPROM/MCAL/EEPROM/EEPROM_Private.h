/*
 * EEPROM_Private.h
 *
 * Created: 2/26/2025 10:03:43 PM
 *  Author: Mostafa Samir
 */ 


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

         // EEPROM Address Register
#define  EEARH_REG       *((volatile u8*)0x3F) // high
#define  EEARL_REG       *((volatile u8*)0x3E) // low
       
	   // EEPROM Control Register
#define   EECR_REG     *((volatile u8*)0x3C) 

      // EEPROM DATA Register
#define   EEDR_REG     *((volatile u8*)0x3D)



#define EERE_BIT   0
#define EEWE_BIT   1
#define EEMWE_BIT  2
#define EERIE_BIT  3

#endif /* EEPROM_PRIVATE_H_ */