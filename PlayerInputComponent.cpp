//
// Created by zthacker on 4/22/2024.
//

#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent(GameObject *owner) : Component(owner), m_moveSpeed(8) {}

void PlayerInputComponent::SetInput(KeyboardInput *input) {
    this->m_input = input;
}

void PlayerInputComponent::SetMovementSpeed(float moveSpeed) {
    this->m_moveSpeed = moveSpeed;
}

void PlayerInputComponent::Update(float deltaTime) {
    if(m_input == nullptr) {
        //TODO log something here maybe
        printf("input is null");
        return;
    }

    //do X's
    float xMove = 0;
    if(m_input->KeyState(SDL_SCANCODE_LEFT))
    {
        xMove = -m_moveSpeed;
    }
    if(m_input->KeyState(SDL_SCANCODE_RIGHT))
    {
        xMove = m_moveSpeed;
    }


    //do Y's
    float yMove = 0;
    if(m_input->KeyState(SDL_SCANCODE_UP))
    {
        yMove = -m_moveSpeed;
    }
    if(m_input->KeyState(SDL_SCANCODE_DOWN))
    {
        yMove = m_moveSpeed;
    }

    //multiple by deltaTime
    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;

    //set Transform Component
    m_owner->transform->AddX(xMove);
    m_owner->transform->AddY(yMove);

}


