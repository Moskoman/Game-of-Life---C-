#include <iostream>
#include "State.h"
#include "Cell.h"
#include "DerivationStrategy.h"
#include "GameEngine.h"

class Game : public State {

public:

	Game (int gridSize);

	~Game ();

	void Update ();

	static Game* instance;

	static vector <SDL_Rect> vertVector;
	static vector <SDL_Rect> horiVector;


private:


	void Loader ();
	void SetGridSize (int gridSize);
	void GridDrawer ();
	vector <SDL_Rect> PopulateGridRectArray ();
	DerivationStrategy derivationStrategy;
	SDL_Rect gameBG;
	SDL_Rect HoriRect;
  	SDL_Rect VertRect;
  	SDL_Rect cellSize;
  	SDL_Surface *horizontalLine = nullptr;
  	SDL_Surface  *verticalLine = nullptr;
  	SDL_Surface *cellSprite = nullptr;
  	SDL_Surface *deadCell = nullptr;
	int usableScreenHeight = 500;
	int usableScreenWidth = 600;
	int gridSize = 10;

	bool isPLaying = false;


};