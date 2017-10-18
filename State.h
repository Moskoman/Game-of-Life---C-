#ifndef STATE_H
#define STATE_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
#include <iostream>
using namespace std;

class State
{
public:
	State();

	~State();

	void Update ();

	vector <SDL_Surface*> getSpriteArray ();

	vector <SDL_Rect*> getRectArray ();

	virtual void TreatInput (vector <int> MouseInput) {};
	
	protected:
		static State *instance;
		vector <SDL_Surface*> spriteArray;
		vector <SDL_Rect*> rectArray;
		bool nextStateCondition;

	void LoadSpriteToArray (char* Path);
};

#endif