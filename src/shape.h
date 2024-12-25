#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

struct Shape {
  Point3D *points;
  int *edges[2];
} typedef Shape;

Shape newLine();
Shape newCube();

void rotateShape(Shape *s, float alpha, float beta, float gamma, float dt);
void drawShapePoints(Shape *s, int fov, int scale);
void drawShapeEdges(Shape *s, int fov, int scale);
void drawShape(Shape *s, char mode, int fov, int scale);

#endif // !SHAPE_H
