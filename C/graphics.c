#include "graphics.h"


void delay_250ns(void){
	/* SystemCoreClock = 168000000 */
	*STK_CTRL = 0;
	*STK_LOAD = ( (168/4) -1);
	*STK_VAL = 0;
	*STK_CTRL = 5;
	while( (*STK_CTRL & 0x10000)== 0 ){}
	*STK_CTRL = 0;
}

void delay_500ns(void){
	/* SystemCoreClock = 168000000 */
	*STK_CTRL = 0;
	*STK_LOAD = ( (168/2) -1);
	*STK_VAL = 0;
	*STK_CTRL = 5;
	while( (*STK_CTRL & 0x10000)== 0 ){}
	*STK_CTRL = 0;
}

void delay_micro(unsigned int us){
	while(us--) {
		delay_250ns();
		delay_250ns();
		delay_250ns();
		delay_250ns();
	}
}

void delay_milli(unsigned int ms){
	#ifdef SIMULATOR
		while(ms--)
			delay_micro(1);
	#else
		while(ms--)
			delay_micro(1000);
	#endif
}

uint8_t draw_buffer_black[1024]; // 128 * 64 / 8
uint8_t draw_buffer_black_gray[1024]; // 128 * 64 / 8
uint8_t draw_buffer_black_light[1024]; // 128 * 64 / 8
uint8_t draw_buffer_black_gray_light[1024]; // 128 * 64 / 8
uint8_t backBuffer[1024]; // 128 * 64 / 8
uint8_t backBufferGray[1024]; // 128 * 64 / 8
uint8_t backBufferLight[1024]; // 128 * 64 / 8
void clear_thisBackBuffer(uint8_t *buffer) {
	int i;
	for (i = 0; i < 1024; i++)
		buffer[i] = 0;
}
void clear_backBuffer() {
	clear_thisBackBuffer(backBuffer);
}
void clear_all_backBuffers() {
	clear_thisBackBuffer(backBuffer);
	clear_thisBackBuffer(backBufferGray);
	clear_thisBackBuffer(backBufferLight);
}

/* välj grafik-display och ettställ de bitar som är 1 i x */
static void graphic_ctrl_bit_set( uint8_t x) {
	uint8_t c;
	c = *portOdrLow;
	c |= x;
	c &= ~B_SELECT; //Graphic display istället för alphanum
	*portOdrLow = c;
}
/* välj grafik-display och nollställ de bitar som är 1 i x */
static void graphic_ctrl_bit_clear( uint8_t x) {
	uint8_t c;
	c = *portOdrLow;
	c &= ~x;
	c &= ~B_SELECT; //Graphic display istället för alphanum
	*portOdrLow = c;
}
void select_controller( uint8_t controller) {
	switch (controller) {
		case 0: 
			graphic_ctrl_bit_clear(B_CS1); 
			graphic_ctrl_bit_clear(B_CS2); 
			break;
		case B_CS1: 
			graphic_ctrl_bit_set(B_CS1); 
			graphic_ctrl_bit_clear(B_CS2); 
			break;
		case B_CS2: 
			graphic_ctrl_bit_clear(B_CS1); 
			graphic_ctrl_bit_set(B_CS2); 
			break;
		case (B_CS1|B_CS2): 
			graphic_ctrl_bit_set(B_CS1); 
			graphic_ctrl_bit_set(B_CS2); 
			break;
	}
}

void graphic_wait_ready( void ) {
	uint8_t c;
	graphic_ctrl_bit_clear(B_E);
	*portModer = 0x00005555;
	graphic_ctrl_bit_clear(B_RS);
	graphic_ctrl_bit_set(B_RW);
	delay_500ns();
	
	while(1) {
		graphic_ctrl_bit_set(B_E);
		delay_500ns();
		c = *portIdrHigh & LCD_BUSY; //...
		graphic_ctrl_bit_clear(B_E);
		delay_500ns();
		/*if (*portIdrHigh & 0x80 == 0x80) {
			break; }*/
		if (c == 0) break;
	}
	//graphic_ctrl_bit_set(B_E); //<--
	*portModer = 0x55555555;	
}

static uint8_t graphic_read(uint8_t controller) {
	graphic_ctrl_bit_clear(B_E);
	*portModer = 0x00005555;
	graphic_ctrl_bit_set(B_RS);
	graphic_ctrl_bit_set(B_RW);
	select_controller(controller);
	delay_500ns();
	graphic_ctrl_bit_set(B_E);
	delay_500ns();
	unsigned char rv = *portIdrHigh;
	graphic_ctrl_bit_clear(B_E);
	*portModer = 0x55555555;
	
	if(controller == B_CS1) {
		select_controller(B_CS1);
		graphic_wait_ready();
	}
	if(controller == B_CS2) {
		select_controller(B_CS2);
		graphic_wait_ready();
	}
	
	return rv;
}

