/*
 * Timer2_Private.h
 *
 * Created: 4/21/2025 10:32:49 PM
 *  Author: Mostafa Samir
 */ 


#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_


/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/********      [TIMER2] Registers       *********/
#define     TCCR2_REG        *((volatile u8*)0x45)     // Timer/Counter2 Control Register
#define     TCNT2_REG        *((volatile u8*)0x44)     // Timer/Counter2 Register
#define     OCR2_REG         *((volatile u8*)0x43)     // Output Compare Register 2
#define     TIMSK_REG        *((volatile u8*)0x59)     // Timer/Counter Interrupt Mask Register (shared)
#define     TIFR_REG         *((volatile u8*)0x58)     // Timer/Counter Interrupt Flag Register (shared)
#define     ASSR_REG	     *((volatile u8*)0X42) 
#define     AS2_BIT           3
/* SREG */
#define SREG_REG             *((volatile u8*)0x5F)
#define GINT_BIT             7
/*================================================================================================================*/
/********   TIMER2 [TCCR2] BITS   *******/ 
#define     TIMER2_TCCR2_CS20          0              // Clock Select Bit 0
#define     TIMER2_TCCR2_CS21          1              // Clock Select Bit 1
#define     TIMER2_TCCR2_CS22          2              // Clock Select Bit 2
#define     TIMER2_TCCR2_WGM20         3              // Waveform Generation Mode Bit 1
#define     TIMER2_TCCR2_COM20         4              // Compare Match Output Mode Bit 0
#define     TIMER2_TCCR2_COM21         5              // Compare Match Output Mode Bit 1
#define     TIMER2_TCCR2_WGM21         6              // Waveform Generation Mode Bit 0
#define     TIMER2_TCCR2_FOC2          7              // Force Output Compare
/*================================================================================================================*/
/********   TIMER2 [TIMSK] BITS   *******/ 
#define     TIMER2_TIMSK_TOIE2         6              // Timer/Counter2 Overflow Interrupt Enable
#define     TIMER2_TIMSK_OCIE2         7              // Timer/Counter2 Output Compare Match Interrupt Enable
/*================================================================================================================*/
/********   TIMER2 [TIFR] BITS    *******/ 
#define     TIMER2_TIFR_TOV2           6              // Timer/Counter2 Overflow Flag
#define     TIMER2_TIFR_OCF2           7              // Timer/Counter2 Output Compare Flag




#endif /* TIMER2_PRIVATE_H_ */
