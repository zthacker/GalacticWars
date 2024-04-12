//
// Created by zthacker on 4/11/2024.
//

#ifndef GALACTICWARS_GAME_H
#define GALACTICWARS_GAME_H

#include <iostream>
#include "common.h"
#include "defs.h"
#include "Core/Coordinator.h"



using namespace std;

class Game {
public:
    Game();


    bool m_gameRunning;
private:

    void initializeSDL();

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

};

#endif //GALACTICWARS_GAME_H