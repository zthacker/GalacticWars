#include <iostream>
#include "Game.h"
#include "Components/Transform.h"
#include "Systems/MovementSystem.h"

Coordinator gCoordinator;

int main(int argc, char *argv[]) {

    gCoordinator.Init();

    gCoordinator.RegisterComponent<Transform>();

    auto mvSystem = gCoordinator.RegisterSystem<MovementSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Transform>());
    }


    Game game;
    while(game.m_is_running) {
        game.read_input();
        mvSystem->Update();

    }
    return 0;
}
