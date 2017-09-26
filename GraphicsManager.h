#include <iostream>
#include <vector>
#include "SDL2/SDL_image.h"
using namespace std;

class GraphicsManager {

public:
  GraphicsManager ();

  ~GraphicsManager ();

  void Run ();

  void Drawer (SDL_Surface *sprite);

  void CreateWindow ();



private:
  static GraphicsManager *instance;
  SDL_Window *gameWindow = nullptr;
  SDL_Surface *surfaceWindow = nullptr;
   SDL_Renderer *renderer = nullptr;
};
