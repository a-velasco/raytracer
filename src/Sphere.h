#pragma once

#include <Eigen/Dense>
#include <opencv2/core/core.hpp>

using namespace Eigen;

class Sphere
{
private:
  Vector3d  _center;
  double    _radius;
  cv::Vec3b _color;

public:
  Sphere(const Vector3d &center, const double &radius, cv::Vec3b &color );

  Vector3d getCenter() const;

  double getRadius() const;

  cv::Vec3b getColor();
};
