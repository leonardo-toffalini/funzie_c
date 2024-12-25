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

Shape newLine();
Shape newCube();

void rotateShape(Shape *s, float alpha, float beta, float gamma, float dt);
void drawShapePoints(Shape *s, int fov, int scale);
void drawShapeEdges(Shape *s, int fov, int scale);
void drawShape(Shape *s, char mode, int fov, int scale);
void shape_free(Shape *s);

#endif // !SHAPE_H
