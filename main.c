#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include "circle.h"
#include "rocket.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float delta = 0.0;
float c = 0.0;
int MAX = 10;
Color BGCOLOR = {250, 243, 221, 255};

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    Ball ball = createBall(10,10,10,10, 300.0);
    Paddle paddle = createPaddle(600,650,100,10, 300.0);

    Rocket r = createRocket(10,10, 1.0, RED);
    Vector2 target = GetMousePosition();
    setRocketTarget(&r, target);


    Circle circles[MAX];
    Color colors[3] = {
        {200,213,185,255},
        {104,175,101,255},
        {109,105,125,255},
    };

    for(int i = 0; i <= MAX - 1; i++)
    {
        int rx = GetRandomValue(10,1200);
        int ry = GetRandomValue(10,700);
        int rr = GetRandomValue(1.0,20.0);
        Color rc = colors[GetRandomValue(0,2)];
        Circle circle = createCircle(rx,ry,rr, rc);
        circles[i] = circle;
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        updateRocket(&r);

        BeginDrawing();
            ClearBackground(BGCOLOR);

            // for(int i = 0; i <= MAX - 1; i++)
            // {
            //     Circle circle = circles[i];
            //     circle.radius += sin(c) * 10;
            //     drawCircle(&circle);
            // }

            drawRocket(&r);

            // drawBall(&ball);
            // drawPaddle(&paddle);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
