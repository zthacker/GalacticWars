//
// Created by zthacker on 4/11/2024.
//

#ifndef GALACTICWARS_TYPES_H
#define GALACTICWARS_TYPES_H

#include <bitset>
#include <cstdint>



//Type alias for Entity
using Entity = uint32_t;
const Entity MAX_ENTITIES = 5000;
using ComponentType = uint8_t;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;


#endif //GALACTICWARS_TYPES_H


