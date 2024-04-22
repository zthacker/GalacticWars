//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_SCENESTATEMACHINE_H
#define GALACTICWARS_SCENESTATEMACHINE_H

#include <iostream>
#include "Window.h"
#include <memory>
#include "Scene.h"
#include "unordered_map"
#include "EnumHash.h"

class SceneStateMachine {
public:
    SceneStateMachine();

    void ProcessInput();
    void Update(float deltaTime);
    void LateUpdate(float deltaTime);
    void Draw(Window& window, float deltaTime);

    //Scene operations
    unsigned int Add(std::shared_ptr<Scene> scene, Window& window);
    void SwitchTo(unsigned int id);
    void Remove(unsigned int id);

private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> curScene;
    unsigned int insertedSceneID{};
};


#endif //GALACTICWARS_SCENESTATEMACHINE_H
