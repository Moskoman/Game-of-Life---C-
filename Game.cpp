#include "Game.h"

Game* Game::instance = nullptr;

Game::Game () {

	if (instance != nullptr){
   		cerr << "Too many Menu instances" << endl;
   		exit (1);
  	};	
  instance = this;
  nextStateCondition = false;
  Loader ();

  DerivationStrategy derivationStrategy  ();
};

Game::~Game () {};

void Game::Update () {

	derivationStrategy.Run ();
};

void Game::Loader () {

	LoadSpriteToArray ("Assets/Game/gameBG.png");
	gameBG.x = gameBG.y = 0;
	gameBG.w = 801;
	gameBG.h = 601;
	rectArray.push_back (&gameBG);


};