#include "Sphere.h"

using namespace Eigen;

Sphere::Sphere(Vector3d center, double radius): m_center(center), m_radius(radius) {};

Vector3d Sphere::getCenter() const
{
  return m_center;
}

double Sphere::getRadius() const
{
  return m_radius;
}
