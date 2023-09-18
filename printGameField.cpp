#include <iostream>
char findSymb(int x){
    switch (x){
        case -1: return ' ';
        case 0: return 'x';
        case 1: return 'o';
        default:
            return ' ';
    }
}

void printGameField(int(&gameField)[3][3]) {
    for (int i = 0; i < 3; i++) {
        //TODO: refactor the code, also use enum instead of int in gameField
        std::cout << findSymb(gameField[i][0]) << '|' << findSymb(gameField[i][1]) << '|' << findSymb(gameField[i][2]) << '\n';
        if (i != 2) {
            std::cout << '_' << '_' << '_' << '_' << '_' << '\n';
        }
    }
}