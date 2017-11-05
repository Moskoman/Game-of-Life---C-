#include <iostream>
#include "SDL2/SDL_image.h"
#include "State.h"
#include <vector>

class GridSizeSelector : public State {

public:

	GridSizeSelector ();

	~GridSizeSelector ();

	void Update ();

	void TreatInput (vector <int> MouseInput);

	static GridSizeSelector* instance;

	int gridSize = 0;
private:

	void Loader();
	SDL_Rect gridSizeSelectorBG;
	SDL_Rect plusButton;
	SDL_Rect lessButton;
	SDL_Rect playButton;
};