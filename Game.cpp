#include "Game.h"

Game* Game::instance = nullptr;
vector <SDL_Rect> Game::vertVector;
vector <SDL_Rect> Game::horiVector;

Game::Game (int gridSize) {

	if (instance != nullptr){
   		cerr << "Too many Menu instances" << endl;
   		exit (1);
  	};	
  instance = this;
  SetGridSize(gridSize);
  nextStateCondition = false;
  Loader ();

  GridDrawer();
  derivationStrategy.Populate(gridSize);
};

Game::~Game () {};

void Game::Update () {

	derivationStrategy.NextGeneration();
};

void Game::Loader () {

	LoadSpriteToArray ("Assets/Game/gameBG.png");
	gameBG.x = gameBG.y = 0;
	gameBG.w = 801;
	gameBG.h = 601;
	rectArray.push_back (&gameBG);


    horizontalLine = IMG_Load ("Assets/line.png");
    verticalLine = IMG_Load ("Assets/verticalLine.png");
    cellSprite = IMG_Load ("Assets/cell.png");
    deadCell = IMG_Load ("Assets/deadCell.png");
};

void Game::GridDrawer () {
	cellSize.w = usableScreenWidth / gridSize;
    cellSize.h = (usableScreenHeight - 99) / gridSize;
    vertVector = PopulateGridRectArray ();
    for (auto i = 0; i <= vertVector.size (); i++){
    	vertVector[i].x = 100;
    	vertVector[i].y = 100 + (cellSize.h * i);
    	vertVector[i].w = usableScreenWidth;
    	vertVector[i].h = 1;
    	LoadSpriteToArray ("Assets/Game/line.png");
    	rectArray.push_back (&vertVector[i]);
    };

    horiVector = PopulateGridRectArray ();
    for (auto i = 0; i <= horiVector.size(); i++){
    	horiVector[i].x = 100 + (cellSize.w * i);
    	horiVector[i].y = 100;
    	horiVector[i].w = 1;
    	horiVector[i].h = usableScreenHeight - 100;
    	LoadSpriteToArray ("Assets/Game/verticalLine.png");
    	rectArray.push_back (&horiVector[i]);
    };

 };

 /*         for (auto x = 0; x < Cells.size(); x++){
          cellSize.x = (Cells[x]->posX * cellSize.w);
          cellSize.y = ((Cells[x]->posY * cellSize.h) + HoriRect.y);
          if (Cells[x]->getState() == true){
          SDL_BlitScaled (cellSprite, NULL, surfaceWindow, &cellSize);
          }
          else{
          SDL_BlitScaled (deadCell, NULL, surfaceWindow, &cellSize);  
          };

        };
  };
*/

void Game::SetGridSize (int gridSize){
	this->gridSize = gridSize;
};

vector <SDL_Rect> Game::PopulateGridRectArray () {

	vector <SDL_Rect> GridRectArray;
	for (auto i = 0; i < gridSize; i++){
		SDL_Rect newRect;
		GridRectArray.push_back (newRect);
	};
	return GridRectArray;
};

void Game::TreatInput (vector <int> MousePosition){
	if (!isPLaying){
		if ((MousePosition[0] > 100 && MousePosition[0] < (100 + usableScreenWidth)) && (MousePosition[1] > 100 && (MousePosition[1] < usableScreenHeight))){
			cout << "clicou no grid" << endl;
 		}

	};
};