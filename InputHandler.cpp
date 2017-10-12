#include "InputHandler.h"


	//Constructor and Destructor
	InputHandler::InputHandler () {};


	InputHandler::~InputHandler () {};


	//Reading
	void InputHandler::ReadInput () {

		while (SDL_PollEvent (&event) != 0){

			if (event.type == SDL_QUIT){
				quit = true;
			}
		}
	};

	bool InputHandler::UserQuits () {

		return quit;
	};