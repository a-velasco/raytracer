#pragma once

#include <Eigen/Dense>
#include <vector>
#include <map>

#include "Ray.h"

using namespace Eigen;

class Camera
{
  typedef Vector3d PointType;
  typedef Vector2i ResolutionType;
  
private:
  PointType      _origin;
  ResolutionType _resolution;
  double          _fov;

public:
  Camera( const PointType &origin, const double &fov, const ResolutionType &resolution );

  std::map< std::vector<int>, Ray > getAllRays();

  ResolutionType getResolution() const;
  double 		 getFOV() const;

};
