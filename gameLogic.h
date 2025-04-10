#pragma once

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <string>

const int GRID_SIZE = 4;

void initializeGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]);
void displayGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE], bool showComputer);
bool placePlayerBoat(char playerGrid[GRID_SIZE][GRID_SIZE], char boatSymbol);
void placeComputerBoat(char computerGrid[GRID_SIZE][GRID_SIZE]);
bool getPlayerShot(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]);
void computerShot(char playerGrid[GRID_SIZE][GRID_SIZE], char boatSymbol); // <- updated
bool checkWin(char computerGrid[GRID_SIZE][GRID_SIZE]);
bool checkComputerWin(char playerGrid[GRID_SIZE][GRID_SIZE], char boatSymbol); // <- updated

#endif
