//
// Created by zthacker on 4/22/2024.
//

#include "BackgroundMovementComponent.h"

BackgroundMovementComponent::BackgroundMovementComponent(GameObject *owner) : Component(owner) {

}

void BackgroundMovementComponent::Update(float deltaTime) {
    m_owner->transform->AddX(-15/deltaTime);
    if(m_owner->transform->GetX() < -SCREEN_WIDTH) {
        m_owner->transform->SetX(0.0);
    }
}
