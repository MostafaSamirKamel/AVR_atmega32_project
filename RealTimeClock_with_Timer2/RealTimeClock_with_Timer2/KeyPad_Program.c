/*
 * KeyPad_Program.c
 *
 * Created: 3/15/2025 3:56:53 AM
 *  Author: Mostafa Samir
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"

#include "KeyPad_Interface.h"
#include "KeyPad_Config.h"

void KPAD_voidInit ()
{
	// Set Rows (Output)
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_R0_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_R1_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_R2_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_R3_PIN,OUTPUT);
	
	// Set Columns (Input with Pull-Up)
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_C0_PIN,INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_C1_PIN,INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_C2_PIN,INPUT);
	
	//Pull-Up
	DIO_voidConfig_Pull_Up_Pin(KPAD_PORT,KPAD_C0_PIN,ON);
	DIO_voidConfig_Pull_Up_Pin(KPAD_PORT,KPAD_C1_PIN,ON);
	DIO_voidConfig_Pull_Up_Pin(KPAD_PORT,KPAD_C2_PIN,ON);
}

u8 KPAD_u8GetPressedKey ()
{
	u8 arr_Key[KPAD_ROWS_NUM][KPAD_COLUMNS_NUM] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
		{'*', '0', '#'}
	};
		
	u8 Rows_Cont, Columns_Cont;
	u8 Local_CheckPress;
	u8 Local_ReturnValue = NOTPRESSED;

	
	for (Rows_Cont = 0; Rows_Cont < KPAD_ROWS_NUM; Rows_Cont++)
	{
		DIO_voidSetPinValue(KPAD_PORT,KPAD_R0_PIN,HIGH);
		DIO_voidSetPinValue(KPAD_PORT,KPAD_R1_PIN,HIGH);
		DIO_voidSetPinValue(KPAD_PORT,KPAD_R2_PIN,HIGH);
		DIO_voidSetPinValue(KPAD_PORT,KPAD_R3_PIN,HIGH);
		
		DIO_voidSetPinValue(KPAD_PORT, Rows_Cont+3, LOW);
		
		for (Columns_Cont = 0; Columns_Cont < KPAD_COLUMNS_NUM; Columns_Cont++)
		{
			Local_CheckPress = DIO_u8GetPinValue(KPAD_PORT, Columns_Cont);
			
			if (Local_CheckPress == 0)
			{
				Local_ReturnValue = arr_Key[Rows_Cont][Columns_Cont];
				break;
			}
		}
		if (Local_CheckPress == 0)
		{
			break;
		}
	}
	
	return Local_ReturnValue;
}
