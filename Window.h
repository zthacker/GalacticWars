//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_WINDOW_H
#define GALACTICWARS_WINDOW_H
#include "defs.h"

#include <iostream>
#include "SDL_image.h"



class Window {
public:
    explicit Window(const char* title);

    void Update();

    void BeginDraw();
    void DrawBlit(SDL_Texture* texture, float x, float y);
    void DrawBlitRect(SDL_Texture* texture, SDL_Rect* src, float x, float y);
    void Display();
    SDL_Window* gameWindow;
    SDL_Renderer* gameRenderer;
    bool IsOpen() const;

private:


    bool m_isOpen;
};

#endif //GALACTICWARS_WINDOW_H
