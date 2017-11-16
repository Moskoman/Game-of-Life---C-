#include "StrategyList.h"

StrategyList::StrategyList () {

	InitializeList();
};

void StrategyList::InitializeList () {

	strategies[0] = new OriginalStrategy ();
	currentStrategy = strategies[0];
};