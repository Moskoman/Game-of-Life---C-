#include "DayNight.h"

	DayNight::DayNight () {	};

	DayNight::DayNight (int dummy) {};

	DayNight::~DayNight () {};

	vector <Cell*> DayNight::ShouldRevive (vector <Cell*> Cells) {

		vector <Cell*> ReviveList;
		for (auto i = 0; i < Cells.size(); i++){
			if ((AliveNeighboors(Cells[i], Cells) == 2 || AliveNeighboors(Cells[i], Cells) == 5 || AliveNeighboors(Cells[i], Cells) == 6 || AliveNeighboors(Cells[i], Cells) == 7) && Cells[i]->getState() == false){
				ReviveList.push_back (Cells[i]);
			};
		};

		return ReviveList;
	};

	vector <Cell*> DayNight::ShouldKeepAlive (vector <Cell*> Cellsa) {

		vector <Cell*> KeepAlive;
		for (auto x = 0; x < Cellsa.size(); x++){
			int cellAliveNeighboors = AliveNeighboors (Cellsa[x], Cellsa);
			if (Cellsa[x]->getState() == true && (cellAliveNeighboors == 2 || cellAliveNeighboors == 3 || cellAliveNeighboors >= 5)){
				KeepAlive.push_back(Cellsa[x]);
			};
		};


		return KeepAlive;
	};