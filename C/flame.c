#include "sprite.h"
#include "gameobject.h"

#include "flame1_black.xbm"
#include "flame1_gray.xbm"
#include "flame1_light.xbm"
#include "flame2_black.xbm"
#include "flame2_gray.xbm"
#include "flame2_light.xbm"
#include "flame3_black.xbm"
#include "flame3_gray.xbm"
#include "flame3_light.xbm"
#include "flame4_black.xbm"
#include "flame4_gray.xbm"
#include "flame4_light.xbm"

sprite *flame1Black;
sprite *flame1Gray;
sprite *flame1Light;
sprite *flame2Black;
sprite *flame2Gray;
sprite *flame2Light;
sprite *flame3Black;
sprite *flame3Gray;
sprite *flame3Light;
sprite *flame4Black;
sprite *flame4Gray;
sprite *flame4Light;

sprite tempFlameBlack;
sprite tempFlameLight;
sprite tempFlameGray;
sprite tempFlame2Black;
sprite tempFlame2Light;
sprite tempFlame2Gray;
sprite tempFlame3Black;
sprite tempFlame3Light;
sprite tempFlame3Gray;
sprite tempFlame4Black;
sprite tempFlame4Light;
sprite tempFlame4Gray;


GameObject flameObj;
Image flame1Image;
Image flame2Image;
Image flame3Image;
Image flame4Image;
Image flameImages[4];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempFlameLight;
	load_sprite(pointer11, flame1_light_bits, flame1_black_width, flame1_black_height);
	flame1Light = pointer11;
	sprite *pointer12 = &tempFlameGray;
	load_sprite(pointer12, flame1_gray_bits, flame1_black_width, flame1_black_height);
	flame1Gray = pointer12;
	sprite *pointer13 = &tempFlameBlack;
	load_sprite(pointer13, flame1_black_bits, flame1_black_width, flame1_black_height);
	flame1Black = pointer13;	
	
	sprite *pointer14 = &tempFlame2Light;
	load_sprite(pointer14, flame2_light_bits, flame2_black_width, flame2_black_height);
	flame2Light = pointer14;
	sprite *pointer15 = &tempFlame2Gray;
	load_sprite(pointer15, flame2_gray_bits, flame2_black_width, flame2_black_height);
	flame2Gray = pointer15;
	sprite *pointer16 = &tempFlame2Black;
	load_sprite(pointer16, flame2_black_bits, flame2_black_width, flame2_black_height);
	flame2Black = pointer16;
	
	
	sprite *finalPointer = &tempFlame3Light;
	load_sprite(finalPointer, flame3_light_bits, flame3_black_width, flame3_black_height);
	flame3Light = finalPointer;
	sprite *pointer17 = &tempFlame3Gray;
	load_sprite(pointer17, flame3_gray_bits, flame3_black_width, flame3_black_height);
	flame3Gray = pointer17;
	sprite *pointer18 = &tempFlame3Black;
	load_sprite(pointer18, flame3_black_bits, flame3_black_width, flame3_black_height);
	flame3Black = pointer18;	
	
	sprite *pointer19 = &tempFlame4Light;
	load_sprite(pointer19, flame4_light_bits, flame4_black_width, flame4_black_height);
	flame4Light = pointer19;
	sprite *pointer20 = &tempFlame4Gray;
	load_sprite(pointer20, flame4_gray_bits, flame4_black_width, flame4_black_height);
	flame4Gray = pointer20;
	sprite *pointer21 = &tempFlame4Black;
	load_sprite(pointer21, flame4_black_bits, flame4_black_width, flame4_black_height);
	flame4Black = pointer21;	
	
}
	
void init_flame( GameObject *flameObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		flameImages[0] = flame1Image;
		flameImages[1] = flame2Image;
		flameImages[2] = flame3Image;
		flameImages[3] = flame4Image;
		
		load_image(&flameImages[0], flame1Black, flame1Gray, flame1Light);
		load_image(&flameImages[1], flame2Black, flame2Gray, flame2Light);
		load_image(&flameImages[2], flame3Black, flame3Gray, flame3Light);
		load_image(&flameImages[3], flame4Black, flame4Gray, flame4Light);
}
	
	flameObj->images = flameImages;

	flameObj->current_frame = 0;
	flameObj->n_frames = 4;
	flameObj->animation_speed = 1;
	flameObj->animation_counter = 0;
}
