#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "image.h"

typedef struct tGameObject {
    Image*		images;	//list of animation frames
	int			xPos;
	int			yPos;

    // methods:
    void        (*update) (struct tGameObject *this);
    void        (*render) (struct tGameObject* gameobj);

	// animation:
	int 		current_frame;
	int			n_frames;
	int			animation_speed;
	int			animation_counter;

} GameObject;

void gameObjectUpdate(GameObject *this);
void render(GameObject* this); // metod

extern GameObject* gameObjects[];
extern int nGameObjects;

#endif // GAMEOBJECT_H