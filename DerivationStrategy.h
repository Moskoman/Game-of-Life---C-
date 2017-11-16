#include "OriginalStrategy.h"
#include "HighLife.h"
#include "DayNight.h"
#include "Maze.h"
#include "Replicator.h"

#ifndef DERIVATIONSTRATEGY_H
#define DERIVATIONSTRATEGY_H
#include "GridSizeSelector.h"
#include <iostream>
#include "GameEngine.h"
using namespace std;

class DerivationStrategy : public GameEngine {

public:

//Constructor and Destructor
	DerivationStrategy ();
	DerivationStrategy (int dummy);
	~DerivationStrategy ();

 //Run
	vector <Cell*> NextGeneration ();

//Game Methods
	virtual vector <Cell*> ShouldRevive (vector <Cell*> Cells);
	virtual vector <Cell*> ShouldKeepAlive (vector <Cell*> Cells);

//Instance
	static DerivationStrategy* instance;

	vector <DerivationStrategy*> strategyList;

	DerivationStrategy* selectedStrategy = nullptr;

	DerivationStrategy* CreateStrategy ();

};

#endif