#ifndef DIP_H
#define DIP_H

#include "startup.h"
#include "gameobject.h"

//extern GameObject DIPObj;
void init_DIP( GameObject *DIPObj );
void DIPUpdate(GameObject *this);
void setPlayerPosition(int x, int y);

#define DIP_WIDTH 18
#define DIP_HEIGHT 18
#define RIGHT_POINT (MAP_WIDTH - DIP_WIDTH - 3)
#define LEFT_POINT (MAP_WIDTH/2 - DIP_WIDTH)

#endif // DIP_H