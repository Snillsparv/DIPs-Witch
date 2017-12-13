#include "sprite.h"
#include "gameobject.h"

#include "witch1_black.xbm"
#include "witch1_gray.xbm"
#include "witch1_light.xbm"
#include "witch2_black.xbm"
#include "witch2_gray.xbm"
#include "witch2_light.xbm"
#include "witch3_black.xbm"
#include "witch3_gray.xbm"
#include "witch3_light.xbm"

sprite *witch1Black;
sprite *witch1Gray;
sprite *witch1Light;
sprite *witch2Black;
sprite *witch2Gray;
sprite *witch2Light;
sprite *witch3Black;
sprite *witch3Gray;
sprite *witch3Light;

sprite tempWitchBlack;
sprite tempWitchLight;
sprite tempWitchGray;
sprite tempWitch2Black;
sprite tempWitch2Light;
sprite tempWitch2Gray;
sprite tempWitch3Black;
sprite tempWitch3Light;
sprite tempWitch3Gray;


GameObject witchObj;
Image witch1Image;
Image witch2Image;
Image witch3Image;
Image witch4Image;
Image witchImages[4];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempWitchLight;
	load_sprite(pointer11, witch1_light_bits, witch1_black_width, witch1_black_height);
	witch1Light = pointer11;
	sprite *pointer12 = &tempWitchGray;
	load_sprite(pointer12, witch1_gray_bits, witch1_black_width, witch1_black_height);
	witch1Gray = pointer12;
	sprite *pointer13 = &tempWitchBlack;
	load_sprite(pointer13, witch1_black_bits, witch1_black_width, witch1_black_height);
	witch1Black = pointer13;	
	
	sprite *pointer14 = &tempWitch2Light;
	load_sprite(pointer14, witch2_light_bits, witch2_black_width, witch2_black_height);
	witch2Light = pointer14;
	sprite *pointer15 = &tempWitch2Gray;
	load_sprite(pointer15, witch2_gray_bits, witch2_black_width, witch2_black_height);
	witch2Gray = pointer15;
	sprite *pointer16 = &tempWitch2Black;
	load_sprite(pointer16, witch2_black_bits, witch2_black_width, witch2_black_height);
	witch2Black = pointer16;
	
	
	sprite *finalPointer = &tempWitch3Light;
	load_sprite(finalPointer, witch3_light_bits, witch3_black_width, witch3_black_height);
	witch3Light = finalPointer;
	sprite *pointer17 = &tempWitch3Gray;
	load_sprite(pointer17, witch3_gray_bits, witch3_black_width, witch3_black_height);
	witch3Gray = pointer17;
	sprite *pointer18 = &tempWitch3Black;
	load_sprite(pointer18, witch3_black_bits, witch3_black_width, witch3_black_height);
	witch3Black = pointer18;	
	
}
	
void init_witch( GameObject *witchObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		witchImages[0] = witch1Image;
		witchImages[1] = witch2Image;
		witchImages[2] = witch3Image;
		witchImages[3] = witch4Image;
		
		
		load_image(&witchImages[0], witch1Black, witch1Gray, witch1Light);
		load_image(&witchImages[1], witch2Black, witch2Gray, witch2Light);
		load_image(&witchImages[2], witch3Black, witch3Gray, witch3Light);
		load_image(&witchImages[3], witch2Black, witch2Gray, witch2Light);
		
	}
	
	witchObj->images = witchImages;

	witchObj->current_frame = 0;
	witchObj->n_frames = 4;
	witchObj->animation_speed = 1;
	witchObj->animation_counter = 0;
}
