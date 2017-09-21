#include <iostream>
#include <vector>
#include "SDL2/SDL_image.h"
using namespace std;

class GraphicsManager {

public:
  GraphicsManager ();

  ~GraphicsManager ();

private:
  static GraphicsManager *instance;
};
