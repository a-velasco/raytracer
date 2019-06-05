#include <iostream>

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"

using namespace Eigen;

RayTracer( Sphere sphere, Camera camera ): m_sphere(sphere), m_camera(camera) {};

void RayTracer::Update()
{
  std::cout << "RayTracer::Update()..." << std::endl;
  Vector3d origin = Vector3d::Zero();
  Vector3d dir(0.,0.,-1.);

 /* // Old way - now we want to precompute all rays and iterate over those
  std::cout << "Creating new ray with origin\n" << origin << "\n and direction\n" << dir << std::endl;
  Ray *ray = new Ray( origin, dir );
  bool test = ray->intersects(m_sphere);

  for( int j = 0; j < m_image.height(); j++ )
  {
    for( int i = 0; i < m_image.width(); i++ )
    {
      Ray ray = ...
      if( ray.intersects(m_sphere) )
      {
        // set object color
      }
      else
      {
        // set background color
      }
    }
  }
  */
}
