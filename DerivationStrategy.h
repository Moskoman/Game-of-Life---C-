#include <iostream>
#include "GameEngine.h"
using namespace std;

class DerivationStrategy : public GameEngine {

public:
  void ShouldRevive ();
  void ShouldKeepAlive ();
};
