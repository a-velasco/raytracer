#include <iostream>

#include <Eigen/Dense>
#include "Ray.h"
#include "Sphere.h"

bool Ray::intersects( const Sphere &sphere )
{
  Vector3d displacement = m_origin - sphere.getCenter();
  Vector3d direction = m_dir;

  double a = direction.squaredNorm();

  return true;
}
