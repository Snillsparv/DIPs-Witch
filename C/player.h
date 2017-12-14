#ifndef PLAYER
#define PLAYER

#include "startup.h"
#include "gameobject.h"

void playerUpdate(GameObject *this);
void playerReset(void);

#define PLAYER_WIDTH 18
#define PLAYER_HEIGHT 18
#define SPEED_ADD_X 3
#define SPEED_ADD_Y 4
#define LIMIT_RIGHT (MAP_WIDTH - PLAYER_WIDTH)
#define LIMIT_LEFT 0
#define LIMIT_DOWN (MAP_HEIGHT - PLAYER_HEIGHT - 7)

#endif // PLAYER