/*
 * led_driver.c
 *
 * Created: 17-May-19 14:53:59
 *  Author: radug
 */ 

#include <avr/io.h>

void init_leds()
{
	//set port H as output
	DDRH = 0xFF;
}

// led_no [1..8], state [0..1]
void set_led(uint8_t led_no, uint8_t state)
{
	if (state)
	//set bit
	//led_no is subtracted from 8 so that it corresponds to the board's order (i.e. the 7th bit is actually LED1)
	PORTH |= 1<<(8-led_no);
	else
	//clear bit
	PORTH &= ~(1<<(8-led_no));
}