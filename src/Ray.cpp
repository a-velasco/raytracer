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
  bool doesIntersect = false;
  Vector3d displacement = _origin - sphere.getCenter();

  double a = 1.; //_dir.squaredNorm();
  double b = 2 * _dir.dot(displacement);
  double c = displacement.squaredNorm() - sphere.getRadius()*sphere.getRadius();

  double disc = (b*b) - 4*a*c; // discriminant

  if( disc > 0 )
  {
    doesIntersect = true;

    double root1 = -b/2. - sqrt(disc);
    double root2 = -b/2. + sqrt(disc);

    // If both roots positive, then check for which one is smaller
    if( root1 > 0 && root2 > 0 )
    {
      // use smallest root (should be first time ray hits )
      if( root1 < root2 || root1 == root2 ) { coords = _origin + (root1 * _dir);}
      else                                  { coords = _origin + (root2 * _dir);}
    }

    // If only one of them is positive, return that one
    else if( root1 > 0 && root2 < 0) { coords = _origin + (root1 * _dir); }
    else if( root2 > 0 && root1 < 0) { coords = _origin + (root2 * _dir); }

    // If neither of them is positive, no intersection
    else { doesIntersect = false; }
    
  }
  else if( disc == 0 )
  {
    double root = -b/(2*a);
    coords = _origin + (root * _dir);
    doesIntersect = true;
  }

  return doesIntersect;
}
