/*=================================================================================*/
/*  File        : SEVEN_SEGMENT_Private.h                                          */
/*  Description : This Private file includes 7_SEGMENT Driver macros for Atmega32  */
/*  Author      : Mostafa Samir Kamel. Embedded SW Engineer                          */
/*  Date        : 2/18/2025                                                            */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                          */
/*  Git account : https://github.com/MostafaSamir0                                      */
/*  mail        : mostafasameer858@gmil.com                                            */
/*======================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef SEVENSEGMENT_PRIVATE_H_
#define SEVENSEGMENT_PRIVATE_H_

/* Private Macros */

/* 7-Segment Common Anode Macros */
					//0b1gfedcba
#define ZERO_A        0b11000000
#define ONE_A         0b11111001
#define TWO_A         0b10100100
#define THREE_A       0b10110000
#define FOUR_A        0b10011001
#define FIVE_A        0b10010010
#define SIX_A         0b10000010
#define SEVEN_A       0b11111000
#define EIGHT_A       0b10000000
#define NINE_A        0b10010000
#define A_A           0b10001000
#define B_A           0b10000011
#define C_A           0b11000110
#define D_A           0b10100001
#define E_A           0b10000110
#define F_A           0b10001110

/* 7-Segment Common Cathode Macros */
					//0b0gfedcba
#define ZERO_C        0b00111111
#define ONE_C         0b00000110
#define TWO_C         0b01011011
#define THREE_C       0b01001111
#define FOUR_C        0b01100110
#define FIVE_C        0b01101101
#define SIX_C         0b01111101
#define SEVEN_C       0b00000111
#define EIGHT_C       0b01111111
#define NINE_C        0b01101111
#define A_C           0b01110111
#define B_C           0b01111100
#define C_C           0b00111001
#define D_C           0b01011110
#define E_C           0b01111001
#define F_C           0b01110001

#endif /* 7SEGMENT_PRIVATE_H_ */