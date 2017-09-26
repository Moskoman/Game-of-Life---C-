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

};

//Destructor
GraphicsManager::~GraphicsManager () {};

//Run (Update)
  void GraphicsManager::Run(){
    SDL_UpdateWindowSurface (gameWindow);}

//Applies images to the screen
  void GraphicsManager::Drawer (SDL_Surface *sprite){
    SDL_BlitSurface (sprite, NULL, surfaceWindow, NULL);};

//Creates Window and Renderer
  void GraphicsManager::CreateWindow (){
    gameWindow =  SDL_CreateWindow ("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);
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
