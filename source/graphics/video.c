#include "video.h"

void drawPixel(int x, int y, u16 color) {
    if (x < 0 || x >= GAME_WIDTH || y < 0 || y >= GAME_HEIGHT) {
        return;
    }
    VRAM[y * SCREEN_WIDTH + x] = color;
}

void drawBox(int x, int y, int width, int height, u16 color) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            drawPixel(x + i, y + j, color);
        }
    }
}

void initVideo(void) {
    // Init mode 5
    *(u16*)0x4000000 = 0x405;    // mode 5 background 2

    // Scale screen
    REG_BG2PA = 256 / 2;         // 256=normal 128=scale
    REG_BG2PD = 256 / 2;         // 256=normal 128=scale
}

void clearBackground(void) {
    for (int x = 0; x < GAME_WIDTH; x++) {
        for (int y = 0; y < GAME_HEIGHT; y++) {
            drawPixel(x, y, RGB(31, 31, 31));
        }
    }
}

void swapBuffers(void) {
    while (*Scanline < 160) {}
    if (DISPCNT & BACKB) {
        DISPCNT &= ~BACKB;
        VRAM = (u16*)VRAM_B;
    } else {
        DISPCNT |= BACKB;
        VRAM = (u16*)VRAM_F;
    }
}