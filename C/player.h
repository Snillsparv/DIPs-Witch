#ifndef PLAYER
#define PLAYER

void playerUpdate(GameObject *this);

#define PLAYER_WIDTH 18
#define PLAYER_HEIGHT 18
#define SPEED_ADD 3
#define LIMIT_RIGHT (128 - PLAYER_WIDTH)
#define LIMIT_LEFT 0

#endif // PLAYER