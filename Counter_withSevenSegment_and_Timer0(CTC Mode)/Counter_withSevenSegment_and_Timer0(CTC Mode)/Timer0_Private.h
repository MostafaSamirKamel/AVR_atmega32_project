/*
 * Timer0_Private.h
 *
 * Created: 4/18/2025 2:23:56 AM
 *  Author: Mostafa Samir
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/********      [TIMER0] Registers       *********/
#define     TCCR0_REG        *((volatile u8*)0x53)     // Timer/Counter Control Register
#define     TCNT0_REG        *((volatile u8*)0x52)     // Timer/Counter Register
#define     OCR0_REG         *((volatile u8*)0x5C)     // Output Compare Register
#define     TIMSK_REG        *((volatile u8*)0x59)     // Timer/Counter Interrupt Mask Register
#define     TIFR_REG         *((volatile u8*)0x58)     // Timer/Counter Interrupt Flag Register
/* SREG */
#define SREG_REG   *((volatile u8*)0x5F)
#define GINT_BIT    7
/*================================================================================================================*/
/********   TIMER0 [TCCR0] BITS   *******/
#define     TIMER0_TCCR0_CS00          0              // TIMER0 Prescaller Clock Select BIT 0
#define     TIMER0_TCCR0_CS01          1              // TIMER0 Prescaller Clock Select BIT 1
#define     TIMER0_TCCR0_CS02          2              // TIMER0 Prescaller Clock Select BIT 2
#define     TIMER0_TCCR0_WGM01         3              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     TIMER0_TCCR0_COM00         4              // Compare Match Output Mode BIT 0 (OC0) behavior
#define     TIMER0_TCCR0_COM01         5              // Compare Match Output Mode BIT 1 (OC0) behavior
#define     TIMER0_TCCR0_WGM00         6              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     TIMER0_TCCR0_FOC0          7              // Force Output Compare
/*================================================================================================================*/
/********   TIMER0 [TIMSK] BITS   *******/
#define     TIMER0_TIMSK_TOIE0         0              // Timer/Counter0 OVF Interrupt Enable BIT 0
#define     TIMER0_TIMSK_OCIE0         1              // Timer/Counter0 CTC Interrupt Enable BIT 1
/*================================================================================================================*/
/********   TIMER0 [TIFR] BITS    *******/
#define      TIMER0_TIFR_TOV0          0              // Timer/Counter0 OVF Flag
#define      TIMER0_TIFR_OCF0          1              // Timer/Counter0 CTC Flag
/*================================================================================================================*/
/********   TIMER0 [SFIOR] BITS   *******/
#define      TIMER0_SFIOR_PSR10        0              // Prescaler Reset TIMER0 and TIMER1
/*================================================================================================================*/
#define     NULL                   (void*)(0)


#endif /* TIMER0_PRIVATE_H_ */