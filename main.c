#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include "circle.h"
#include "rocket.h"
#include "logging.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float delta = 0.0;
float c = 0.0;
int MAX = 5;
Color BGCOLOR = {250, 243, 221, 255};

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    Rocket r = createRocket(10,10, 2.0, RED);

    int rocket_count = 0;
    Rocket rockets[MAX];

    for(int i = 0; i <= MAX - 1; i++)
    {
        Rocket r = createRocket(1280 / 2, 720, 5.0, BLUE);
        r.isMoving = false;
        rockets[i] = r;
    }
    
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

        if(IsMouseButtonPressed(0))
        {
            printf("ROCKET LAUNCHED: %i \n", rocket_count);
            Vector2 mp = GetMousePosition();
            Rocket r = createRocket(1280 / 2, 720, 5.0, RED);
            r.isMoving = true;
            setRocketTarget(&r, mp);

            rockets[rocket_count] = r;

            rocket_count += 1;
        }

        Vector2 target = GetMousePosition();
        setRocketTarget(&r, target);

        BeginDrawing();
            ClearBackground(BGCOLOR);

            drawRocket(&r);

            for(int i = 0; i <= MAX - 1; i++)
            {
                Rocket* r = &rockets[i];
                updateRocket(r);
                drawRocket(r);
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
