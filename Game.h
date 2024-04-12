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

    void update();
    void render();
    void read_input()
    {
        SDL_Event sdl_event;
        SDL_PollEvent(&sdl_event);
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

        if (keystates[SDL_SCANCODE_ESCAPE] || sdl_event.type == SDL_QUIT) {
            m_is_running = false;
        }
    }

    bool m_is_running;
private:

    void initializeSDL();
    void initializePlayer();



    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

};

#endif //GALACTICWARS_GAME_H