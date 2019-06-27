#include "Light.h"

Light::Light( const Vector3d &origin ): _origin(origin) {};

Light::PointType Light::getOrigin() const
{
	return _origin;
}