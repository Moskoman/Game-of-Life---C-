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