graphic_read_data(uint8_t controller) {
	graphic_read(controller);
	graphic_read(controller);
}

void graphic_write(uint8_t value, uint8_t controller) {
	*portOdrHigh = value; //I
	select_controller(controller);
	delay_500ns();
	graphic_ctrl_bit_set(B_E);
	delay_500ns();
	graphic_ctrl_bit_clear(B_E);
	
	if(controller & B_CS1) {
		select_controller(B_CS1);
		graphic_wait_ready();
	}
	if(controller & B_CS2) {
		select_controller(B_CS2);
		graphic_wait_ready();
	}
	
	*portOdrHigh = 0;	//I
	graphic_ctrl_bit_set(B_E);
	select_controller(0);
}
void graphic_write_command(uint8_t command, uint8_t controller) {
	graphic_ctrl_bit_clear(B_E);
	select_controller(controller);
	graphic_ctrl_bit_clear(B_RS);
	graphic_ctrl_bit_clear(B_RW);
	graphic_write(command, controller);
}
void graphic_write_data(uint8_t command, uint8_t controller) {
	graphic_ctrl_bit_clear(B_E);
	select_controller(controller);
	graphic_ctrl_bit_set(B_RS);
	graphic_ctrl_bit_clear(B_RW);
	graphic_write(command, controller);
}

void graphic_initialize( void ) {
	graphic_ctrl_bit_set(B_E);
	delay_micro(10);
	
	graphic_ctrl_bit_clear(B_CS1);
	graphic_ctrl_bit_clear(B_CS2);
	graphic_ctrl_bit_clear(B_RST);
	graphic_ctrl_bit_clear(B_E);
	//#define SIMULATOR
	delay_milli(30);
	graphic_ctrl_bit_set(B_RST);
	delay_milli(100); //...
	
	graphic_write_command(LCD_OFF, B_CS1|B_CS2);
	graphic_write_command(LCD_ON, B_CS1|B_CS2);
	graphic_write_command(LCD_DISP_START, B_CS1|B_CS2);
	graphic_write_command(LCD_SET_ADD, B_CS1|B_CS2);
	graphic_write_command(LCD_SET_PAGE, B_CS1|B_CS2);
	select_controller(0);
}
void graphic_clear_screen( void ) {	//Annat i slidesen
	uint8_t page;
	for (page = 0; page < 8; page++) {
		graphic_write_command(LCD_SET_PAGE | page, B_CS1|B_CS2);
		graphic_write_command(LCD_SET_ADD | 0, B_CS1|B_CS2);
		uint8_t add;
		for (add = 0; add < 64; add++) {
			graphic_write_data(0, B_CS1|B_CS2);
		}
	}
}

/** Color: 1=light 2=gray 3=black*/
void pixel(int x, int y, int set, int color) {
	uint8_t mask;
	int index = 0;
	if( (x > 128 ) || (x < 1) || (y > 64) || (y < 1) ) 
		return;
	mask = 1 << ((y-1)%8);
	if(x > 64) {
		x -= 65;
		index = 512;
	}
	index += x + ((y-1)/8)*64;

	if(set == 0)
		mask = ~mask;

	switch (color) {
		case 1:	
			if(set)
				backBufferLight[index] |= mask;
			else
				backBufferLight[index] &= mask;
			break;
		
		case 2:	
			if(set)
				backBufferGray[index] |= mask;
			else
				backBufferGray[index] &= mask;
			break;
		
		case 3:	
			if(set)
				backBuffer[index] |= mask;
			else
				backBuffer[index] &= mask;
			break;
			
	}

}

void fill_screen(int pixels) {
	int row, col;
	for(row = 1; row < 65; row++) {
		for(col = 1; col < 129; col++) {
			pixel(col, row, 1, 3);
			if(pixels <= 0)
				return;
			pixels--;
		}
	}
}

void pixel2(int x, int y, int set) {
	uint8_t mask, c, controller;
	int index;
	if((x < 1) || (y < 1) || (x > 128) || (y > 64)) return;
	index = (y-1)/8;
	switch( (y-1)%8 ) {
		case 0: mask = 1; break;
		case 1: mask = 2; break;
		case 2: mask = 4; break;
		case 3: mask = 8; break;
		case 4: mask = 0x10; break;
		case 5: mask = 0x20; break;
		case 6: mask = 0x40; break;
		case 7: mask = 0x80; break;
	}
	
	if(set == 0)
		mask = ~mask;
	
	if(x > 64){
		controller = B_CS2;
		x = x - 65;
	} else {
		controller = B_CS1;
		x = x-1;
	}
	graphic_write_command(LCD_SET_ADD | x, controller );
	graphic_write_command(LCD_SET_PAGE | index, controller );
	
	c = graphic_read_data(controller);
	graphic_write_command(LCD_SET_ADD | x, controller);
	
	if(set)
		mask = mask | c;
	else
		mask = mask & c;
	
	graphic_write_data(mask, controller);
}

