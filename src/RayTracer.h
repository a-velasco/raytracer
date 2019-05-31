#pragma once

#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include "Image.h"

class RayTracer
{
private:
  Sphere m_sphere;

public:
  RayTracer( Sphere sphere ):
            m_sphere(sphere)
  {};

  void Update();

};
