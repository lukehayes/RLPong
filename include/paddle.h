#pragma once
#include "raylib.h"
#include <stdio.h>

typedef struct Paddle
{
    Rectangle rect;
    float dx;
    float dy;
    float speed;
    Color color;
} Paddle;

Paddle createPaddle(int x, int y, int w, int h, float speed);

void updatePaddle(Paddle* paddle, float delta);

void drawPaddle(Paddle* paddle);
