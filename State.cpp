#include "State.h"

State* State::instance = nullptr;

State::State() {};

State::~State() {};

void State::Update() {};


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

void State::LoadRectToArray (int x, int y, int w, int h){
	newRect.x = x;
	newRect.y = y;
	newRect.w = w;
	newRect.h = h;

	rectArray.push_back(&newRect);
};