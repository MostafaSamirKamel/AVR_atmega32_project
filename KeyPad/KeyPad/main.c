/*
 * KeyPad.c
 *
 * Created: 3/15/2025 3:54:40 AM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"

#define MAX_EXPRESSION_LENGTH 16  

char expression[MAX_EXPRESSION_LENGTH];  
u8 exprIndex = 0;  

s32 evaluateExpression(const char *expr);

int main(void)
{
   LCD_voidInit();
   KPAD_voidInit();
   
   LCD_voidWriteString("Ready"); 
   LCD_voidGoTo_XY(LINE_2,0);
   LCD_voidWriteString("Eng/MostafaSamir");
   _delay_ms(3000);
   LCD_voidClearDisplay();
   
   u8 PressValue;
   
   while (1)
   {
       PressValue = KPAD_u8GetPressedKey();
       if (PressValue != NotPressed)
       {
           if (PressValue == '#')  
           {
               LCD_voidClearDisplay();
               exprIndex = 0;
               expression[0] = '\0';
           }
           else if ((PressValue >= '0' && PressValue <= '9') || PressValue == '+' || PressValue == '-' || PressValue == '*' || PressValue == '/')
           {
               if (exprIndex < MAX_EXPRESSION_LENGTH - 1)
               {
                   expression[exprIndex++] = PressValue;
                   expression[exprIndex] = '\0';  
                   LCD_voidWriteChar(PressValue);
               }
           }
           else if (PressValue == '=')
           {
               s32 result = evaluateExpression(expression);

               LCD_voidGoTo_XY(LINE_2,0);
               LCD_voidWriteString("Res = ");
               LCD_voidWrite_u32Number(result);
           }

           // **Debounce keypad** – Wait for key release
           while (KPAD_u8GetPressedKey() != NotPressed);
           _delay_ms(50);
       }
   }
}

s32 evaluateExpression(const char *expr) {
	s32 result = 0;
	char op = '+';
	s32 num = 0;

	while (*expr) {
		if (*expr >= '0' && *expr <= '9') {
			num = num * 10 + (*expr - '0');  // Convert char to int
			} else {
			if (op == '+') result += num;
			else if (op == '-') result -= num;
			else if (op == '*') result *= num;
			else if (op == '/') result /= num;

			op = *expr;
			num = 0;
		}
		expr++;
	}
	
	if (op == '+') result += num;
	else if (op == '-') result -= num;
	else if (op == '*') result *= num;
	else if (op == '/') result /= num;

	return result;
}
