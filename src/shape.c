#include "shape.h"
#include "point.h"
#include "raylib.h"
#include "vector.h"
#include <stdio.h>

Shape newLine() {
  Point3D start = {1, 1, 1};
  Point3D finish = {1, 0, 1};
  Vector points = vector_init(sizeof(Point3D));
  vector_push_back(&points, &start);
  vector_push_back(&points, &finish);
  Vector edges = vector_init(sizeof(Edge));
  vector_push_back(&edges, &(Edge){0, 1});
  return (Shape){points, edges};
}

void rotateShape(Shape *s, float alpha, float beta, float gamma, float dt) {
  int i = 0;
  Point3D *curr;
  Point3D projected;
  while (i < s->points.size) {
    curr = vector_get(&s->points, i);
    projected = rotatePoint3D(*curr, alpha, beta, gamma, dt);
    vector_set(&s->points, i, &projected);
    i++;
  }
}

void drawShapePoints(Shape *s, int fov, int scale) {
  int i = 0;
  Point2D pp;
  while (i < s->points.size) {
    pp = project(vector_get(&s->points, i), fov, scale);
    DrawPixel(pp.x, pp.y, WHITE);
    i++;
  }
}

void drawShapeEdges(Shape *s, int fov, int scale) {
  int i = 0;
  Edge *e;
  Point3D *start, *finish;
  Point2D p_start, p_finish;
  while (i < s->edges.size) {
    e = vector_get(&s->edges, i);
    start = vector_get(&s->points, e->start);
    finish = vector_get(&s->points, e->finish);
    p_start = project(start, fov, scale);
    p_finish = project(finish, fov, scale);
    DrawLine(p_start.x, p_start.y, p_finish.x, p_finish.y, WHITE);
    i++;
  }
}

void drawShape(Shape *s, char mode, int fov, int scale);

void shape_free(Shape *s) { vector_free(&s->points); }
