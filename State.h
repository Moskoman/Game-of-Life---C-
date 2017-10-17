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

	void LoadSpriteToArray (char* Path);

	void LoadRectToArray (int x, int y, int w, int h);

	protected:
		static State *instance;
		SDL_Rect newRect;
		vector <SDL_Surface*> spriteArray;
		vector <SDL_Rect*> rectArray;
};

#endif