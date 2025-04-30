#include "video.h"
#include "fps.h"
#include "game.h"

int main() {
    initVideo();
	initFPS(30);
    initGame();

    while (1) {
		waitForNextFrame();
        clearBackground();

        updateGame();
		renderGame();

        updateFPS();
        swapBuffers();
    }
}
