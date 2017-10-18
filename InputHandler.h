#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "SDL.h"
#include <iostream>
#include <vector>
using namespace std;

class InputHandler {

public:

	//Constructor and Destructor
	InputHandler ();

	~InputHandler ();

	//Handles Inputs
	vector <int> ReadInput ();

	vector <int> GetMouseInput (int mouseX, int mouseY);

	bool GetQuit ();

private:

	SDL_Event event;
	int mouseX, mouseY;
	bool quit = false;



};

#endif