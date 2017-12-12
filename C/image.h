#ifndef IMAGE_H
#define IMAGE_H

#include "sprite.h"

typedef struct tImage {
    sprite*		blackImage;
	sprite*		grayImage;
	sprite*		lightImage;
} Image;


void load_image( Image *image, sprite *blackImage, sprite *grayImage, sprite *lightImage );

#endif // IMAGE_H