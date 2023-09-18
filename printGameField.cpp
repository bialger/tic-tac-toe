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

void printGameField(GameFieldElements (&gameField)[3][3]) {
    if (!isWindows()) {
        std::cout <<"┌"<<"─"<<"┬"<<"─"<<"┬"<<"─"<<"┐"<< '\n';
        std::cout <<"│"<<findSymbol(gameField[0][0]) <<"│"<<findSymbol(gameField[0][1])<<"│"<<findSymbol(gameField[0][2])<<"│"<<'\n';
        std::cout<<"├"<<"─"<<"┼"<<"─"<<"┼"<<"─"<<"┤"<<'\n';
        std::cout <<"│"<<findSymbol(gameField[1][0]) <<"│"<<findSymbol(gameField[1][1])<<"│"<<findSymbol(gameField[1][2])<<"│"<<'\n';
        std::cout<<"├"<<"─"<<"┼"<<"─"<<"┼"<<"─"<<"┤"<<'\n';
        std::cout <<"│"<<findSymbol(gameField[2][0]) <<"│"<<findSymbol(gameField[2][1])<<"│"<<findSymbol(gameField[2][2])<<"│"<<'\n';
        std::cout <<"└"<<"─"<<"┴"<<"─"<<"┴"<<"─"<<"┘"<<"\n";
    }
    else {
        std::cout <<char(218)<<char(196)<<char(194)<<char(196)<<char(194)<<char(196)<<char(191)<< '\n';
        std::cout <<char(179)<<findSymbol(gameField[0][0]) <<char(179)<<findSymbol(gameField[0][1])<<char(179)<<findSymbol(gameField[0][2])<<char(179)<<'\n';
        std::cout<<char(195)<<char(196)<<char(197)<<char(196)<<char(197)<<char(196)<<char(180)<<'\n';
        std::cout <<char(179)<<findSymbol(gameField[1][0]) <<char(179)<<findSymbol(gameField[1][1])<<char(179)<<findSymbol(gameField[1][2])<<char(179)<<'\n';
        std::cout<<char(195)<<char(196)<<char(197)<<char(196)<<char(197)<<char(196)<<char(180)<<'\n';
        std::cout <<char(179)<<findSymbol(gameField[2][0]) <<char(179)<<findSymbol(gameField[2][1])<<char(179)<<findSymbol(gameField[2][2])<<char(179)<<'\n';
        std::cout <<char(192)<<char(196)<<char(193)<<char(196)<<char(193)<<char(196)<<char(217)<<"\n";
    }
}
//┌─┬─┬─┐
//│ │ │ │
//├─┼─┼─┤
//│ │ │ │
//├─┼─┼─┤
//│ │ │ │
//└─┴─┴─┘