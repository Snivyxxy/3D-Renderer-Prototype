#include "Screen.h"

#include <stdio.h>
#include "Matrix4x4.h"


Screen::Screen(
    const char* name, 
    int width, 
    int height,  
    Uint32 flags,
    int x, 
    int y)
    
{
    valid = false;

    //Inits Video
    if(!SDL_WasInit(SDL_INIT_VIDEO))
    {
        if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
        {
            printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        }
    }

    

    //Creates Window
    window = SDL_CreateWindow(name,x,y,width,height,flags);
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error; %s\n", SDL_GetError() );
    }
    this->width = width;
    this->height = height;
    valid = true;
}

Screen::~Screen()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

int Screen::GetWidth()
{
    return width;
}

int Screen::GetHeight()
{
    return height;
}

bool Screen::IsValid()
{
    return valid;
}

void Screen::DrawWireTriangle(SDL_Point * pts, Triangle t)
{
    SDL_Color c = t.color;
    SDL_SetRenderDrawColor(renderer,c.r,c.g,c.b,c.a);
    SDL_Point drawList[4] = 
    {
        pts[t.p1],
        pts[t.p2],
        pts[t.p3],
        pts[t.p1]
    };
    SDL_RenderDrawLines(renderer,drawList,4);
}

void Screen::DrawMeshInstance(MeshInstance& m)
{
    const Mesh * mesh = m.m;
    const Matrix4x4 fullMat = MatrixProject() * m.t.GetMatrix();

    /*
    printf("[%.5f, %.5f, %.5f, %.5f \n %.5f, %.5f, %.5f, %.5f\n %.5f, %.5f, %.5f, %.5f\n %.5f, %.5f, %.5f, %.5f]\n", 
        fullMat[0],fullMat[1],fullMat[2],fullMat[3],
        fullMat[4], fullMat[5], fullMat[6],fullMat[7],
        fullMat[8], fullMat[9], fullMat[10],fullMat[11],
        fullMat[12], fullMat[13], fullMat[14],fullMat[15]
    );
    */


    SDL_Point points[mesh->numOfPoints];

    for (int i = 0; i < mesh->numOfPoints; i++)
    {
        Vector4 projected = fullMat * (mesh->points[i]);
        points[i] = Homogenous4ToCartesian2(projected);
        //printf("%.5f, %.5f, %.5f, %.5f\n",projected.x,projected.y,projected.z,projected.w);

        //printf("%d,%d\n",points[i].x,points[i].y);
    }
    
    for (int i = 0; i < mesh->numOfTriangles; i++)
    {
        DrawWireTriangle(points,mesh->triangles[i]);
    }
    
}