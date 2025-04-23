/*
 * Timer2_Program.c
 *
 * Created: 4/21/2025 11:00:00 PM
 *  Author: Mostafa Samir
 */ 

/* Include Header Files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* Include My own Header Files */
#include "Timer2_Interface.h"
#include "Timer2_Private.h"
#include "Timer2_Config.h"


void Enterrupt_GlobalEnable()
{
	SET_BIT(SREG_REG, GINT_BIT);
}

void TIMER2_voidInit()
{
	// Set to use external 32.768 kHz crystal oscillator
	SET_BIT(ASSR_REG, AS2_BIT); // Use the external crystal oscillator
	
	// Set Timer2 in normal mode (overflow mode)
	CLEAR_BIT(TCCR2_REG, TIMER2_TCCR2_WGM20); // Clear WGM20 for Normal mode
	CLEAR_BIT(TCCR2_REG, TIMER2_TCCR2_WGM21); // Clear WGM21 for Normal mode
	
	// Set pre-scaler to 128 (divide the 32.768 kHz by 128)
	SET_BIT(TCCR2_REG, TIMER2_TCCR2_CS20); // Set CS20 bit
	CLEAR_BIT(TCCR2_REG, TIMER2_TCCR2_CS21); // Clear CS21 bit
	SET_BIT(TCCR2_REG, TIMER2_TCCR2_CS22); // Set CS22 bit
	
	// Enable Timer2 overflow interrupt
	SET_BIT(TIMSK_REG, TIMER2_TIMSK_TOIE2);
	
	// Enable global interrupt
	Enterrupt_GlobalEnable();  // Global interrupt enable
	
}
