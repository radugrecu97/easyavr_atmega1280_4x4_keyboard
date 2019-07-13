/*
* Assignment02.c
*
* Created: 09-Mar-19 1:39:44 PM
* Author : Radu
*/

#include "util/delay.h"
#include "led_driver.h"
#include "keypad4x4_driver.h"

int main(void)
{
	int8_t volatile key;
	
	init_keyboard();
	init_leds();

	while (1)
	{
		//store pressed key
		key = getCh();
		
		//set LED i according to bit (i-8)
		for (int i=8; i>0; i--)
		{
			//check if bits 0-3 are set
			if (key & 1<<abs(i-8))
				set_led(i, 1);
			else
				set_led(i, 0);
		}
		
		_delay_ms(10);
	}
}



