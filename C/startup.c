#include "graphics.h"
#include "monster_black.xbm"
#include "monster_light.xbm"
#include "monster_gray.xbm"

#include "press_black.xbm"
#include "press_light.xbm"
#include "press_gray.xbm"

#include "controls.h"

#include "castle_black.xbm"
#include "castle_gray.xbm"
#include "castle_light.xbm"
#include "title_light.xbm"
#include "title_gray.xbm"
#include "title_black.xbm"

#include "startup.h"
#include "slow_text.h"
#include "ascii_display.h"
#include "bg.xbm"
#include "gpio.h"
#include "fire.h"
#include "player.h"
#include "bird.h"
#include "witch.h"
#include "indoors.h"
#include "indoors2.h"
#include "DIP.h"

int abs(int value);

int random_seed;

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
sprite *pressBlack;
sprite *pressGray;
sprite *pressLight;

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
sprite tempPressBlack;
sprite tempPressGray;
sprite tempPressLight;

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
	
	pointer8 = &tempPressLight;
	load_sprite(pointer8, press_light_bits, press_black_width, press_black_height);
	pressLight = pointer8;
	pointer9 = &tempPressGray;
	load_sprite(pointer9, press_gray_bits, press_black_width, press_black_height);
	pressGray = pointer9;
	pointer10 = &tempPressBlack;
	load_sprite(pointer10, press_black_bits, press_black_width, press_black_height);
	pressBlack = pointer10;	
	
	
}
	
