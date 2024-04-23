//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_GAMESCENE_H
#define GALACTICWARS_GAMESCENE_H

#include "Scene.h"
#include <memory>
#include <iostream>
#include "GameObject.h"
#include "TextureComponent.h"
#include "KeyboardInput.h"

class GameScene : public Scene {
public:

    explicit GameScene();

    void OnCreate(Window& window) override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update(float deltaTime) override;
    void LateUpdate(float deltaTime) override;
    void Draw(Window& window, float deltaTime) override;

private:
    std::shared_ptr<GameObject> m_player{};
    std::shared_ptr<GameObject> m_background{};

    KeyboardInput m_input;
};


#endif //GALACTICWARS_GAMESCENE_H
