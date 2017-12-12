#include "graphics.h"
#include "monster_black.xbm"
#include "monster_light.xbm"
#include "monster_gray.xbm"
#include "castle_black.xbm"
#include "castle_gray.xbm"
#include "castle_light.xbm"
#include "title_light.xbm"
#include "title_gray.xbm"
#include "title_black.xbm"


#include "bg.xbm"
#include "gpio.h"
#include "fire.h"
#include "player.h"


void startup(void) __attribute__((naked)) __attribute__((section (".start_section")) );

void init_app( void ) {
	*portModer = 0x55555555;
	set_up_DIL();
	//* ( (unsigned long *) 0x40023830) = 0x18;
	graphic_initialize();
#ifndef SIMULATOR
	graphic_clear_screen();
#endif
}

void startup ( void )
{
__asm volatile(
	" LDR R0,=0x2001C000\n"		/* set stack */
	" MOV SP,R0\n"
	" BL main\n"				/* call main */
	"_exit: B .\n"				/* never return */
	) ;
}

sprite *monster;
sprite *monsterLight;
sprite *monsterGray;
sprite *bg;

sprite *castleBlack;
sprite *castleGray;
sprite *castleLight;
sprite *titleBlack;
sprite *titleGray;
sprite *titleLight;

sprite tempMonster;
sprite tempMonsterLight;
sprite tempMonsterGray;
sprite tempBg;

sprite tempCastleBlack;
sprite tempCastleGray;
sprite tempCastleLight;
sprite tempTitleBlack;
sprite tempTitleGray;
sprite tempTitleLight;

void initSprites( void ) {
	sprite *monsterPointer = &tempMonster;
	load_sprite(monsterPointer, monster_black_bits, monster_black_width, monster_black_height);
	monster = monsterPointer;
	
	sprite *monsterPointer2 = &tempMonsterLight;
	load_sprite(monsterPointer2, monster_light_bits, monster_light_width, monster_light_height);
	monsterLight = monsterPointer2;

	sprite *monsterPointer3 = &tempMonsterGray;
	load_sprite(monsterPointer3, monster_gray_bits, monster_gray_width, monster_gray_height);
	monsterGray = monsterPointer3;

	sprite *pointer4 = &tempBg;
	load_sprite(pointer4, bg_bits, bg_width, bg_height);
	bg = pointer4;
	
	sprite *pointer5 = &tempCastleBlack;
	load_sprite(pointer5, castle_black_bits, castle_black_width, castle_black_height);
	castleBlack = pointer5;
	
	sprite *pointer6 = &tempCastleGray;
	load_sprite(pointer6, castle_gray_bits, castle_black_width, castle_black_height);
	castleGray = pointer6;
	
	sprite *pointer7 = &tempCastleLight;
	load_sprite(pointer7, castle_light_bits, castle_black_width, castle_black_height);
	castleLight = pointer7;
	
	sprite *pointer8 = &tempTitleLight;
	load_sprite(pointer8, title_light_bits, title_black_width, title_black_height);
	titleLight = pointer8;
	sprite *pointer9 = &tempTitleGray;
	load_sprite(pointer9, title_gray_bits, title_black_width, title_black_height);
	titleGray = pointer9;
	sprite *pointer10 = &tempTitleBlack;
	load_sprite(pointer10, title_black_bits, title_black_width, title_black_height);
	titleBlack = pointer10;
}
	
