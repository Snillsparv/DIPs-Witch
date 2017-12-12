#include "sprite.h"

void load_sprite(sprite* s, unsigned char* data, int width, int height)
{
	s->width = width;
	s->height = height;
	s->data = data;
}

/*sprite* give_me_a_sprite_pointer(unsigned char* data, int width, int height) {
	sprite tempSprite;
	sprite *mySprite = &tempSprite;
	load_sprite(mySprite, data, width, height);
	return mySprite;
}*/