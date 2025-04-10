#include <iostream>
#include "gameLogic.h"

using namespace std;

int main() {
    char playerGrid[GRID_SIZE][GRID_SIZE];
    char computerGrid[GRID_SIZE][GRID_SIZE];
    bool gameOver = false;
    char playAgain;
    char boatSymbol;

    cout << "Welcome to Battle Boats!" << endl;

    do {
        gameOver = false;
        initializeGrids(playerGrid, computerGrid);

        cout << "Choose a character to represent your boat (e.g., B, #, @): ";
        cin >> boatSymbol;

        while (!placePlayerBoat(playerGrid, boatSymbol)) {}
        placeComputerBoat(computerGrid);

        while (!gameOver) {
            displayGrids(playerGrid, computerGrid, false);

            if (getPlayerShot(playerGrid, computerGrid)) {
                gameOver = true;
                continue;
            }

            computerShot(playerGrid, boatSymbol); // <-- updated to pass symbol

            if (checkComputerWin(playerGrid, boatSymbol)) { // <-- updated to pass symbol
                cout << "The computer has destroyed your boat! You lose." << endl;
                gameOver = true;
            }

            if (checkWin(computerGrid)) {
                gameOver = true;
            }
        }

        cout << "Play again? (Y/N): ";
        cin >> playAgain;
        playAgain = toupper(playAgain);

    } while (playAgain == 'Y');

    cout << "Thanks for playing Battle Boats!" << endl;
    return 0;
}
