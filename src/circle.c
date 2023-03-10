#include "circle.h"

Circle createCircle(int x, int y, float r, Color c)
{
  Circle circle = {.x = x, .y = y, .radius = r, .color = c};
  return circle;
}

void drawCircle(Circle* circle)
{
  DrawCircleLines(
      circle->x,
      circle->y,
      circle->radius,
      circle->color
  );
}
