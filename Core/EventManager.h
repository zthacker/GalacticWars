//
// Created by zthacker on 4/11/2024.
//

#ifndef GALACTICWARS_EVENTMANAGER_H
#define GALACTICWARS_EVENTMANAGER_H

#endif //GALACTICWARS_EVENTMANAGER_H

#include "Event.h"
#include "Types.h"
#include <functional>
#include <list>
#include <unordered_map>


class EventManager
{
public:
    void AddListener(EventId eventId, std::function<void(Event&)> const& listener)
    {
        listeners[eventId].push_back(listener);
    }

    void SendEvent(Event& event)
    {
        uint32_t type = event.GetType();

        for (auto const& listener : listeners[type])
        {
            listener(event);
        }
    }

    void SendEvent(EventId eventId)
    {
        Event event(eventId);

        for (auto const& listener : listeners[eventId])
        {
            listener(event);
        }
    }

private:
    std::unordered_map<EventId, std::list<std::function<void(Event&)>>> listeners;
};

