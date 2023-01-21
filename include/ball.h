#pragma once
#include <stdio.h>

typedef struct Ball
{
    float x;
    float y;
    float w;
    float h;
    float dx;
    float dy;
    float speed;
    Color color;
} Ball;

Ball createBall(int x, int y, int w, int h, float speed)
{
    Ball ball = {.x = x, .y = y, .w = w, .h = h};
    ball.dx = 1;
    ball.dy = 1;
    ball.speed = speed;
    ball.color = LIGHTGRAY;
    return ball;
}

void checkScreenEdgeCollision(Ball* ball)
{
    if(ball->x < 0 || ball->x > 1260)
    {
        ball->dx = -ball->dx;
        printf("Collision X \n");
    }

    if(ball->y < 0 || ball->y > 700)
    {
        printf("Collision Y \n");
        ball->dy = -ball->dy;
    }
}

void updateBall(Ball* ball, float delta)
{
    checkScreenEdgeCollision(ball);

    ball->x += ball->dx * ball->speed * delta; 
    ball->y += ball->dy * ball->speed * delta; 
}

void drawBall(Ball* ball)
{
    DrawRectangle(
        ball->x,
        ball->y,
        ball->w,
        ball->h,
        ball->color
    );
}
