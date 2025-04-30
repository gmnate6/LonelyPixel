#ifndef VIDEO_H
#define VIDEO_H

#include "gba.h"

#define RGB(r,g,b) ((r) + ((g)<<5) + ((b)<<10))

void initVideo(void);
void drawPixel(int x, int y, u16 color);
void clearBackground(void);
void swapBuffers(void);

#endif