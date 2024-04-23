//
// Created by zthacker on 4/23/2024.
//

#include "BackgroundTextureComponent.h"
#include <iostream>

void BackgroundTextureComponent::Load(Window &window, const std::string &filepath) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filepath.c_str());
    texture = IMG_LoadTexture(window.gameRenderer,filepath.c_str());
}

void BackgroundTextureComponent::Draw(Window &window, float deltaTime) {
    SDL_Rect dest;
    for (int x = m_owner->transform->GetX(); x < SCREEN_WIDTH; x += SCREEN_WIDTH) {
        dest.x = x;
        dest.y = 0;
        dest.w = SCREEN_WIDTH;
        dest.h = SCREEN_HEIGHT;

        SDL_RenderCopy(window.gameRenderer, texture, nullptr, &dest);
    }
}

void BackgroundTextureComponent::LateUpdate(float deltaTime) {
    x = m_owner->transform->GetX();
    y = m_owner->transform->GetY();
}
