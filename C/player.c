#include "gpio.h"
#include "controls.h"
#include "gameobject.h"
#include "player.h"

void playerUpdate(GameObject *this) {
	
	// Animate
	this->animation_counter++;
	if (this->animation_counter == this->animation_speed) {
		this->animation_counter = 0;
		this->current_frame = (this->current_frame + 1) % this->n_frames;
	}
	
	// Variables
	static lastJumpValue = 0;
	static lastRightValue = 0;
	static lastLeftValue = 0; 
	static xSpeed = 0;
	static ySpeed = 0;
	
	// Y position changes
	
	if (lastJumpValue != read_DIL_single(JUMP_TRIGGER) && (this->yPos == LIMIT_DOWN || this->yPos == PLATFORM_Y - PLAYER_HEIGHT)){
		ySpeed = -(SPEED_ADD_Y);
	}
	
	if (this->yPos + ySpeed > LIMIT_DOWN){
		this->yPos = LIMIT_DOWN;
		ySpeed = 0;
	}
	else if (this->yPos + ySpeed > PLATFORM_Y - PLAYER_HEIGHT && this->yPos + ySpeed < PLATFORM_Y - PLAYER_HEIGHT + SPEED_ADD_Y){
		this->yPos = PLATFORM_Y - PLAYER_HEIGHT;
		ySpeed = 0;
	}
	else{
		this->yPos+=ySpeed;
		ySpeed++;
	}
	
	
	
	// X position changes
	
	if (!lastRightValue && read_DIL_single(RIGHT_TRIGGER)){
		xSpeed += SPEED_ADD_X;
	}
	
	if (!lastLeftValue && read_DIL_single(LEFT_TRIGGER)){
		xSpeed -= SPEED_ADD_X;
	}
	
	if (this->xPos + xSpeed > LIMIT_RIGHT || this->xPos + xSpeed < LIMIT_LEFT){
		xSpeed *= -1;	
	}
	
	this->xPos += xSpeed;	
	
	if (xSpeed > 0){
		xSpeed--;
	}
	else if (xSpeed < 0){
		xSpeed++;
	}
	
	// Prepare values
	lastRightValue = read_DIL_single(RIGHT_TRIGGER);
	lastLeftValue = read_DIL_single(LEFT_TRIGGER);
	lastJumpValue = read_DIL_single(JUMP_TRIGGER);
	
}