/*
 * Timer2_config.h
 *
 * Created: 4/21/2025 10:45:00 PM
 *  Author: Mostafa Samir
 */ 


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

/*===============================================*/
/*              TIMER2 Mode Selection            */
/*-----------------------------------------------*/
#define     NORMAL_OVF                   0
#define     PWM_PHASECORRECT             1
#define     CTC                          2
#define     FAST_PWM                     3
/*===============================================*/
#define     MODE                     NORMAL_OVF
/*===============================================*/

/*===============================================*/
/*          TIMER2 Prescaler Selection           */
/*-----------------------------------------------*/
#define     NO_CLK_SOURCE_TIMER_STOPPED        0x00
#define     NOT_USE_PRESCALER                  0x01
#define     PRESCALER_DIVISION_BY_8            0x02
#define     PRESCALER_DIVISION_BY_32           0x03
#define     PRESCALER_DIVISION_BY_64           0x04
#define     PRESCALER_DIVISION_BY_128          0x05
#define     PRESCALER_DIVISION_BY_256          0x06
#define     PRESCALER_DIVISION_BY_1024         0x07
/*===========================================================*/
#define     PRESCALER           PRESCALER_DIVISION_BY_128
/*===========================================================*/
#define     CPU_CLK       32.768  // kHz



#endif /* TIMER2_CONFIG_H_ */
