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
            gameField[i][j] = space;
        }
    }
    while (gameState == gameContinues) {
        playerTurn(gameField);
        robotTurn(gameField);
        printGameField(gameField);
        gameState = getGameState(gameField);
    }
    std::string result;
    switch (gameState) {
        case playerLost:
            result = "Player lost!\n";
            break;
        case playerWon:
            result = "Player won!\n";
            break;
        case draw:
            result = "A draw!\n";
            break;
        default:
            result = "Oops, something went wrong!\n";
            break;
    }
    std::cout << result;
    std::cout << "Thank you for playing, see you later!" << std::endl;
    return 0;
}
