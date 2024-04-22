//
// Created by zthacker on 4/22/2024.
//

#include "TransformComponent.h"

TransformComponent::TransformComponent(GameObject *owner) : Component(owner), posX(0), posY(0){};

float TransformComponent::GetX() {
    return posX;
}

float TransformComponent::GetY() {
    return posY;
}

void TransformComponent::SetY(float y) {
    posY = y;
}

void TransformComponent::SetX(float x) {
    posX = x;
}

void TransformComponent::AddX(float x) {
    posX += x;
}

void TransformComponent::AddY(float y) {
    posY += y;
}
