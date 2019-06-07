#pragma once

#include <opencv2/core/core.hpp>

#include "Sphere.h"
#include "Light.h"
#include "Camera.h"

class RayTracer
{
private:
  Sphere _sphere;
  Camera _camera;
  cv::Mat _image;
  //Light  _light;

public:
  RayTracer( const Sphere &sphere, const Camera &camera, cv::Mat &image );

  void Update();

  cv::Mat getRender();
};
