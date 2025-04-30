#ifndef FPS_H
#define FPS_H

#pragma once
#include "gba.h"

void initFPS(int targetFPS);
void waitForNextFrame(void);
void updateFPS(void);
int  getFPS(void);
float getDeltaTime(void);

#endif
