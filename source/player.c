#include "player.h"
#include "video.h"

void handleInput(Player *p) {
    if (KEY_RIGHT) { p->x += p->speed; if (p->x > GAME_WIDTH - 1) { p->x = GAME_WIDTH - 1; }}
    if (KEY_LEFT) { p->x -= p->speed; if (p->x < 0) { p->x = 0; }}
    if (KEY_UP) { p->y -= p->speed; if (p->y < 0) { p->y = 0; }}
    if (KEY_DOWN) { p->y += p->speed; if (p->y > GAME_HEIGHT - 1) { p->y = GAME_HEIGHT - 1; }}
}

void drawPlayer(const Player *p) {
    drawPixel(p->x, p->y, RGB(0, 0, 0));
}