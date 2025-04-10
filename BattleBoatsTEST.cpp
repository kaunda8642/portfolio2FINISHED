// BattleBoatsTEST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "gameLogic.h"

using namespace std;

int main() {
    char playerGrid[GRID_SIZE][GRID_SIZE];
    char computerGrid[GRID_SIZE][GRID_SIZE];

    initializeGrids(playerGrid, computerGrid);
    cout << "Testing grid initialization:" << endl;
    displayGrids(playerGrid, computerGrid, false);  // <- changed to false to hide computer's boats

    char boatSymbol;
    cout << "Enter a symbol for your boat: ";
    cin >> boatSymbol;

    while (!placePlayerBoat(playerGrid, boatSymbol)) {}
    placeComputerBoat(computerGrid);

    displayGrids(playerGrid, computerGrid, false);  // <- changed to false again

    return 0;
}