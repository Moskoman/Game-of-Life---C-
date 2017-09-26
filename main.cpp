#include "SDL2/SDL.h"
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

int main (int argc, char* args[]){
    GraphicsManager G1;
    G1.CreateWindow ();
    SDL_Delay (5000);
}
