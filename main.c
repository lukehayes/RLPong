#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float delta = 0.0;
float c = 0.0;

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    DisableCursor();

    Ball ball = createBall(10,10,10,10, 300.0);
    Paddle paddle = createPaddle(600,650,100,10, 300.0);

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

        BeginDrawing();
            ClearBackground(DARKGRAY);
            drawBall(&ball);
            drawPaddle(&paddle);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
