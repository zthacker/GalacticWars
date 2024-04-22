//
// Created by zthacker on 4/22/2024.
//

#ifndef GALACTICWARS_KEYBOARDINPUT_H
#define GALACTICWARS_KEYBOARDINPUT_H

#include <SDL_events.h>
#include "defs.h"

class KeyboardInput {
public:

    void Update();


    bool KeyState(SDL_Scancode sdlScancode);

private:
    void keyPressUp(SDL_KeyboardEvent *event);
    void keyPressDown(SDL_KeyboardEvent *event);

    int m_keyboard[MAX_KEYBOARD_KEYS]{};

};


#endif //GALACTICWARS_KEYBOARDINPUT_H
