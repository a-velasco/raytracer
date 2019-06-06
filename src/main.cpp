#include <iostream>
#include <Eigen/Dense>

#include "Sphere.h"
#include "Ray.h"
#include "RayTracer.h"

using namespace Eigen;

int main()
{
  // Raycasting Test
  Vector3d center(0.0, 0.0, -3.0);
  double radius = 1.0;
  std::cout << "Making sphere with radius " << radius << std::endl;
  Sphere sphere0( center, radius );

  Vector3d origin(0.0, 0.0, 0.0);
  Vector2d resolution(10,10);
  float fov = 90;
  Camera camera0( origin, fov, resolution);

  RayTracer rayTracer( sphere0, camera0 );
  rayTracer.Update();

}
