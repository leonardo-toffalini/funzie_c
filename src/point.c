#include "point.h"
#include <math.h>
#include <stdio.h>

// hardcoded values for now
const float windowWidth = 1280.0f;
const float windowHeight = 800.0f;

Point3D new_point3D(float x, float y, float z) { return (Point3D){x, y, z}; }

Point2D new_point2D(float x, float y) { return (Point2D){x, y}; }

Point3D rotate_point3D(Point3D p, float alpha, float beta, float gamma,
                      float dt) {
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

  return new_point3D(newX, newY, newZ);
}

Point2D project(Point3D *p, int fov, int scale) {
  // project, then translate coordinates to the center and magnify
  return new_point2D(windowWidth / 2 + scale * (p->x * fov) / (p->z + fov),
                    windowHeight / 2 + scale * (p->y * fov) / (p->z + fov));
}
