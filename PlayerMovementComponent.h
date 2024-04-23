//
// Created by zthacker on 4/22/2024.
//

#ifndef GALACTICWARS_PLAYERMOVEMENTCOMPONENT_H
#define GALACTICWARS_PLAYERMOVEMENTCOMPONENT_H


#include "Component.h"
#include "KeyboardInput.h"
#include "GameObject.h"


class PlayerMovementComponent : public Component {
public:

    explicit PlayerMovementComponent(GameObject*  owner);

    void SetInput(KeyboardInput* input);
    void SetMovementSpeed(float moveSpeed);

    void Update(float deltaTime) override;

private:
    /*
     * Generally don’t want our keyboard controller class to care/know about the players move speed
     * and once I look into creating the platform physics I'll will change this but it’ll do for now.
     */
    float m_moveSpeed;
    KeyboardInput* m_input;
};


#endif //GALACTICWARS_PLAYERMOVEMENTCOMPONENT_H
