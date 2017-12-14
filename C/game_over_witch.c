#include "sprite.h"
#include "gameobject.h"

#include "game_over_witch1_black.xbm"
#include "game_over_witch1_gray.xbm"
#include "game_over_witch1_light.xbm"
#include "game_over_witch2_black.xbm"
#include "game_over_witch2_gray.xbm"
#include "game_over_witch2_light.xbm"
#include "game_over_witch3_black.xbm"
#include "game_over_witch3_gray.xbm"
#include "game_over_witch3_light.xbm"
#include "game_over_witch4_black.xbm"
#include "game_over_witch4_gray.xbm"
#include "game_over_witch4_light.xbm"
#include "game_over_witch5_black.xbm"
#include "game_over_witch5_gray.xbm"
#include "game_over_witch5_light.xbm"
#include "game_over_witch6_black.xbm"
#include "game_over_witch6_gray.xbm"
#include "game_over_witch6_light.xbm"
/*#include "game_over_witch7_black.xbm"
#include "game_over_witch7_gray.xbm"
#include "game_over_witch7_light.xbm"
#include "game_over_witch8_black.xbm"
#include "game_over_witch8_gray.xbm"
#include "game_over_witch8_light.xbm"
#include "game_over_witch9_black.xbm"
#include "game_over_witch9_gray.xbm"
#include "game_over_witch9_light.xbm"
#include "game_over_witch10_black.xbm"
#include "game_over_witch10_gray.xbm"
#include "game_over_witch10_light.xbm"
#include "game_over_witch11_black.xbm"
#include "game_over_witch11_gray.xbm"
#include "game_over_witch11_light.xbm"
#include "game_over_witch12_black.xbm"
#include "game_over_witch12_gray.xbm"
#include "game_over_witch12_light.xbm"*/


sprite *game_over_witch1Black;
sprite *game_over_witch1Gray;
sprite *game_over_witch1Light;
sprite *game_over_witch2Black;
sprite *game_over_witch2Gray;
sprite *game_over_witch2Light;
sprite *game_over_witch3Black;
sprite *game_over_witch3Gray;
sprite *game_over_witch3Light;
sprite *game_over_witch4Black;
sprite *game_over_witch4Gray;
sprite *game_over_witch4Light;
sprite *game_over_witch5Black;
sprite *game_over_witch5Gray;
sprite *game_over_witch5Light;
sprite *game_over_witch6Black;
sprite *game_over_witch6Gray;
sprite *game_over_witch6Light;
/*sprite *game_over_witch7Black;
sprite *game_over_witch7Gray;
sprite *game_over_witch7Light;
sprite *game_over_witch8Black;
sprite *game_over_witch8Gray;
sprite *game_over_witch8Light;
sprite *game_over_witch9Black;
sprite *game_over_witch9Gray;
sprite *game_over_witch9Light;
sprite *game_over_witch10Black;
sprite *game_over_witch10Gray;
sprite *game_over_witch10Light;
sprite *game_over_witch11Black;
sprite *game_over_witch11Gray;
sprite *game_over_witch11Light;
sprite *game_over_witch12Black;
sprite *game_over_witch12Gray;
sprite *game_over_witch12Light;*/

sprite tempgame_over_witchBlack;
sprite tempgame_over_witchLight;
sprite tempgame_over_witchGray;
sprite tempgame_over_witch2Black;
sprite tempgame_over_witch2Light;
sprite tempgame_over_witch2Gray;
sprite tempgame_over_witch3Black;
sprite tempgame_over_witch3Light;
sprite tempgame_over_witch3Gray;
sprite tempgame_over_witch4Black;
sprite tempgame_over_witch4Light;
sprite tempgame_over_witch4Gray;
sprite tempgame_over_witch5Black;
sprite tempgame_over_witch5Light;
sprite tempgame_over_witch5Gray;
sprite tempgame_over_witch6Black;
sprite tempgame_over_witch6Light;
sprite tempgame_over_witch6Gray;
/*sprite tempgame_over_witch7Black;
sprite tempgame_over_witch7Light;
sprite tempgame_over_witch7Gray;
sprite tempgame_over_witch8Black;
sprite tempgame_over_witch8Light;
sprite tempgame_over_witch8Gray;
sprite tempgame_over_witch9Black;
sprite tempgame_over_witch9Light;
sprite tempgame_over_witch9Gray;
sprite tempgame_over_witch10Black;
sprite tempgame_over_witch10Light;
sprite tempgame_over_witch10Gray;
sprite tempgame_over_witch11Black;
sprite tempgame_over_witch11Light;
sprite tempgame_over_witch11Gray;
sprite tempgame_over_witch12Black;
sprite tempgame_over_witch12Light;
sprite tempgame_over_witch12Gray;*/


