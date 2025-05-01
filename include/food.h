#ifndef FOOD_H
#define FOOD_H

typedef struct Food {
    int x;
    int y;
} Food;

Food createFood(void);
void randomizeFoodPosition(Food *p);
void drawFood(const Food *p);

#endif