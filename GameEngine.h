#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <vector>
#include "Cell.h"
using namespace std;

//Classe abstrata Game Engine
class GameEngine {

public:

//Revive
 void Revive (int posX, int posY);


  vector<Cell*> Cells;
  
//Populate board
void Populate (int gridSize);
  
void SetGridSize (int grid);

protected:
int gridSize = 0;

//Returns vector with x and y coordinates of cell 
vector<int> GetCellPosition (Cell *cell);


//Return number of alive neighbors of a cell
int AliveNeighboors (Cell *cell);

//calcula próxima geração
  void NextGeneration ();

//metódos abstratos ShouldRevive e ShouldKeepAlive
  virtual vector <Cell*> ShouldRevive () {};

  virtual vector <Cell*> ShouldKeepAlive () {};
};

#endif