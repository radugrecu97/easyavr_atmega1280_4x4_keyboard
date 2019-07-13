/*
 * led_driver.h
 *
 * Created: 17-May-19 14:53:52
 *  Author: radug
 */ 


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

void init_leds();

// led_no [1..8], state [0..1]
void set_led(uint8_t led_no, uint8_t state);

#endif /* LED_DRIVER_H_ */