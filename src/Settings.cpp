#include "Settings.h"
#include <SDL.h>

#include "Constants.h"


float Settings::FOV = 90;
float Settings::zMult = 1;
int Settings::ScreenWidth = 640;
int Settings::ScreenHeight = 480;

float Settings::GetFOV()
{
    return FOV;
}

void Settings::SetFOV(const float fov)
{
    FOV = fov;
    zMult = SDL_tanf(DEGTORAD * FOV/2);
}

float Settings::GetZMult()
{
    return zMult;
}

int Settings::GetScreenWidth()
{
    return ScreenWidth;
}

int Settings::GetScreenHeight()
{
    return ScreenHeight;
}

int Settings::GetLargestScreenDim()
{
    return (ScreenWidth > ScreenHeight) ? ScreenWidth : ScreenHeight;
}