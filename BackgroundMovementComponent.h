//
// Created by zthacker on 4/22/2024.
//

#ifndef GALACTICWARS_BACKGROUNDMOVEMENTCOMPONENT_H
#define GALACTICWARS_BACKGROUNDMOVEMENTCOMPONENT_H

#include "Component.h"
#include "GameObject.h"

class BackgroundMovementComponent : public Component {
public:
    explicit BackgroundMovementComponent(GameObject* owner);

    void Update(float deltaTime) override;

private:
};


#endif //GALACTICWARS_BACKGROUNDMOVEMENTCOMPONENT_H
