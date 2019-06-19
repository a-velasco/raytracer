#include "Sphere.h"

using namespace Eigen;

Sphere::Sphere(const Vector3d &center, const double &radius, cv::Vec3b &color )
	           : _center(center), _radius(radius), _color(color) {};

Vector3d Sphere::getCenter() const
{
  return _center;
}

double Sphere::getRadius() const
{
  return _radius;
}

cv::Vec3b Sphere::getColor()
{
	return _color;
}

