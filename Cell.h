#include <iostream>
using namespace std;

class Cell {

//Constructor and Destructor
public:
  Cell (int, int);

  ~Cell ();

private:
  bool isAlive;
  int posX, posY;

  void setState (bool);
};
