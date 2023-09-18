#include <iostream>
#include "gameFieldElements.h"

void playerTurn(GameFieldElements ( &gameField )[3][3]) {
    short x, y;
    bool correctInput = false;
    while (!correctInput) {
        std::cout << "Enter coordinates of your turn (row from up to down and than columns from left to right): ";
        std::cin >> x >> y;
        if (x < 1 || x > 3 || y < 1 || y > 3) {
            std::cout << "Enter correct value (from 1 to 3)";
        }
        else if (gameField[x - 1][y - 1] != GameFieldElements::space) { //fixed
            std::cout << "This cell is occupied, enter coordinates of free cell";
        }
        else {
            correctInput = true;
        }
        std::cout << '\n';
    }
    gameField[x - 1][y - 1] = GameFieldElements::cross;
}
