#include "raylib.h"
#include "math.h"
#include <stdio.h>

typedef struct Rocket
{
  Vector2 position;
  Vector2 target;
  float speed;
  Color color;

} Rocket;

Rocket createRocket(int x, int y, float s, Color c)
{
  Rocket rocket = {.position = {x,y}, .speed = s, .color = c};
  return rocket;
}

void setRocketTarget(Rocket* r, Vector2 t)
{
  r->target = t;
}

void updateRocket(Rocket* r)
{
  float angle = atan2(
      r->position.y - r->target.y,
      r->position.x - r->target.x
  );

  bool targetReached = (r->position.x == r->target.x) && (r->position.y == r->target.y);

  r->position.x -= cos(angle) *  r->speed;
  r->position.y -= sin(angle) *  r->speed;
}

void drawRocket(Rocket* r)
{
  DrawRectangle(
    r->position.x,
    r->position.y,
    10,10,
    r->color
  );

  DrawLine(1280 / 2, 720, r->position.x + 2, r->position.y +2, BLUE);
}
