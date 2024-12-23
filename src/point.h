#ifndef POINT_H
#define POINT_H

struct Point2D {
  float x;
  float y;
} typedef Point2D;

struct Point3D {
  float x;
  float y;
  float z;
} typedef Point3D;

Point2D newPoint2D(float x, float y);
Point3D newPoint3D(float x, float y, float z);
Point3D rotatePoint3D(Point3D p, float alpha, float beta, float gamma, float dt);
Point2D project(Point3D p, int fov, int scale);

#endif // !POINT_H
