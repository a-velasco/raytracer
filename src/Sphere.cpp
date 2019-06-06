#include "Sphere.h"

using namespace Eigen;

Sphere::Sphere(Vector3d center, double radius): _center(center), _radius(radius) {};

Vector3d Sphere::getCenter() const
{
  return _center;
}

double Sphere::getRadius() const
{
  return _radius;
}
