#include "gpio.h"

/** Sets up PE0-7 as inports and PE8-15 as outports. */
void set_up_DIL( void ) {
	GPIO_D.Moder = 0x55550000;
}

char read_DIL( void ) {
	GPIO_D.idrHigh = GPIO_D.idrLow; //Show on bargraph
	return GPIO_D.idrLow;
}


int read_DIL_single( int bit ) {
	char DIL = read_DIL();
	if (DIL & (1<<bit)) {
		return 1;
	} else {
		return 0;
	}
}