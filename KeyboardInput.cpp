//
// Created by zthacker on 4/22/2024.
//

#include <cstdio>
#include "KeyboardInput.h"
#include "SDL.h"

void KeyboardInput::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;

            case SDL_KEYDOWN:
                keyPressDown(&event.key);
                break;

            case SDL_KEYUP:
                keyPressUp(&event.key);
                break;

            default:
                break;
        }
    }
}

void KeyboardInput::keyPressUp(SDL_KeyboardEvent *event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
    {
        m_keyboard[event->keysym.scancode] = 0;
    }
}

//Player needs to move (1)
void KeyboardInput::keyPressDown(SDL_KeyboardEvent *event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
    {
        m_keyboard[event->keysym.scancode] = 1;
    }
}

bool KeyboardInput::KeyState(SDL_Scancode sdlScancode) {
    return m_keyboard[sdlScancode];;
}


