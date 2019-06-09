#pragma once

#include <Eigen/Dense>

#include "Ray.h"

class Light
{
private:
	Vector3d _origin;
	// type? enum - isotropic, directional...
	double _intensity;

public:
	Light( const Vector3d &origin, const double &intensity );

	double getIntensityAt( const Ray & ray, std::vector<double> intersectionCoords );

};
