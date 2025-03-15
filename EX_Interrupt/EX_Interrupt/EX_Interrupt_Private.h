/*
 * EX_Interrupt_Private.h
 *
 * Created: 3/9/2025 11:48:03 PM
 *  Author: Mostafa Samir
 */ 


#ifndef EX_INTERRUPT_PRIVATE_H_
#define EX_INTERRUPT_PRIVATE_H_

/* GICR */
#define GICR_REG   *((volatile u8*)0x5B)

#define INT1    7
#define INT0    6
#define INT2    5

/* GIFR */
#define GIFR_REG   *((volatile u8*)0x5A)

#define INTF1   7
#define INTF0   6
#define INTF2   5


/* MCUCR */
#define MCUCR_REG   *((volatile u8*)0x55)

#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* MCUCSR */
#define MCUCSR_REG   *((volatile u8*)0x54)

#define ISC2    6


/* SREG */
#define SREG_REG   *((volatile u8*)0x5F)

#define GINT    7



#endif /* EX_INTERRUPT_PRIVATE_H_ */