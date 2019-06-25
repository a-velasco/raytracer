#include <iostream>
#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Sphere.h"
#include "Ray.h"
#include "Light.h"
#include "RayTracer.h"
#include "Mesh.h"

using namespace Eigen;

int main(int argc, char *argv[])
{
  typedef Vector3d PointType;
  typedef Vector2d EdgeType;
  typedef Vector3i TriangleType;

  typedef std::vector< PointType >    PointTypeVector;
  typedef std::vector< EdgeType >     EdgeTypeVector;
  typedef std::vector< TriangleType > TriangleTypeVector;

  typedef cv::Vec3b BGRColorType;

  // Initialize Sphere objects
  PointType center0(2.5, 0.0, -5.0); // issue? x = 2.5 and res non square e.g.(500,700)
  PointType center1(-2.5, 0.0, -5.0);

  double radius0 = 1.0;
  BGRColorType color0(189,217,239);
  BGRColorType color1(245,180,200);

  Sphere sphere0( center0, radius0, color0 );
  Sphere sphere1( center1, radius0, color1 );

  std::vector< Sphere > spheres = {sphere0, sphere1};

  // Initialize Camera
  PointType origin(0.0, 0.0, 0.0);
  Vector2i resolution(500,500);
  float fov = 90;
  Camera camera( origin, fov, resolution);
  
  // Initialize Light
  Vector3d lightOrigin(0.0, 2.0, 0.5);
  Light light0( lightOrigin );

  // Initialize Image
  cv::Mat image0(resolution.x(), resolution.y(), CV_8UC3, cv::Scalar(0,0,0));

  // Render Spheres
  // RayTracer rayTracer( spheres, camera, light0, image0);
  // rayTracer.UpdateSpheres();

  // Load mesh
  PointTypeVector    points;
  EdgeTypeVector     edges;
  TriangleTypeVector triangles;

  Mesh mesh0( points, edges, triangles );
  mesh0.import("/home/andrea/Documents/Development/raytracer/mesh_files/basic.msh");

  std::vector< Mesh > meshes = { mesh0 };
  RayTracer rayTracer( meshes, camera, light0, image0);
  rayTracer.UpdateMeshes();

  cv::imshow("Render", rayTracer.getRender());

  cv::waitKey(0);

  return 0;
}
