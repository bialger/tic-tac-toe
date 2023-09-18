// These two lines prevents the file from being included multiple
// times in the same source file
#ifndef GAMESTATE_H_
#define GAMESTATE_H_

enum GameState
{
    gameContinues,
    playerLost,
    playerWon,
    draw
};

#endif // GAMESTATE_H_