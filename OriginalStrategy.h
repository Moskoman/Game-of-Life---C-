#ifndef ORIGINALSTRATEGY_H
#define ORIGINALSTRATEGY_H
#include <iostream>
#include <vector>
#include "Cell.h"
#include "DerivationStrategy.h"

class OriginalStrategy : public DerivationStrategy {

	public:

		OriginalStrategy ();
		OriginalStrategy (int dummy);

		~OriginalStrategy ();

		vector <Cell*> ShouldRevive (vector <Cell*> Cells);

		vector <Cell*> ShouldKeepAlive (vector <Cell*> Cellsa);


};

#endif