
#include "Game.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


//int main(int argc, char *argv[])
int main(int argc, char *argv[]) {
    Game game;

    auto previous = system_clock::now();
    float lag = 0.0;

    while(game.IsRunning()) {
        auto current = system_clock::now();
        duration<float,milli> elapsed = current - previous;
        previous = current;
        lag += elapsed.count();

        //do input
        game.ProcessInput();

        while(lag >= MS_PER_UPDATE) {
            //lag being passed here, but not being used right now
            game.Update(lag);
            lag -= MS_PER_UPDATE;
        }

        game.Draw(lag / MS_PER_UPDATE);
        game.LateUpdate(lag/MS_PER_UPDATE);

        //Cap FPS
        SDL_Delay(MS_PER_UPDATE - lag);
    }


    return 0;
}
