#include "slow_text.h"
#include "ascii_display.h"

void display(SlowText *this, int length_of_row1) {
	int limit1 = this->counter / this->speed;
	int limit2 = this->counter / this->speed - length_of_row1;
	ascii_write_part(this->row1, this->row2, limit1, limit2);
	
	this->counter++;
}

void init_slow_text(SlowText *obj, char *row1, char *row2, int speed) {
	obj->row1 = row1;
	obj->row2 = row2;
	obj->speed = speed;
	obj->counter = 0;
	obj->display = display;
}