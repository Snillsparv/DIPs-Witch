#include "gpio.h"
#include "controls.h"
#include "gameobject.h"
#include "player.h"

void playerUpdate(GameObject *this) {
	this->animation_counter++;
	if (this->animation_counter == this->animation_speed) {
		this->animation_counter = 0;
		this->current_frame = (this->current_frame + 1) % this->n_frames;
	}
	
	static lastRightValue = 0;
	static lastLeftValue = 0; 
	static speed = 0;
	
	if (!lastRightValue && read_DIL_single(RIGHT_TRIGGER)){
		speed += SPEED_ADD;
	}
	
	if (!lastLeftValue && read_DIL_single(LEFT_TRIGGER)){
		speed -= SPEED_ADD;
	}
	
	if (this->xPos + speed > LIMIT_RIGHT || this->xPos + speed < LIMIT_LEFT){
		speed *= -1;	
	}
	
	this->xPos += speed;	
	
	if (speed > 0){
		speed--;
	}
	else if (speed < 0){
		speed++;
	}
	
	lastRightValue = read_DIL_single(RIGHT_TRIGGER);
	lastLeftValue = read_DIL_single(LEFT_TRIGGER);
	
}