#include "gameFieldElement.h"
#include "gameState.h"

// TODO: also please fix logics - it does not work properly
 GameState getGameState(GameFieldElement arr[3][3]){ // TODO: refactor to Code Standard - leave only one return statement, also reanme argument to gameField
    for (int i=0; i<3; ++i){
        if ((arr[i][0]==arr[i][1]==arr[i][2]==cross)||(arr[0][i]==arr[1][i]==arr[2][i]==cross)){
            return playerWon;
        }
        if ((arr[0][i]==arr[1][i]==arr[2][i]==null) || (arr[i][0]==arr[i][1]==arr[i][2]==null)){
            return playerLost;
        }
    }
    if ((arr[0][0]==arr[1][1]==arr[2][2]==cross)||(arr[0][2]==arr[1][1]==arr[2][0]==cross)){
        return playerWon;
    }
    if ((arr[0][0]==arr[1][1]==arr[2][2]==null)||(arr[0][2]==arr[1][1]==arr[2][0]==null)){
        return playerLost;
    }
    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            if (arr[i][j]==-1){
                return gameContinues;
            }
        }
    }
    return draw;
}