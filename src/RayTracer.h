#pragma once

#include "Sphere.h"
#include "Light.h"
#include "Camera.h"

class RayTracer
{
private:
  Sphere m_sphere;
  Camera m_camera
  //Light  m_light;

public:
  RayTracer( Sphere sphere, Camera camera );

  void Update();

};
