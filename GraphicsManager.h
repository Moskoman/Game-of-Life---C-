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


  void CellDrawer (vector <Cell*> AliveCells);

  void CreateWindow ();



private:
  void GridDrawer (SDL_Surface *horizontalLine, SDL_Surface *verticalLine);
  
  static GraphicsManager *instance;
  SDL_Window *gameWindow = nullptr;
  SDL_Surface *horizontalLine = nullptr;
  SDL_Surface  *verticalLine = nullptr;
  SDL_Surface *surfaceWindow = nullptr;
  SDL_Surface *cellSprite = nullptr;
  SDL_Surface *deadCell = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_Rect HoriRect;
  SDL_Rect VertRect;
  SDL_Rect cellSize;
  int ScreenWidth = 801;
  int ScreenHeight = 600;
};