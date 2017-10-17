#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "SDL.h"
#include <iostream>
using namespace std;

class InputHandler {

public:

	//Constructor and Destructor
	InputHandler ();

	~InputHandler ();

	//Handles Inputs
	bool ReadInput ();


private:

	SDL_Event event;
	int mouseX, mouseY;
	bool quit = false;



};

#endif