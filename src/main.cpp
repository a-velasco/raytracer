#include <iostream>
#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Sphere.h"
#include "Ray.h"
#include "Light.h"
#include "RayTracer.h"

using namespace Eigen;

int main()
{
  // Initialize Sphere object
  Vector3d center(0.0, 0.0, -4.0);
  double radius = 2.0;
  std::cout << "Making sphere with radius " << radius << std::endl;
  Sphere sphere0( center, radius );

  // Initialize Camera
  Vector3d origin(0.0, 0.0, 0.0);
  Vector2i resolution(500,500);
  float fov = 90;
  Camera camera0( origin, fov, resolution);

  // Initialize Light
  Vector3d lightOrigin(0.0, 2.0, -1.0);
  Light light0( lightOrigin );

  // Initialize Image
  cv::Mat image0(resolution.x(), resolution.y(), CV_8UC3, cv::Scalar(0,0,0));
  
  // Compute
  RayTracer rayTracer( sphere0, camera0, light0, image0);
  rayTracer.Update();

  cv::imshow("Render", rayTracer.getRender());

  cv::waitKey(0);

  return 0;
}
