//
// Created by zthacker on 4/11/2024.
//

#include "Game.h"
#include "defs.h"

Coordinator gCoordinator;

Game::Game() {

    gCoordinator.Init();
    initializeSDL();


    m_gameRunning = true;

}

void Game::initializeSDL() {
    int rendererFlags, windowFlags;
    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    m_window = SDL_CreateWindow("Some Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    m_renderer = SDL_CreateRenderer(m_window, -1, rendererFlags);

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}
