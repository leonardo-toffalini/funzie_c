#ifndef POINT_H
#define POINT_H

typedef struct {
  float x;
  float y;
} Point2D;

typedef struct {
  float x;
  float y;
  float z;
} Point3D;

Point2D new_point2D(float x, float y);
Point3D new_point3D(float x, float y, float z);
Point3D rotate_point3D(Point3D p, float alpha, float beta, float gamma, float dt);
Point2D project(Point3D *p, int fov, int scale);

#endif // !POINT_H
