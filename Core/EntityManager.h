//
// Created by zthacker on 4/11/2024.
//

#ifndef GALACTICWARS_ENTITYMANAGER_H
#define GALACTICWARS_ENTITYMANAGER_H

#endif //GALACTICWARS_ENTITYMANAGER_H

#include "Types.h"
#include <array>
#include <cassert>
#include <queue>


class EntityManager
{
public:
    //Initialize the queue with the max amount of valid IDs
    EntityManager()
    {
        for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
        {
            m_availableEntities.push(entity);
        }
    }

    //When an entity is created, take an ID from the front of the queue and return it
    Entity CreateEntity()
    {
        assert(m_livingEntityCount < MAX_ENTITIES && "Too many entities in existence.");

        Entity id = m_availableEntities.front();
        m_availableEntities.pop();
        ++m_livingEntityCount;

        return id;
    }

    //When an entity is destroyed, we'll take the ID and put it in the back of the queue
    void DestroyEntity(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        m_signatures[entity].reset();
        m_availableEntities.push(entity);
        --m_livingEntityCount;
    }

    void SetSignature(Entity entity, Signature signature)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        m_signatures[entity] = signature;
    }

    Signature GetSignature(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        return m_signatures[entity];
    }

private:
    std::queue<Entity> m_availableEntities{};
    std::array<Signature, MAX_ENTITIES> m_signatures{};
    uint32_t m_livingEntityCount{};
};
