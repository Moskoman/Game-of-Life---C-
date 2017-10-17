#include "Menu.h"

Menu::Menu () {

	if (instance != nullptr){
   		cerr << "Too many Menu instances" << endl;
   		exit (1);
  	};	
  instance = this;


  LoadSpriteToArray ("Assets/Menu/bg.png");
  rectMenuBG.x = rectMenuBG.y = 0;
  rectMenuBG.w = 801;
  rectMenuBG.h = 601;
  rectArray.push_back (&rectMenuBG);
  LoadSpriteToArray ("Assets/Menu/playButton.png");
  //LoadRectToArray (300, 400, 200, 100);
  rectPlayButton.x = 300;
  rectPlayButton.y = 400;
  rectPlayButton.w = 200;
  rectPlayButton.h = 100;
  rectArray.push_back (&rectPlayButton);
};

Menu::~Menu(){};

void Menu::Loader() {
	int i = 2;
};