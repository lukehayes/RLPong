
#include "ball.h"
#include <stdio.h>

Ball createBall(int x, int y, int w, int h, float speed)
{
    Ball ball = {.rect = {x,y,w,h}};
    ball.dx = 1;
    ball.dy = 1;
    ball.speed = speed;
    ball.color = LIGHTGRAY;
    return ball;
}

void checkScreenEdgeCollision(Ball* ball)
{
    if(ball->rect.x < 0 || ball->rect.x > 1260)
    {
        ball->dx = -ball->dx;
        printf("Collision X \n");
    }

    if(ball->rect.y < 0 || ball->rect.y > 700)
    {
        printf("Collision Y \n");
        ball->dy = -ball->dy;
    }
}

void updateBall(Ball* ball, float delta)
{
    checkScreenEdgeCollision(ball);

    ball->rect.x += ball->dx * ball->speed * delta; 
    ball->rect.y += ball->dy * ball->speed * delta; 
}

void drawBall(Ball* ball)
{
    DrawRectangle(
        ball->rect.x,
        ball->rect.y,
        ball->rect.width,
        ball->rect.height,
        ball->color
    );
}
