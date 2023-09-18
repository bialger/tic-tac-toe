#include <iostream>
#include "gameState.h"
#include "printGameField.cpp"
#include "getGameState.cpp"
#include "playerTurn.cpp"
#include "robotTurn.cpp"

int main() {
    GameFieldElements gameField[3][3];
    GameState gameState = gameContinues;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameField[i][j] = space; // TODO: refactor with enum - it should be in printGameField.cpp
        }
    }
    printGameField(gameField);
    playerTurn(gameField);
    printGameField(gameField);
    std::cout << "Test" << std::endl;
    return 0;
}
