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
  Sphere sphere0( center, radius );

  RayTracer rayTracer( sphere0 );
  rayTracer.Update();

}
