#include <iostream>

#include "Ray.h"

Ray::Ray( PointType origin, PointType dir )
{
  _origin = origin;

  // Make sure direction is normalized
  _dir = dir.normalized();
}

Ray::PointType Ray::getOrigin() const
{
  return _origin;
}

Ray::PointType Ray::getDirection() const
{
  return _dir;
}
