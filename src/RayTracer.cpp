#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"
#include "Light.h"
#include "Mesh.h"

using namespace Eigen;

RayTracer::RayTracer( const std::vector< Sphere > &spheres, const Camera &camera, const Light &light, cv::Mat &image ): 
                     _spheres(spheres), _camera(camera), _light(light), _image(image) {};

RayTracer::RayTracer( const std::vector< Mesh > &meshes, const Camera &camera, const Light &light, cv::Mat &image ): 
                     _meshes(meshes), _camera(camera), _light(light), _image(image) {};

void RayTracer::Update()
{
  std::map<std::vector<int>, Ray> allRays = _camera.getAllRays();

  double start = clock();
  double start_omp = omp_get_wtime();

  #pragma omp parallel for
  for( int i = 0; i < allRays.size(); i++ )
  {
    for( int s = 0; s < _spheres.size(); s++ )
    {
      Sphere currentSphere = _spheres[s]; 

      int x = i%_camera.getResolution().x();
      int y = (i - x) / _camera.getResolution().x();

      std::vector<int> key = {x,y};
      Ray &currentRay = allRays.at( key );

      Vector3d intersectionCoords;
      if( currentSphere.intersects(currentRay, intersectionCoords) )
      {
        Vector3d surfaceNormal = (intersectionCoords - currentSphere.getCenter()).normalized();

        double   a = 2.0 * currentRay.getDirection().dot(surfaceNormal);
        Vector3d b = a * surfaceNormal;
        Vector3d finalDir = currentRay.getDirection() - b;
        
        Ray reflectedRay( intersectionCoords, finalDir );

        Vector3d intersectionToLight = (_light.getOrigin() - intersectionCoords).normalized();
        
        double ambient  = 0.5;
        double diffuse  = surfaceNormal.dot(intersectionToLight);
        double specular = 0.;

        double illum_total = (0.5 * ambient) + (0.6 * diffuse) + (0.2 * specular);

        _image.at<cv::Vec3b>(y, x) = illum_total * currentSphere.getColor();
      }
    }
  }

  double end = clock();
  double end_omp = omp_get_wtime();
  std::cout << " STD clock: " << (end-start)/CLOCKS_PER_SEC << " s" <<  std::endl;
  std::cout << " OMP clock: " << (end_omp-start_omp) << " s" <<  std::endl;
}

cv::Mat RayTracer::getRender()
{
  return _image;
}
