#pragma once
#include <stdio.h>

typedef struct Paddle
{
    Rectangle rect;
    float dx;
    float dy;
    float speed;
    Color color;
} Paddle;

Paddle createPaddle(int x, int y, int w, int h, float speed)
{
    Paddle paddle = {.rect = {x,y,w,h}};
    paddle.dx = 1;
    paddle.dy = 1;
    paddle.speed = speed;
    paddle.color = LIGHTGRAY;
    return paddle;
}

//void checkScreenEdgeCollision(Paddle* paddle)
//{
    //if(paddle->rect.x < 0 || paddle->rect.x > 1260)
    //{
        //paddle->rect.dx = -paddle->rect.dx;
        //printf("Collision X \n");
    //}

    //if(paddle->rect.y < 0 || paddle->rect.y > 700)
    //{
        //printf("Collision Y \n");
        //paddle->rect.dy = -paddle->rect.dy;
    //}
//}

void updatePaddle(Paddle* paddle, float delta)
{
    //checkScreenEdgeCollision(paddle);

    paddle->rect.x = GetMouseX();

    //paddle->rect.x += paddle->rect.dx * paddle->rect.speed * delta; 
    //paddle->rect.y += paddle->rect.dy * paddle->rect.speed * delta; 
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
