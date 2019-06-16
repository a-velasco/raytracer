#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"
#include "Light.h"

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

      double   a = 2.0 * currentRay.getDirection().dot(surfaceNormal);
      Vector3d b = a * surfaceNormal;
      Vector3d finalDir = currentRay.getDirection() - b;
      
      Ray reflectedRay( intersectionCoords, finalDir );

      Vector3d intersectionToLight = (_light.getOrigin() - intersectionCoords).normalized();
      
      double diffuse = surfaceNormal.dot(intersectionToLight);
      //double diffuse = reflectedRay.getDirection().dot( intersectionToLight );

      double specular = 0.; 

      double ambient = 0.5;

      double illum_total = (1. * ambient) + (0.5 * diffuse) + (0.5 * specular);

      _image.at<cv::Vec3b>(rIt->first[1], rIt->first[0]) = cv::Vec3b(209*illum_total,133*illum_total,152*illum_total);
    }
  }
}

cv::Mat RayTracer::getRender()
{
  return _image;
}
