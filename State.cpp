#include "State.h"

State::State() {};

State::~State() {};

vector <SDL_Surface*> State::getSpriteArray () {
	return spriteArray;
};

vector <SDL_Rect*> State::getRectArray () {
	return rectArray;
};

void State::LoadSpriteToArray (char* Path) {
	SDL_Surface *newSprite;
	string file (Path);
	if (loadedSurfaces [file] == NULL){
		newSprite = IMG_Load (Path);
		loadedSurfaces[file] = newSprite;
	}
	else
		newSprite = loadedSurfaces[file]; 
		
	spriteArray.push_back (newSprite);
};

bool State::getNextStateCondition () {
	return nextStateCondition;
};