int counter = 0;
void main(void)
{

	/* Now it should work like this:
 * 
 * 1. Set up monster as a gameObject.
 * 2. Draw it with method above.
 * 3. Show frame with some long fram_length for testing.
 * 
 * */
	
	init_app();	
	initSprites();
	
	GameObject monsterObj;
	Image monsterImage;
	Image monsterImages[] = {monsterImage};
	monsterObj.images = monsterImages;
	load_image(&monsterObj.images[0], monster, monsterGray, monsterLight);
	monsterObj.xPos = 30;
	monsterObj.yPos = 4;
	monsterObj.current_frame = 0;
	monsterObj.update = playerUpdate;
	
	GameObject titleObj;
	Image titleImage;
	Image titleImages[] = {titleImage};
	titleObj.images = titleImages;
	load_image(&titleObj.images[0], titleBlack, titleGray, titleLight);
	titleObj.xPos = 1;
	titleObj.yPos = -40;
	titleObj.current_frame = 0;
	


	/*monsterObj.image.blackImage = monster;
	monsterObj.image.grayImage = monsterGray;
	monsterObj.image.lightImage = monsterLight;
	*/
	GameObject castleObj;
	Image castleImage;
	Image castleImages[] = {castleImage};
	castleObj.images = castleImages;
	load_image(&castleObj.images[0], castleBlack, castleGray, castleLight);
	castleObj.xPos = 1;
	castleObj.yPos = 1;
	castleObj.current_frame = 0;
	
	GameObject fire2;
	init_fire( &fire2 );
	GameObject fire3;
	init_fire( &fire3 );
	fire2.xPos = 94;
	fire2.yPos = 64-12;
	fire3.xPos = 94+13;
	fire3.yPos = 64-12;
	//draw_game_object(&castleObj);
	
	fire2.animation_speed = 2;
	fire3.animation_speed = 2;
	
	fire2.update = gameObjectUpdate;
	fire3.update = gameObjectUpdate;
	
	while(1) {
		counter++;
		if(titleObj.yPos < 1) {
			titleObj.yPos++;
		}
		
		draw_game_object(&castleObj);
		draw_game_object(&fire2);
		draw_game_object(&fire3);
		//draw_game_object(&monsterObj);
		draw_game_object(&titleObj);
		show_frame(1);
		
		fire2.update(&fire2);
		fire3.update(&fire3);
		
		monsterObj.update(&monsterObj);
		
		/*fireObj.animation_counter++;
		if (fireObj.animation_counter == fireObj.animation_speed) {
			fireObj.animation_counter = 0; 
			fireObj.current_frame = (fireObj.current_frame + 1) % fireObj.n_frames;
		}*/
		/*int switch_zero = read_DIL_single(0);
		GPIO_D.odrHigh = read_DIL();
		if (switch_zero) {
			monsterObj.xPos--;	
		} else {
			monsterObj.xPos++;
		}*/
		
	}
	
	/*
	
	while(1) {
		draw_game_object(&monsterObj);
		show_frame(1);
		
		int switch_zero = read_DIL_single(0);
		GPIO_D.odrHigh = read_DIL();
		if (switch_zero) {
			monsterObj.xPos--;	
		} else {
			monsterObj.xPos++;
		}
		
	}
	
	
	clear_backBuffer();
	//fillRectangle(20, 20, 10, 10);
	//int xPos = 1;
	
	
	draw_sprite(monster, 2, 2, 1, 3);
	draw_sprite(monsterLight, 2, 2, 1, 3);
	graphic_draw_screen(draw_buffer_black);
	delay_milli(1000);
	
	clear_backBuffer();
	draw_sprite(bg, 1, 1, 1, 3);
	graphic_draw_screen(draw_buffer_black);
	delay_milli(1000);
	
	int xPos = 2;
	int xInc = 1;
	while(1) {
/*		clear_backBuffer();
		draw_sprite(monster, 2, 2, 1);
		draw_sprite(monsterLight, 2, 2, 0);
		graphic_draw_screen();
	*/	/*
		static int i;
		xPos += xInc;
		if(xPos > 100 || xPos < 2) {
			xInc = -xInc;
			xInc = (xInc > 0) ? xInc + 1 : xInc - 1;
		}
		for (i = 0; i < 1; i++) {
			clear_backBuffer();
			draw_sprite(monster, xPos, 2, 1, 3);
			draw_sprite(monsterLight, xPos, 2, 0, 3);
			draw_sprite(monsterGray, xPos, 2, 1, 3);
			graphic_draw_screen(draw_buffer_black);
			delay_milli(1);
			
			clear_backBuffer();
			draw_sprite(monster, xPos, 2, 1, 3);
			draw_sprite(monsterLight, xPos, 2, 0, 3);
			draw_sprite(monsterGray, xPos, 2, 1, 3);
			graphic_draw_screen(draw_buffer_black);
			delay_milli(1);


			clear_backBuffer();
			draw_sprite(monster, xPos, 2, 1, 3);
			draw_sprite(monsterLight, xPos, 2, 0, 3);
			draw_sprite(monsterGray, xPos, 2, 0, 3);
			graphic_draw_screen(draw_buffer_black);
			delay_milli(1);
			
			clear_backBuffer();
			draw_sprite(monster, xPos, 2, 1, 3);
			draw_sprite(monsterLight, xPos, 2, 1, 3);
			draw_sprite(monsterGray, xPos, 2, 0, 3);
			graphic_draw_screen(draw_buffer_black);
			delay_milli(1);
			
		}
	}
	
	
	
	
	//while(1);
/*
	clear_backBuffer();
	//fillRectangle(20, 20, 10, 10);
	draw_sprite(&monster, 10, 2, 1);
	graphic_draw_screen();
	delay_milli(1000);
*/ /*


	while(1){
		clear_backBuffer();
		//fillRectangle(20, 20, 10, 10);
		draw_sprite(monster, 3, 2, 1, 3);
		graphic_draw_screen(draw_buffer_black);
		delay_milli(30);
	}
	
	clear_backBuffer();
	//fillRectangle(20, 20, 10, 10);
	draw_sprite(monster, 2, 2, 1, 3);
	graphic_draw_screen(draw_buffer_black);
	while(1);
	//grayScaleTest();
	
	 */
}