#include "sprite.h"
#include "gameobject.h"

#include "indoors2_black.xbm"
#include "indoors2_gray.xbm"
#include "indoors2_light.xbm"

sprite *indoors2Black;
sprite *indoors2Gray;
sprite *indoors2Light;

sprite tempIndoors2Black;
sprite tempIndoors2Light;
sprite tempIndoors2Gray;


GameObject indoors2Obj;
Image indoors2Image;
Image indoors2Images[1];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempIndoors2Light;
	load_sprite(pointer11, indoors2_light_bits, indoors2_black_width, indoors2_black_height);
	indoors2Light = pointer11;
	sprite *pointer12 = &tempIndoors2Gray;
	load_sprite(pointer12, indoors2_gray_bits, indoors2_black_width, indoors2_black_height);
	indoors2Gray = pointer12;
	sprite *pointer13 = &tempIndoors2Black;
	load_sprite(pointer13, indoors2_black_bits, indoors2_black_width, indoors2_black_height);
	indoors2Black = pointer13;	
	
}
	
void init_indoors2( GameObject *indoors2Obj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		indoors2Images[0] = indoors2Image;
		
		load_image(&indoors2Images[0], indoors2Black, indoors2Gray, indoors2Light);
	}
	
	indoors2Obj->images = indoors2Images;

	indoors2Obj->current_frame = 0;
	indoors2Obj->n_frames = 1;
	indoors2Obj->animation_speed = 1;
	indoors2Obj->animation_counter = 0;
}
