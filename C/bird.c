#include "sprite.h"
#include "gameobject.h"

#include "bird1_black.xbm"
#include "bird1_gray.xbm"
#include "bird1_light.xbm"
#include "bird2_black.xbm"
#include "bird2_gray.xbm"
#include "bird2_light.xbm"
#include "bird3_black.xbm"
#include "bird3_gray.xbm"
#include "bird3_light.xbm"
#include "bird4_black.xbm"
#include "bird4_gray.xbm"
#include "bird4_light.xbm"
#include "bird5_black.xbm"
#include "bird5_gray.xbm"
#include "bird5_light.xbm"


sprite *bird1Black;
sprite *bird1Gray;
sprite *bird1Light;
sprite *bird2Black;
sprite *bird2Gray;
sprite *bird2Light;
sprite *bird3Black;
sprite *bird3Gray;
sprite *bird3Light;
sprite *bird4Black;
sprite *bird4Gray;
sprite *bird4Light;
sprite *bird5Black;
sprite *bird5Gray;
sprite *bird5Light;

sprite tempBirdBlack;
sprite tempBirdLight;
sprite tempBirdGray;
sprite tempBird2Black;
sprite tempBird2Light;
sprite tempBird2Gray;
sprite tempBird3Black;
sprite tempBird3Light;
sprite tempBird3Gray;
sprite tempBird4Black;
sprite tempBird4Light;
sprite tempBird4Gray;
sprite tempBird5Black;
sprite tempBird5Light;
sprite tempBird5Gray;


GameObject birdObj;
Image bird1Image;
Image bird2Image;
Image bird3Image;
Image bird4Image;
Image bird5Image;
Image bird6Image;
//Image bird7Image;
//Image bird8Image;
Image birdImages[6];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempBirdLight;
	load_sprite(pointer11, bird1_light_bits, bird1_black_width, bird1_black_height);
	bird1Light = pointer11;
	sprite *pointer12 = &tempBirdGray;
	load_sprite(pointer12, bird1_gray_bits, bird1_black_width, bird1_black_height);
	bird1Gray = pointer12;
	sprite *pointer13 = &tempBirdBlack;
	load_sprite(pointer13, bird1_black_bits, bird1_black_width, bird1_black_height);
	bird1Black = pointer13;	
	
	sprite *pointer14 = &tempBird2Light;
	load_sprite(pointer14, bird2_light_bits, bird2_black_width, bird2_black_height);
	bird2Light = pointer14;
	sprite *pointer15 = &tempBird2Gray;
	load_sprite(pointer15, bird2_gray_bits, bird2_black_width, bird2_black_height);
	bird2Gray = pointer15;
	sprite *pointer16 = &tempBird2Black;
	load_sprite(pointer16, bird2_black_bits, bird2_black_width, bird2_black_height);
	bird2Black = pointer16;
	
	
	sprite *finalPointer = &tempBird3Light;
	load_sprite(finalPointer, bird3_light_bits, bird3_black_width, bird3_black_height);
	bird3Light = finalPointer;
	sprite *pointer17 = &tempBird3Gray;
	load_sprite(pointer17, bird3_gray_bits, bird3_black_width, bird3_black_height);
	bird3Gray = pointer17;
	sprite *pointer18 = &tempBird3Black;
	load_sprite(pointer18, bird3_black_bits, bird3_black_width, bird3_black_height);
	bird3Black = pointer18;	
	
	sprite *pointer19 = &tempBird4Light;
	load_sprite(pointer19, bird4_light_bits, bird4_black_width, bird4_black_height);
	bird4Light = pointer19;
	sprite *pointer20 = &tempBird4Gray;
	load_sprite(pointer20, bird4_gray_bits, bird4_black_width, bird4_black_height);
	bird4Gray = pointer20;
	sprite *pointer21 = &tempBird4Black;
	load_sprite(pointer21, bird4_black_bits, bird4_black_width, bird4_black_height);
	bird4Black = pointer21;	
	
	sprite *pointer22 = &tempBird5Light;
	load_sprite(pointer22, bird5_light_bits, bird5_black_width, bird5_black_height);
	bird5Light = pointer22;
	sprite *pointer23 = &tempBird5Gray;
	load_sprite(pointer23, bird5_gray_bits, bird5_black_width, bird5_black_height);
	bird5Gray = pointer23;
	sprite *pointer24 = &tempBird5Black;
	load_sprite(pointer24, bird5_black_bits, bird5_black_width, bird5_black_height);
	bird5Black = pointer24;
}
	
void init_bird( GameObject *birdObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		birdImages[0] = bird1Image;
		birdImages[1] = bird2Image;
		birdImages[2] = bird3Image;
		birdImages[3] = bird4Image;
		birdImages[4] = bird5Image;
		birdImages[5] = bird6Image;
//		birdImages[6] = bird7Image;
		//birdImages[7] = bird8Image;
		
		load_image(&birdImages[0], bird1Black, bird1Gray, bird1Light);
		load_image(&birdImages[1], bird2Black, bird2Gray, bird2Light);
		load_image(&birdImages[2], bird3Black, bird3Gray, bird3Light);
		load_image(&birdImages[3], bird4Black, bird4Gray, bird4Light);
		load_image(&birdImages[4], bird5Black, bird5Gray, bird5Light);
		
		//load_image(&birdImages[7], bird2Black, bird2Gray, bird2Light);
		load_image(&birdImages[5], bird3Black, bird3Gray, bird3Light);
		//load_image(&birdImages[5], bird4Black, bird4Gray, bird4Light);
	}
	
	birdObj->images = birdImages;

	birdObj->current_frame = 0;
	birdObj->n_frames = 6;
	birdObj->animation_speed = 1;
	birdObj->animation_counter = 0;
}
