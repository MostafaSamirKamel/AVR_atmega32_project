/*
 * Timer0_Program.c
 *
 * Created: 4/18/2025 2:24:17 AM
 *  Author: Mostafa Samir
 */ 

/* Include Header Files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* Include My own Header Files*/
#include "Timer0_Inerface.h"
#include "Timer0_Private.h"
#include "Timer0_config.h"


void Enterrupt_GlobalEnable()
{
	SET_BIT(SREG_REG,GINT_BIT);
}

void TIMER0_voidInit ()
{
	/*======================================*/
	/*         TIMER0 Mode Selection        */
	/*--------------------------------------*/
	
	#if (MODE == NORMAL_OVF)           // OVF Normal Mode of Timer/Counter0
	CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
	CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
	// Enable T0 OVF Interrupt [PIE].
	Enterrupt_GlobalEnable();
	SET_BIT(TIMSK_REG,TIMER0_TIMSK_TOIE0);   	
	   
	#elif (MODE == CTC)                  // CTC Mode of Timer/Counter0
	CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
	SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
	// Enable T0 CTC Interrupt [PIE].
	Enterrupt_GlobalEnable();
	SET_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);   
	// load a value in OCR0 
	OCR0_REG = 78; // (10ms * 8MHz) / (1024 prescaler) - 1 ? 78
	#endif     

	
	/*======================================*/
	/*======================================*/
	/*     TIMER0 Prescaller Selection (clock select)     */
	/*--------------------------------------*/
	 #if (PRESCALER == NO_CLK_SOURCE_TIMER_STOPED) //
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02) ;
	 	 
	 #elif (PRESCALER == NOT_USE_PRESCALER) //
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
	 
	 #elif (PRESCALER == PRESCALER_DIVISION_BY_8) //
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
	 
	 #elif (PRESCALER == PRESCALER_DIVISION_BY_64) //
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
	 
	 #elif (PRESCALER == PRESCALER_DIVISION_BY_256) //
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
	 
	 #elif (PRESCALER == PRESCALER_DIVISION_BY_1024) //
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
	 
	 #elif (PRESCALER == EXTERNAL_CLK_SOURCE_FALLING_EDGE) //
	 CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	 SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
	 
	  #elif (PRESCALER == EXTERNAL_CLK_SOURCE_RAISING_EDGE) //
	  SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
	  SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
	  SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
	  
	  	#endif

	/*======================================*/
}

 
 