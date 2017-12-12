#ifndef SPRITE_H
#define SPRITE_H


typedef struct
{
	unsigned int width;
	unsigned int height;
	unsigned char *data;
} sprite;

void load_sprite(sprite* s, unsigned char* data, int width, int height);
//sprite* give_me_a_sprite_pointer(unsigned char* data, int width, int height);


#endif //SPRITE_H