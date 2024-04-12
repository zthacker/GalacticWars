//
// Created by zthacker on 4/11/2024.
//

#include "MovementSystem.h"
#include <iostream>

extern Coordinator gCoordinator;

using namespace std;

void MovementSystem::Update() {

    const Uint8 *keys = SDL_GetKeyboardState(nullptr);

    for (auto &e: m_entities) {
        cout<<"checking entity"<<endl;
        auto &transform = gCoordinator.GetComponent<Transform>(e);
        if(keys[SDL_SCANCODE_A]) {transform.position.x = -1.0f;}
        if(keys[SDL_SCANCODE_S]) {transform.position.x = 1.0f;}
        if(keys[SDL_SCANCODE_W]) {transform.position.x = -1.0f;}
        if(keys[SDL_SCANCODE_D]) {transform.position.x = 1.0f;}

        cout<<transform.position.x<<endl;
        cout<<transform.position.y<<endl;
    }
}