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
  }
  instance = this;

    horizontalLine = IMG_Load ("Assets/line.png");
    verticalLine = IMG_Load ("Assets/verticalLine.png");
    cellSprite = IMG_Load ("Assets/cell.png");
    deadCell = IMG_Load ("Assets/deadCell.png");
    HoriRect.x = 0;
    HoriRect.y = 99;
    VertRect.x = 0;
    VertRect.y = 99;
    cellSize.w = 80;
    cellSize.h = 50;
};

//Destructor
GraphicsManager::~GraphicsManager () {};

//Run (Update)
  void GraphicsManager::Run(){
    GridDrawer (horizontalLine, verticalLine);  
    SDL_UpdateWindowSurface (gameWindow);
  };

//Applies images to the screen
  void GraphicsManager::GridDrawer (SDL_Surface *horizontalLine, SDL_Surface *verticalLine){
    while (HoriRect.y <= 800){
        SDL_BlitSurface (horizontalLine, NULL, surfaceWindow, &HoriRect);
        SDL_BlitSurface (verticalLine, NULL, surfaceWindow, &VertRect);
        VertRect.x += 80;
        HoriRect.y += 50;
        };
        HoriRect.y = 99;
        VertRect.x = 80;
      };

  void GraphicsManager::CellDrawer (vector <Cell*> Cells) {
        for (auto x = 0; x < Cells.size(); x++){
          cellSize.x = (Cells[x]->posX * cellSize.w);
          cellSize.y = (((Cells[x]->posY + 1) * cellSize.h) + 50);
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
  }
