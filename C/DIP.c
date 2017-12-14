#include "sprite.h"
#include "gameobject.h"
#include "DIP.h"
#include "gpio.h"
#include "controls.h"

#include "witch1_black.xbm"
#include "witch1_gray.xbm"
#include "witch1_light.xbm"
#include "witch2_black.xbm"
#include "witch2_gray.xbm"
#include "witch2_light.xbm"
#include "witch3_black.xbm"
#include "witch3_gray.xbm"
#include "witch3_light.xbm"


sprite *DIP1Black;
sprite *DIP1Gray;
sprite *DIP1Light;
sprite *DIP2Black;
sprite *DIP2Gray;
sprite *DIP2Light;
sprite *DIP3Black;
sprite *DIP3Gray;
sprite *DIP3Light;

sprite tempDIPBlack;
sprite tempDIPLight;
sprite tempDIPGray;
sprite tempDIP2Black;
sprite tempDIP2Light;
sprite tempDIP2Gray;
sprite tempDIP3Black;
sprite tempDIP3Light;
sprite tempDIP3Gray;


GameObject DIPObj;
Image DIP1Image;
Image DIP2Image;
Image DIP3Image;
Image DIP4Image;
Image DIPImages[4];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempDIPLight;
	load_sprite(pointer11, witch1_light_bits, witch1_black_width, witch1_black_height);
	DIP1Light = pointer11;
	sprite *pointer12 = &tempDIPGray;
	load_sprite(pointer12, witch1_gray_bits, witch1_black_width, witch1_black_height);
	DIP1Gray = pointer12;
	sprite *pointer13 = &tempDIPBlack;
	load_sprite(pointer13, witch1_black_bits, witch1_black_width, witch1_black_height);
	DIP1Black = pointer13;	
	
	sprite *pointer14 = &tempDIP2Light;
	load_sprite(pointer14, witch2_light_bits, witch2_black_width, witch2_black_height);
	DIP2Light = pointer14;
	sprite *pointer15 = &tempDIP2Gray;
	load_sprite(pointer15, witch2_gray_bits, witch2_black_width, witch2_black_height);
	DIP2Gray = pointer15;
	sprite *pointer16 = &tempDIP2Black;
	load_sprite(pointer16, witch2_black_bits, witch2_black_width, witch2_black_height);
	DIP2Black = pointer16;
	
	
	sprite *finalPointer = &tempDIP3Light;
	load_sprite(finalPointer, witch3_light_bits, witch3_black_width, witch3_black_height);
	DIP3Light = finalPointer;
	sprite *pointer17 = &tempDIP3Gray;
	load_sprite(pointer17, witch3_gray_bits, witch3_black_width, witch3_black_height);
	DIP3Gray = pointer17;
	sprite *pointer18 = &tempDIP3Black;
	load_sprite(pointer18, witch3_black_bits, witch3_black_width, witch3_black_height);
	DIP3Black = pointer18;	
	
}
	
void init_DIP( GameObject *DIPObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		DIPImages[0] = DIP1Image;
		DIPImages[1] = DIP2Image;
		DIPImages[2] = DIP3Image;
		DIPImages[3] = DIP4Image;
		
		
		load_image(&DIPImages[0], DIP1Black, DIP1Light, DIP1Gray);
		load_image(&DIPImages[1], DIP2Black, DIP2Light, DIP2Gray);
		load_image(&DIPImages[2], DIP3Black, DIP3Light, DIP3Gray);
		load_image(&DIPImages[3], DIP2Black, DIP2Light, DIP2Gray);
		
	}
	
	DIPObj->images = DIPImages;

	DIPObj->current_frame = 0;
	DIPObj->n_frames = 4;
	DIPObj->animation_speed = 1;
	DIPObj->animation_counter = 0;
}

static int playerPositionX = 0;
static int playerPositionY = 0;
static int counter = 0;
static int direction = -1;
static int isRunning = 0;

void setPlayerPosition(int x, int y){
	playerPositionX = x;
	playerPositionY = y;
}

void resetDIP(void){
	playerPositionX = 0;
	playerPositionY = 0;
	counter = 0;
	direction = -1;
	isRunning = 0;
}

void DIPUpdate(GameObject *this) {
	gameObjectUpdate(this);
	counter++;
	
	if (!read_DIL_single(LIGHT_TRIGGER)){ // Only move if the light is off
		
		if (this->yPos >= playerPositionY){
			isRunning = 1;
		}
		else if ((playerPositionX + DIP_WIDTH >= this->xPos && playerPositionX <= this->xPos + DIP_WIDTH )) { // Move faster if player is below or on the same level
			isRunning = 1;
			if (RIGHT_POINT - playerPositionX > playerPositionX - LEFT_POINT){
				direction = 1;
			}
			else{
				direction = -1;
			}
		} 
		
		
		
		if (isRunning){
			this->xPos += direction*3;
		} else {
			this->xPos += (counter % 2)*direction;
		}
		
		if(this->xPos > RIGHT_POINT) {
			isRunning = 0;
			direction = -1;
		} else if(this->xPos < LEFT_POINT) {
			isRunning = 0;
			direction = 1;
		}
	}
}
