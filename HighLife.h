#ifndef HIGHLIFE_H
#define HIGHLIFE_H
#include <iostream>
#include <vector>
#include "Cell.h"
#include "DerivationStrategy.h"

class HighLife : public DerivationStrategy {

	public:

		HighLife ();
		HighLife (int dummy);

		~HighLife ();

		vector <Cell*> ShouldRevive (vector <Cell*> Cells);

		vector <Cell*> ShouldKeepAlive (vector <Cell*> Cellsa);


};

#endif