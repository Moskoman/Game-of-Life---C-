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
	void TreatInput (vector <int> MousePosition);
	void SetCellRect (Cell* cell);
	void InitializeCellArray ();
	void PrepareVectorWithCells ();
	vector <Cell*> gameCells;
	DerivationStrategy derivationStrategy;
	SDL_Rect gameBG, cellSize, pauseButton;
  	SDL_Surface *cellSprite = nullptr;
  	SDL_Surface *deadCell = nullptr;
	int usableScreenHeight = 500;
	int usableScreenWidth = 600;
	int gridSize = 10;

	bool isPLaying = false;


};