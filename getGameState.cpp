#include "gameFieldElement.h"
#include "gameState.h"


 GameState getGameState(GameFieldElement gameField[3][3]){
    GameState result = draw;
    for (int i = 0; i < 3; ++i){
        if ((gameField[i][0] == cross && gameField[i][1] == cross && gameField[i][2] == cross) ||
            (gameField[0][i] == cross && gameField[1][i] == cross && gameField[2][i] == cross)){
            result = playerWon;
            break;
        }
        if ((gameField[0][i] == null && gameField[1][i] == null && gameField[2][i] == null) ||
            (gameField[i][0] == null && gameField[i][1] == null && gameField[i][2] == null)){
            result = playerLost;
            break;
        }
    }
    if (result == draw) {
        if ((gameField[0][0] == cross && gameField[1][1] == cross && gameField[2][2] == cross) ||
            (gameField[0][2] == cross && gameField[1][1] == cross && gameField[2][0] == cross)) {
            result = playerWon;
        } else if ((gameField[0][0] == null && gameField[1][1] == null && gameField[2][2] == null) ||
                   (gameField[0][2] == null && gameField[1][1] == null && gameField[2][0] == null)) {
            result = playerLost;
        } else {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (gameField[i][j] == space) {
                        result = gameContinues;
                    }
                }
            }
        }
    }
    return result;
}