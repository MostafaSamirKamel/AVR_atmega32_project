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
	DIO_voidSetPinDirection(KPAD_PORT,PIN0,OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,PIN1,OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,PIN2,OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,PIN3,OUTPUT);
	
	// Set Columns (Input with Pull-Up)
	DIO_voidSetPinDirection(KPAD_PORT,PIN4,INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,PIN5,INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,PIN6,INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,PIN7,INPUT);
	
	//Pull-Up
	DIO_voidConfig_Pull_Up_Pin(KPAD_PORT,PIN4,ON);
	DIO_voidConfig_Pull_Up_Pin(KPAD_PORT,PIN5,ON);
	DIO_voidConfig_Pull_Up_Pin(KPAD_PORT,PIN6,ON);
	DIO_voidConfig_Pull_Up_Pin(KPAD_PORT,PIN7,ON);
}

u8 KPAD_u8GetPressedKey ()
{
	u8 arr_Key[KPAD_ROWS_NUM][KPAD_COLUMNS_NUM] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', '*'},
		{'1', '2', '3', '-'},
		{'#', '0', '=', '+'}
	};
		
	u8 Rows_Cont, Columns_Cont;
	u8 Local_CheckPress;
	u8 Local_ReturnValue = NotPressed;

	
	for (Rows_Cont = 0; Rows_Cont < KPAD_ROWS_NUM; Rows_Cont++)
	{
		DIO_voidSetPinValue(KPAD_PORT,PIN0,HIGH);
		DIO_voidSetPinValue(KPAD_PORT,PIN1,HIGH);
		DIO_voidSetPinValue(KPAD_PORT,PIN2,HIGH);
		DIO_voidSetPinValue(KPAD_PORT,PIN3,HIGH);
		
		DIO_voidSetPinValue(KPAD_PORT, Rows_Cont, LOW);
		
		for (Columns_Cont = 0; Columns_Cont < KPAD_COLUMNS_NUM; Columns_Cont++)
		{
			Local_CheckPress = DIO_u8GetPinValue(KPAD_PORT, Columns_Cont + 4);
			
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
