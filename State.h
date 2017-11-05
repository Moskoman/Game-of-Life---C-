#ifndef STATE_H
#define STATE_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class State
{
public:
	State();

	~State();

	virtual void Update () {};

	vector <SDL_Surface*> getSpriteArray ();

	vector <SDL_Rect*> getRectArray ();

	bool getNextStateCondition ();

	virtual void TreatInput (vector <int> MouseInput) {};
	
		int gridSize;
		int GetGridSize(){return gridSize;};
	protected:

		unordered_map <string, SDL_Surface*> loadedSurfaces;
		virtual void Loader () {};
		vector <SDL_Surface*> spriteArray;
		vector <SDL_Rect*> rectArray;
		bool nextStateCondition;

	void LoadSpriteToArray (char* Path);
};

#endif