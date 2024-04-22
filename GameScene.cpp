//
// Created by zthacker on 4/20/2024.
//

#include "GameScene.h"
#include "Game.h"
#include "PlayerInputComponent.h"

class Game;

GameScene::GameScene() {
}

void GameScene::OnCreate(Window& window) {

    //TODO current issue is we are needing to pass a Renderer to the TextureComponent so it can draw
    //itself. Right now, since we're creating a new player here, we'd have to pass a Renderer, or Window object
    //Scene doesn't have a reference to a Window object, but maybe it could. Right now it gets it from
    //Game because Game is running Window's Update function, then the Scene's Update Function.
    //We can have OnCreate take in a Window object to then pass over to the Component, which is what
    //We're doing now.
    //This traces all the way back to Game and Scene::OnCreate. SceneStateMachine::Add()
    player = make_shared<GameObject>();
    player->transform->SetY(SCREEN_HEIGHT / 2);

    //TODO Debug checking here basically, probably tidy this up at some point
    if(player) {
        auto texture = player->AddComponent<TextureComponent>();
        //TODO need to find out why this isn't loading in current gfx dir
        texture->Load(window, R"(C:\Users\zthacker\laserlibre\gfx\player.png)");

        auto movement = player->AddComponent<PlayerInputComponent>();
        movement->SetInput(&input);
    } else {
        exit(0);
    }


}

void GameScene::OnDestroy() {

}

void GameScene::ProcessInput() {
    input.Update();
}

void GameScene::Update(float deltaTime) {
    player->Update(deltaTime);
}

void GameScene::LateUpdate(float deltaTime) {
    player->LateUpdate(deltaTime);
}

void GameScene::Draw(Window& window, float deltaTime) {
    player->Draw(window, deltaTime);
}

