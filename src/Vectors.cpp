#include "Vectors.h"
#include <SDL.h>
#include "Settings.h"

SDL_Point Vec3ToSDLPoint(const Vector3& v)
{
    float totalZ = (-v.z * Settings::GetZMult());
    float normalizedx = v.x / totalZ;
    float normalizedy = v.y / totalZ;
    return 
    {
        normalizedx * Settings::GetLargestScreenDim()/2 + Settings::GetScreenWidth()/2,
        -normalizedy * Settings::GetLargestScreenDim()/2 + Settings::GetScreenHeight()/2
    };
}

Vector2::operator SDL_Point() const
{
    return {(int)x+Settings::GetScreenWidth()/2,(int)y+Settings::GetScreenHeight()/2};
}