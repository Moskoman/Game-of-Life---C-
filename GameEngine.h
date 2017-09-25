#include <iostream>
#include <vector>
using namespace std;
//Classe abstrata Game Engine
class GameEngine {

private:

//retorna as células vivas
  vector<int> AliveCells ();

//calcula próxima geração
  void NextGeneration ();

//metódos abstratos ShouldRevive e ShouldKeepAlive
  virtual void ShouldRevive () {};

  virtual void ShouldKeepAlive () {};
};
