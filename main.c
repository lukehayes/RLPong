#include "raylib.h"
#include "ball.h"
#include <math.h>
#include <stdio.h>

float delta = 0.0;
float c = 0.0;

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    Ball ball = createBall(10,10,10,10, 300.0);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        updateBall(&ball, delta);

        BeginDrawing();
            ClearBackground(DARKGRAY);
            drawBall(&ball);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
