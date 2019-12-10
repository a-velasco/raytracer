#pragma once

#include <Eigen/Dense>

using namespace Eigen;

class Light
{
	typedef Vector3d PointType;
private:
	PointType _origin;
	// type? enum - isotropic, directional, ambient...

public:
	Light( const PointType &origin );

	PointType getOrigin() const;

};
