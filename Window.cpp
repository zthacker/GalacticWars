//
// Created by zthacker on 4/20/2024.
//

#include "Window.h"

Window::Window(const char* title) {
    int rendererFlags, windowFlags;
    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        m_isOpen = false;
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    gameWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    gameRenderer = SDL_CreateRenderer(gameWindow, -1, rendererFlags);

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    m_isOpen = true;
}

void Window::Update() {
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            m_isOpen = false;
            SDL_DestroyWindow(gameWindow);
            exit(0);
        }
    }
}

void Window::BeginDraw() {
    //background color
    SDL_SetRenderDrawColor(gameRenderer, 96, 128, 255, 255);
    //clear out renderer
    SDL_RenderClear(gameRenderer);
}

void Window::DrawBlit(SDL_Texture* texture, float x, float y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    SDL_RenderCopy(gameRenderer, texture, nullptr, &dest);
}

void Window::DrawBlitRect(SDL_Texture* texture, SDL_Rect* src, float x, float y) {
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = src->w;
    dest.h = src->h;

    SDL_RenderCopy(gameRenderer, texture, src, &dest);
}


void Window::Display() {
    SDL_RenderPresent(gameRenderer);
}

bool Window::IsOpen() const {
    return m_isOpen;
}

