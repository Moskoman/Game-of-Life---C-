#include <iostream>
#include "State.h"
#include "Menu.h"
using namespace std;

class StateManager {

public:
	StateManager();

	~StateManager();

	void SetState(int newState);


	State *currentState = nullptr;
private:
	State* CreateState(int newState);
	static StateManager *instance;

};