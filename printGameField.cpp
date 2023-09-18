#include <iostream>
#include "gameFieldElements.h"
char findSymbol(int x){
    switch (x){
        case space: return ' ';
        case cross: return 'x';
        case null: return 'o';
        default:
            return ' ';
    }
}

void printGameField(int(&gameField)[3][3]) {
    std::cout <<"┌"<<"─"<<"┬"<<"─"<<"┬"<<"─"<<"┐"<< '\n';
    std::cout <<"│"<<findSymbol(gameField[0][0]) <<"│"<<findSymbol(gameField[0][1])<<"│"<<findSymbol(gameField[0][2])<<"│"<<'\n';
    std::cout<<"├"<<"─"<<"┼"<<"─"<<"┼"<<"─"<<"┤"<<'\n';
    std::cout <<"│"<<findSymbol(gameField[1][0]) <<"│"<<findSymbol(gameField[1][1])<<"│"<<findSymbol(gameField[1][2])<<"│"<<'\n';
    std::cout<<"├"<<"─"<<"┼"<<"─"<<"┼"<<"─"<<"┤"<<'\n';
    std::cout <<"│"<<findSymbol(gameField[2][0]) <<"│"<<findSymbol(gameField[2][1])<<"│"<<findSymbol(gameField[2][2])<<"│"<<'\n';
    std::cout <<"└"<<"─"<<"┴"<<"─"<<"┴"<<"─"<<"┘"<<"\n";
    }
//┌─┬─┬─┐
//│ │ │ │
//├─┼─┼─┤
//│ │ │ │
//├─┼─┼─┤
//│ │ │ │
//└─┴─┴─┘