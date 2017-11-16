#ifndef DAYNIGHT_H
#define DAYNIGHT_H
#include <iostream>
#include <vector>
#include "Cell.h"
#include "DerivationStrategy.h"

class DayNight : public DerivationStrategy {

	public:

		DayNight ();
		DayNight (int dummy);

		~DayNight ();

		vector <Cell*> ShouldRevive (vector <Cell*> Cells);

		vector <Cell*> ShouldKeepAlive (vector <Cell*> Cellsa);


};

#endif