#include <iostream>
#include "printGameField.cpp"

void playerTurn(int ( &gameField )[3][3]) {
    short x, y;
    std::cin >> x >> y;
    if (x < 0 || x > 3 || y < 0 || y > 3) {
        std::cout << "Введите корректное значение";
    }
    else if (gameField[x][y] != -1) { //TODO: refactor with enum
        std::cout << "Эта клетка занята";
    }
    else {
        gameField[x][y] = 1;
    }
}