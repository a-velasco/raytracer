#include <iostream>
#include <vector>
#include <math.h>

#include <Eigen/Dense>
#include "Ray.h"
#include "Camera.h"

using namespace Eigen;

// Coordinate system: OpenGL

Camera::Camera( const Vector3d &origin, const float &fov, const Vector2d &resolution ):
        _origin(origin), _fov(fov), _resolution(resolution) {};

// Given a viewport size (image resolution), origin, and focal point, compute
// all rays at once and store in a vector.
std::vector<Ray> Camera::getAllRays()
{
  int numPixels = int(_resolution.x() * _resolution.y());
  std::vector<Ray> rays;
  rays.reserve(numPixels); // Reserve empty vec of size numPixels
  
  // For each pixel, get its location in world coordinates and compute ray
  // from origin to pixelpoint.
  double aspectRatio = _resolution.x()/_resolution.y();
  double scale = tan(_fov * (M_PI/180.) * 0.5);
  for( int x = 0; x < _resolution.x(); x++ )
  {
    for( int y = 0; y < _resolution.y(); y++ )
    {
      double pixCameraX = (2 * ((x + 0.5) /  _resolution.x()) - 1) * aspectRatio * scale;
      double pixCameraY = (1 - 2 * (y + 0.5) /  _resolution.y()) * scale; 

      // Compute ray from origin to current pixel
      Vector3d rayDirection( pixCameraX, pixCameraY, -1. ); // - rayOrigin?

      Ray currentRay(_origin, rayDirection);
      rays.push_back(currentRay);
    }
  }

  return rays;
}