GameObject game_over_witchObj;
Image game_over_witch1Image;
Image game_over_witch2Image;
Image game_over_witch3Image;
Image game_over_witch4Image;
Image game_over_witch5Image;
Image game_over_witch6Image;
/*Image game_over_witch7Image;
Image game_over_witch8Image;
Image game_over_witch9Image;
Image game_over_witch10Image;
Image game_over_witch11Image;
Image game_over_witch12Image;*/
Image game_over_witchImages[6];
static void initSprites( void ) {	
	
	sprite *pointer11 = &tempgame_over_witchLight;
	load_sprite(pointer11, game_over_witch1_light_bits, game_over_witch1_black_width, game_over_witch1_black_height);
	game_over_witch1Light = pointer11;
	sprite *pointer12 = &tempgame_over_witchGray;
	load_sprite(pointer12, game_over_witch1_gray_bits, game_over_witch1_black_width, game_over_witch1_black_height);
	game_over_witch1Gray = pointer12;
	sprite *pointer13 = &tempgame_over_witchBlack;
	load_sprite(pointer13, game_over_witch1_black_bits, game_over_witch1_black_width, game_over_witch1_black_height);
	game_over_witch1Black = pointer13;	
	
	sprite *pointer14 = &tempgame_over_witch2Light;
	load_sprite(pointer14, game_over_witch2_light_bits, game_over_witch2_black_width, game_over_witch2_black_height);
	game_over_witch2Light = pointer14;
	sprite *pointer15 = &tempgame_over_witch2Gray;
	load_sprite(pointer15, game_over_witch2_gray_bits, game_over_witch2_black_width, game_over_witch2_black_height);
	game_over_witch2Gray = pointer15;
	sprite *pointer16 = &tempgame_over_witch2Black;
	load_sprite(pointer16, game_over_witch2_black_bits, game_over_witch2_black_width, game_over_witch2_black_height);
	game_over_witch2Black = pointer16;
	
	
	sprite *finalPointer = &tempgame_over_witch3Light;
	load_sprite(finalPointer, game_over_witch3_light_bits, game_over_witch3_black_width, game_over_witch3_black_height);
	game_over_witch3Light = finalPointer;
	sprite *pointer17 = &tempgame_over_witch3Gray;
	load_sprite(pointer17, game_over_witch3_gray_bits, game_over_witch3_black_width, game_over_witch3_black_height);
	game_over_witch3Gray = pointer17;
	sprite *pointer18 = &tempgame_over_witch3Black;
	load_sprite(pointer18, game_over_witch3_black_bits, game_over_witch3_black_width, game_over_witch3_black_height);
	game_over_witch3Black = pointer18;	
	
	sprite *pointer19 = &tempgame_over_witch4Light;
	load_sprite(pointer19, game_over_witch4_light_bits, game_over_witch4_black_width, game_over_witch4_black_height);
	game_over_witch4Light = pointer19;
	sprite *pointer20 = &tempgame_over_witch4Gray;
	load_sprite(pointer20, game_over_witch4_gray_bits, game_over_witch4_black_width, game_over_witch4_black_height);
	game_over_witch4Gray = pointer20;
	sprite *pointer21 = &tempgame_over_witch4Black;
	load_sprite(pointer21, game_over_witch4_black_bits, game_over_witch4_black_width, game_over_witch4_black_height);
	game_over_witch4Black = pointer21;	
	
	sprite *pointer22 = &tempgame_over_witch5Light;
	load_sprite(pointer22, game_over_witch5_light_bits, game_over_witch5_black_width, game_over_witch5_black_height);
	game_over_witch5Light = pointer22;
	sprite *pointer23 = &tempgame_over_witch5Gray;
	load_sprite(pointer23, game_over_witch5_gray_bits, game_over_witch5_black_width, game_over_witch5_black_height);
	game_over_witch5Gray = pointer23;
	sprite *pointer24 = &tempgame_over_witch5Black;
	load_sprite(pointer24, game_over_witch5_black_bits, game_over_witch5_black_width, game_over_witch5_black_height);
	game_over_witch5Black = pointer24;
	
	sprite *pointer25 = &tempgame_over_witch6Light;
	load_sprite(pointer25, game_over_witch6_light_bits, game_over_witch6_black_width, game_over_witch6_black_height);
	game_over_witch6Light = pointer25;
	sprite *pointer26 = &tempgame_over_witch6Gray;
	load_sprite(pointer26, game_over_witch6_gray_bits, game_over_witch6_black_width, game_over_witch6_black_height);
	game_over_witch6Gray = pointer26;
	sprite *pointer27 = &tempgame_over_witch6Black;
	load_sprite(pointer27, game_over_witch6_black_bits, game_over_witch6_black_width, game_over_witch6_black_height);
	game_over_witch6Black = pointer27;
	
	/*sprite *pointer;
	
	*pointer = &tempgame_over_witch7Light;
	load_sprite(pointer, game_over_witch7_light_bits, game_over_witch7_black_width, game_over_witch7_black_height);
	game_over_witch7Light = pointer;
	*pointer = &tempgame_over_witch7Gray;
	load_sprite(pointer, game_over_witch7_gray_bits, game_over_witch7_black_width, game_over_witch7_black_height);
	game_over_witch7Gray = pointer;
	*pointer = &tempgame_over_witch7Black;
	load_sprite(pointer, game_over_witch7_black_bits, game_over_witch7_black_width, game_over_witch7_black_height);
	game_over_witch7Black = pointer;
	
	*pointer = &tempgame_over_witch8Light;
	load_sprite(pointer, game_over_witch8_light_bits, game_over_witch8_black_width, game_over_witch8_black_height);
	game_over_witch8Light = pointer;
	*pointer = &tempgame_over_witch8Gray;
	load_sprite(pointer, game_over_witch8_gray_bits, game_over_witch8_black_width, game_over_witch8_black_height);
	game_over_witch8Gray = pointer;
	*pointer = &tempgame_over_witch8Black;
	load_sprite(pointer, game_over_witch8_black_bits, game_over_witch8_black_width, game_over_witch8_black_height);
	game_over_witch8Black = pointer;

	*pointer = &tempgame_over_witch9Light;
	load_sprite(pointer, game_over_witch9_light_bits, game_over_witch9_black_width, game_over_witch9_black_height);
	game_over_witch9Light = pointer;
	*pointer = &tempgame_over_witch9Gray;
	load_sprite(pointer, game_over_witch9_gray_bits, game_over_witch9_black_width, game_over_witch9_black_height);
	game_over_witch9Gray = pointer;
	*pointer = &tempgame_over_witch9Black;
	load_sprite(pointer, game_over_witch9_black_bits, game_over_witch9_black_width, game_over_witch9_black_height);
	game_over_witch9Black = pointer;
	
	*pointer = &tempgame_over_witch10Light;
	load_sprite(pointer, game_over_witch10_light_bits, game_over_witch10_black_width, game_over_witch10_black_height);
	game_over_witch10Light = pointer;
	*pointer = &tempgame_over_witch10Gray;
	load_sprite(pointer, game_over_witch10_gray_bits, game_over_witch10_black_width, game_over_witch10_black_height);
	game_over_witch10Gray = pointer;
	*pointer = &tempgame_over_witch10Black;
	load_sprite(pointer, game_over_witch10_black_bits, game_over_witch10_black_width, game_over_witch10_black_height);
	game_over_witch10Black = pointer;
	
	*pointer = &tempgame_over_witch11Light;
	load_sprite(pointer, game_over_witch11_light_bits, game_over_witch11_black_width, game_over_witch11_black_height);
	game_over_witch11Light = pointer;
	*pointer = &tempgame_over_witch11Gray;
	load_sprite(pointer, game_over_witch11_gray_bits, game_over_witch11_black_width, game_over_witch11_black_height);
	game_over_witch11Gray = pointer;
	*pointer = &tempgame_over_witch11Black;
	load_sprite(pointer, game_over_witch11_black_bits, game_over_witch11_black_width, game_over_witch11_black_height);
	game_over_witch11Black = pointer;
	
	*pointer = &tempgame_over_witch12Light;
	load_sprite(pointer, game_over_witch12_light_bits, game_over_witch12_black_width, game_over_witch12_black_height);
	game_over_witch12Light = pointer;
	*pointer = &tempgame_over_witch12Gray;
	load_sprite(pointer, game_over_witch12_gray_bits, game_over_witch12_black_width, game_over_witch12_black_height);
	game_over_witch12Gray = pointer;
	*pointer = &tempgame_over_witch12Black;
	load_sprite(pointer, game_over_witch12_black_bits, game_over_witch12_black_width, game_over_witch12_black_height);
	game_over_witch12Black = pointer;*/
}
	
