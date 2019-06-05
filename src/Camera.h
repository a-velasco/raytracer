#pragma once

#include <Eigen/Dense>
#include <vector>
#include "Ray.h"

using namespace Eigen;

class Camera
{
private:
  Vector3d m_origin;
  float    m_focal;
  Vector2d m_resolution;

public:
  Camera( const Vector3d &origin, const float &focal, const Vector2d &resolution );

  struct RayProperties
  {
    Ray ray;
    int pixel_id;
  };

  std::vector<Ray> getAllRays(); // Function for precomputing all rays

};
