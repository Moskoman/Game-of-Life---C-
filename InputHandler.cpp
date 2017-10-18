#include "InputHandler.h"


	//Constructor and Destructor
	InputHandler::InputHandler () {};


	InputHandler::~InputHandler () {};


	//Reading
	vector <int> InputHandler::ReadInput () {

		while (SDL_PollEvent (&event) != 0){

			if (event.type == SDL_QUIT){
				quit = true;
			}

			if (event.type == SDL_MOUSEBUTTONDOWN){
				SDL_GetMouseState(&mouseX, &mouseY);
				return GetMouseInput (mouseX, mouseY);
			}
		}
		vector <int> empty;
		return empty;
	};

	vector <int> InputHandler::GetMouseInput (int mouseX, int mouseY) {

		vector <int> returnXY;
		int returnX = mouseX;
		int returnY = mouseY;
		returnXY.push_back (mouseX);
		returnXY.push_back (mouseY);

		return returnXY;
	};

	bool InputHandler::GetQuit () {
		return quit;
	};