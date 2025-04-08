
/* File Gaurd by ifndef & endif */
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Private Macros */
#define      ADMUX_REG             *((volatile u8*)0x27)
#define     ADCSRA_REG             *((volatile u8*)0x26)
#define       ADCH_REG             *((volatile u8*)0x25)   // Pointer to 8 bit ADCH to read Data From 8 BIT of ADC Data by Right Adjust.
#define       ADCL_REG             *((volatile u8*)0x24)
#define        ADC_REG             *((volatile u16*)0x24)  // Pointer to 16 bit ADCH and ADCL to read Data From 10 BIT of ADC Data. 
#define      SFIOR_REG             *((volatile u8*)0x50)


/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#endif