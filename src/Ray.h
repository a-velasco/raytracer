#pragma once

#include <vector>

#include <Eigen/Dense>

using namespace Eigen;

class Ray
{

  typedef Vector3d                  PointType;
  typedef std::vector< PointType >  PointTypeVector;

private:
  PointType _origin;
  PointType _dir;

public:
  Ray( PointType origin, PointType dir );

  PointType getOrigin() const;
  PointType getDirection() const;
};
