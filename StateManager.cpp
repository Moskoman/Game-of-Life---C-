#include "StateManager.h"

StateManager* StateManager::instance = nullptr; 

StateManager::StateManager() {

//Singleton to make sure we only have one instace of the manager
  if (instance != nullptr){
    cerr << "Too many StateManager instances" << endl;
    exit (1);
  }
	instance = this;
	stateCounter = 1;
	SetState(stateCounter);
	InputHandler Handler ();
	hasQuit = false;

};

StateManager::~StateManager(){};

void StateManager::SetState (int newState){
	State *stateToSet = CreateState (newState);
	if (stateCounter == 3){
		stateToSet->gridSize = currentState->gridSize;
	}
	this->currentState = stateToSet;
};

State* StateManager::CreateState (int newState){
	State *returnNewState = nullptr;
	if (newState == 1){
		returnNewState = new Menu ();
	}
	else if (newState == 2){
		returnNewState = new GridSizeSelector ();
	}
	else if (newState == 3){
		returnNewState = new Game (20);
	}

	return returnNewState;
};

bool StateManager::UserQuits () {
	return hasQuit;
};

void StateManager::Update () {
	vector <int> Input = Handler.ReadInput();
	if (Handler.GetQuit () == true){
		hasQuit = true;
	};

	if (Input.size() > 1){
		currentState->TreatInput (Input);
	};

	currentState->Update ();

	if (currentState->getNextStateCondition () == true){
		stateCounter++;
		SetState(stateCounter);
	};
};