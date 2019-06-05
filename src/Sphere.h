#pragma once

#include <Eigen/Dense>

using namespace Eigen;

class Sphere
{
private:
  Vector3d m_center;
  double   m_radius;

public:
  Sphere(Vector3d center, double radius);

  Vector3d getCenter() const;

  double getRadius() const;

};
