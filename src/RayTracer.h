#pragma once

#include "Sphere.h"
#include "Light.h"
#include "Camera.h"

class RayTracer
{
private:
  Sphere _sphere;
  Camera _camera;
  //Light  _light;

public:
  RayTracer( Sphere sphere, Camera camera );

  void Update();

};
