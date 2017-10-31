#include <iostream>
#include "GameEngine.h"


void GameEngine::NextGeneration () {
};


void GameEngine::ChangeCellState (int posX, int posY) {

	for (auto y = 0; y < Cells.size(); y++){
		vector <int> CellXY = GetCellPosition (Cells [y]);
		if (CellXY[0] == posX && CellXY[1] == posY){
			if (Cells[y]->getState() == false){
				Cells[y]->setState (true);
				break;
			}
			else if (Cells[y]->getState() == true){
				Cells[y]->setState(false);
			};
		};
	};
};

void GameEngine::Populate (int gridSize) {
	for (auto y = 0; y < gridSize; y++){
		for (auto x = 0; x < gridSize; x++){
			Cell *cellptr = new Cell (x, y);
			cellptr->setState(false);
			Cells.push_back (cellptr);
		}
	}
};

vector<int> GameEngine::GetCellPosition (Cell *cell) {

	int x = cell->posX;
	int y = cell->posY;
	vector <int> CellXY;
	CellXY.push_back (x);
	CellXY.push_back (y);                                  

	return CellXY;
};

int GameEngine::AliveNeighboors (Cell *cell) {

	int numberOfAliveNeighboors = -1;
	vector<int> CellXY = GetCellPosition (cell);
	for (auto x = 0; x < Cells.size(); x++){
		//Desculpa pela gambiarra :c kkkkkjjj??
		if (Cells[x]->posX == CellXY[0] - 1 || Cells[x]->posX == CellXY [0] || Cells[x]->posX == CellXY[0] + 1){
			if (Cells[x]->posY == CellXY[1] -1 || Cells[x]->posY == CellXY [1] || Cells [x]->posY == CellXY[1] + 1){
				if (Cells[x]->getState() == true){
					numberOfAliveNeighboors++;
				};
			};
		};
	}
	return numberOfAliveNeighboors;
};

void GameEngine::SetGridSize (int grid){
	gridSize = grid;
}