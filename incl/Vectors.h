#ifndef VECTORS_H
#define VECTORS_H

#include <SDL.h>

struct Vector2
{
    float x;
    float y;
    
    operator SDL_Point() const;
};

struct Vector3
{
    float x;
    float y;
    float z;
};

struct Vector4
{
    float x;
    float y;
    float z;
    float w;
};

constexpr Vector2 operator+(Vector2& a, Vector2& b)
{
    return {a.x + b.x, a.y + b.y};
}
constexpr Vector2 operator-(Vector2& a, Vector2& b)
{
    return {a.x - b.x, a.y - b.y};
}
constexpr Vector2 operator*(float a, Vector2& b)
{
    return {a*b.x,a*b.y};
}
constexpr Vector2 operator*(Vector2& a, float b)
{
    return b*a;
}
constexpr float DotProduct(Vector2& a, Vector2& b)
{
    return a.x*b.x + a.y*b.y;
}

constexpr Vector3 operator+(Vector3& a, Vector3& b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}
constexpr Vector3 operator-(Vector3& a, Vector3& b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
constexpr Vector3 operator*(float a, Vector3& b)
{
    return {a*b.x,a*b.y,a*b.z};
}
constexpr Vector3 operator*(Vector3& a, float b)
{
    return b*a;
}
constexpr float DotProduct(Vector3& a, Vector3& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

constexpr Vector4 operator+(Vector4& a, Vector4& b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
constexpr Vector4 operator-(Vector4& a, Vector4& b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
constexpr Vector4 operator*(float a, Vector4& b)
{
    return {a*b.x,a*b.y,a*b.z,a*b.w};
}
constexpr Vector4 operator*(Vector4& a, float b)
{
    return b*a;
}
constexpr float DotProduct(Vector4& a, Vector4& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

constexpr Vector2 Homogeneous3ToCartesian2(Vector3& v)
{
    return {v.x/v.z,v.y/v.z};
}

constexpr Vector3 Homogeneous4ToCartesian3(Vector4& v)
{
    return {v.x/v.w, v.y/v.w, v.z/v.w};
}

constexpr Vector2 Homogenous4ToCartesian2(Vector4& v)
{
    return {v.x/(v.w*v.z),v.y/(v.w*v.z)};
}

constexpr Vector4 CartesianToHomogeneous(Vector3& v)
{
    return {v.x,v.y,v.z,1.f};
}

SDL_Point Vec3ToSDLPoint(const Vector3& v);



#endif