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
    DerivationStrategy D1;
    D1.Populate (50);
    D1.Revive (0, 2);
    D1.Revive (1, 2);
    D1.Revive (2, 2);
    D1.Revive (2, 1);
    D1.Revive (1, 0);
//    D1.Revive (8, 6);
//    D1.Revive (8, 7);
    while (manageStates.UserQuits () != true){
        manageStates.Update();
        GameView.RenderArray (manageStates.currentState->getSpriteArray(), manageStates.currentState->getRectArray());
        GameView.Run();

    };
};
