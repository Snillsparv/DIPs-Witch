#include "sprite.h"
#include "gameobject.h"

#include "boom1_black.xbm"
#include "boom1_gray.xbm"
#include "boom1_light.xbm"
#include "boom2_black.xbm"
#include "boom2_gray.xbm"
#include "boom2_light.xbm"
#include "boom3_black.xbm"
#include "boom3_gray.xbm"
#include "boom3_light.xbm"
#include "boom4_black.xbm"
#include "boom4_gray.xbm"
#include "boom4_light.xbm"
#include "boom5_black.xbm"
#include "boom5_gray.xbm"
#include "boom5_light.xbm"
#include "boom6_black.xbm"
#include "boom6_gray.xbm"
#include "boom6_light.xbm"


sprite *boom1Black;
sprite *boom1Gray;
sprite *boom1Light;
sprite *boom2Black;
sprite *boom2Gray;
sprite *boom2Light;
sprite *boom3Black;
sprite *boom3Gray;
sprite *boom3Light;
sprite *boom4Black;
sprite *boom4Gray;
sprite *boom4Light;
sprite *boom5Black;
sprite *boom5Gray;
sprite *boom5Light;
sprite *boom6Black;
sprite *boom6Gray;
sprite *boom6Light;

sprite tempBoomBlack;
sprite tempBoomLight;
sprite tempBoomGray;
sprite tempBoom2Black;
sprite tempBoom2Light;
sprite tempBoom2Gray;
sprite tempBoom3Black;
sprite tempBoom3Light;
sprite tempBoom3Gray;
sprite tempBoom4Black;
sprite tempBoom4Light;
sprite tempBoom4Gray;
sprite tempBoom5Black;
sprite tempBoom5Light;
sprite tempBoom5Gray;
sprite tempBoom6Black;
sprite tempBoom6Light;
sprite tempBoom6Gray;


GameObject boomObj;
Image boom1Image;
Image boom2Image;
Image boom3Image;
Image boom4Image;
Image boom5Image;
Image boom6Image;
Image boom7Image;
Image boom8Image;
Image boom9Image;
Image boom10Image;
Image boom11Image;
Image boom12Image;
Image boom13Image;
Image boom14Image;
Image boom15Image;
Image boomImages[15];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempBoomLight;
	load_sprite(pointer11, boom1_light_bits, boom1_black_width, boom1_black_height);
	boom1Light = pointer11;
	sprite *pointer12 = &tempBoomGray;
	load_sprite(pointer12, boom1_gray_bits, boom1_black_width, boom1_black_height);
	boom1Gray = pointer12;
	sprite *pointer13 = &tempBoomBlack;
	load_sprite(pointer13, boom1_black_bits, boom1_black_width, boom1_black_height);
	boom1Black = pointer13;	
	
	sprite *pointer14 = &tempBoom2Light;
	load_sprite(pointer14, boom2_light_bits, boom2_black_width, boom2_black_height);
	boom2Light = pointer14;
	sprite *pointer15 = &tempBoom2Gray;
	load_sprite(pointer15, boom2_gray_bits, boom2_black_width, boom2_black_height);
	boom2Gray = pointer15;
	sprite *pointer16 = &tempBoom2Black;
	load_sprite(pointer16, boom2_black_bits, boom2_black_width, boom2_black_height);
	boom2Black = pointer16;
	
	
	sprite *finalPointer = &tempBoom3Light;
	load_sprite(finalPointer, boom3_light_bits, boom3_black_width, boom3_black_height);
	boom3Light = finalPointer;
	sprite *pointer17 = &tempBoom3Gray;
	load_sprite(pointer17, boom3_gray_bits, boom3_black_width, boom3_black_height);
	boom3Gray = pointer17;
	sprite *pointer18 = &tempBoom3Black;
	load_sprite(pointer18, boom3_black_bits, boom3_black_width, boom3_black_height);
	boom3Black = pointer18;	
	
	sprite *pointer19 = &tempBoom4Light;
	load_sprite(pointer19, boom4_light_bits, boom4_black_width, boom4_black_height);
	boom4Light = pointer19;
	sprite *pointer20 = &tempBoom4Gray;
	load_sprite(pointer20, boom4_gray_bits, boom4_black_width, boom4_black_height);
	boom4Gray = pointer20;
	sprite *pointer21 = &tempBoom4Black;
	load_sprite(pointer21, boom4_black_bits, boom4_black_width, boom4_black_height);
	boom4Black = pointer21;	
	
	sprite *pointer22 = &tempBoom5Light;
	load_sprite(pointer22, boom5_light_bits, boom5_black_width, boom5_black_height);
	boom5Light = pointer22;
	sprite *pointer23 = &tempBoom5Gray;
	load_sprite(pointer23, boom5_gray_bits, boom5_black_width, boom5_black_height);
	boom5Gray = pointer23;
	sprite *pointer24 = &tempBoom5Black;
	load_sprite(pointer24, boom5_black_bits, boom5_black_width, boom5_black_height);
	boom5Black = pointer24;

	sprite *pointer25 = &tempBoom6Light;
	load_sprite(pointer25, boom6_light_bits, boom6_black_width, boom6_black_height);
	boom6Light = pointer25;
	sprite *pointer26 = &tempBoom6Gray;
	load_sprite(pointer26, boom6_gray_bits, boom6_black_width, boom6_black_height);
	boom6Gray = pointer26;
	sprite *pointer27 = &tempBoom6Black;
	load_sprite(pointer27, boom6_black_bits, boom6_black_width, boom6_black_height);
	boom6Black = pointer27;
}
	
void init_boom( GameObject *boomObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		boomImages[0] = boom1Image;
		boomImages[1] = boom2Image;
		boomImages[2] = boom3Image;
		boomImages[3] = boom4Image;
		boomImages[4] = boom5Image;
		boomImages[5] = boom6Image;
		boomImages[6] = boom7Image;
		boomImages[7] = boom8Image;
		boomImages[8] = boom9Image;
		boomImages[9] = boom10Image;
		boomImages[10] = boom11Image;
		boomImages[11] = boom12Image;
		boomImages[12] = boom13Image;
		boomImages[13] = boom14Image;
		boomImages[14] = boom15Image;
		
		load_image(&boomImages[0], boom1Black, boom1Gray, boom1Light);
		load_image(&boomImages[1], boom2Black, boom2Gray, boom2Light);
		load_image(&boomImages[2], boom3Black, boom3Gray, boom3Light);
		load_image(&boomImages[3], boom4Black, boom4Gray, boom4Light);
		load_image(&boomImages[4], boom5Black, boom5Gray, boom5Light);
		load_image(&boomImages[5], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[6], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[7], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[8], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[9], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[10], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[11], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[12], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[13], boom6Black, boom6Gray, boom6Light);
		load_image(&boomImages[14], boom6Black, boom6Gray, boom6Light);
	}
	
	boomObj->images = boomImages;

	boomObj->current_frame = 0;
	boomObj->n_frames = 15;
	boomObj->animation_speed = 1;
	boomObj->animation_counter = 0;
}
