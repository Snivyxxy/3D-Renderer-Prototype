#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
#include "Mesh.h"
#include "MeshInstance.h"

class Screen
{
    
    int width;
    int height;
    bool valid;
    

    public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Screen(const char* name, int width, int height, Uint32 flags, int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED);
    ~Screen();

    int GetWidth();
    int GetHeight();
    bool IsValid();

    void DrawWireTriangle(SDL_Point * pts, Triangle t);

    void DrawMeshInstance(MeshInstance& m);
};

#endif