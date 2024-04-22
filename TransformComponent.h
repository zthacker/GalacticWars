//
// Created by zthacker on 4/22/2024.
//

#ifndef GALACTICWARS_TRANSFORMCOMPONENT_H
#define GALACTICWARS_TRANSFORMCOMPONENT_H

#include "Component.h"



class TransformComponent : public Component {
public:
    explicit TransformComponent(GameObject* owner);

    float GetX();
    float GetY();
    void SetX(float x);
    void SetY(float y);
    void AddX(float x);
    void AddY(float y);

private:
    float posX, posY;
};


#endif //GALACTICWARS_TRANSFORMCOMPONENT_H
