#include "StateManager.h"

StateManager* StateManager::instance = nullptr; 

StateManager::StateManager() {

//Singleton to make sure we only have one instace of the manager
  if (instance != nullptr){
    cerr << "Too many StateManager instances" << endl;
    exit (1);
  }
  instance = this;

SetState(1);


};

StateManager::~StateManager(){};

void StateManager::SetState (int newState){
	State *stateToSet = CreateState (newState);
	this->currentState = stateToSet;

};

State* StateManager::CreateState (int newState){
	State *returnNewState = nullptr;
	if (newState == 1){
		returnNewState = new Menu ();
	}

	return returnNewState;
};
