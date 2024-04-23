//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_TEXTURECOMPONENT_H
#define GALACTICWARS_TEXTURECOMPONENT_H

#include "Component.h"
#include <iostream>
#include "TransformComponent.h"

class GameObject;

using namespace std;
//TODO probably want some sort of ResourceAllocator for this
class TextureComponent : public Component {
public:
    explicit TextureComponent(GameObject* owner) : Component(owner){};

    void Load(Window &window, const string &filepath);

    void Draw(Window& window, float deltaTime) override;

    void LateUpdate(float deltaTime) override;

private:
    SDL_Texture* texture{};
    float x, y;

};


#endif //GALACTICWARS_TEXTURECOMPONENT_H
