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

Mesh::PointTypeVector    Mesh::getPoints()    { return _points;    }
Mesh::EdgeTypeVector     Mesh::getEdges()     { return _edges;     }
Mesh::TriangleTypeVector Mesh::getTriangles() { return _triangles; }
