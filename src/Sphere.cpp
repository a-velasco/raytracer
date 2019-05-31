#include "Sphere.h"

using namespace Eigen;

Vector3d Sphere::getCenter() const
{
  return m_center;
}

double Sphere::getRadius() const
{
  return m_radius;
}
