#pragma once

#include <opencv2/core/core.hpp>
#include <Eigen/Dense>

#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include "Mesh.h"

using namespace Eigen;

class RayTracer
{
private:
  std::vector< Sphere > _spheres;
  Camera 				_camera;
  Light  				_light;
  cv::Mat 				_image;

public:
  RayTracer( const std::vector< Sphere > &spheres, const Camera &camera, const Light &light, cv::Mat &image );
  
  void Update();

  cv::Mat getRender();
};
