#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "Vectors.h"
#include <stdio.h>

class Matrix4x4
{
    //row first storage
    float entries[16];


    public:
    Matrix4x4() {};
    constexpr Matrix4x4(float * data) :
    entries()
    {
        for (int i = 0; i < 16; i++)
        {
            entries[i] = data[i];
            
        }
    }

    float operator[](int i) const;
    const float* Data() const;
};

constexpr Matrix4x4 MatrixScale(float factor)
{
    float data[16] = 
    {
        factor,0,0,0,
        0,factor,0,0,
        0,0,factor,0,
        0,0,0,     1
    };
    return Matrix4x4(data);
}

constexpr Matrix4x4 MatrixScale(Vector3 v)
{
    float data[16] = 
    {
        v.x,0,0,0,
        0,v.y,0,0,
        0,0,v.z,0,
        0,0,0,  1
    };
    return Matrix4x4(data);
}

constexpr Matrix4x4 MatrixTranslate(float x, float y, float z)
{
    float data[16] = 
    {
        1,0,0,x,
        0,1,0,y,
        0,0,1,z,
        0,0,0,1
    };
    return Matrix4x4(data);
}

constexpr Matrix4x4 MatrixTranslate(Vector3 v)
{
    float data[16] = 
    {
        1,0,0,v.x,
        0,1,0,v.y,
        0,0,1,v.z,
        0,0,0,1
    };
    return Matrix4x4(data);
}

Matrix4x4 MatrixProject();

Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b);

Vector4 operator*(const Matrix4x4& a, const Vector4& b);

Vector4 operator*(const Matrix4x4& a, const Vector3& b);



#endif