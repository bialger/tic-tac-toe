#include <iostream>
#include <random>
#include "gameFieldElement.h"

void convertToCalculable(GameFieldElement gameField[3][3], int (&calculableGameField)[9]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            switch (gameField[i][j]) {
                case space:
                    calculableGameField[3 * i + j] = 3 * i + j;
                    break;
                case cross:
                    calculableGameField[3 * i + j] = -2;
                    break;
                case null:
                    calculableGameField[3 * i + j] = -1;
                    break;
            }
        }
    }
}

void convertToGameField(GameFieldElement (&newGameField)[3][3], int calculableGameField[9]) {
    for (int i = 0; i < 9; ++i) {
        switch (calculableGameField[i]) {
            case -2:
                newGameField[i / 3][i % 3] = cross;
                break;
            case -1:
                newGameField[i / 3][i % 3] = null;
                break;
            default:
                newGameField[i / 3][i % 3] = space;
                break;
        }
    }
}

void evaluateAvailableCells(int calculableGameField[9], int (&availableCells)[10]) {
    availableCells[0] = 0;
    for (int i = 0; i < 9; ++i) {
        if (calculableGameField[i] >= 0) {
            ++availableCells[0];
            availableCells[availableCells[0]] = calculableGameField[i];
        }
    }
    for (int i = availableCells[0] + 1; i < 10; ++i) {
        availableCells[i] = -3;
    }
}

bool makeMistake(int probability) {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> distribution( 1, 100);
    int attempt = distribution(generator);
    std::cout << attempt << " < " << probability << " = " << ((probability - attempt) < 0) << '\n';
    bool result = probability < attempt;
    return result;
}

int miniMax(int calculableGameField[9], bool isMaximizer) {
    int human = -2;
    int robot = -1;
    GameFieldElement newGameField[3][3];
    int availableCells[10];
    int score;
    convertToGameField(newGameField, calculableGameField);
    GameState gameState = getGameState(newGameField);
    evaluateAvailableCells(calculableGameField, availableCells);
    if (gameState == playerWon) {
        score = -10;
    }
    else if (gameState == playerLost) {
        score = 10;
    }
    else if (gameState == draw) {
        score = 0;
    }
    else {
        int bestScore = isMaximizer ? -10000 : 10000;
        for (int i = 1; i <= availableCells[0]; ++i) {
            int moveID = availableCells[i];
            calculableGameField[moveID] = isMaximizer ? robot : human;
            int moveScore = miniMax(calculableGameField, !isMaximizer);
            if (isMaximizer ? moveScore > bestScore : moveScore < bestScore) {
                bestScore = moveScore;
            }
            calculableGameField[moveID] = moveID;
        }
        score = bestScore;
    }
    return score;
}

void robotTurn(GameFieldElement (&gameField)[3][3], int accuracy) {
    int bestScore = -10000;
    int bestMove = -1;
    int calculableGameField[9];
    int availableCells[10];
    convertToCalculable(gameField, calculableGameField);
    evaluateAvailableCells(calculableGameField, availableCells);
    for (int i = 1; i <= availableCells[0]; ++i) {
        int moveID = availableCells[i];
        calculableGameField[moveID] = -1;
        int moveScore = miniMax(calculableGameField, false);
        bool makeCorrectConclusion = !makeMistake(accuracy);
        if (makeCorrectConclusion && moveScore > bestScore) {
            bestScore = moveScore;
            bestMove = moveID;
        }
        calculableGameField[moveID] = moveID;
    }
    if (bestMove == -1) {
        bestMove = availableCells[1];
    }
    std::cout << "Computer`s turn: " << bestMove / 3 + 1 << ' ' << bestMove % 3 + 1 << "\n\n";
    gameField[bestMove / 3][bestMove % 3] = null;
}