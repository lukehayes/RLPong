#include "raylib.h"
#include <math.h>

float delta = 0.0;
float c = 0.0;
float N = 100.0;

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        BeginDrawing();
            ClearBackground(DARKGRAY);

            for(int i = 0; i <= 100; i++)
            {

                /*DrawRectangle(100.0f * cos(i), 320 + (sin(c) * 100.0), 10, 10, LIGHTGRAY);*/
                DrawRectangle(640 + cos(i) * sin(c) * N , 360 + -sin(i) * cos(c) * N, 10,10, LIGHTGRAY);
            }
            /*DrawRectangle(1280/2 - 40, 320 + (sin(c) * 100.0), 80, 80, LIGHTGRAY);*/
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
