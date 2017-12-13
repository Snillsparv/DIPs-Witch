#include "sprite.h"
#include "gameobject.h"

#include "trophy_black.xbm"
#include "trophy_gray.xbm"
#include "trophy_light.xbm"

sprite *trophyBlack;
sprite *trophyGray;
sprite *trophyLight;

sprite tempTrophyBlack;
sprite tempTrophyLight;
sprite tempTrophyGray;


GameObject trophyObj;
Image trophyImage;
Image trophyImages[1];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempTrophyLight;
	load_sprite(pointer11, trophy_light_bits, trophy_black_width, trophy_black_height);
	trophyLight = pointer11;
	sprite *pointer12 = &tempTrophyGray;
	load_sprite(pointer12, trophy_gray_bits, trophy_black_width, trophy_black_height);
	trophyGray = pointer12;
	sprite *pointer13 = &tempTrophyBlack;
	load_sprite(pointer13, trophy_black_bits, trophy_black_width, trophy_black_height);
	trophyBlack = pointer13;	
	
}
	
void init_trophy( GameObject *trophyObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		trophyImages[0] = trophyImage;
		
		load_image(&trophyImages[0], trophyBlack, trophyGray, trophyLight);
	}
	
	trophyObj->images = trophyImages;

	trophyObj->current_frame = 0;
	trophyObj->n_frames = 1;
	trophyObj->animation_speed = 1;
	trophyObj->animation_counter = 0;
}
