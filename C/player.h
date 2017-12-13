#ifndef PLAYER
#define PLAYER

void playerUpdate(GameObject *this);

#define PLAYER_WIDTH 18
#define PLAYER_HEIGHT 18
#define SPEED_ADD_X 3
#define SPEED_ADD_Y 4
#define LIMIT_RIGHT (MAP_WIDTH - PLAYER_WIDTH)
#define LIMIT_LEFT 0
#define LIMIT_DOWN (MAP_HEIGHT - PLAYER_HEIGHT - 7)
#define MAP_HEIGHT 64
#define MAP_WIDTH 128
#define PLATFORM_Y 23

#endif // PLAYER