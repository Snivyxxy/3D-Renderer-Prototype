#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vectors.h"

struct Quaternion
{
    float r;
    float i;
    float j;
    float k;

    constexpr Quaternion(float r, float i, float j, float k):
    r(r), i(i), j(j), k(k)
    {}

    Quaternion(float angleRad, const Vector3 normVector) :
    r(SDL_cosf(angleRad/2)),
    i(SDL_sinf(angleRad/2)* normVector.x),
    j(SDL_sinf(angleRad/2)* normVector.y),
    k(SDL_sinf(angleRad/2)* normVector.z)
    {}

    constexpr Quaternion(const Vector3 v) :
    r(0),
    i(v.x),
    j(v.y),
    k(v.z)
    {}

    constexpr float MagnitudeSquared()
    {
        return r*r + i*i + j*j + k*k;
    }

    constexpr Quaternion Conjugate()
    {
        return { r, -i, -j, -k };
    }

    constexpr Quaternion Inverse()
    {
        float ms = MagnitudeSquared();
        return 
        {
            r/ms,
            -i/ms,
            -j/ms,
            -k/ms
        };
    }
};


constexpr Quaternion operator*(const float scalar, const Quaternion& q)
{
    return
    {
        scalar * q.r,
        scalar * q.i,
        scalar * q.j,
        scalar * q.k
    };
}

constexpr Quaternion operator*(const Quaternion& q, const float scalar)
{
    return scalar * q;
}

constexpr Quaternion operator*(const Quaternion& a, const Quaternion& b)
{
    return {
        a.r*b.r - a.i*b.i - a.j*b.j - a.k*b.k,
        a.r*b.i + a.i*b.r + a.j*b.k - a.k*b.j,
        a.r*b.j + a.j*b.r + a.k*b.i - a.i*b.k,
        a.r*b.k + a.k*b.r + a.i*b.j - a.j*b.i
    };
}

constexpr Quaternion operator*=(Quaternion& a, const float scalar)
{
    return a = (scalar * a);
}

constexpr Quaternion operator-(const Quaternion& a)
{
    return -1 * a;
}

constexpr Quaternion operator/(const Quaternion& a, float b)
{
    return a * (1/b);
}


#endif