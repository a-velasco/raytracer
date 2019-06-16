#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"
#include "Light.h"

#include <omp.h>

using namespace Eigen;

RayTracer::RayTracer( const Sphere &sphere, const Camera &camera, const Light &light, cv::Mat &image ): 
                     _sphere(sphere), _camera(camera), _light(light), _image(image) {};

void RayTracer::Update()
{
  std::map<std::vector<int>, Ray> allRays = _camera.getAllRays();
  std::map<std::vector<int>, Ray>::iterator rIt;

  int count = 0;
  for( rIt = allRays.begin(); rIt != allRays.end(); rIt++ )
  {
    Ray &currentRay = rIt->second; 
    Vector3d intersectionCoords;
    if( currentRay.intersects(_sphere, intersectionCoords) )
    {
      Vector3d surfaceNormal = (intersectionCoords - _sphere.getCenter()).normalized();
      //std::cout << "intersectionCoords:\n" << intersectionCoords << std::endl;

      double   a = 2.0 * currentRay.getDirection().dot(surfaceNormal);
      Vector3d b = a * surfaceNormal;
      Vector3d finalDir = currentRay.getDirection() - b;
      
      Ray reflectedRay( intersectionCoords, finalDir );

      Vector3d intersectionToLight = (_light.getOrigin() - intersectionCoords).normalized();
      double illum = reflectedRay.getDirection().dot( intersectionToLight );
      std::cout << intersectionToLight << "\n ------" << std::endl;

      // set pixel color, TODO: based on material & intensity
      illum += 0.5;
      if( illum < 0 )
      {
        illum = 0.;
      }
      if( illum > 1 )
      {
        illum = 1.;
      }
      //_image.at<cv::Vec3b>(rIt->first[1], rIt->first[0]) = cv::Vec3b(0,0,255 * (intersectionToLight.z()/2 +0.5));
      _image.at<cv::Vec3b>(rIt->first[1], rIt->first[0]) = cv::Vec3b(20*illum,10*illum,255*illum);
    }
  }
}

cv::Mat RayTracer::getRender()
{
  return _image;
}
