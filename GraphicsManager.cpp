#include <iostream>
#include "GraphicsManager.h"

//instance pointer = null for safety reasons
GraphicsManager* GraphicsManager::instance = nullptr;

//constructor
GraphicsManager::GraphicsManager (){

//Singleton to make sure we only have one instace of the manager printing on screen
  if (instance != nullptr){
    cerr << "Too many GraphicsManager instances" << endl;
    exit (1);
  };
  instance = this;

    horizontalLine = IMG_Load ("Assets/line.png");
    verticalLine = IMG_Load ("Assets/verticalLine.png");
    cellSprite = IMG_Load ("Assets/cell.png");
    deadCell = IMG_Load ("Assets/deadCell.png");
    HoriRect.x = 0;
    HoriRect.y = 99;
    VertRect.x = 0;
    VertRect.y = 99;
};

//Destructor
GraphicsManager::~GraphicsManager () {};

//Run (Update)
  void GraphicsManager::Run(){
    //GridDrawer (horizontalLine, verticalLine);  
    SDL_UpdateWindowSurface (gameWindow);
  };

//Applies images to the screen
  void GraphicsManager::GridDrawer (SDL_Surface *horizontalLine, SDL_Surface *verticalLine){
    cellSize.w = ScreenWidth / gridSize;
    cellSize.h = (ScreenHeight - HoriRect.y) / gridSize;


    while (HoriRect.y <= 800){
        SDL_BlitSurface (horizontalLine, NULL, surfaceWindow, &HoriRect);
        SDL_BlitSurface (verticalLine, NULL, surfaceWindow, &VertRect);
        VertRect.x += cellSize.w;
        HoriRect.y += cellSize.h;
        };
        HoriRect.y = 99;
        VertRect.x = cellSize.w;
      };

  void GraphicsManager::CellDrawer (vector <Cell*> Cells) {
        for (auto x = 0; x < Cells.size(); x++){
          cellSize.x = (Cells[x]->posX * cellSize.w);
          cellSize.y = ((Cells[x]->posY * cellSize.h) + HoriRect.y);
          if (Cells[x]->getState() == true){
          SDL_BlitScaled (cellSprite, NULL, surfaceWindow, &cellSize);
          }
          else{
          SDL_BlitScaled (deadCell, NULL, surfaceWindow, &cellSize);  
          };

        };
  };

//Creates Window and Renderer
  void GraphicsManager::CreateWindow (){
    gameWindow =  SDL_CreateWindow ("LG's Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
    if (gameWindow == NULL){
      cout << "Window initialization error: " << SDL_GetError () << endl;}
    else {
      renderer = SDL_CreateRenderer (gameWindow, -1, SDL_RENDERER_ACCELERATED);
      surfaceWindow = SDL_GetWindowSurface (gameWindow);
      SDL_SetRenderDrawColor (renderer, 255, 255, 255, 120);

  		//Initialize IMG Modules
    	IMG_Init (IMG_INIT_PNG);

    }
  };


  void GraphicsManager::RenderArray (vector <SDL_Surface*> spriteArray, vector <SDL_Rect*> rectArray) {
    for (auto current = 0; current < spriteArray.size(); current++){
      SDL_BlitScaled (spriteArray[current], NULL, surfaceWindow, rectArray[current]);
     };
  };

  void GraphicsManager::SetGridSize (int gridSize){
    this->gridSize = gridSize;
  };