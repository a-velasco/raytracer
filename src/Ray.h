#pragma once

#include <Eigen/Dense>
#include "Sphere.h"

using namespace Eigen;

class Ray
{
private:
  Vector3d m_origin;
  Vector3d m_dir;

  bool   m_hasRoot = false;
  double m_root = -1;

public:
  Ray( Vector3d origin, Vector3d dir );

  bool intersects( const Sphere &sphere );
};
