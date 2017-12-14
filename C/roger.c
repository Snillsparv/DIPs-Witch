#include "sprite.h"
#include "gameobject.h"

#include "roger_black.xbm"
#include "roger_gray.xbm"
#include "roger_light.xbm"

sprite *rogerBlack;
sprite *rogerGray;
sprite *rogerLight;

sprite tempRogerBlack;
sprite tempRogerLight;
sprite tempRogerGray;


GameObject rogerObj;
Image rogerImage;
Image rogerImages[1];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempRogerLight;
	load_sprite(pointer11, roger_light_bits, roger_black_width, roger_black_height);
	rogerLight = pointer11;
	sprite *pointer12 = &tempRogerGray;
	load_sprite(pointer12, roger_gray_bits, roger_black_width, roger_black_height);
	rogerGray = pointer12;
	sprite *pointer13 = &tempRogerBlack;
	load_sprite(pointer13, roger_black_bits, roger_black_width, roger_black_height);
	rogerBlack = pointer13;	
	
}
	
void init_roger( GameObject *rogerObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		rogerImages[0] = rogerImage;
		
		load_image(&rogerImages[0], rogerBlack, rogerGray, rogerLight);
	}
	
	rogerObj->images = rogerImages;

	rogerObj->current_frame = 0;
	rogerObj->n_frames = 1;
	rogerObj->animation_speed = 1;
	rogerObj->animation_counter = 0;
}
