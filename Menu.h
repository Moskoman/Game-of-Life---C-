#ifndef MENU_H
#define MENU_H
#include "State.h"

class Menu : public State {

public:
	Menu();

private:
	SDL_Surface *menuBG = nullptr;

};

#endif