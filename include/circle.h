#pragma once

#include "raylib.h"

typedef struct Circle
{
  int x;
  int y;
  float radius;
  Color color;

} Circle;

Circle createCircle(int x, int y, float r, Color c);

void drawCircle(Circle* circle);
