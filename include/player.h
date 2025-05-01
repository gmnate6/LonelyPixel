#ifndef PLAYER_H
#define PLAYER_H

#include "gba.h"

typedef struct Player {
    int x;
    int y;
    int speed;
    int size;
} Player;

Player createPlayer(void);
void clampPlayerToBounds(Player *p);
void growPlayer(Player *p);
void handlePlayerInput(Player *p);
void drawPlayer(const Player *p);

#endif