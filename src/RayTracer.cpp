#include <iostream>
#include <opencv2/core/core.hpp>

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"

using namespace Eigen;

RayTracer::RayTracer( const Sphere &sphere, const Camera &camera, cv::Mat &image ): 
                     _sphere(sphere), _camera(camera), _image(image) {};

void RayTracer::Update()
{
  std::map<std::vector<int>, Ray> allRays = _camera.getAllRays();
  std::map<std::vector<int>, Ray>::iterator rIt;

  for( rIt = allRays.begin(); rIt != allRays.end(); rIt++ )
  {
    double root = -1.;
    Vector2d pixel;
    if( rIt->second.intersects(_sphere, root) )
    {
      // TODO: get sphere color

      // set sphere color
      _image.at<cv::Vec3b>(rIt->first[0], rIt->first[1]) = cv::Vec3b(255, 255, 255);
    }
    else
    {
      // TODO: either set background color or initialize image with it already
    }
  }
}

cv::Mat RayTracer::getRender()
{
  return _image;
}
