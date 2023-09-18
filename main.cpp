#include <iostream>
#include "printGameField.cpp"
#include "getGameState.cpp"
#include "playerTurn.cpp"
#include "robotTurn.cpp"

int main() {
    int gameField[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameField[i][j] = -1; // TODO: refactor with enum - it should be in printGameField.cpp
        }
    }
    printGameField(gameField);
    std::cout << "Test" << std::endl;
    return 0;
}
