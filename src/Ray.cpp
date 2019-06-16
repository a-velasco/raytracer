#include <iostream>

#include <Eigen/Dense>
#include "Ray.h"
#include "Sphere.h"

Ray::Ray( Vector3d origin, Vector3d dir )
{
  _origin = origin;

  // Make sure direction is normalized
  _dir = dir.normalized();
}

bool Ray::intersects( const Sphere &sphere, Vector3d &coords )
{
  Vector3d displacement = _origin - sphere.getCenter();

  double a = 1.; //_dir.squaredNorm();
  double b = 2 * _dir.dot(displacement);
  double c = displacement.squaredNorm() - sphere.getRadius()*sphere.getRadius();

  double disc = (b*b) - 4*a*c; // discriminant

  double q, x0, x1;
  if( disc < 0 ) { return false; }
  else if ( disc == 0 )
  {
    x0 = x1 =  -b/(2*a);
  }
  else
  {
    q = ( b > 0 ) ?
              -0.5 * (b + sqrt(disc)) :
              -0.5 * (b - sqrt(disc)); 
    x0 = q/a;
    x1 = c/q;
  }

  if( x0 > x1 ) { std::swap( x0, x1 ); }
  if( x0 < 0 )
  { 
    x0 = x1;
    if( x0 < 0 )
    {
      return false;
    }
  }

  coords = _origin + (x0 * _dir);

  return true;
}
