#include "fps.h"

static int targetTicksPerFrame = 0;
static u16 startTick = 0;

static int lastFrame = 0;
static int frameCount = 0;
static int currentFPS = 0;

static float deltaTime = 0.0f;

#define TICKS_PER_SECOND 65536.0f

void initFPS(int targetFPS) {
    *(u16*)0x400010A = 0x82;     // enable timer for fps
    *(u16*)0x400010E = 0x84;     // cnt timer overflow

    startTick = REG_TM2D;
    targetTicksPerFrame = 65536 / targetFPS;

    lastFrame = REG_TM2D >> 12;
    frameCount = 0;
    currentFPS = 0;

    deltaTime = 0.0f;
}

void waitForNextFrame(void) {
    u16 currentTick;
    do {
        currentTick = REG_TM2D;
    } while ((u16)(currentTick - startTick) < targetTicksPerFrame);

    deltaTime = (u16)(currentTick - startTick) / TICKS_PER_SECOND;
    startTick = currentTick;
}

void updateFPS(void) {
    int timerFrame = REG_TM2D >> 12;
    if (timerFrame != lastFrame) {
        frameCount++;
        lastFrame = timerFrame;
    }

    // When timer wraps (0xF -> 0x0), 1 second has passed
    if (timerFrame == 0) {
        currentFPS = frameCount;
        frameCount = 0;
    }
}

int getFPS(void) {
    return currentFPS;
}

float getDeltaTime(void) {
    return deltaTime;
}
