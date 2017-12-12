#include "sprite.h"
#include "gameobject.h"

#include "fire_black_2.xbm"
#include "fire1_gray.xbm"
#include "fire1_light.xbm"
#include "fire2_gray.xbm"
#include "fire2_light.xbm"
#include "fire3_gray.xbm"
#include "fire3_light.xbm"
#include "fire4_gray.xbm"
#include "fire4_light.xbm"
#include "fire5_gray.xbm"
#include "fire5_light.xbm"


sprite *fireBlack;
sprite *fire1Gray;
sprite *fire1Light;
sprite *fire2Gray;
sprite *fire2Light;
sprite *fire3Gray;
sprite *fire3Light;
sprite *fire4Gray;
sprite *fire4Light;
sprite *fire5Gray;
sprite *fire5Light;

sprite tempFireBlack;
sprite tempFire1Gray;
sprite tempFire1Light;
sprite tempFire2Gray;
sprite tempFire2Light;
sprite tempFire3Gray;
sprite tempFire3Light;
sprite tempFire4Gray;
sprite tempFire4Light;
sprite tempFire5Gray;
sprite tempFire5Light;


GameObject fireObj;
Image fire1Image;
Image fire2Image;
Image fire3Image;
Image fire4Image;
Image fire5Image;
Image fireImages[5];
static void initSprites( void ) {	
	sprite *pointer0 = &tempFireBlack;
	load_sprite(pointer0, fire_black_2_bits, fire1_gray_width, fire1_gray_height);
	fireBlack = pointer0;
	
	sprite *pointer1 = &tempFire1Gray;
	load_sprite(pointer1, fire1_gray_bits, fire1_gray_width, fire1_gray_height);
	fire1Gray = pointer1;

	sprite *pointer2 = &tempFire1Light;
	load_sprite(pointer2, fire1_light_bits, fire1_gray_width, fire1_gray_height);
	fire1Light = pointer2;

	sprite *pointer3 = &tempFire2Gray;
	load_sprite(pointer3, fire2_gray_bits, fire1_gray_width, fire1_gray_height);
	fire2Gray = pointer3;

	sprite *pointer4 = &tempFire2Light;
	load_sprite(pointer4, fire2_light_bits, fire1_gray_width, fire1_gray_height);
	fire2Light = pointer4;

	sprite *pointer5 = &tempFire3Gray;
	load_sprite(pointer5, fire3_gray_bits, fire1_gray_width, fire1_gray_height);
	fire3Gray = pointer5;

	sprite *pointer6 = &tempFire3Light;
	load_sprite(pointer6, fire3_light_bits, fire1_gray_width, fire1_gray_height);
	fire3Light = pointer6;

	sprite *pointer7 = &tempFire4Gray;
	load_sprite(pointer7, fire4_gray_bits, fire1_gray_width, fire1_gray_height);
	fire4Gray = pointer7;

	sprite *pointer8 = &tempFire4Light;
	load_sprite(pointer8, fire4_light_bits, fire1_gray_width, fire1_gray_height);
	fire4Light = pointer8;

	sprite *pointer9 = &tempFire5Gray;
	load_sprite(pointer9, fire5_gray_bits, fire1_gray_width, fire1_gray_height);
	fire5Gray = pointer9;

	sprite *pointer10 = &tempFire5Light;
	load_sprite(pointer10, fire5_light_bits, fire1_gray_width, fire1_gray_height);
	fire5Light = pointer10;
}
	
void init_fire( GameObject *fireObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		fireImages[0] = fire1Image;
		fireImages[1] = fire2Image;
		fireImages[2] = fire3Image;
		fireImages[3] = fire4Image;
		fireImages[4] = fire5Image;
		
		load_image(&fireImages[0], fireBlack, fire1Gray, fire1Light);
		load_image(&fireImages[1], fireBlack, fire2Gray, fire2Light);
		load_image(&fireImages[2], fireBlack, fire3Gray, fire3Light);
		load_image(&fireImages[3], fireBlack, fire4Gray, fire4Light);
		load_image(&fireImages[4], fireBlack, fire5Gray, fire5Light);
	}
	
	fireObj->images = fireImages;

	fireObj->current_frame = 0;
	fireObj->n_frames = 5;
	fireObj->animation_speed = 1;
	fireObj->animation_counter = 0;
}

/*
Image monsterImage;
Image monsterImages[] = {monsterImage};
monsterObj.image = monsterImages;
load_image(&monsterObj.image[0], monster, monsterGray, monsterLight);
monsterObj.xPos = 30;
monsterObj.yPos = 4;
monsterObj.current_frame = 0;*/