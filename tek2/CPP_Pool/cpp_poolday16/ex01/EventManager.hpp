/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "Event.hpp"
#include <list>

class EventManager {
    public:
        EventManager();
        EventManager(EventManager const &other);
        EventManager &operator=(EventManager const &other);
        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents(void) const;
        void dumpEventAt(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(const std::list<Event> &events);
        ~EventManager();

    protected:
        std::list<Event> _events;
        unsigned int _currentTime;
    private:
};

#endif /* !EVENTMANAGER_HPP_ */
