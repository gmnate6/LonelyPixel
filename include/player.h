#ifndef PLAYER_H
#define PLAYER_H

#include "gba.h"

typedef struct Player {
    int x;
    int y;
    int speed;
} Player;

void handleInput(Player *p);
void drawPlayer(const Player *p);

#endif