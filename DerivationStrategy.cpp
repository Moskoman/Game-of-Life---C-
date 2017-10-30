#include "DerivationStrategy.h"

//Instance pointer set to NULL for safety reasons
  DerivationStrategy* DerivationStrategy::instance = nullptr;

//Constructor and Destructor
DerivationStrategy::DerivationStrategy () {

    //Simple Singleton
    if (instance != nullptr){
      cerr << "Too many DerivationStrategy instances" << endl;
      exit (1);
    }
    instance = this;
};

DerivationStrategy::~DerivationStrategy () {};

	
vector <Cell*> DerivationStrategy::NextGeneration() {
	vector <Cell*> ReviveList = ShouldRevive ();
	vector <Cell*> KeepAliveList = ShouldKeepAlive ();
	vector <Cell*> NextGeneration;
	NextGeneration.reserve (ReviveList.size() + KeepAliveList.size());
	NextGeneration.insert (NextGeneration.begin(), ReviveList.begin(), ReviveList.end());
	NextGeneration.insert (NextGeneration.end(), KeepAliveList.begin(), KeepAliveList.end());
	for (auto i = 0; i < Cells.size(); i++){
		Cells[i]->setState(false);
	};
	for (auto i = 0; i < NextGeneration.size(); i++){
		for (auto f = 0; f < Cells.size(); f++){
			if (NextGeneration[i]->posX == Cells[f]->posX && NextGeneration[i]->posY == Cells[f]->posY){
				Cells[f]->setState (true);
			};
		};
	};
	return NextGeneration;
};


//Game Methods
vector <Cell*> DerivationStrategy::ShouldRevive() {

	vector <Cell*> ReviveList;
	for (auto i = 0; i < Cells.size(); i++){
		if (AliveNeighboors(Cells[i]) == 2 && Cells[i]->getState() == false){
			ReviveList.push_back (Cells[i]);
		};
	};

	return ReviveList;
};

vector <Cell*> DerivationStrategy::ShouldKeepAlive() {

	vector <Cell*> KeepAlive;
	for (auto x = 0; x < Cells.size(); x++){
		int cellAliveNeighboors = AliveNeighboors (Cells[x]);
		if (Cells[x]->getState() == true && (cellAliveNeighboors >= 2 && cellAliveNeighboors < 4)){
			KeepAlive.push_back(Cells[x]);
		};
	};

	return KeepAlive;
};
