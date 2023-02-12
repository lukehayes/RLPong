#include "rocket.h"
#include "raylib.h"
#include "raymath.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Rocket createRocket(int x, int y, float s, Color c)
{
  Rocket rocket = {.position = {x,y}, .speed = s, .color = c};
  rocket.isMoving = true;
  return rocket;
}

Rocket* createRocketPtr(int x, int y, float s, Color c)
{
  Rocket* rocket = malloc(sizeof(Rocket));
  rocket->position.x = x;
  rocket->position.y = y;
  rocket->isMoving = true;
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

  float distanceToTarget = Vector2Distance(r->position, r->target);



  if(distanceToTarget > 1 && r->isMoving)
  {
    r->position.x -= cos(angle) *  r->speed;
    r->position.y -= sin(angle) *  r->speed;
  }else
  {
    r->isMoving = false;
  }
}

void drawRocket(Rocket* r)
{
  DrawRectangle(
    r->position.x,
    r->position.y,
    10,10,
    r->color
  );

  // DrawLine(1280 / 2, 720, r->position.x + 2, r->position.y +2, BLUE);
}
