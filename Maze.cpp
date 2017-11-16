#include "Maze.h"

	Maze::Maze () {	};

	Maze::Maze (int dummy) {};

	Maze::~Maze () {};

	vector <Cell*> Maze::ShouldRevive (vector <Cell*> Cells) {

		vector <Cell*> ReviveList;
		for (auto i = 0; i < Cells.size(); i++){
			if (AliveNeighboors(Cells[i], Cells) == 2 && Cells[i]->getState() == false){
				ReviveList.push_back (Cells[i]);
			};
		};

		return ReviveList;
	};

	vector <Cell*> Maze::ShouldKeepAlive (vector <Cell*> Cellsa) {

		vector <Cell*> KeepAlive;
		for (auto x = 0; x < Cellsa.size(); x++){
			int cellAliveNeighboors = AliveNeighboors (Cellsa[x], Cellsa);
			if (Cellsa[x]->getState() == true && (cellAliveNeighboors >= 0 && cellAliveNeighboors < 5)){
				KeepAlive.push_back(Cellsa[x]);
			};
		};


		return KeepAlive;
	};