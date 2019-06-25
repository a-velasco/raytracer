#include "Mesh.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace Eigen;

Mesh::Mesh( PointTypeVector    &points,
            EdgeTypeVector     &edges,
            TriangleTypeVector &triangles) :
            _points(points), _edges(edges), _triangles(triangles) {};

void Mesh::import( const std::string filename )
{
    std::ifstream fs(filename.c_str());
    std::string s = "";
    
    // read until nodes
    while( s != "$Nodes") { fs >> s; }

    int num_nodes;
    fs >> num_nodes;

    for( int i = 0; i < num_nodes; i++ )
    {
        int id;
        double x, y, z;
        fs >> id >> x >> y >> z;
        _points.push_back( Vector3d(x, y, z) );
    }
        
    fs >> s;
    fs >> s;

    int num_elements;
    fs >> num_elements;

    for( int i = 0; i < num_elements; i++ )
    {
        int id, type, unused, node1, node2, node3;
        fs >> id >> type >> unused >> unused >> unused;
        if( type == 2 )
        {
            fs >> node1 >> node2 >> node3; 
            // .msh index starts at 1
            _triangles.push_back( Vector3i(node1-1, node2-1, node3-1) );
        }
        else if( type == 1 )
        {
            fs >> node1 >> node2;
            _edges.push_back( Vector2d(node1-1, node2-1) );
        }
        else
        {
            // read till the end of the edge
            char c = ' ';
            while( c != '\n' ) {
                fs.get(c);
            }
            std::cout << ".msh file contains unsupported element of type " << type << std::endl;
        }
    }
}

bool Mesh::triangleIntersectsRay( const TriangleType &triangle, const Ray &ray, PointType &coords, PointType &surfaceNormal )
{
    // 1. Compute the normal of the triangle's plane
    // Vertex IDs
    int v0Id = triangle(0);
    int v1Id = triangle(1);
    int v2Id = triangle(2);

    // Vertex coordinates
    PointType v0 = _points[v0Id];
    PointType v1 = _points[v1Id];
    PointType v2 = _points[v2Id];

    PointType edge0 = v1 - v0;
    PointType edge1 = v2 - v1;
    PointType edge2 = v0 - v2;
    PointType N = edge0.cross(edge1); // normal
    surfaceNormal = N.normalized();

    // 2. Check if ray and plane are parallel
    double NdotRayDir = N.dot(ray.getDirection());
    if( fabs(NdotRayDir) < 1e-8 ) // almost 0
    {
        return false; // parallel, therefore they don't intersect
    }

    double d = N.dot(v0);
    double t = ( N.dot(ray.getOrigin()) + d ) / NdotRayDir;

    // 3. Check if triangle is behind ray
    if( t < 0 ){ return false; }

    // 4. Intersection point
    PointType P = ray.getOrigin() + t * ray.getDirection();

    // 5. Check if outside any of the edges
    std::vector<PointType> edges = {edge0, edge1, edge2};
    PointType C;
    for( int i = 0; i < 3; i++ )
    {
        PointType vp = P - edges[i];
        C = edges[i].cross(vp); // Vec perpendicular to plane
        if( N.dot(C) < 0 ) { return false; }
    }

    coords = ray.getOrigin() + (t * ray.getDirection());
    return true;
}

Mesh::PointTypeVector    Mesh::getPoints()    { return _points;    }
Mesh::EdgeTypeVector     Mesh::getEdges()     { return _edges;     }
Mesh::TriangleTypeVector Mesh::getTriangles() { return _triangles; }
