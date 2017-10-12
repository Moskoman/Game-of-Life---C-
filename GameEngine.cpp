#include <iostream>
#include "GameEngine.h"


void GameEngine::NextGeneration () {

  ShouldRevive ();
  NextGeneration ();
} ;
