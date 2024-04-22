//
// Created by zthacker on 4/11/2024.
//

#ifndef GALACTICWARS_GAME_H
#define GALACTICWARS_GAME_H

#include <iostream>
#include "common.h"
#include "defs.h"
#include "Window.h"
#include "SceneStateMachine.h"
#include "GameScene.h"


using namespace std;

class Game {
public:
    Game();
    ~Game() = default;

    void ProcessInput();
    void Update(float deltaTime);
    void LateUpdate(float deltaTime);
    void Draw(float deltaTime);
    bool IsRunning() const;

    void read_input()
    {
        SDL_Event sdl_event;
        SDL_PollEvent(&sdl_event);
        const Uint8* keystates = SDL_GetKeyboardState(nullptr);

        if (keystates[SDL_SCANCODE_ESCAPE] || sdl_event.type == SDL_QUIT) {
            m_isRunning = false;
        }
    }


private:
    bool m_isRunning;
    Window m_window;

    SceneStateMachine sceneManager;

};

#endif //GALACTICWARS_GAME_H