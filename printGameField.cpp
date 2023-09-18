#include <iostream>
#include "gameFieldElement.h"

enum BoxSymbol {
    leftUpperCorner,
    leftLowerCorner,
    rightUpperCorner,
    rightLowerCorner,
    horizontalLine,
    verticalLine,
    crossLikeSymbol,
    verticalLeftLine,
    verticalRightLine,
    horizontalUpLine,
    horizontalDownLine
};

bool isWindows() {
    bool result =
#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
        true
#else
        false
#endif
    ;
    return result;
}

char findSymbol(GameFieldElement x){
    char answer;
    switch (x) {
        case space:
            answer = ' ';
            break;
        case cross:
            answer = 'X';
            break;
        case null:
            answer =  'O';
            break;
        default:
            answer = ' ';
            break;
    }
    return answer;
}

std::string boxSymbol(BoxSymbol symbol) {
    std::string result;
    switch (symbol) {
        case leftUpperCorner:
            result = isWindows() ? std::string(1 , char(218)) : "┌";
            break;
        case leftLowerCorner:
            result = isWindows() ? std::string(1 , char(192)) : "└";
            break;
        case rightUpperCorner:
            result = isWindows() ? std::string(1 , char(191)) : "┐";
            break;
        case rightLowerCorner:
            result = isWindows() ? std::string(1 , char(217)) : "┘";
            break;
        case horizontalLine:
            result = isWindows() ? std::string(1 , char(196)) : "─";
            break;
        case verticalLine:
            result = isWindows() ? std::string(1 , char(179)) : "│";
            break;
        case crossLikeSymbol:
            result = isWindows() ? std::string(1 , char(197)) : "┼";
            break;
        case verticalRightLine:
            result = isWindows() ? std::string(1 , char(195)) : "├";
            break;
        case verticalLeftLine:
            result = isWindows() ? std::string(1 , char(180)) : "┤";
            break;
        case horizontalDownLine:
            result = isWindows() ? std::string(1 , char(194)) : "┬";
            break;
        case horizontalUpLine:
            result = isWindows() ? std::string(1 , char(193)) : "┴";
            break;
    }
    return result;
}

void printGameField(GameFieldElement (&gameField)[3][3]) {
    std::string field[7];
    field[0] = boxSymbol(leftUpperCorner) + boxSymbol(horizontalLine) +
            boxSymbol(horizontalDownLine) + boxSymbol(horizontalLine) +
            boxSymbol(horizontalDownLine) + boxSymbol(horizontalLine) +
            boxSymbol(rightUpperCorner) + '\n';
    field[1] = boxSymbol(verticalLine) + findSymbol(gameField[0][0]) +
            boxSymbol(verticalLine) + findSymbol(gameField[0][1]) +
            boxSymbol(verticalLine) + findSymbol(gameField[0][2]) +
            boxSymbol(verticalLine) + '\n';
    field[2] = boxSymbol(verticalRightLine) + boxSymbol(horizontalLine) +
            boxSymbol(crossLikeSymbol) + boxSymbol(horizontalLine) +
            boxSymbol(crossLikeSymbol) + boxSymbol(horizontalLine) +
            boxSymbol(verticalLeftLine) + '\n';
    field[3] = boxSymbol(verticalLine) + findSymbol(gameField[1][0]) +
            boxSymbol(verticalLine) + findSymbol(gameField[1][1]) +
            boxSymbol(verticalLine) + findSymbol(gameField[1][2]) +
            boxSymbol(verticalLine) + '\n';
    field[4] = boxSymbol(verticalRightLine) + boxSymbol(horizontalLine) +
            boxSymbol(crossLikeSymbol) + boxSymbol(horizontalLine) +
            boxSymbol(crossLikeSymbol) + boxSymbol(horizontalLine) +
            boxSymbol(verticalLeftLine) + '\n';
    field[5] = boxSymbol(verticalLine) + findSymbol(gameField[2][0]) +
            boxSymbol(verticalLine) + findSymbol(gameField[2][1]) +
            boxSymbol(verticalLine) + findSymbol(gameField[2][2]) +
            boxSymbol(verticalLine) + '\n';
    field[6] = boxSymbol(leftLowerCorner) + boxSymbol(horizontalLine) +
            boxSymbol(horizontalUpLine) + boxSymbol(horizontalLine) +
            boxSymbol(horizontalUpLine) + boxSymbol(horizontalLine) +
            boxSymbol(rightLowerCorner) + '\n';
    for (int i = 0; i < 7; ++i) {
        std::cout << field[i];
    }
}
//┌─┬─┬─┐
//│ │ │ │
//├─┼─┼─┤
//│ │ │ │
//├─┼─┼─┤
//│ │ │ │
//└─┴─┴─┘