int counter = 0;
int current_screen = START_SCREEN;
void main(void)
{
	
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
	
	GameObject pressObj;
	Image pressImage;
	Image pressImages[] = {pressImage};
	pressObj.images = pressImages;
	load_image(&pressObj.images[0], pressBlack, pressLight, pressGray);
	pressObj.xPos = 65-30;
	pressObj.yPos = 29-15;
	pressObj.current_frame = 0;
	
	GameObject castleObj;
	Image castleImage;
	Image castleImages[] = {castleImage};
	castleObj.images = castleImages;
	load_image(&castleObj.images[0], castleBlack, castleGray, castleLight);
	castleObj.xPos = 1;
	castleObj.yPos = 1;
	castleObj.current_frame = 0;
	
	GameObject indoors;
	init_indoors( &indoors );
	indoors.xPos = 1;
	indoors.yPos = 1;
	
	GameObject indoors2;
	init_indoors2( &indoors2 );
	indoors2.xPos = 1;
	indoors2.yPos = 1;
	
	GameObject trophy;
	init_trophy( &trophy );

	
	GameObject hair;
	init_flame(&hair);
	hair.xPos = 40;
	hair.yPos = 10;
	hair.update = gameObjectUpdate;
	
	GameObject bird;
	init_bird( &bird );
	bird.xPos = 180;
	bird.yPos = 40;
	bird.update = gameObjectUpdate;
	
	GameObject DIP;
	init_DIP( &DIP );
	DIP.update = DIPUpdate;
	
	GameObject player;
	init_witch( &player );
	player.xPos = 3;
	player.yPos = LIMIT_DOWN - 1; //player position
	player.update = playerUpdate;
	
	GameObject fire2;
	init_fire( &fire2 );
	GameObject fire3;
	init_fire( &fire3 );
	GameObject fire4;
	init_fire( &fire4 );
	GameObject fire1;
	init_fire( &fire1 );
	
	GameObject fire1_indoors;
	init_fire( &fire1_indoors );
	fire1_indoors.xPos = 50;		//FIRE1_INDO
	fire1_indoors.yPos = 64-12-7;
	fire1_indoors.update = gameObjectUpdate;
	GameObject fire2_indoors;
	init_fire( &fire2_indoors );
	fire2_indoors.update = gameObjectUpdate;
	GameObject fire3_indoors;
	init_fire( &fire3_indoors );
	fire3_indoors.update = gameObjectUpdate;
	GameObject fires[] = {fire1_indoors, fire2_indoors, fire3_indoors};
	
	
	fire2.xPos = 98;
	fire2.yPos = 26-12;
	fire3.xPos = 115;
	fire3.yPos = 34-12;
	
	fire1.xPos = 85;
	fire1.yPos = 23-12;
	fire4.xPos = 71;
	fire4.yPos = 27-11;
	//draw_game_object(&castleObj);
	
	fire2.animation_speed = 2;
	fire3.animation_speed = 2;
	fire1.animation_speed = 2;
	fire4.animation_speed = 2;
	
	fire2.update = gameObjectUpdate;
	fire3.update = gameObjectUpdate;
	fire1.update = gameObjectUpdate;
	fire4.update = gameObjectUpdate;
	
	SlowText text_kra;
	SlowText text1;
	SlowText text2;
	SlowText text3;
	SlowText text4;
	SlowText text5;
	SlowText text6;
	SlowText text7;
	SlowText text8;
	SlowText text9;
	SlowText text10;
	SlowText text11;
	SlowText text12;
	init_slow_text(&text_kra, "*KRA!* *KRA!*", "   ", 1);
	init_slow_text(&text1, "For centuries the", "DILs-witches have", 1);
	init_slow_text(&text2, "coiled in fear,", "    ", 1);
	init_slow_text(&text3, "whenever they hear", "that a DIPs-witch", 1);
	init_slow_text(&text4, "is near.", "   ", 1);
	init_slow_text(&text5, "So it is quite", "surprising, finding", 1);
	init_slow_text(&text6, "you here,", "    ", 1);
	init_slow_text(&text7, "queen Daffo of DILs,", "heir to king Lear.", 1);
	init_slow_text(&text8, "But maybe you're", "tempted, to loot", 1);
	init_slow_text(&text9, "from the riches,", "    ", 1);
	init_slow_text(&text12, "wicked DIPs-witches.", "    ", 1);
	init_slow_text(&text10, "so grippily trea-", "sured by", 1);
	init_slow_text(&text11, "Enter, brave witch,", "- reset the switch!", 1);
	//ascii_write_part("Yeeaaah!!!", "This is working! :)", 5, 10);
	set_up_ascii();
	set_up_DIL();
	clear_ascii();
	
	int is_climbing = 0;
	int has_climbed = 0;
	int game_over = 0;
	int game_over_adder = 0;
	int no_DIP = 0;
	int lastFireTrigger = 0;
	
	
	current_screen = RESET_GAME;
	
	//Game loop
	while(1) {
			
		switch(current_screen) {
			
			case SWITCH_LOCK: //before

				while(read_DIL() == 0){
					draw_game_object(&pressObj);
					show_frame(1);
				}
				
				counter = 0;
				current_screen = START_SCREEN;
				break;
			
			
			case START_SCREEN: //outside
				
				counter++;
				
				if(titleObj.yPos < 1) {
					titleObj.yPos++;
				}
				
				draw_game_object(&castleObj);
				draw_game_object(&fire2);
				draw_game_object(&fire3);
				draw_game_object(&fire1);
				draw_game_object(&fire4);
				draw_game_object(&titleObj);
				draw_game_object(&bird);
				show_frame(1);
				
				static int long_text = 40;
				static int short_text = 20;
				static int delay_until_text = 130;
				
				if (counter < delay_until_text - 55 && counter > delay_until_text - 90)
					text_kra.display(&text_kra, 20);
				if (counter == delay_until_text - 25)
					clear_ascii();
				
				if (counter < delay_until_text);
				else if (counter < delay_until_text + 1*long_text)
					text1.display(&text1, 20);
				else if(counter < delay_until_text + 1*long_text + 1*short_text)
					text2.display(&text2, 20);
				else if(counter < delay_until_text + 2*long_text + 1*short_text)
					text3.display(&text3, 20);
				else if(counter < delay_until_text + 2*long_text + 2*short_text)
					text4.display(&text4, 20);
				else if(counter < delay_until_text + 3*long_text + 2*short_text)
					text5.display(&text5, 15);
				else if(counter < delay_until_text + 3*long_text + 3*short_text)
					text6.display(&text6, 20);
				else if(counter < delay_until_text + 4*long_text + 3*short_text + 3)
					text7.display(&text7, 20);
				else if(counter < delay_until_text + 5*long_text + 3*short_text + 2)
					text8.display(&text8, 20);
				else if(counter < delay_until_text + 5*long_text + 4*short_text + 2)
					text9.display(&text9, 20);
				else if(counter < delay_until_text + 6*long_text + 4*short_text - 2 + 2)
					text10.display(&text10, 15);
				else if(counter < delay_until_text + 6*long_text + 5*short_text + 3 + 2)
					text12.display(&text12, 15);
				else if(counter < delay_until_text + 7*long_text + 5*short_text + 6 + 2) {
					text11.display(&text11, 20);
				} else {
					if (read_DIL() == 0) {
						current_screen = GAME_SCREEN;
						random_seed = counter;
						counter = 0;
						ascii_write("Daffo: I'm feeling ","a bit spooked out...");
					}
				}
				
				if(read_DIL() == SKIP_VALUE) {
					current_screen = GAME_SCREEN;
					random_seed = counter;
					counter = 0;
					ascii_write("Daffo: I'm feeling ","a bit spooked out...");
				}
				
				
				fire2.update(&fire2);
				fire3.update(&fire3);
				fire1.update(&fire1);
				fire4.update(&fire4);
				bird.update(&bird);
				bird.xPos -= 2;
				if (counter % 2 == 0) {
					bird.yPos--;
				}
				
				break;
				
			case GAME_SCREEN: //inside
				
				counter++;
				if(read_DIL_single( LIGHT_TRIGGER )) {
					draw_game_object( &indoors2 );
					ascii_write("*click*","");
				} else {
					draw_game_object( &indoors );
					draw_game_object( &trophy );
				}
				
				if(!no_DIP)
					draw_game_object( &DIP );
				draw_game_object( &player );
				static int i;
				for(i = 0; i < 3; i++) {
					draw_game_object( &fires[i] );
					fires[i].update( &fires[i] );
				}
				draw_game_object( &hair );
				show_frame(1);
				
				static int last_climb_value = 100;
				if((read_DIL_single(CLIMB_TRIGGER) != last_climb_value) && player.xPos > 90 && player.xPos < 108 && !has_climbed) {
					is_climbing = 1;
					player.xPos = 98;
				}
				last_climb_value = read_DIL_single(CLIMB_TRIGGER);
				
				if(is_climbing) {
					gameObjectUpdate( &player );
					if (player.yPos % 6 == 0){
						ascii_write("*tipp*","");
					}
					else if (player.yPos % 6 == 3) {
						ascii_write("*tapp*","");
					}
					if(player.yPos > 4) {
						player.yPos--;
					} else {	//Stay at top level and disable climbing forever!
						player.yPos = 5;
						player.xPos = 96;
						is_climbing = 0;
						has_climbed = 1;
					}
				} else {
					player.update(&player);
				}
				
				if (trophy.yPos >= player.yPos && (player.xPos + PLAYER_WIDTH/2 >= trophy.xPos && player.xPos <= trophy.xPos + PLAYER_WIDTH/2 )) {
					ascii_write("Daffo: I need magic ","to grab the trophy!");
				}
				
				if (read_DIL_single(EXPLOSION_TRIGGER)){
					if (trophy.yPos >= player.yPos && (player.xPos + PLAYER_WIDTH/2 >= trophy.xPos && player.xPos <= trophy.xPos + PLAYER_WIDTH/2 )){
						//TODO WIN
						ascii_write("PLACEHOLDER DU VANN","");
					}
					else{
						game_over_adder = 20;
						ascii_write("*KABOOOOM*","");
					}
				}
				
				//fire1_indoors.update(&fire1_indoors);
				//fire updates done above
				if(!no_DIP) {
					setPlayerPosition(player.xPos, player.yPos);
					DIP.update(&DIP);					
				}
				hair.update(&hair);
				if(read_DIL_single(HAIR_TRIGGER)) {
					if (lastFireTrigger == 0){
						ascii_write("*FwOOOo*","");
					}
					hair.xPos = player.xPos;
					hair.yPos = player.yPos - 28;
				} else {
					hair.xPos = -100;
					hair.yPos = -100;
				}
				
				
				
				if (!no_DIP && DIP.yPos >= player.yPos && (player.xPos + DIP_WIDTH/2 >= DIP.xPos && player.xPos <= DIP.xPos + DIP_WIDTH/2 )){ // DIP_collision
					game_over_adder = 100;
					ascii_write("DIPs-WITCH:","      NyAHAHAHAH!");
				}
				
				static int distance_player_fire;	//fire_collision
				static int j;
				for(j = 0; j < 3; j++) {
					distance_player_fire = (player.xPos + 9) - (fires[j].xPos + 5);
					if(player.yPos > (fires[j].yPos - 18 + 7) && 
							player.yPos < fires[j].yPos && distance_player_fire < 8 && distance_player_fire > -8) {
						game_over_adder = 20;
						ascii_write("*FWOOSH*","");
					}					
				}
				
				static int trophy_burned = 0;	//trophy burning
				static int distance_hair_trophy;
				distance_hair_trophy = (hair.xPos + 9) - (trophy.xPos + 5);
				if(!trophy_burned && abs(distance_hair_trophy) < 5) {
					trophy_burned = 1;
					fires[1].xPos = trophy.xPos;
					fires[1].yPos = trophy.yPos + 5;
					trophy.xPos = 500;
					ascii_write("DAFFO:  ","        Oops...!");
				}
				
				static int DIP_burned = 0;
				static int distance_hair_DIP;
				distance_hair_DIP = (hair.xPos + 9) - (DIP.xPos + 9);
				if(!DIP_burned && read_DIL_single(LIGHT_TRIGGER) && player.yPos > 10 && abs(distance_hair_DIP) < 5) {
					DIP_burned = 1;
					fires[2].xPos = DIP.xPos;
					fires[2].yPos = DIP.yPos + 6;
					no_DIP = 1;
					ascii_write("DIPs-WITCH:","       ARGHGHHRH!");
				}
				
				lastFireTrigger = read_DIL_single(HAIR_TRIGGER);
				
				game_over += game_over_adder;
				
				if(game_over >= 100) {
					current_screen = RESET_GAME;
				}
				
				break;
				
			
			case RESET_GAME: //restart
				counter = 0;
				current_screen = START_SCREEN;
				if(read_DIL() == 0) {
					current_screen = SWITCH_LOCK; 
				}
	
				static int test = 0;
				test+=2;
	
				is_climbing = 0;
				has_climbed = 0;
				game_over = 0;
				game_over_adder = 0;
				fires[0].xPos = 40;		//FIRE1_INDO
				fires[0].yPos = 64-12-8;
				fires[2].xPos = -50;		//FIRE1_INDO
				fires[2].yPos = -50;
				fires[1].xPos = -50;		//FIRE1_INDO
				fires[1].yPos = -50;
				bird.xPos = 180;
				bird.yPos = 40;
				
				trophy.xPos = 24;
				trophy.yPos = 5;
				trophy_burned = 0;
				
				DIP.xPos = 100;
				DIP.yPos = 5;
				DIP_burned = 0;
				no_DIP = 0;
				
				lastFireTrigger = 0;
				
				player.xPos = 3;
				player.yPos = 64-18-7; //player position
				clear_ascii();
				break;
							
		} //end of switch
		
		
		
		
		
		
	}
	
}

int abs(int value) {
	if(value < 0) {
		return -value;
	}
	return value;
}

