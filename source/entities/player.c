#include "player.h"
#include "video.h"

Player createPlayer(void) {
    Player p;
    p.x = GAME_WIDTH / 2;
    p.y = GAME_HEIGHT / 2;
    p.speed = 1;
    p.size = 1;
    return p;
}

void clampPlayerToBounds(Player *p) {
    if (p->x < 0) { p->x = 0; }
    if (p->y < 0) { p->y = 0; }
    if (p->x + p->size > GAME_WIDTH) { p->x = GAME_WIDTH - p->size; }
    if (p->y + p->size > GAME_HEIGHT) { p->y = GAME_HEIGHT - p->size; }
}

void growPlayer(Player *p) {
    p->size += 1;
}

void handlePlayerInput(Player *p) {
    if (KEY_RIGHT) { p->x += p->speed; }
    if (KEY_LEFT)  { p->x -= p->speed; }
    if (KEY_UP)    { p->y -= p->speed; }
    if (KEY_DOWN)  { p->y += p->speed; }
}

void drawPlayer(const Player *p) {
    drawBox(p->x, p->y, p->size, p->size, RGB15(0, 0, 0));
}