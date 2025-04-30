#ifndef FPS_H
#define FPS_H

void initFPS(int targetFPS);
void waitForNextFrame(void);
void updateFPS(void);
int  getFPS(void);
float getDeltaTime(void);

#endif
