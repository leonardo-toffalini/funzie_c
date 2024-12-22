#include "raylib.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir

int main() {
  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(1280, 800, "Hello Raylib");

  SearchAndSetResourceDir("resources");

  // Load a texture from the resources directory
  Texture wabbit = LoadTexture("wabbit_alpha.png");

  // game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("Hello Raylib", 600, 400, 20, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
