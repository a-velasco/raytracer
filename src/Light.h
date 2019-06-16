#pragma once

#include <Eigen/Dense>

using namespace Eigen;

class Light
{
private:
	Vector3d _origin;
	// type? enum - isotropic, directional, ambient...

public:
	Light( const Vector3d &origin );

	Vector3d getOrigin()
	{
		return _origin;
	}
};
