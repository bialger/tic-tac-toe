#include <iostream>
#include "gameFieldElement.h"

void playerTurn(GameFieldElement ( &gameField )[3][3]) {
    char inputX, inputY;
    int x, y;
    bool correctInput = false;
    while (!correctInput) {
        std::cout << "Enter coordinates of your turn (row from up to down and then columns from left to right): ";
        std::cin >> inputX;
        std::cin.ignore(1);
        std::cin >> inputY;
        x = inputX - '0';
        y = inputY - '0';
        if (x < 1 || x > 3 || y < 1 || y > 3) {
            std::cout << "Enter correct value (from 1 to 3)";
        }
        else if (gameField[x - 1][y - 1] != GameFieldElement::space) { //fixed
            std::cout << "This cell is occupied, enter coordinates of free cell";
        }
        else {
            correctInput = true;
        }
        std::cout << '\n';
    }
    gameField[x - 1][y - 1] = GameFieldElement::cross;
}
