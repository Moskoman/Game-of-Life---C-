#include "SDL.h"
using namespace std;

class InputHandler {

public:

	//Constructor and Destructor
	InputHandler ();

	~InputHandler ();

	//Handles Inputs
	void ReadInput ();

	bool UserQuits ();

private:

	SDL_Event event;
	bool quit = false;



};