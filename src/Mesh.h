#pragma once

#include <Eigen/Dense>
#include <vector>

using namespace Eigen;

// Mesh class to store triangles, points, and edges.
// Can either be constructed with these elements already parsed, 
// or you can import a .msh file with the import() function.

class Mesh
{
	typedef Vector3d PointType;
	typedef Vector2d EdgeType;
	typedef Vector3i TriangleType;
	
	typedef std::vector< PointType > 	PointTypeVector;
	typedef std::vector< EdgeType >     EdgeTypeVector;
	typedef std::vector< TriangleType > TriangleTypeVector;

private:
	PointTypeVector    _points;
    EdgeTypeVector     _edges;
    TriangleTypeVector _triangles;

public:

	Mesh( PointTypeVector    &points,
          EdgeTypeVector     &edges,
          TriangleTypeVector &triangles );

	void import( const std::string filename );

	PointTypeVector    getPoints();
	EdgeTypeVector     getEdges();
	TriangleTypeVector getTriangles();

};