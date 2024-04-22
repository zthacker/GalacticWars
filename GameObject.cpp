//
// Created by zthacker on 4/20/2024.
//

#include "GameObject.h"

GameObject::GameObject() {
    //ensuring that every GameObject has a Transform component
    //In this Component system, every GameObject needs a transform
    transform = AddComponent<TransformComponent>();
}
void GameObject::Awake()
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Awake();
    }
}

void GameObject::Start()
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Start();
    }
}

void GameObject::Update(float timeDelta)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Update(timeDelta);
    }
}

void GameObject::LateUpdate(float timeDelta)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->LateUpdate(timeDelta);
    }
}

void GameObject::Draw(Window& window, float deltaTime)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Draw(window, deltaTime);
    }
}

