#include <iostream>
#include <Eigen/Dense>

#include "Sphere.h"
#include "Ray.h"
#include "RayTracer.h"

using namespace Eigen;

int main()
{
  // Intersection Test
  Vector3d center(0.0, 0.0, -5.0);
  double radius = 5.0;
  std::cout << "Making sphere with radius " << radius << std::endl;
  Sphere sphere0( center, radius );

  Vector3d origin(0.0, 0.0, 0.0);
  Vector3d dir(0.0, 1.0, 0.0);
  Ray ray0( origin, dir );

  double root = 0.0;
  bool doesIntersect = ray0.intersects( sphere0, root );
  std::cout << "doesIntersect = " << doesIntersect << std::endl;
  std::cout << "root = " << root << std::endl;

  //RayTracer rayTracer( sphere0 );
  //rayTracer.Update();

  /*Sphere sphere0 = new Sphere(coords, radius, color, material);

  Light light0 = new Light(coords, intensity, type);

  RayTracer myRayTracer = new RayTracer( sphere0, light0, camera, "image.png" );
  myRayTracer->Update();*/

}
