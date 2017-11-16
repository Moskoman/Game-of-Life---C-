#include "GridSizeSelector.h"


GridSizeSelector* GridSizeSelector::instance = nullptr;
int GridSizeSelector::selectedStrategy = 0;

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

	LoadSpriteToArray ("Assets/GridSelector/0.png");
	numbers.x = 364;
	numbers.y = 300;
	numbers.w = numbers.h = 50;
	rectArray.push_back (&numbers);

	LoadSpriteToArray ("Assets/GridSelector/plusButton.png");
	statePlusButton.x = 700;
	statePlusButton.y = stateLessButton.y = 400;
	statePlusButton.w = statePlusButton.h =  stateLessButton.w = stateLessButton.h = 50;
	rectArray.push_back (&statePlusButton);

	LoadSpriteToArray ("Assets/GridSelector/lessButton.png");
	stateLessButton.x = 50;
	rectArray.push_back (&stateLessButton);

	LoadSpriteToArray ("Assets/GridSelector/conway.png");
	stateName.x = 150;
	stateName.y = 400;
	stateName.w = 447;
	stateName.h = 105;
	rectArray.push_back (&stateName);

};

void GridSizeSelector::TreatInput (vector <int> MouseInput) {
	if ((MouseInput[0] > playButton.x && MouseInput[0] < (playButton.x + playButton.w)) && (MouseInput[1] > playButton.y && MouseInput[1] < (playButton.y + playButton.h ))){
    nextStateCondition = true;
	}

	else if ((MouseInput[0] > plusButton.x && MouseInput[0] < (plusButton.x + plusButton.w)) && (MouseInput[1] > plusButton.y && MouseInput[1] < (plusButton.y + plusButton.h ))){
    	if (gridSize < 70){
	    	this->gridSize = gridSize + 5;
	    	UpdateGridSizeImage(gridSize);
    	};
	}

	else if ((MouseInput[0] > lessButton.x && MouseInput[0] < (lessButton.x + lessButton.w)) && (MouseInput[1] > lessButton.y && MouseInput[1] < (lessButton.y + lessButton.h ))) {
		if (gridSize > 0){
			this->gridSize = gridSize - 5;
			UpdateGridSizeImage(gridSize);
		};
	}

	else if ((MouseInput[0] > statePlusButton.x && MouseInput[0] < (statePlusButton.x + statePlusButton.w)) && (MouseInput[1] > statePlusButton.y && MouseInput[1] < (statePlusButton.y + statePlusButton.h ))){
    	if (currentState < 5){
	    	this->currentState = currentState + 1;
	    	selectedStrategy = currentState;
	    	UpdateStateImage(currentState);
    	};
	}

	else if ((MouseInput[0] > stateLessButton.x && MouseInput[0] < (stateLessButton.x + stateLessButton.w)) && (MouseInput[1] > stateLessButton.y && MouseInput[1] < (stateLessButton.y + stateLessButton.h ))) {
		if (currentState > 0){
			this->currentState = currentState - 1;
			selectedStrategy = currentState;
			UpdateStateImage(currentState);
		};
	}

	
};

void GridSizeSelector::UpdateGridSizeImage (int gridSize){

	switch (gridSize){

		case 0:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/0.png");
			 break;
		case 5:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/5.png");
			 break;
		case 10:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/10.png");
			 break;
		case 15:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/15.png");
			 break;
		case 20:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/20.png");
			 break;
		case 25:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/25.png");
			 break;
		case 30:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/30.png");
			 break;
		case 35:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/35.png");
			 break;
		case 40:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/40.png");
			 break;
		case 45:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/45.png");
			 break;
		case 50:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/50.png");
			 break;
		case 55:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/55.png");
			 break;
		case 60:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/60.png");
			 break;
		case 65:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/65.png");
			 break;
		case 70:
			 spriteArray[4] = IMG_Load ("Assets/GridSelector/70.png");
			 break;
				
	}
};

void GridSizeSelector::UpdateStateImage (int currentState){

	switch (currentState){

		case 1:
			 spriteArray[7] = IMG_Load ("Assets/GridSelector/conways.png");
			 break;
		case 2:
			 spriteArray[7] = IMG_Load ("Assets/GridSelector/daynight.png");
			 break;
		case 3:
			 spriteArray[7] = IMG_Load ("Assets/GridSelector/highlife.png");
			 break;
		case 4:
			 spriteArray[7] = IMG_Load ("Assets/GridSelector/maze.png");
			 break;
		case 5:
			 spriteArray[7] = IMG_Load ("Assets/GridSelector/replication.png");
			 break;
		
	}
};