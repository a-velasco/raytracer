#pragma once

#include <Eigen/Dense>
#include <opencv2/core/core.hpp>

#include "Ray.h"

using namespace Eigen;

class Sphere
{
  typedef Vector3d                  PointType;
  typedef std::vector< PointType >  PointTypeVector;

  typedef cv::Vec3b BGRColorType;

private:
  PointType     _center;
  double        _radius;
  BGRColorType  _color;

public:
  Sphere(const PointType &center, const double &radius, BGRColorType &color );

  bool intersects( const Ray &ray, PointType &coords );

  PointType getCenter() const;

  double getRadius() const;

  BGRColorType getColor();
};
