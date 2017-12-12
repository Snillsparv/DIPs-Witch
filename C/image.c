#include "image.h"

void load_image( Image *image, sprite *blackImage, sprite *grayImage, sprite *lightImage ) {
	image->blackImage = blackImage;
	image->grayImage = grayImage;
	image->lightImage = lightImage;
}
