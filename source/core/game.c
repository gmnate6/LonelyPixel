#include "game.h"
#include "player.h"
#include "food.h"

#define min(a, b) ((a) < (b) ? (a) : (b))

static Player player;
static Food food;

void initGame(void) {
    player = createPlayer();
    food = createFood();
}

void onPlayerEatFood() {
    growPlayer(&player);
    randomizeFoodPosition(&food);
}

void updateGame(void) {
    handlePlayerInput(&player);

    // Check for collision with food
    if (food.x >= player.x && food.x < player.x + player.size &&
        food.y >= player.y && food.y < player.y + player.size) {
        onPlayerEatFood();
    }

    // Clamp player to bounds
    clampPlayerToBounds(&player);

    // Check death condition
    if (player.size >= min(GAME_WIDTH, GAME_HEIGHT)) {
        player = createPlayer(); // Reset player
    }
}

void renderGame(void) {
    drawPlayer(&player);
    drawFood(&food);
}