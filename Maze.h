#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include "Cell.h"
#include "DerivationStrategy.h"

class Maze : public DerivationStrategy {

	public:

		Maze ();
		Maze (int dummy);

		~Maze ();

		vector <Cell*> ShouldRevive (vector <Cell*> Cells);

		vector <Cell*> ShouldKeepAlive (vector <Cell*> Cellsa);


};

#endif