void init_game_over_witch( GameObject *game_over_witchObj ) {
	static int firstTime = 1;
	if (firstTime) {
		initSprites();
		firstTime = 0;			

		game_over_witchImages[0] = game_over_witch1Image;
		game_over_witchImages[1] = game_over_witch2Image;
		game_over_witchImages[2] = game_over_witch3Image;
		game_over_witchImages[3] = game_over_witch4Image;
		game_over_witchImages[4] = game_over_witch5Image;
		game_over_witchImages[5] = game_over_witch6Image;
		/*game_over_witchImages[6] = game_over_witch7Image;
		game_over_witchImages[7] = game_over_witch8Image;
		game_over_witchImages[8] = game_over_witch9Image;
		game_over_witchImages[9] = game_over_witch10Image;
		game_over_witchImages[10] = game_over_witch11Image;
		game_over_witchImages[11] = game_over_witch12Image;*/
		
		load_image(&game_over_witchImages[0], game_over_witch1Black, game_over_witch1Gray, game_over_witch1Light);
		load_image(&game_over_witchImages[1], game_over_witch2Black, game_over_witch2Gray, game_over_witch2Light);
		load_image(&game_over_witchImages[2], game_over_witch3Black, game_over_witch3Gray, game_over_witch3Light);
		load_image(&game_over_witchImages[3], game_over_witch4Black, game_over_witch4Gray, game_over_witch4Light);
		load_image(&game_over_witchImages[4], game_over_witch5Black, game_over_witch5Gray, game_over_witch5Light);
		load_image(&game_over_witchImages[5], game_over_witch6Black, game_over_witch6Gray, game_over_witch6Light);
		/*load_image(&game_over_witchImages[6], game_over_witch7Black, game_over_witch7Gray, game_over_witch7Light);
		load_image(&game_over_witchImages[7], game_over_witch8Black, game_over_witch8Gray, game_over_witch8Light);
		load_image(&game_over_witchImages[8], game_over_witch9Black, game_over_witch9Gray, game_over_witch9Light);
		load_image(&game_over_witchImages[9], game_over_witch10Black, game_over_witch10Gray, game_over_witch10Light);
		load_image(&game_over_witchImages[10], game_over_witch11Black, game_over_witch11Gray, game_over_witch11Light);
		load_image(&game_over_witchImages[11], game_over_witch12Black, game_over_witch12Gray, game_over_witch12Light);*/
	}
	
	game_over_witchObj->images = game_over_witchImages;

	game_over_witchObj->current_frame = 0;
	game_over_witchObj->n_frames = 6;
	game_over_witchObj->animation_speed = 1;
	game_over_witchObj->animation_counter = 0;
}
