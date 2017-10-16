#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;

class Cell {

//Constructor and Destructor
public:
  Cell (int, int);

  ~Cell ();

  int posX, posY;

  void setState (bool);

  bool getState ();
  
private:
  bool isAlive;

};

#endif