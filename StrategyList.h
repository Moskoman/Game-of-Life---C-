#ifndef STRATEGY_LIST_H
#define STRATEGY_LIST_H
#include <iostream>
#include <vector>
#include "DerivationStrategy.h"
#include "OriginalStrategy.h"
using namespace std;

class StrategyList {

public:

	StrategyList ();

	~StrategyList ();

	DerivationStrategy* currentStrategy;
private:

	void InitializeList ();

	vector <DerivationStrategy*> strategies;


};

#endif