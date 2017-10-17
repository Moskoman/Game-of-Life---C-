#include "InputHandler.h"


	//Constructor and Destructor
	InputHandler::InputHandler () {};


	InputHandler::~InputHandler () {};


	//Reading
	bool InputHandler::ReadInput () {

		while (SDL_PollEvent (&event) != 0){

			if (event.type == SDL_QUIT){
				quit = true;
			}

			if (event.type == SDL_MOUSEBUTTONDOWN){
				SDL_GetMouseState(&mouseX, &mouseY);
				cout << "mouse" << mouseX << " " << mouseY  << endl;
			}
		}
		return quit;
	};