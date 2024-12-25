#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"
#include "vector.h"

typedef struct {
  int start;
  int finish;
} Edge;

typedef struct{
  Vector points;
  Vector edges;
} Shape;

Shape new_line();
Shape new_cube();

void rotate_shape(Shape *s, float alpha, float beta, float gamma, float dt);
void draw_shape_points(Shape *s, int fov, int scale);
void draw_shape_edges(Shape *s, int fov, int scale);
void draw_shape(Shape *s, char mode, int fov, int scale);
void shape_free(Shape *s);

#endif // !SHAPE_H
