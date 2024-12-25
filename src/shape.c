#include "shape.h"
#include "point.h"
#include "raylib.h"
#include <stdio.h>

Shape newLine() {
  Point3D start = {1, 1, 1};
  Point3D finish = {1, 0, 1};
  return (Shape){{start, finish}, {}};
}

void rotateShape(Shape *s, float alpha, float beta, float gamma, float dt) {
  int i = 0;
  while (s->points[i] != NULL) {
    s->points[i] = rotatePoint3D(s->points[i], alpha, beta, gamma, dt);
    i++;
  }
}

void drawShapePoints(Shape *s, int fov, int scale) {
  int i = 0;
  while (s->points[i] != NULL) {
    Point2D pp = project(s->points[i], fov, scale);
    DrawPixel(pp.x, pp.y, WHITE);
    printf("%d", i);
    i++;
  }
  printf("\n");
}

void drawShapeEdges(Shape *s, int fov, int scale);
void drawShape(Shape *s, char mode, int fov, int scale);
