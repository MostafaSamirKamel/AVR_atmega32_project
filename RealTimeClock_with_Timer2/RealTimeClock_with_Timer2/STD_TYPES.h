/*=================================================================================*/
/*  File        : STD_TYPES.h                                                      */
/*  Description : This file includes STD_TYPES macros for Atmega32                 */
/*  Author      : Mostafa Samir Kamel. Embedded SW Engineer                      */
/*  Date        : 2/18/2025                                                        */
/*  Linkedin    : https://www.linkedin.com/in/mostafasameer00                        */
/*  Git account : https://github.com/MostafaSamir0                                 */
/*  mail        : mostafasameer858@gmil.com                                        */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char           u8  ;        // 1 Byte - 255 Bit
typedef volatile unsigned char  vu8 ;
typedef unsigned short int      u16 ;       // 2 Byte 
typedef unsigned long int       u32 ;       // 4 Byte
typedef signed char             s8  ;        // 1 Byte
typedef signed short int        s16 ;       // 2 Byte
typedef signed long int		    s32 ;       // 4 Byte
typedef float                   f32 ;       // 4 Byte
typedef double                  f64 ;       // 8 Byte


#define     NOT_OK          0
#define     OK              1

#endif
