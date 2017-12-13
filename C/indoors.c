#include "sprite.h"
#include "gameobject.h"

#include "indoors_black.xbm"
#include "indoors_gray.xbm"
#include "indoors_light.xbm"

sprite *indoorsBlack;
sprite *indoorsGray;
sprite *indoorsLight;

sprite tempIndoorsBlack;
sprite tempIndoorsLight;
sprite tempIndoorsGray;


GameObject indoorsObj;
Image indoorsImage;
Image indoorsImages[1];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempIndoorsLight;
	load_sprite(pointer11, indoors_light_bits, indoors_black_width, indoors_black_height);
	indoorsLight = pointer11;
	sprite *pointer12 = &tempIndoorsGray;
	load_sprite(pointer12, indoors_gray_bits, indoors_black_width, indoors_black_height);
	indoorsGray = pointer12;
	sprite *pointer13 = &tempIndoorsBlack;
	load_sprite(pointer13, indoors_black_bits, indoors_black_width, indoors_black_height);
	indoorsBlack = pointer13;	
	
}
	
void init_indoors( GameObject *indoorsObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		indoorsImages[0] = indoorsImage;
		
		load_image(&indoorsImages[0], indoorsBlack, indoorsGray, indoorsLight);
	}
	
	indoorsObj->images = indoorsImages;

	indoorsObj->current_frame = 0;
	indoorsObj->n_frames = 1;
	indoorsObj->animation_speed = 1;
	indoorsObj->animation_counter = 0;
}
