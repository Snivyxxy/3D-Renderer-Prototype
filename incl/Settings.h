#ifndef CAMSETTINGS_H
#define CAMSETTINGS_H

class Settings
{
    static float FOV;
    static float zMult;
    static int ScreenWidth;
    static int ScreenHeight;
    
    Settings() = delete;

    public:
    static float GetFOV();
    static void SetFOV(const float fov);
    static float GetZMult();
    static int GetScreenWidth();
    static int GetScreenHeight();
    static int GetLargestScreenDim();
};

#endif