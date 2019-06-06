#pragma once

#include <Eigen/Dense>
#include <vector>
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

  struct RayProperties
  {
    Ray ray;
    int pixel_id;
  };

  std::vector<Ray> getAllRays(); // Function for precomputing all rays

};
