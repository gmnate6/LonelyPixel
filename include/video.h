#ifndef VIDEO_H
#define VIDEO_H

#include "gba.h"

#define RGB15(r, g, b) (r + (g<<5) + (b<<10))

void drawPixel(int x, int y, u16 color);
void drawBox(int x, int y, int width, int height, u16 color);
void initVideo(void);
void clearBackground(void);
void swapBuffers(void);

#endif