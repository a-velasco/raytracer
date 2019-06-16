#pragma once

#include <Eigen/Dense>
#include <vector>
#include <map>

#include "Ray.h"

using namespace Eigen;

class Camera
{
private:
  Vector3d _origin;
  float    _fov; // TODO: relate to alpha
  Vector2d _resolution; // (width, height)

public:
  Camera( const Vector3d &origin, const float &fov, const Vector2d &resolution );

  std::map< std::vector<int>, Ray > getAllRays(); // Function for precomputing all rays

  Vector2d getResolution()
  {
  	return _resolution;
  }

  float getFOV()
  {
  	return _fov;
  }

};
