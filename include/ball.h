#pragma once


typedef struct Ball
{
    float x;
    float y;
    float w;
    float h;
    Color color;
} Ball;

Ball createBall(int x, int y, int w, int h)
{
    Ball ball = {.x = x, .y = y, .w = w, .h = h};
    ball.color = LIGHTGRAY;
    return ball;
}
