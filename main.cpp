#include <iostream>
#include "gameState.h"
#include "printGameField.cpp"
#include "getGameState.cpp"
#include "playerTurn.cpp"
#include "robotTurn.cpp"

int main() {
    GameFieldElement gameField[3][3];
    GameState gameState = gameContinues;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameField[i][j] = space; // TODO: refactor with enum - it should be in printGameField.cpp
        }
    }
    printGameField(gameField);
    playerTurn(gameField);
    printGameField(gameField);
    std::cout << (isWindows() ? "Windows" : "Not Windows") << std::endl;
    return 0;
}
