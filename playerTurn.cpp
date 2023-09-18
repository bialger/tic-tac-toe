#include <iostream>

void playerTurn(int ( &gameField )[3][3]) {
    short x, y;
    bool correct_input = false;
    while (!correct_input) {
        std::cin >> x >> y;
        if (x < 0 || x > 3 || y < 0 || y > 3) {
            std::cout << "Введите корректное значение";
        }
        else if (gameField[x][y] != -1) { //TODO: refactor with enum
            std::cout << "Эта клетка занята";
        }
        else {
            correct_input = true;
        }
    }
        gameField[x][y] = 1;
}
