#include "Menu.h"

Menu::Menu () {

	if (instance != nullptr){
   		cerr << "Too many Menu instances" << endl;
   		exit (1);
  	};	
  instance = this;


  LoadSpriteToArray ("Assets/Menu/bg.png");
  SDL_Rect newRect;
  	newRect.x = 0;
	newRect.y = 0;
	newRect.w = 801;
	newRect.h = 601;
rectArray.push_back (&newRect);
  //LoadRectToArray (0, 0, 801, 601);
};