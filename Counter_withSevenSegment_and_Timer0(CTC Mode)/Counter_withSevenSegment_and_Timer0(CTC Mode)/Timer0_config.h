/*
 * Timer0_config.h
 *
 * Created: 4/18/2025 2:23:28 AM
 *  Author: Mostafa Samir
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*===============================================*/
/*              TIMER0 Mode Selection            */
/*-----------------------------------------------*/
#define     NORMAL_OVF                   0
#define     PWM_PHASECORRECT             1
#define     CTC                          2
#define     FAST_PWM                     3
/*===============================================*/
#define     MODE                     CTC
/*===============================================*/

/*===============================================*/
/*          TIMER0 Prescaller Selection          */
/*-----------------------------------------------*/
#define     NO_CLK_SOURCE_TIMER_STOPED        0x00
#define     NOT_USE_PRESCALER                 0x01
#define     PRESCALER_DIVISION_BY_8           0x02
#define     PRESCALER_DIVISION_BY_64          0x03
#define     PRESCALER_DIVISION_BY_256         0x04
#define     PRESCALER_DIVISION_BY_1024        0x05
#define     EXTERNAL_CLK_SOURCE_FALLING_EDGE  0x06
#define     EXTERNAL_CLK_SOURCE_RAISING_EDGE  0x07
/*===========================================================*/
#define     PRESCALER           PRESCALER_DIVISION_BY_1024
/*===========================================================*/
#define     CPU_CLK       8  // MHz



#endif /* TIMER0_CONFIG_H_ */