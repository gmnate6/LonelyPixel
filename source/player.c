#include "player.h"

void handleInput(Player *p) {
    if (KEY_R) { p->x += p->speed; if (p->x > GAME_WIDTH - 1) { p->x = GAME_WIDTH - 1; }}
    if (KEY_L) { p->x -= p->speed; if (p->x < 0) { p->x = 0; }}
    if (KEY_U) { p->y -= p->speed; if (p->y < 0) { p->y = 0; }}
    if (KEY_D) { p->y += p->speed; if (p->y > GAME_HEIGHT - 1) { p->y = GAME_HEIGHT - 1; }}
}

void drawPlayer(const Player *p) {
    VRAM[p->y * SCREEN_WIDTH + p->x] = RGB(0, 0, 0);
}