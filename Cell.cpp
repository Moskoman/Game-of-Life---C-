#include "Cell.h"

//Constructor and Destructor

  Cell::Cell (int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    setState (true);
  };

  Cell::~Cell () {};

//Sets
  void Cell::setState (bool State){
    this->isAlive = State;
  }

  bool Cell::getState () {

  	return isAlive;
  };