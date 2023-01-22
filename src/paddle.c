#include "paddle.h"
#include <stdio.h>

Paddle createPaddle(int x, int y, int w, int h, float speed)
{
    Paddle paddle = {.rect = {x,y,w,h}};
    paddle.dx = 1;
    paddle.dy = 1;
    paddle.speed = speed;
    paddle.color = LIGHTGRAY;
    return paddle;
}

void updatePaddle(Paddle* paddle, float delta)
{
    paddle->rect.x = GetMouseX();
}

void drawPaddle(Paddle* paddle)
{
    DrawRectangle(
        paddle->rect.x,
        paddle->rect.y,
        paddle->rect.width,
        paddle->rect.height,
        paddle->color
    );
}
