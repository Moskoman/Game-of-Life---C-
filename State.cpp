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
	SDL_Surface *newSprite = IMG_Load (Path);
	spriteArray.push_back (newSprite);
};

bool State::getNextStateCondition () {
	return nextStateCondition;
};