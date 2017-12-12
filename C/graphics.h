#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "sprite.h"
#include "gameobject.h"

#define STK_CTRL ((volatile unsigned int *) (0xE000E010))
#define STK_LOAD ((volatile unsigned int *) (0xE000E014))
#define STK_VAL ((volatile unsigned int *) (0xE000E018))

#define PORT_BASE 0x40021000
// Definera word-adresser för initieringar
#define portModer ((volatile unsigned int*) (PORT_BASE))
#define portOtyper ((volatile unsigned short*) (PORT_BASE+0x4))
#define portPupdr ((volatile unsigned int*) (PORT_BASE+0xC))
// Definera byte-adresser för data- och styrregister
#define portIdrLow ((volatile unsigned short*) (PORT_BASE+0x10))
#define portIdrHigh ((volatile unsigned char*) (PORT_BASE+0x11))
#define portOdrLow ((volatile unsigned char*) (PORT_BASE+0x14))
#define portOdrHigh ((volatile unsigned char*) (PORT_BASE+0x15))
//Bitarna i styrregistret
#define B_E 0x40
#define B_SELECT 4
#define B_RW 2
#define B_RS 1
#define B_RST 0x20
#define B_CS2 0x10
#define B_CS1 8

#define LCD_ON 0x3f
#define LCD_OFF 0x3e
#define LCD_SET_ADD 0x40
#define LCD_SET_PAGE 0xb8
#define LCD_DISP_START 0xc0
#define LCD_BUSY 0x80
typedef unsigned char uint8_t;

void delay_250ns(void);
void delay_500ns(void);
void delay_micro(unsigned int us);
void delay_milli(unsigned int ms);

extern uint8_t backBuffer[1024]; // 128 * 64 / 8
extern uint8_t draw_buffer_black[1024]; // 128 * 64 / 8
extern uint8_t draw_buffer_black_gray[1024]; // 128 * 64 / 8
extern uint8_t draw_buffer_black_light[1024]; // 128 * 64 / 8
extern uint8_t draw_buffer_black_gray_light[1024]; // 128 * 64 / 8
extern uint8_t backBufferGray[1024]; // 128 * 64 / 8
extern uint8_t backBufferLight[1024]; // 128 * 64 / 8

void clear_all_backBuffers(void);
void clear_backBuffer(void);
void clear_thisBackBuffer(uint8_t* buffer);
void graphic_initialize(void);
void graphic_clear_screen(void);
void pixel(int x, int y, int set, int color);
void graphic_draw_screen(uint8_t* buffer);
void draw_sprite(sprite* s, int x, int y, int set, int color);
void show_frame(int frame_length);
void draw_game_object(GameObject* gObj);


#endif //GRAPHICS_H
