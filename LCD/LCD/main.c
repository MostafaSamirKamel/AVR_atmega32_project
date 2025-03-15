/*
 * LCD.c
 *
 * Created: 3/10/2025 11:17:29 PM
 * Author : Mostafa Samir
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LCD_Interface.h"

// Custom character patterns
u8 smiley[] = {
	0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00  // Smiley face
};

u8 ball[] = {
	0x00, 0x0E, 0x1F, 0x1F, 0x1F, 0x0E, 0x00, 0x00  // Ball
};

// Function to scroll text
void LCD_ScrollText(u8 *text, u8 line) {
	u8 i;
	for (i = 0; i < 16; i++) {
		LCD_voidGoTo_XY(line, i);
		LCD_voidWriteString(text);
		_delay_ms(500);
		LCD_voidClearLine(line);  // Clear the line before next iteration
	}
}

// Function to animate custom characters
void LCD_AnimateCustomChar(u8 pattern, u8 line, u8 start_pos, u8 end_pos) {
	u8 i;
	for (i = start_pos; i <= end_pos; i++) {
		LCD_voidGoTo_XY(line, i);
		LCD_voidShowPattern(pattern, line, i);
		_delay_ms(200);
		LCD_voidClearGrid(line, i);  // Clear the current position
	}
}

int main(void) {
	// Initialize LCD
	LCD_voidInit();

	// Load custom characters into CGRAM
	LCD_voidDrawPattern(PATTERN_0_Add, smiley);  // Smiley face at pattern 0
	_delay_ms(100);
	LCD_voidDrawPattern(PATTERN_1_Add, ball);    // Ball at pattern 1

	// Main loop
	while (1) {
		// Scroll text on line 1
		LCD_ScrollText("Mostafa Samir", LINE_1);

		// Animate smiley face on line 2
		LCD_AnimateCustomChar(PATTERN_0, LINE_2, 0, 15);

		// Animate ball on line 1
		LCD_AnimateCustomChar(PATTERN_1, LINE_1, 0, 15);
	}

}
