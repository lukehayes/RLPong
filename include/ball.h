#pragma once

#include "raylib.h"

typedef struct Ball
{
    Rectangle rect;
    float dx;
    float dy;
    float speed;
    Color color;
} Ball;

Ball createBall(int x, int y, int w, int h, float speed);

void checkScreenEdgeCollision(Ball* ball);

void updateBall(Ball* ball, float delta);

void drawBall(Ball* ball);
