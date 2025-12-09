#include <SDL.h>
#undef main

#include "Settings.h"

/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <stdio.h>
#include "Wireframes/Cube.h"
#include "Screen.h"
#include "MeshInstance.h"
#include <iostream>


int main( int argc, char* args[] )
{
    Settings::SetFOV(90);
    Screen s = Screen("Wynn's 3D Renderer",
        Settings::GetScreenWidth(),
        Settings::GetScreenHeight(),
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    

    SDL_Renderer * renderer = s.renderer;

    SDL_Event e;
    bool quit = false;
    
    MeshInstance instance = {&Cube,Transform({1,0,-4},{0.5f,1,1})};

    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) quit = true;
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        //SDL_RenderDrawLine(renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        
        s.DrawMeshInstance(instance);
        

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(renderer);
    }
    
	

	
	//Quit SDL subsystems
	SDL_Quit();
    
    /*
    Quaternion a(1,2,3,4);
    Quaternion b(5,6,7,8);

    Quaternion c = a*b;
    printf("%.5f,%.5f,%.5f,%.5f",c.r,c.i,c.j,c.k);
    */
}

/*
int main()
{
    Quaternion l = Quaternion(3,4,5,6)*Quaternion(1,2,3,4);
    std::cout << "i is: " << 
        l.r << " " <<
        l.i << " " <<
        l.j << " " <<
        l.k << "\n";
    return 0;
}
    */