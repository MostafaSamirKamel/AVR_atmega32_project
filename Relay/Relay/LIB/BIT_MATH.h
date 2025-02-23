/*=================================================================================*/
/*  File        : BIT_MATH.h                                                       */
/*  Description : This file includes BIT_MATH macros for Atmega32                  */
/*  Author      : Mostafa Samir Kamel. Embedded SW Engineer                      */
/*  Date        : 2/18/2025                                                        */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                        */
/*  Git account : https://github.com/MostafaSamir0                                 */
/*  mail        : mostafasameer858@gmil.com                                        */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define REGISTER_SIZE 8

#define SET_BIT(REG,BIT_POSITION)     REG |= (1<<BIT_POSITION)
#define CLEAR_BIT(REG,BIT_POSITION)   REG &= ~(1<<BIT_POSITION)
#define GET_BIT(REG,BIT_POSITION)     REG & (1<<BIT_POSITION)
#define TOGGLE_BIT(REG,BIT_POSITION)  REG ^= (1<<BIT_POSITION)

#define ROR(REG,NUM)                  REG =(REG<<(REGISTER_SIZE-NUM))|(REG>>(NUM))
#define ROL(REG,NUM)                  REG =(REG>>(REGISTER_SIZE-NUM))|(REG<<(NUM))


#endif