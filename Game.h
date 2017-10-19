#include <iostream>
#include "State.h"
#include "DerivationStrategy.h"
#include "GameEngine.h"

class Game : public State {

public:

	Game ();

	~Game ();

	void Update ();

	static Game* instance;

private:

	void Loader ();
	DerivationStrategy derivationStrategy;
	SDL_Rect gameBG;

};