void graphic_draw_screen(uint8_t *buffer) {
	uint8_t i, j, controller, c;
	unsigned int k = 0;
	for(c = 0; c < 2; c++) {
		controller = (c == 0) ? B_CS1 : B_CS2;
		for(j = 0; j < 8; j++) {
			graphic_write_command(LCD_SET_PAGE | j, controller);
			graphic_write_command(LCD_SET_ADD | 0, controller);
			for(i = 0; i <= 63; i++, k++) {
				graphic_write_data(buffer[k], controller);
			}
		}
	}
}




void grayScaleTest( void );


void draw_sprite(sprite* s, int x, int y, int set, int color) {
	int i,j,k, width_in_bytes;
	if (s->width % 8 == 0)
		width_in_bytes = s->width / 8;
	else
		width_in_bytes = (s->width / 8) + 1;
	for (i = 0; i < s->height; i++)
		for (j = 0; j < width_in_bytes; j++) {
			unsigned char byte = s->data[i * width_in_bytes + j];
			for (k =0; k < 8; k++) {
				if (byte & (1 << k)){
					pixel(8 * j + k + x + 1, i + y + 1, set, color);
					
					if(set) {	//Remove the other colors from this pixel
						pixel(8 * j + k + x + 1, i + y + 1, 0, (color+1) % 3);
						pixel(8 * j + k + x + 1, i + y + 1, 0, (color+2) % 3);
					}
				}
			}
		}
}

void fillRectangle( int x, int y, int width, int height ){
	int i;
	int j;
	for (i = x; i < x + width; i++) {
		for (j = y; j < y + height; j++) {
			pixel(i, j, 1, 3);
		}
	}
}

void clearRectangle( int x, int y, int width, int height ){
	int i;
	int j;
	for (i = x; i < x + width; i++) {
		for (j = y; j < y + height; j++) {
			pixel(i, j, 0, 3);
		}
	}
}


void grayScaleTest( void ) {
	int x = 10;
	int y = 10;
	int width = 70;
	int height = 50;
	
	int x2 = 50;
	
	fillRectangle(x, y, width, height);
	
	int i;
	int k = 5;
	while(1) {
		clear_backBuffer();
		fillRectangle(x, y, width, height);
		clearRectangle(x+2+2, y+1, width-k, height-k); //outer square
		clearRectangle(x+2+k, y+2, width-4-k, height-4-k); //inner square
		graphic_draw_screen(draw_buffer_black);
		clear_backBuffer();
		fillRectangle(x, y, width, height);
		
		fillRectangle(x+2+2, y+1, width-k, height-k); //outer white square
		fillRectangle(x+2+k, y+2, width-4-k, height-4-k); //inner square
		clearRectangle(x+12, y+5, 5, 5);
		
		graphic_draw_screen(draw_buffer_black);
		delay_milli(20);
		
		clear_backBuffer();
		fillRectangle(x, y, width, height);
		clearRectangle(x+2+k, y+2, width-4-k, height-4-k); //inner square
		graphic_draw_screen(draw_buffer_black);
		
		delay_milli(20);
	}
}

/** Should prepare the different drawing buffers, before the drawing of each frame.*/
void set_up_draw_buffers( void ) {
	int i;
	for(i = 0; i < 1024; i++) {
		draw_buffer_black[i] = backBuffer[i] & (~backBufferGray[i] & ~backBufferLight[i]); //Had to work a bit on these
		draw_buffer_black_gray[i] = (backBuffer[i] | backBufferGray[i]) & ~backBufferLight[i]; //in order to make it possible
		draw_buffer_black_light[i] = (backBuffer[i] | backBufferLight[i]) & ~backBufferGray[i]; //to show a lighter sprite
		draw_buffer_black_gray_light[i] = backBuffer[i] | backBufferGray[i] | backBufferLight[i]; //on top of a darker one.
	}
}

void draw_game_object(GameObject *gObj) {
	int frame = gObj->current_frame;
	draw_sprite(gObj->images[frame].blackImage, gObj->xPos, gObj->yPos, 1, 3);
	draw_sprite(gObj->images[frame].grayImage, gObj->xPos, gObj->yPos, 1, 2);
	draw_sprite(gObj->images[frame].lightImage, gObj->xPos, gObj->yPos, 1, 1);
}


void show_frame(int frame_length) {
	set_up_draw_buffers();
	
	while(frame_length--) {
		graphic_draw_screen(draw_buffer_black_gray_light);
		delay_milli(1);
		
		graphic_draw_screen(draw_buffer_black);
		delay_milli(1);
		
		graphic_draw_screen(draw_buffer_black_gray);
		delay_milli(1);
		
		graphic_draw_screen(draw_buffer_black);
		delay_milli(1);
	}
	
	clear_all_backBuffers();	//Maybe we could be more effective by only clearing the necessary stuff,
								//but let's keep it like this if it works.
}