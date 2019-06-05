#include <iostream>

#include <Eigen/Dense>
#include "Ray.h"
#include "Sphere.h"

Ray( Vector3d origin, Vector3d dir ): m_origin(origin), m_dir(dir) {};

void Ray::intersects( const Sphere &sphere )
{
  Vector3d displacement = m_origin - sphere.getCenter();

  double a = direction.squaredNorm();
  double b = 2 * ( m_dir.dot(m_origin - sphere.getCenter()) );
  double c = (m_origin - sphere.getCenter()).squaredNorm() - sphere.getRadius();

  double disc = (b*b) - 4*a*c; // discriminant

  if( disc > 0 )
  {
    m_hasRoot = true;

    double root1 = -b - sqrt(disc);
    double root2 = -b + sqrt(disc)

    // use smallest root (should be first time ray hits )
    if( root1 < root2 || root1 == root2 ) { m_root = root1; }
    else(){ m_root = root2; }
  }
  else if( disc == 0 )
  {
    m_hasRoot = true;
    m_root = -b/(2*a)
  }
  else
  {
    m_hasRoot = false;
    m_root = -1.;
  }

}
