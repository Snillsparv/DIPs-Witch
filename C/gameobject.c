#include "gameobject.h"

GameObject* gameObjects[100];
int nGameObjects = 0;


void render(GameObject* this)
{
    
}

void gameObjectUpdate(GameObject *this) {
	this->animation_counter++;
	if (this->animation_counter == this->animation_speed) {
		this->animation_counter = 0;
		this->current_frame = (this->current_frame + 1) % this->n_frames;
	}
}


