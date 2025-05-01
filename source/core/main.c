#include "video.h"
#include "fps.h"
#include "game.h"

int main() {
    initVideo();
	initFPS(60);
    initGame();

    while (1) {
		waitForNextFrame();
        clearBackground();

        updateGame();
		renderGame();

        updateFPS();
        swapBuffers();
    }
    return 0;
}
