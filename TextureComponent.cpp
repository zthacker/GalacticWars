//
// Created by zthacker on 4/20/2024.
//

#include "TextureComponent.h"
#include "Window.h"
#include "GameObject.h"


void TextureComponent::Load(Window& window, const std::string &filepath) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filepath.c_str());
    texture = IMG_LoadTexture(window.gameRenderer,filepath.c_str());
}

void TextureComponent::Draw(Window &window, float deltaTime) {
    float xFrameMove = x += deltaTime;
    float yFrameMove = y+= deltaTime;
    window.DrawBlit(texture, xFrameMove, yFrameMove);
}

void TextureComponent::LateUpdate(float deltaTime) {
    x = m_owner->transform->GetX();
    y = m_owner->transform->GetY();
}
