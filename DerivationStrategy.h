#include <iostream>
#include "GameEngine.h"
using namespace std;

class DerivationStrategy : public GameEngine {

public:

//Constructor and Destructor
  DerivationStrategy ();
  ~DerivationStrategy ();

//Game Methods
  void ShouldRevive ();
  void ShouldKeepAlive ();

//Instance
  static DerivationStrategy* instance;

};
