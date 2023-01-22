#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float delta = 0.0;
float c = 0.0;
int COUNT = 10;

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    DisableCursor();

    Ball ball = createBall(10,10,10,10, 300.0);
    Paddle paddle = createPaddle(600,650,100,10, 300.0);

    Ball balls[COUNT];

    for(int i = 0; i<= COUNT; i++)
    {
        int rx = GetRandomValue(10,40);
        int ry = GetRandomValue(10,40);
        int dx = GetRandomValue(-1,1);
        balls[i] = createBall(i * rx,  i * rx, 10,10, 300.0);
        balls[i].dx = dx;
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        if(CheckCollisionRecs(ball.rect, paddle.rect))
        {
            switch(GetRandomValue(1,4))
            {
                case 1:
                    ball.dx = -ball.dx;
                    break;
                case 2:
                    ball.dy = -ball.dy;
                    break;
                case 3:
                    ball.dx = -ball.dx;
                    ball.dy = -ball.dy;
                    break;
            }
        }

        updateBall(&ball, delta);
        updatePaddle(&paddle, delta);

        for(int i = 0; i<= COUNT; i++)
        {
            Ball* b = &balls[i];
            updateBall(b, delta);
        }

        BeginDrawing();
            ClearBackground(DARKGRAY);
            drawBall(&ball);
            drawPaddle(&paddle);

            for(int i = 0; i<= COUNT; i++)
            {
                Ball b = balls[i];
                drawBall(&b);
            }

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
