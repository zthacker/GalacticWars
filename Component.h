//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_COMPONENT_H
#define GALACTICWARS_COMPONENT_H

#include "Window.h"

class GameObject;
class Window;

class Component {
public:
    explicit Component(GameObject* owner) : m_owner(owner){}

    virtual void Awake() {};
    virtual void Start() {};

    virtual void Update(float deltaTime) {};
    virtual void LateUpdate(float deltaTime) {};
    virtual void Draw(Window& window, float deltaTime) {};

protected:
    GameObject* m_owner;
};

#endif //GALACTICWARS_COMPONENT_H
