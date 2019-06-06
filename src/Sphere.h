#pragma once

#include <Eigen/Dense>

using namespace Eigen;

class Sphere
{
private:
  Vector3d _center;
  double   _radius;

public:
  Sphere(Vector3d center, double radius);

  Vector3d getCenter() const;

  double getRadius() const;

};
