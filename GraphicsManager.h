#include <iostream>
#include <vector>
#include "Cell.h"
#include "SDL2/SDL_image.h"
using namespace std;

class GraphicsManager {

public:
  GraphicsManager ();

  ~GraphicsManager ();

  void Run ();


  void CreateWindow ();

  void RenderArray (vector <SDL_Surface*> spriteArray, vector <SDL_Rect*> rectArray);

  void SetGridSize (int gridSize);

private:
  
  static GraphicsManager *instance;
  SDL_Window *gameWindow = nullptr;

  SDL_Surface *surfaceWindow = nullptr;

  SDL_Renderer *renderer = nullptr;
  int ScreenWidth = 801;
  int ScreenHeight = 601;
  
};