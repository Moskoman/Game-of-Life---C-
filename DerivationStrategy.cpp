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

DerivationStrategy::DerivationStrategy (int dummy) {
    selectedStrategy = CreateStrategy ();
  };

DerivationStrategy::~DerivationStrategy () {};

	
vector <Cell*> DerivationStrategy::NextGeneration() {
  vector <Cell*> ReviveList = selectedStrategy->ShouldRevive (Cells);
  vector <Cell*> KeepAliveList = selectedStrategy->ShouldKeepAlive (Cells);
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
vector <Cell*> DerivationStrategy::ShouldRevive(vector <Cell*> Cells) {};

vector <Cell*> DerivationStrategy::ShouldKeepAlive(vector <Cell*> Cells) {};

DerivationStrategy* DerivationStrategy::CreateStrategy () {

  if (selectedStrategy != nullptr) {
    return selectedStrategy;
  }
  switch (GridSizeSelector::selectedStrategy){
      case 1:
       return new OriginalStrategy ();
       break;
    case 2:
       return new DayNight ();
       break;
    case 3:
       return new HighLife ();
       break;
    case 4:
       return new Maze ();
       break;
    case 5:
       return new Replicator ();
       break;
    default:
      return new OriginalStrategy ();
    };


    };