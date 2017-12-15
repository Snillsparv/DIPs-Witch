#include "sprite.h"
#include "gameobject.h"

#include "dragon1_black.xbm"
#include "dragon1_gray.xbm"
#include "dragon1_light.xbm"
#include "dragon2_black.xbm"
#include "dragon2_gray.xbm"
#include "dragon2_light.xbm"
#include "dragon3_black.xbm"
#include "dragon3_gray.xbm"
#include "dragon3_light.xbm"


sprite *dragon1Black;
sprite *dragon1Gray;
sprite *dragon1Light;
sprite *dragon2Black;
sprite *dragon2Gray;
sprite *dragon2Light;
sprite *dragon3Black;
sprite *dragon3Gray;
sprite *dragon3Light;

sprite tempDragonBlack;
sprite tempDragonLight;
sprite tempDragonGray;
sprite tempDragon2Black;
sprite tempDragon2Light;
sprite tempDragon2Gray;
sprite tempDragon3Black;
sprite tempDragon3Light;
sprite tempDragon3Gray;


GameObject dragonObj;
Image dragon1Image;
Image dragon2Image;
Image dragon3Image;
Image dragon4Image;
Image dragonImages[4];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempDragonLight;
	load_sprite(pointer11, dragon1_light_bits, dragon1_black_width, dragon1_black_height);
	dragon1Light = pointer11;
	sprite *pointer12 = &tempDragonGray;
	load_sprite(pointer12, dragon1_gray_bits, dragon1_black_width, dragon1_black_height);
	dragon1Gray = pointer12;
	sprite *pointer13 = &tempDragonBlack;
	load_sprite(pointer13, dragon1_black_bits, dragon1_black_width, dragon1_black_height);
	dragon1Black = pointer13;	
	
	sprite *pointer14 = &tempDragon2Light;
	load_sprite(pointer14, dragon2_light_bits, dragon2_black_width, dragon2_black_height);
	dragon2Light = pointer14;
	sprite *pointer15 = &tempDragon2Gray;
	load_sprite(pointer15, dragon2_gray_bits, dragon2_black_width, dragon2_black_height);
	dragon2Gray = pointer15;
	sprite *pointer16 = &tempDragon2Black;
	load_sprite(pointer16, dragon2_black_bits, dragon2_black_width, dragon2_black_height);
	dragon2Black = pointer16;
	
	
	sprite *finalPointer = &tempDragon3Light;
	load_sprite(finalPointer, dragon3_light_bits, dragon3_black_width, dragon3_black_height);
	dragon3Light = finalPointer;
	sprite *pointer17 = &tempDragon3Gray;
	load_sprite(pointer17, dragon3_gray_bits, dragon3_black_width, dragon3_black_height);
	dragon3Gray = pointer17;
	sprite *pointer18 = &tempDragon3Black;
	load_sprite(pointer18, dragon3_black_bits, dragon3_black_width, dragon3_black_height);
	dragon3Black = pointer18;	
	
}
	
void init_dragon( GameObject *dragonObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		dragonImages[0] = dragon1Image;
		dragonImages[1] = dragon2Image;
		dragonImages[2] = dragon3Image;
		dragonImages[3] = dragon4Image;
		
		load_image(&dragonImages[0], dragon1Black, dragon1Gray, dragon1Light);
		load_image(&dragonImages[2], dragon2Black, dragon2Gray, dragon2Light);
		load_image(&dragonImages[1], dragon3Black, dragon3Gray, dragon3Light);
		load_image(&dragonImages[3], dragon3Black, dragon3Gray, dragon3Light);
			
	}
	
	dragonObj->images = dragonImages;

	dragonObj->current_frame = 0;
	dragonObj->n_frames = 4;
	dragonObj->animation_speed = 3;
	dragonObj->animation_counter = 0;
}
