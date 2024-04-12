#include <iostream>
#include "Game.h"
int main(int argc, char *argv[]) {
    Game game;
    while(game.m_gameRunning) {
        cout<<"game is running"<<endl;
    }
    return 0;
}
