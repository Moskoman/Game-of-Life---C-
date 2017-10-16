#include "SDL2/SDL.h"
#include "DerivationStrategy.h"
#include "InputHandler.h"
#include "Cell.h"
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

int main (int argc, char* args[]){
    GraphicsManager GameView;
    GameView.CreateWindow ();
    InputHandler Handler;
    DerivationStrategy D1;
    D1.Populate (10);
    D1.Revive (4, 3);
    D1.Revive (4, 4);
    D1.Revive (4, 5);
    D1.Revive (7, 6);
    D1.Revive (8, 8);
    D1.Revive (3, 6);
    D1.Revive (6, 7);
    while (Handler.UserQuits () != true){
    	Handler.ReadInput ();
    	GameView.Run();
    	SDL_Delay (1000);
    	GameView.CellDrawer (D1.Cells);
    	D1.Run();
    };
};
