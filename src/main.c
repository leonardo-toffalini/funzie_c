#include "point.h"
#include "raylib.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include <stdio.h>
#include <math.h>

int main() {
  float alpha = M_PI / 8;
  float beta = M_PI / 16;
  float gamma = M_PI / 32;
  int fov = 10;
  int scale = 100;

  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(1280, 800, "Hello Raylib");

  SetTargetFPS(100);

  SearchAndSetResourceDir("resources");

  Point3D start = {1, 1, 1};
  Point2D startProjected = project(start, fov, scale);
  Point3D finish = {1, 0, 1};
  Point2D finishProjected = project(finish, fov, scale);

  int i = 0;
  float dt;
  // game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    // DrawLine(200, 200, 400, 400, WHITE);
    // DrawLine(50, 50, 50, 0, WHITE);
    dt = 1.0f / GetFPS();
    start = rotatePoint3D(start, alpha, beta, gamma, 1.0f / GetFPS());
    startProjected = project(start, fov, scale);
    DrawLine(startProjected.x, startProjected.y, finishProjected.x,
             finishProjected.y, WHITE);

    EndDrawing();

    i++;
    // if (i > 5) break;
  }

  CloseWindow();
  return 0;
}
