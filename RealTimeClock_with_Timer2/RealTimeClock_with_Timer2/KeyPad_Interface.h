/*
 * KeyPad_Interface.h
 *
 * Created: 3/15/2025 3:55:34 AM
 *  Author: Mostafa Samir
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define NOTPRESSED   0xFF

void KPAD_voidInit ();
u8   KPAD_u8GetPressedKey ();


#endif /* KEYPAD_INTERFACE_H_ */