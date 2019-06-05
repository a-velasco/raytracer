#include <iostream>
#include <vector>

#include <Eigen/Dense>
#include "Ray.h"
#include "Camera.h"

// Note about coordinate systems:
//

Camera::Camera( const Vector3d &origin, const float &focal, const Vector2d &resolution ):
        m_origin(origin), m_focal(focal), m_resolution(resolution) {};

// Given a viewport size (image resolution), origin, and focal point, compute
// all rays at once and store in a vector.
std::vector<Ray> Camera::getAllRays()
{/*
  int numPixels = m_resolution.x * m_resolution.y;
  std::vector<Ray> rays;
  rays.reserve(numPixels); // Reserve empty vec of size numPixels

  // For each pixel, get its location in world coordinates and compute ray
  // from origin to pixelpoint.
  for( int j = 0; j < m_resolution.x; j++ )
  {
    for( int i = 0; i < m_resolution.y; i++ )
    {

    }
  }

  return rays;
  */
}
