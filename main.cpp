#include "SDL2/SDL.h"
#include "DerivationStrategy.h"
#include "StateManager.h"
#include "InputHandler.h"
#include "Cell.h"
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

int main (int argc, char* args[]){
	StateManager manageStates {};
    GraphicsManager GameView {};
    GameView.CreateWindow ();
    while (manageStates.UserQuits () != true){
        manageStates.Update();
        GameView.RenderArray (manageStates.currentState->getSpriteArray(), manageStates.currentState->getRectArray());
        GameView.Run();

    };
};
