#ifndef MESHINSTANCE_H
#define MESHINSTANCE_H

#include "Mesh.h"
#include "Transform.h"

struct MeshInstance
{
    const Mesh * m;
    Transform t;
};


#endif