#include <iostream>

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"

using namespace Eigen;

RayTracer::RayTracer( Sphere sphere, Camera camera ): _sphere(sphere), _camera(camera) {};

void RayTracer::Update()
{
  std::vector<Ray> allRays = _camera.getAllRays();
  for( int i = 0; i < allRays.size(); i++ )
  {
    double root = -1.;
    if( allRays[i].intersects(_sphere, root) )
    {
      std::cout << "Ray " << i << " intersects" << std::endl;
      // get sphere color
    }
    else
    {
      std::cout << "Ray " << i << " is background" << std::endl;
      // get background color
    }
  }
  
}
