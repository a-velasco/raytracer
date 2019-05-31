#include <iostream>
#include <Eigen/Dense>

#include "Sphere.h"
#include "Ray.h"
#include "RayTracer.h"

using namespace Eigen;

int main()
{
  Vector3d center(0.0, 0.0, 20.0);
  double radius = 5.0;
  std::cout << "Making sphere with radius " << radius << std::endl;
  Sphere sphere0( center, radius );


  RayTracer rayTracer( sphere0 );
  rayTracer.Update();

  /*Sphere sphere0 = new Sphere(coords, radius, color, material);

  Light light0 = new Light(coords, intensity, type);

  Camera camera = new Camera(coords, normal)

  RayTracer myRayTracer = new RayTracer( sphere0, light0, camera, "image.png" );
  myRayTracer->Update();*/

}
