#include "food.h"
#include "gba.h"
#include "video.h"

#include <stdlib.h>

Food createFood(void) {
    Food f;
    randomizeFoodPosition(&f);
    return f;
}

void randomizeFoodPosition(Food *f) {
    f->x = rand() % GAME_WIDTH;
    f->y = rand() % GAME_HEIGHT;
}

void drawFood(const Food *f) {
    drawPixel(f->x, f->y, RGB(31, 0, 0));
}