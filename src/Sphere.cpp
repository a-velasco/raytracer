#include "Ray.h"
#include "Sphere.h"

using namespace Eigen;

Sphere::Sphere(const Vector3d &center, const double &radius, cv::Vec3b &color )
	           : _center(center), _radius(radius), _color(color) {};

bool Sphere::intersects( const Ray &ray, PointType &coords )
{
  PointType displacement = ray.getOrigin() - _center;

  double a = 1.; //ray.getDirection().squaredNorm();
  double b = 2 * ray.getDirection().dot(displacement);
  double c = displacement.squaredNorm() - _radius*_radius;

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

  coords = ray.getOrigin() + (x0 * ray.getDirection());

  return true;
}

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

