#include "Menu.h"

Menu::Menu () {

	if (instance != nullptr){
   		cerr << "Too many Menu instances" << endl;
   		exit (1);
  	};	
  instance = this;
  nextStateCondition = false;
  Loader ();
};

Menu::~Menu(){};

void Menu::Update () {};

void Menu::Loader() {
	
  LoadSpriteToArray ("Assets/Menu/bg.png");
  rectMenuBG.x = rectMenuBG.y = 0;
  rectMenuBG.w = 801;
  rectMenuBG.h = 601;
  rectArray.push_back (&rectMenuBG);
  LoadSpriteToArray ("Assets/Menu/playButton.png");
  rectPlayButton.x = 300;
  rectPlayButton.y = 400;
  rectPlayButton.w = 200;
  rectPlayButton.h = 100;
  rectArray.push_back (&rectPlayButton);
};

void Menu::TreatInput (vector <int> MouseInput){
  if ((MouseInput[0] > 300 && MouseInput[0] < 500) && (MouseInput[1] > 400 && MouseInput[1] < 500 )){
    cout << "clicou" << endl;
  }
};