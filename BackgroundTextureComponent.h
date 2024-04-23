//
// Created by zthacker on 4/23/2024.
//

#ifndef GALACTICWARS_BACKGROUNDTEXTURECOMPONENT_H
#define GALACTICWARS_BACKGROUNDTEXTURECOMPONENT_H

#include <iostream>
#include "GameObject.h"



class BackgroundTextureComponent : public Component {
public:
    explicit BackgroundTextureComponent(GameObject* owner) : Component(owner){};

    void Load(Window &window, const std::string &filepath);

    void Draw(Window& window, float deltaTime) override;

    void LateUpdate(float deltaTime) override;

private:
    SDL_Texture* texture{};
    float x, y;
};


#endif //GALACTICWARS_BACKGROUNDTEXTURECOMPONENT_H
