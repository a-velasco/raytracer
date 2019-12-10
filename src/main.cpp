#include <iostream>
#include <random>

#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Sphere.h"
#include "Ray.h"
#include "Light.h"
#include "RayTracer.h"

using namespace Eigen;

std::vector< Sphere > generateRandomSpheres( int num, double maxCoord, double maxR)
{
  std::vector< Sphere > spheres;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> rand_centerXY(-maxCoord, maxCoord);
  std::uniform_real_distribution<> rand_centerZ(-0.5, -maxCoord);
  std::uniform_real_distribution<> rand_radius(0.01, maxR);
  std::uniform_int_distribution<>  rand_color(0, 255);
  for( int n = 0; n < num; n++ )
  {
    Vector3d center( rand_centerXY(gen), rand_centerXY(gen), rand_centerZ(gen));
    std::cout << "random center:\n" << center << std::endl;
    double radius = rand_radius(gen);
    std::cout << "random radius: " << radius << std::endl;
    cv::Vec3b color( rand_color(gen), rand_color(gen), rand_color(gen) );
    std::cout << "random color: " << color << std::endl;

    Sphere sphere( center, radius, color );
    spheres.push_back(sphere);
  }

  return spheres;
}

void generateTimeSamples()
{
  typedef Vector3d  PointType;
  typedef cv::Vec3b BGRColorType;

  // Create list of resolutions to use
  std::vector<int> resolutions;
  for( int i = 10; i < 2010; i+=10 )
  {
    resolutions.push_back(i);
  }

  // For each resolution
  for( int i = 0; i < resolutions.size(); i++ )
  {
    std::cout << "Computing resolution " << resolutions[i] << " x " << resolutions[i] << std::endl;
    // Initialize sphere of radius 1 at z = -2
    BGRColorType color( 255, 10, 10 );
    Sphere sphere( Vector3d(0.0, 0.0, -2.0),  1.0,  color);

    // Initialize camera
    PointType origin(0.0, 0.0, 0.0);
    Vector2i resolution(resolutions[i],resolutions[i]);
    float fov = 90;
    Camera camera( origin, fov, resolution);

    // Initialize Light
    Vector3d lightOrigin(0.0, 2.0, 0.5);
    Light light( lightOrigin );

    // Initialize Image
    cv::Mat image(resolution.x(), resolution.y(), CV_8UC3, cv::Scalar(255,255,255));

    // Compute
    RayTracer rayTracer( {sphere}, camera, light, image );
    rayTracer.Update();
  }
}

int main(int argc, char *argv[])
{
  typedef Vector3d PointType;
  typedef Vector2d EdgeType;
  typedef Vector3i TriangleType;

  typedef std::vector< PointType >    PointTypeVector;
  typedef std::vector< EdgeType >     EdgeTypeVector;
  typedef std::vector< TriangleType > TriangleTypeVector;

  typedef cv::Vec3b BGRColorType;

  BGRColorType color0( 89,17,77 );
  BGRColorType color1( 64,135,34 );
  BGRColorType color2( 131,90,169 );
  BGRColorType color3( 40,110,53);

  Sphere sphere0( Vector3d(2.0, 0.0, -10.0),  2.0, color0 );
  Sphere sphere1( Vector3d(0.0, 0.0, -6.0),  1.0,  color1 );
  Sphere sphere2( Vector3d(1.0, 2.0, -7.0), 0.5,  color2 );
  Sphere sphere3(Vector3d(4., -4, -30.0), 3.0,  color3);

  std::vector< Sphere > spheres = { sphere0, sphere1, sphere3 };

  // Initialize Camera
  PointType origin(0.0, 0.0, 0.0);
  Vector2i resolution(500,500);
  double fov = 50;
  Camera camera( origin, fov, resolution);

  // Initialize Light
  Vector3d lightOrigin(3.0, -2, -1);
  Light light( lightOrigin );

  // Initialize Image
  cv::Mat image(resolution.x(), resolution.y(), CV_8UC3, cv::Scalar(0,0,0));

  // Compute
  RayTracer rayTracer( spheres, camera, light, image);
  rayTracer.Update();

  cv::imshow("Render", rayTracer.getRender());
  cv::waitKey(0);

  //cv::imwrite( "../images/render.png", rayTracer.getRender() );

  return 0;
}
