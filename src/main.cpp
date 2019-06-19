#include <iostream>
#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Sphere.h"
#include "Ray.h"
#include "Light.h"
#include "RayTracer.h"

using namespace Eigen;

int main(int argc, char *argv[])
{
  // Initialize Sphere objects
  Vector3d center0(2.5, 0.0, -5.0); // issue! x = 2.5 and res non square e.g.(500,700)
  Vector3d center1(-2.5, 0.0, -5.0);

  double radius0 = 1.0;
  cv::Vec3b color0(189,217,239);
  cv::Vec3b color1(245,180,200);

  Sphere sphere0( center0, radius0, color0 );
  Sphere sphere1( center1, radius0, color1 );

  std::vector< Sphere > spheres = {sphere0, sphere1};

  // Initialize Camera
  Vector3d origin(0.0, 0.0, 0.0);
  Vector2i resolution(500,500);
  float fov = 90;
  Camera camera( origin, fov, resolution);
  // Initialize Light
  Vector3d lightOrigin(0.0, 2.0, 0.5);
  Light light0( lightOrigin );

  // Initialize Image
  cv::Mat image0(resolution.x(), resolution.y(), CV_8UC3, cv::Scalar(0,0,0));
  
  // Compute
  RayTracer rayTracer( spheres, camera, light0, image0);
  rayTracer.Update();

  cv::imshow("Render", rayTracer.getRender());

  cv::waitKey(0);
/*
*/
  return 0;
}
