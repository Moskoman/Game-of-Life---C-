#ifndef GRIDSIZESELECTOR_H
#define GRIDSIZESELECTOR_H
#include <iostream>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "State.h"
#include <vector>

class GridSizeSelector : public State {

public:

	GridSizeSelector ();

	~GridSizeSelector ();

	void Update ();

	void TreatInput (vector <int> MouseInput);

	static GridSizeSelector* instance;

	static int selectedStrategy;

private:

	void Loader();
	void UpdateGridSizeImage (int gridSize);
	void UpdateStateImage (int currentState);
	SDL_Rect gridSizeSelectorBG;
	SDL_Rect plusButton;
	SDL_Rect lessButton;
	SDL_Rect statePlusButton;
	SDL_Rect stateLessButton;
	SDL_Rect playButton;
	SDL_Rect numbers;
	SDL_Rect stateName;
	int currentState = 0;

};

#endif