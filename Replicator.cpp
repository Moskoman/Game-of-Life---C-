#include "Replicator.h"

	Replicator::Replicator () {	};

	Replicator::Replicator (int dummy) {};

	Replicator::~Replicator () {};

	vector <Cell*> Replicator::ShouldRevive (vector <Cell*> Cells) {

		vector <Cell*> ReviveList;
		for (auto i = 0; i < Cells.size(); i++){
			if ((AliveNeighboors(Cells[i], Cells) == 0 || AliveNeighboors(Cells[i], Cells) == 2 || AliveNeighboors(Cells[i], Cells) == 4 || AliveNeighboors(Cells[i], Cells) == 6) && Cells[i]->getState() == false){
				ReviveList.push_back (Cells[i]);
			};
		};

		return ReviveList;
	};

	vector <Cell*> Replicator::ShouldKeepAlive (vector <Cell*> Cellsa) {

		vector <Cell*> KeepAlive;
		for (auto x = 0; x < Cellsa.size(); x++){
			int cellAliveNeighboors = AliveNeighboors (Cellsa[x], Cellsa);
			if (Cellsa[x]->getState() == true && (cellAliveNeighboors == 0 || cellAliveNeighboors == 2 || cellAliveNeighboors == 4 || cellAliveNeighboors == 6)){
				KeepAlive.push_back(Cellsa[x]);
			};
		};


		return KeepAlive;
	};