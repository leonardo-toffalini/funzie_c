#include "point.h"
#include <math.h>
#include <stdio.h>

// hardcoded values for now
const float windowWidth = 1280.0f;
const float windowHeight = 800.0f;

Point3D newPoint3D(float x, float y, float z) {
  Point3D p = {x, y, z};
  return p;
}

Point2D newPoint2D(float x, float y) {
  Point2D p = {x, y};
  return p;
}

Point3D rotatePoint3D(Point3D p, float alpha, float beta, float gamma,
                      float dt) {
  // dt = dt < 0.1 ? 0.1 : dt;
  dt = 0.01f;
  alpha = alpha * dt;
  beta = beta * dt;
  gamma = gamma * dt;
  float newX = p.x * (cos(alpha) * cos(beta)) + p.y * (sin(alpha) * cos(beta)) -
               p.z * sin(beta);
  float newY =
      p.x * (cos(alpha) * sin(beta) * sin(gamma) - sin(alpha) * cos(gamma)) +
      p.y * (sin(alpha) * sin(beta) * sin(gamma) + cos(alpha) * cos(gamma)) +
      p.z * cos(beta) * sin(gamma);
  float newZ =
      p.x * (cos(alpha) * sin(beta) * cos(gamma) + sin(alpha) * sin(gamma)) +
      p.y * (sin(alpha) * sin(beta) * cos(gamma) - cos(alpha) * sin(gamma)) +
      p.z * cos(beta) * cos(gamma);

  return newPoint3D(newX, newY, newZ);
}

Point2D project(Point3D p, int fov, int scale) {
  // project, then translate coordinates to the center and magnify
  return newPoint2D(windowWidth / 2 + scale * (p.x * fov) / (p.z + fov),
                    windowHeight / 2 + scale * (p.y * fov) / (p.z + fov));
}
