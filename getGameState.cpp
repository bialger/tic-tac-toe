#include "gameFieldElements.h"
#include "gameState.h"


 GameState getGameState(int gameField[3][3]){ // TODO: refactor to Code Standard, also change function type to int or enum
    GameState result=draw;
    for (int i=0; i<3; ++i){
        if ((gameField[i][0]==gameField[i][1]==gameField[i][2]==cross) ||
            (gameField[0][i]==gameField[1][i]==gameField[2][i]==cross)){
            result = playerWon;
            break;
        }
        if ((gameField[0][i]==gameField[1][i]==gameField[2][i]==null) ||
            (gameField[i][0]==gameField[i][1]==gameField[i][2]==null)){
            result = playerLost;
            break;
        }
    }
    if ((gameField[0][0]==gameField[1][1]==gameField[2][2]==cross) ||
        (gameField[0][2]==gameField[1][1]==gameField[2][0]==cross)){
        result = playerWon;
    }
    else if ((gameField[0][0]==gameField[1][1]==gameField[2][2]==null)||
             (gameField[0][2]==gameField[1][1]==gameField[2][0]==null)){
        result = playerLost;
    }
    else {
        for (int i = 0; i < 3; ++i) { //
            for (int j = 0; j < 3; ++j) {
                if (gameField[i][j] == -1) {
                    result = gameContinues;
                }
            }
        }
    }
    return result;
}