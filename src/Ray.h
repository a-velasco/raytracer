#pragma once

#include <Eigen/Dense>
#include "Sphere.h"

using namespace Eigen;

class Ray
{
private:
  Vector3d _origin;
  Vector3d _dir;

public:
  Ray( Vector3d origin, Vector3d dir );

  bool intersects( const Sphere &sphere, double &root );

  Vector3d getOrigin()
  {
  	return _origin;
  }

  Vector3d getDirection()
  {
  	return _dir;
  }
};
