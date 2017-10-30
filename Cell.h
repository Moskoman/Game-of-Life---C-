#ifndef CELL_H
#define CELL_H
#include "SDL2/SDL.h"
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
  
  SDL_Rect cellRect;
  
private:
  bool isAlive;


};

#endif