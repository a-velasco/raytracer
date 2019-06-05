#include <iostream>

#include <Eigen/Dense>
#include "Ray.h"
#include "Sphere.h"

Ray::Ray( Vector3d origin, Vector3d dir ): m_origin(origin), m_dir(dir) {};

bool Ray::intersects( const Sphere &sphere, double &root )
{
  Vector3d displacement = m_origin - sphere.getCenter();

  double a = m_dir.squaredNorm();
  double b = 2 * ( m_dir.dot(m_origin - sphere.getCenter()) );
  double c = (m_origin - sphere.getCenter()).squaredNorm() - sphere.getRadius();

  double disc = (b*b) - 4*a*c; // discriminant

  if( disc > 0 )
  {
    double root1 = -b - sqrt(disc);
    double root2 = -b + sqrt(disc);

    // use smallest root (should be first time ray hits )
    if( root1 < root2 || root1 == root2 ) { root = root1; }
    else { root = root2; }

    return true;
  }
  else if( disc == 0 )
  {
    root = -b/(2*a);
    return true;
  }
  else
  {
    root = -1.;
    return false;
  }

}
