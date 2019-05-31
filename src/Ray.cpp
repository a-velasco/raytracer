#include <iostream>

#include <Eigen/Dense>
#include "Ray.h"
#include "Sphere.h"

bool Ray::intersects( const Sphere &sphere )
{
  std::cout << "  Ray::intersects(sphere)" << std::endl;
  Vector3d displacement = m_origin - sphere.getCenter();
  Vector3d direction = m_dir;

  double a = direction.squaredNorm();

  std::cout << "  a should be 1: " << a << std::endl;

  return true;
}
