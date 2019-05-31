#pragma once

#include <Eigen/Dense>
#include "Sphere.h"

using namespace Eigen;

class Ray
{
private:
  Vector3d m_origin;
  Vector3d m_dir;

public:
  Ray( Vector3d origin, Vector3d dir ):
       m_origin(origin), m_dir(dir) {};

  bool intersects( const Sphere &sphere );
};