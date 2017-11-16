#ifndef REPLICATOR_H
#define REPLICATOR_H
#include <iostream>
#include <vector>
#include "Cell.h"
#include "DerivationStrategy.h"

class Replicator : public DerivationStrategy {

	public:

		Replicator ();
		Replicator (int dummy);

		~Replicator ();

		vector <Cell*> ShouldRevive (vector <Cell*> Cells);

		vector <Cell*> ShouldKeepAlive (vector <Cell*> Cellsa);


};

#endif