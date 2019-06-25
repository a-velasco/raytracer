#pragma once

#include <Eigen/Dense>
#include <vector>
#include <map>

#include "Ray.h"

using namespace Eigen;

class Camera
{
  typedef Vector3d PointType;
  
private:
  PointType _origin;
  float    _fov;
  Vector2i _resolution; // (width, height)

public:
  Camera( const PointType &origin, const float &fov, const Vector2i &resolution );

  std::map< std::vector<int>, Ray > getAllRays(); // Function for precomputing all rays

  Vector2i getResolution()
  {
  	return _resolution;
  }

  float getFOV()
  {
  	return _fov;
  }

};
