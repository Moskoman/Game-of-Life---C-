#ifndef DERIVATIONSTRATEGY_H
#define DERIVATIONSTRATEGY_H
#include <iostream>
#include "GameEngine.h"
using namespace std;

class DerivationStrategy : public GameEngine {

public:

//Constructor and Destructor
  DerivationStrategy ();
  ~DerivationStrategy ();

 //Run
  	vector <Cell*> NextGeneration ();

//Game Methods
  vector <Cell*> ShouldRevive ();
  vector <Cell*> ShouldKeepAlive ();

//Instance
  static DerivationStrategy* instance;

};

#endif