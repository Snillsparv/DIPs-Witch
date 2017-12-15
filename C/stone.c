#include "sprite.h"
#include "gameobject.h"

#include "stone_black.xbm"
#include "stone_gray.xbm"
#include "stone_light.xbm"

#include "gpio.h"
#include "controls.h"

sprite *stoneBlack;
sprite *stoneGray;
sprite *stoneLight;

sprite tempStoneBlack;
sprite tempStoneLight;
sprite tempStoneGray;


GameObject stoneObj;
Image stoneImage;
Image stoneImages[1];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempStoneLight;
	load_sprite(pointer11, stone_light_bits, stone_black_width, stone_black_height);
	stoneLight = pointer11;
	sprite *pointer12 = &tempStoneGray;
	load_sprite(pointer12, stone_gray_bits, stone_black_width, stone_black_height);
	stoneGray = pointer12;
	sprite *pointer13 = &tempStoneBlack;
	load_sprite(pointer13, stone_black_bits, stone_black_width, stone_black_height);
	stoneBlack = pointer13;	
	
}
	
void init_stone( GameObject *stoneObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		stoneImages[0] = stoneImage;
		
		load_image(&stoneImages[0], stoneBlack, stoneGray, stoneLight);
	}
	
	stoneObj->images = stoneImages;

	stoneObj->current_frame = 0;
	stoneObj->n_frames = 1;
	stoneObj->animation_speed = 1;
	stoneObj->animation_counter = 0;
}

int stone_fall_1 = 0;
int stone_speed = 0;
int stone_bounces = 3;
int stone_gravity = 1;
int stone_stoneCount = 0;

void reset_Stone( void ) {
	 stone_fall_1 = 0;
	 stone_speed = 0;
	 stone_bounces = 3;
	 stone_gravity = 1;
	 stone_stoneCount = 0;
}


void stoneUpdate( GameObject *this ) {
	if(!stone_fall_1 && read_DIL_single(STONE_TRIGGER)){
		stone_fall_1 = 1;
	}
		
	stone_stoneCount++;
	if(stone_fall_1) {
		stone_speed += stone_gravity * (stone_stoneCount % 2);
		
		this->yPos += stone_speed;
		if(stone_bounces && this->yPos > 53-23) {
			stone_speed = -(2 * stone_bounces);
			stone_bounces--;
		}
	}
}
