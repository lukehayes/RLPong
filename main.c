#include "raylib.h"
#include "ball.h"
#include <math.h>

float delta = 0.0;
float c = 0.0;

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    Ball ball = createBall(10,10,10,10);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawRectangle(1280/2 - 40, 320 + (sin(c) * 100.0), 80, 80, LIGHTGRAY);
            DrawRectangle(
                ball.x,
                ball.y,
                ball.w,
                ball.h,
                ball.color
            );
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
