//
// Created by zthacker on 4/20/2024.
//

#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine() : scenes(0), curScene(0) { }

void SceneStateMachine::ProcessInput()
{
    if(curScene)
    {
        curScene->ProcessInput();
    }
}

void SceneStateMachine::Update(float deltaTime)
{
    if(curScene)
    {
        curScene->Update(deltaTime);
    }
}

void SceneStateMachine::LateUpdate(float deltaTime)
{
    if(curScene)
    {
        curScene->LateUpdate(deltaTime);
    }
}

void SceneStateMachine::Draw(Window& window, float deltaTime)
{
    if(curScene)
    {
        curScene->Draw(window, deltaTime);
    }
}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene, Window& window)
{
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));

    //first is sceneID, second is Scene
    inserted.first->second->OnCreate(window);

    return insertedSceneID++;
}

void SceneStateMachine::Remove(unsigned int id)
{
    auto it = scenes.find(id);
    if(it != scenes.end())
    {
        //first is sceneID, second is Scene
        if(curScene == it->second)
        {
            curScene = nullptr;
        }

        it->second->OnDestroy();

        scenes.erase(it);
    }
}

void SceneStateMachine::SwitchTo(unsigned int id)
{
    auto it = scenes.find(id);
    if(it != scenes.end())
    {
        if(curScene)
        {
            curScene->OnDeactivate();
        }

        curScene = it->second;

        curScene->OnActivate();
    }
}