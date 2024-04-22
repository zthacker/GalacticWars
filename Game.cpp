//
// Created by zthacker on 4/11/2024.
//

#include "Game.h"
#include "defs.h"

Game::Game() : m_isRunning(true), m_window("Galactic Wars"){
    std::shared_ptr<GameScene> gameScene = std::make_shared<GameScene>();

    unsigned int gameSceneID = sceneManager.Add(gameScene, m_window);
    sceneManager.SwitchTo(gameSceneID);
}

void Game::ProcessInput() {
    sceneManager.ProcessInput();
}

void Game::Update(float deltaTime) {
    m_window.Update();
    sceneManager.Update(deltaTime);
}

void Game::LateUpdate(float deltaTime) {
    sceneManager.LateUpdate(deltaTime);
}

void Game::Draw(float deltaTime) {
    m_window.BeginDraw();
    sceneManager.Draw(m_window, deltaTime);
    m_window.Display();
}

bool Game::IsRunning() const {
    return m_isRunning;
}



