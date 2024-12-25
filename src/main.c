#include "raylib.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include "shape.h"
#include <stdio.h>
#include <math.h>

int main() {
  float alpha = M_PI / 8;
  float beta = M_PI / 16;
  float gamma = M_PI / 32;
  int fov = 10;
  int scale = 100;
  Shape shape = new_cube();

  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(1280, 800, "Hello Raylib");
  SetTargetFPS(100);
  SearchAndSetResourceDir("resources");


  int i = 0;
  float dt;
  // game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawFPS(50, 50);

    rotate_shape(&shape, alpha, beta, gamma, GetFrameTime());
    draw_shape_points(&shape, fov, scale);
    draw_shape_edges(&shape, fov, scale);

    EndDrawing();

    i++;
    // if (i > 5) break;
  }

  shape_free(&shape);
  CloseWindow();
  return 0;
}
