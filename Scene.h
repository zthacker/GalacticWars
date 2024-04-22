//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_SCENE_H
#define GALACTICWARS_SCENE_H

#include "Window.h"
#include <iostream>

using namespace std;

class Scene {
public:
    virtual void OnCreate(Window& window) = 0; // Called when scene initially created. Called once per scene.
    virtual void OnDestroy() = 0; // Called when scene destroyed. Called once per scene.

    virtual void OnActivate() {}; // Called whenever a scene is activated.
    virtual void OnDeactivate() {}; // Called whenever a scene is deactivated.

    virtual void ProcessInput() {};
    virtual void Update(float deltaTime) {};
    virtual void LateUpdate(float deltaTime) {};
    virtual void Draw(Window& window, float deltaTime){};

};





#endif //GALACTICWARS_SCENE_H
