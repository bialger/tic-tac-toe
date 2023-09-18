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

// Declare (which is different from defining) a global variable, to be
// visible by all who include this file.
// The actual definition of the variable is in the gamestate.cpp file.
extern GameState gameState;

#endif // GAMESTATE_H_