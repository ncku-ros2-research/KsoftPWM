/*
	Access raspberry pi3 gpio by kernel module.
	Shao-Hua Wang
	2017.02.02
*/

#include "gpio.h"

extern volatile unsigned *gpio;

void gpio_input(int pin) {

	*(gpio + (pin / 10)) &= ~(7 << ((pin % 10) * 3));

}

void gpio_output(int pin) {

	*(gpio + (pin / 10)) |=  (1 << ((pin % 10) * 3));

}

void gpio_set(int pin) {

	*(gpio + 7) = 1 << pin;

}

void gpio_clr(int pin) {

	*(gpio + 10) = 1 << pin;

}
