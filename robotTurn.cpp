#include <iostream>
#include "gameFieldElement.h"

void convertToCalculable(GameFieldElement gameField[3][3], int (&result)[9]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            switch (gameField[i][j]) {
                case space:
                    result[3 * i + j] = 3 * i + j;
                    break;
                case cross:
                    result[3 * i + j] = -2;
                    break;
                case null:
                    result[3 * i + j] = -1;
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

void robotTurn(GameFieldElement (&gameField)[3][3]) {
    // TODO: finish a function
    int human = -2;
    int robot = -1;
    int calculableGameField[9];
    GameFieldElement newGameField[3][3];
    int availableCells[10];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            newGameField[i][j] = gameField[i][j];
        }
    }
    convertToCalculable(newGameField, calculableGameField);
    evaluateAvailableCells(calculableGameField, availableCells);
//    for (int i = 0; i < 9; ++i) {
//        std::cout << calculableGameField[i] << ' ';
//    }
//    std::cout << '\n';
//    for (int i = 0; i < 10; ++i) {
//        std::cout << availableCells[i] << ' ';
//    }
//    std::cout << '\n';
}