#include <iostream>

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"

using namespace Eigen;

RayTracer::RayTracer( Sphere sphere, Camera camera ): m_sphere(sphere), m_camera(camera) {};

void RayTracer::Update()
{/*
  std::cout << "RayTracer::Update()..." << std::endl;
  Vector3d origin = Vector3d::Zero();
  Vector3d dir(0.,0.,-1.);

  std::vector<Ray> allRays = m_camera.getAllRays();
  for( int i = 0; i < allRays.size(); i++ )
  {
    if( allRays[i].intersects(m_sphere) )
    {
      std::cout << "Ray " << i << " intersects" << std::endl;
      // color corresponding pixel
    }
    else
    {
      std::cout << "Ray " << i << " is background" << std::endl;
      // background color
    }
  }
  */
}
