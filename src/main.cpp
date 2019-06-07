#include <iostream>
#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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
  Vector2d resolution(500,700);
  float fov = 90;
  Camera camera0( origin, fov, resolution);

  cv::Mat image0(resolution.x(), resolution.y(), CV_8UC3, cv::Scalar(0,0,0));
  RayTracer rayTracer( sphere0, camera0, image0);
  rayTracer.Update();

  cv::imshow("Render", rayTracer.getRender());

  cv::waitKey(0);

  return 0;
}
