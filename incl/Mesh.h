#ifndef MESH_H
#define MESH_H

#include "Vectors.h"

struct Triangle
{
    int p1,p2,p3;
    SDL_Color color;
};

struct Mesh
{
    const int numOfPoints;
    const Vector3 * points;
    const int numOfTriangles;
    const Triangle * triangles;
};


#endif