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
    while (Handler.UserQuits () != true){
    	Handler.ReadInput ();
    	GameView.Run();
    	SDL_Delay (1000);
    	for (auto f = 0; f < D1.Cells.size(); f++){
			if (D1.Cells[f]->getState() == true){
				cout << D1.Cells[f]->posX << " " << D1.Cells[f]->posY << endl;

			};
		};
    	GameView.CellDrawer (D1.Cells);
    	D1.Run();
    };
};
