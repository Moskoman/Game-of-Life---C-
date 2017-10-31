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

  derivationStrategy.Populate(gridSize);
  derivationStrategy.ChangeCellState (4, 1);
  derivationStrategy.ChangeCellState (4, 2);
  derivationStrategy.ChangeCellState (4, 3);
  GridDrawer();
  InitializeCellArray ();
  isPLaying = false;
};

Game::~Game () {};

void Game::Update () {
		PrepareVectorWithCells();

	if (isPLaying){
		derivationStrategy.NextGeneration();
	};
};

void Game::Loader () {

	LoadSpriteToArray ("Assets/Game/gameBG.png");
	gameBG.x = gameBG.y = 0;
	gameBG.w = 801;
	gameBG.h = 601;
	rectArray.push_back (&gameBG);

	LoadSpriteToArray ("Assets/Game/pauseButton.png");
	pauseButton.x = 364;
	pauseButton.y = 10;
	pauseButton.w = pauseButton.h = 75;
	rectArray.push_back (&pauseButton);
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

	//click on grid
		if ((MousePosition[0] > 100 && MousePosition[0] < (100 + usableScreenWidth)) && (MousePosition[1] > 100 && (MousePosition[1] < usableScreenHeight))){
			if (!isPLaying){
				derivationStrategy.ChangeCellState ((MousePosition[0] / cellSize.w), (MousePosition[1] /cellSize.h));
			};
			
 		}

 	//pause button
 		else if ((MousePosition[0] > pauseButton.x && MousePosition[0] < (pauseButton.x + pauseButton.w)) && (MousePosition[1] > pauseButton.y && MousePosition[1] < (pauseButton.y + pauseButton.h))){
 			if (!isPLaying) {
 				isPLaying = true;
 				spriteArray[1] = IMG_Load ("Assets/Game/playButton.png");
 			}
 			else {
 				isPLaying = false;
 				spriteArray[1] = IMG_Load ("Assets/Game/pauseButton.png");
 			};
 		}

};

void Game::SetCellRect (Cell* cell){
	cell->cellRect.x = cell->posX * cellSize.w + 101;
	cell->cellRect.y = cell->posY * cellSize.h + 101;
	cell->cellRect.w = cellSize.w - 1;
	cell->cellRect.h = cellSize.h - 1;
	rectArray.push_back(&cell->cellRect);
}

void Game::InitializeCellArray (){
	gameCells = derivationStrategy.Cells;
	for (auto i = 0; i < gameCells.size(); i++){
		if (gameCells[i]->getState() == true){
			LoadSpriteToArray("Assets/Game/cell.png");
		}
		else if (gameCells[i]->getState() == false){
			LoadSpriteToArray("Assets/Game/deadCell.png");
		};
		SetCellRect(gameCells[i]);

	}
}

void Game::PrepareVectorWithCells () {
	spriteArray.erase ((spriteArray.begin() + ((gridSize + 1) * 2) + 2));
	rectArray.erase ((rectArray.begin() + ((gridSize + 1) * 2) + 2));
	InitializeCellArray ();
}