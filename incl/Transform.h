#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vectors.h"
#include "Matrix4x4.h"

class Transform
{
    private:
    Vector3 position;
    Vector3 scale;
    //ROTATION HERE
    
    Matrix4x4 tMat;

    public:
    Transform();
    Transform(Vector3 position);
    Transform(Vector3 position, Vector3 scale);

    void UpdateMatrix();
    const Matrix4x4& GetMatrix();
    const Vector3& GetPostion();
    void SetPosition(Vector3& v);
    
};

#endif