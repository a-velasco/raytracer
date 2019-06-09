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
  Vector3d lightOrigin(0.0, -2.0, -1.0);

  std::map<std::vector<int>, Ray> allRays = _camera.getAllRays();
  std::map<std::vector<int>, Ray>::iterator rIt;

  for( rIt = allRays.begin(); rIt != allRays.end(); rIt++ )
  {
    Vector3d intersectionCoords;
    if( rIt->second.intersects(_sphere, intersectionCoords) )
    {
      Vector3d surfaceNormal = (intersectionCoords - _sphere.getCenter()).normalized();
      //std::cout << "intersectionCoords:\n" << intersectionCoords << std::endl;

      double a = 2.0 * rIt->second.getDirection().dot(surfaceNormal);
      Vector3d b = a * surfaceNormal;
      Vector3d finalDir = rIt->second.getDirection() - b;
      Ray finalRay( intersectionCoords, finalDir );

      Vector3d intersectionToLight = (intersectionCoords - lightOrigin).normalized();
      double illum = finalRay.getDirection().dot( intersectionToLight );

      // set pixel color, TODO: based on material & intensity
      if( illum < 0 )
      {
        illum = 0;
      }
      _image.at<cv::Vec3b>(rIt->first[1], rIt->first[0]) = cv::Vec3b(20*illum,10*illum,255*illum);

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
