#include <iostream>

void printGameField(int(&gameField)[3][3]) {
    char symb[3]={' ', 'x', 'o'};
    for (int i = 0; i < 3; i++) {

        std::cout << symb[gameField[i][0]] << '|' << symb[gameField[i][1]] << '|' << symb[gameField[i][2]] << '\n';
        if (i != 2) {
            std::cout << '_' << '_' << '_' << '_' << '_' << '\n';
        }
    }
}