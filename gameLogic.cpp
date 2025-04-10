#include "gameLogic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initializeGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            playerGrid[i][j] = '_';
            computerGrid[i][j] = '_';
        }
    }
}

void displayGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE], bool showComputer) {
    cout << "You:                Computer:\n\n";
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << (char)('A' + i) << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << playerGrid[i][j] << " ";
        }

        cout << "    " << (char)('A' + i) << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << (showComputer ? computerGrid[i][j] : '_') << " ";
        }
        cout << endl;
    }
}

bool placePlayerBoat(char playerGrid[GRID_SIZE][GRID_SIZE], char boatSymbol) {
    string input;
    int row, col;

    cout << "Where would you like to hide your boat? (e.g., A1, B2): ";
    cin >> input;

    if (input.length() != 2 || input[0] < 'A' || input[0] > 'D' || input[1] < '1' || input[1] > '4') {
        cout << "Invalid input! Please enter a grid coordinate like A1 to D4." << endl;
        return false;
    }

    row = input[0] - 'A';
    col = input[1] - '1';

    if (playerGrid[row][col] != '_') {
        cout << "There's already something there! Try another spot." << endl;
        return false;
    }

    playerGrid[row][col] = boatSymbol;
    return true;
}

void placeComputerBoat(char computerGrid[GRID_SIZE][GRID_SIZE]) {
    srand(time(0));
    int row, col;
    do {
        row = rand() % GRID_SIZE;
        col = rand() % GRID_SIZE;
    } while (computerGrid[row][col] != '_');
    computerGrid[row][col] = '*';
}

bool getPlayerShot(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]) {
    string input;
    int row, col;

    cout << "Pick a spot to shoot (e.g., A1): ";
    cin >> input;

    if (input.length() != 2 || input[0] < 'A' || input[0] > 'D' || input[1] < '1' || input[1] > '4') {
        cout << "That is invalid! Enter something like A1 to D4." << endl;
        return false;
    }

    row = input[0] - 'A';
    col = input[1] - '1';

    if (computerGrid[row][col] == '*') {
        cout << "You win the game! Great job!" << endl;
        computerGrid[row][col] = '!';
        return true;
    }
    else {
        computerGrid[row][col] = 'X';
        cout << "You missed!" << endl;
        return false;
    }
}

void computerShot(char playerGrid[GRID_SIZE][GRID_SIZE], char boatSymbol) {
    srand(time(0));
    int row, col;

    do {
        row = rand() % GRID_SIZE;
        col = rand() % GRID_SIZE;
    } while (playerGrid[row][col] == 'X' || playerGrid[row][col] == '!');

    if (playerGrid[row][col] == boatSymbol) {
        cout << "The computer hits your boat at " << (char)('A' + row) << col + 1 << "!" << endl;
        playerGrid[row][col] = '!';
    }
    else {
        playerGrid[row][col] = 'X';
        cout << "The computer missed!" << endl;
    }
}

bool checkWin(char computerGrid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (computerGrid[i][j] == '*') return false;
        }
    }
    return true;
}

bool checkComputerWin(char playerGrid[GRID_SIZE][GRID_SIZE], char boatSymbol) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (playerGrid[i][j] == boatSymbol) {
                return false;
            }
        }
    }
    return true;
}
}