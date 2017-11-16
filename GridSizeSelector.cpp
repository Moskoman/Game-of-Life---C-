#include "GridSizeSelector.h"


GridSizeSelector* GridSizeSelector::instance = nullptr;

GridSizeSelector::GridSizeSelector () {

	if (instance != nullptr){
   		cerr << "Too many Menu instances" << endl;
   		exit (1);
  	};	
  instance = this;
  nextStateCondition = false;
  Loader ();

  };

GridSizeSelector::~GridSizeSelector () {};

void GridSizeSelector::Update () {
	cout << gridSize << endl;
};

void GridSizeSelector::Loader () {

	LoadSpriteToArray ("Assets/GridSelector/bg.png");
	gridSizeSelectorBG.x = gridSizeSelectorBG.y = 0;
	gridSizeSelectorBG.w = 801;
	gridSizeSelectorBG.h = 601;
	rectArray.push_back (&gridSizeSelectorBG);

	LoadSpriteToArray ("Assets/GridSelector/plusButton.png");
	plusButton.x = 700;
	plusButton.y = lessButton.y = 275;
	plusButton.w = plusButton.h =  lessButton.w = lessButton.h = 50;
	rectArray.push_back (&plusButton);

	LoadSpriteToArray ("Assets/GridSelector/lessButton.png");
	lessButton.x = 50;
	rectArray.push_back (&lessButton);
	
	LoadSpriteToArray ("Assets/GridSelector/playButton.png");
	playButton.x = 364;
	playButton.y = 500;
	playButton.w = playButton.h = 75;
	rectArray.push_back (&playButton);

};

void GridSizeSelector::TreatInput (vector <int> MouseInput) {
	if ((MouseInput[0] > playButton.x && MouseInput[0] < (playButton.x + playButton.w)) && (MouseInput[1] > playButton.y && MouseInput[1] < (playButton.y + playButton.h ))){
    nextStateCondition = true;
	}

	else if ((MouseInput[0] > plusButton.x && MouseInput[0] < (plusButton.x + plusButton.w)) && (MouseInput[1] > plusButton.y && MouseInput[1] < (plusButton.y + plusButton.h ))){
    	this->gridSize = gridSize + 5;
    	
	}

	else if ((MouseInput[0] > lessButton.x && MouseInput[0] < (lessButton.x + lessButton.w)) && (MouseInput[1] > lessButton.y && MouseInput[1] < (lessButton.y + lessButton.h ))) {
		this->gridSize = gridSize - 5;
	}

};