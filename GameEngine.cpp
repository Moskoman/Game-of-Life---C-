#include <iostream>
#include "GameEngine.h"

vector<int> GameEngine::AliveCells () {};

void GameEngine::NextGeneration () {

  ShouldRevive ();
  NextGeneration ();
} ;
