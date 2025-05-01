#include "fps.h"
#include "gba.h"

/* ------------------------------------------------------------------ */
/*  Timer-2 configuration                                             */
/* ------------------------------------------------------------------ */
#define TIMER2_PRESCALER 256u                    /* /256  → 65 536 Hz */
static const float TICKS_PER_SECOND =
        (float) GBA_CLOCK_HZ / (float) TIMER2_PRESCALER;

/* ------------------------------------------------------------------ */
/*  Module-private state                                              */
/* ------------------------------------------------------------------ */
static int  targetTicksPerFrame = 0;
static u16  startTick           = 0;

static int  lastFrame  = 0;
static int  frameCount = 0;
static int  currentFPS = 0;

static float deltaTime = 0.0f;

/* ------------------------------------------------------------------ */
/*  Public functions                                                  */
/* ------------------------------------------------------------------ */
void initFPS(int targetFPS) {
    /* Enable Timer-2 with /256 prescaler (0x0082) */
    REG_TM2CNT_H = TM_ENABLE | TM_PRESCALE_256;

    startTick             = REG_TM2CNT_L;
    targetTicksPerFrame   = (int) (TICKS_PER_SECOND / targetFPS);

    lastFrame             = REG_TM2CNT_L >> 12;
    frameCount            = 0;
    currentFPS            = 0;
    deltaTime             = 0.0f;
}

void waitForNextFrame(void) {
    u16 currentTick;
    do {
        currentTick = REG_TM2CNT_L;
    } while ((u16) (currentTick - startTick) < targetTicksPerFrame);

    deltaTime = (float) (u16) (currentTick - startTick) / TICKS_PER_SECOND;
    startTick = currentTick;
}

void updateFPS(void) {
    int timerFrame = REG_TM2CNT_L >> 12;
    if (timerFrame != lastFrame) {
        ++frameCount;
        lastFrame = timerFrame;
    }

    // When the 4-bit “frame counter” wraps, one second has elapsed
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