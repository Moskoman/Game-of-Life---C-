#include <iostream>
#include "State.h"
#include "InputHandler.h"
#include "Menu.h"
#include "GridSizeSelector.h"
#include "Game.h"
using namespace std;

class StateManager {

public:
	StateManager();

	~StateManager();

	void Update ();

	void SetState(int newState);

	bool UserQuits ();

	State *currentState = nullptr;
	
private:
	State* CreateState(int newState);
	static StateManager *instance;
	int stateCounter;
	bool hasQuit = true;
	InputHandler Handler;

};