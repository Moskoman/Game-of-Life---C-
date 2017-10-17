#ifndef MENU_H
#define MENU_H
#include <vector>
#include "State.h"

class Menu : public State {

public:
	Menu();
	~Menu();


private:

	void Loader ();
	SDL_Surface *menuBG = nullptr;
	SDL_Rect rectMenuBG, rectPlayButton;
};

#endif