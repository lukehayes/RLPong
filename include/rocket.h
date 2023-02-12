#pragma once

#include "raylib.h"

typedef struct Rocket
{
  Vector2 position;
  Vector2 target;
  float speed;
  Color color;
  bool isMoving;

} Rocket;

Rocket createRocket(int x, int y, float s, Color c);

Rocket* createRocketPtr(int x, int y, float s, Color c);

void setRocketTarget(Rocket* r, Vector2 t);

void updateRocket(Rocket* r);

void drawRocket(Rocket* r);
