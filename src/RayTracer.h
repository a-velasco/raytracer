#pragma once

#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include "Image.h"

class RayTracer
{
private:
  Sphere m_sphere;
  //Light  m_light;
  //Camera m_camera;
  //Image  m_image;

public:
  /*RayTracer(Sphere sphere, Light light, Camera camera, Image image):
            m_sphere(sphere), m_light(light), m_camera(camera), m_image(image)
  {};*/

  RayTracer( Sphere sphere ):
            m_sphere(sphere)
  {};
  
  void Update();

};
