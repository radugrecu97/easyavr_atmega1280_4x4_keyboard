/*
 * _keypad4x4_driver.c
 *
 * Created: 17-May-19 14:44:24
 *  Author: radug
 */ 

#include <avr/io.h>

void init_keyboard()
{
	//Enables pull-ups on Columns
	//PORTJ |= 0b00001111;
	
}



int8_t getCh()
{
	uint8_t row = 0, col = 0;
	DDRJ = 0xF0;
	PORTJ = 0x0F;
	
	for(int i=0; i<4; i++)
	{
		//Determine which column pin is pulled LOW with a bitwise mask
		if(!(PINJ & (0b00001000>>i)))
		{
			col = i;
		}
	}
	/*
	for(int i=0; i<4; i++)
	{
		//Set the (4-c) row to high
		PORTJ |= (0b10000000>>i);
		
		//Determine which column pin is pulled HIGH with a bitwise mask
		if((PINJ & (0b00001000>>col)))
		{
			row = i;
		}
	}
*/
	return col;
}