#include "DerivationStrategy.h"

//Instance pointer set to NULL for safety reasons
  DerivationStrategy* DerivationStrategy::instance = nullptr;

//Constructor and Destructor
DerivationStrategy::DerivationStrategy () {

    //Simple Singleton
    if (instance != nullptr){
      cerr << "Too many DerivationStrategy instances" << endl;
      exit (1);
    }
    instance = this;
};

DerivationStrategy::~DerivationStrategy () {};


//Game Methods
  void DerivationStrategy::ShouldRevive() {};

  void DerivationStrategy::ShouldKeepAlive() {};
