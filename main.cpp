#include "SDL2/SDL.h"
#include "InputHandler.h"
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

int main (int argc, char* args[]){
    GraphicsManager GameView;
    GameView.CreateWindow ();
    InputHandler Handler;
    while (Handler.UserQuits () != true){
    	Handler.ReadInput ();
    	GameView.Run();
    };

}
