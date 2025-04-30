#include "game.h"
#include "player.h"

static Player player;

void initGame(void) {
    player.x = GAME_WIDTH / 2;
    player.y = GAME_HEIGHT / 2;
    player.speed = 1;
}

void updateGame(void) {
    handleInput(&player);
}

void renderGame(void) {
    drawPlayer(&player);
}