/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** EventManager
*/

#include "EventManager.hpp"

bool sortList(const Event &event1, const Event &event2)
{
    if (event1.getTime() <= event2.getTime())
        return (true);
    return (false);
}

EventManager::EventManager()
{
    this->_currentTime = 0;
}

EventManager::EventManager(EventManager const &other)
{
    this->_events = other._events;
    this->_currentTime = other._currentTime;
}

EventManager &EventManager::operator=(EventManager const &other)
{
    this->_events = other._events;
    this->_currentTime = other._currentTime;
    return (*this);
}

void EventManager::addEvent(const Event &e)
{
    if (e.getTime() < this->_currentTime)
        return;
    this->_events.push_back(e);
    this->_events.sort(sortList);
}

void EventManager::removeEventsAt(unsigned int time)
{
    std::list<Event>::iterator it = this->_events.begin();

    for (; it != this->_events.end(); it++) {
        if (it->getTime() == time) {
            it = this->_events.erase(it);
            it--;
        }
    }
}

void EventManager::dumpEvents(void) const
{
    for (auto it = this->_events.begin(); it != this->_events.end(); it++) {
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (auto it = this->_events.begin(); it != this->_events.end(); it++) {
        if (it->getTime() == time) {
            std::cout << time << ": " << it->getEvent() << std::endl;
        }
    }
}

void EventManager::addTime(unsigned int time)
{
    this->_currentTime += time;

    for (auto it = this->_events.begin(); it != this->_events.end(); it++) {
        if (it->getTime() <= this->_currentTime) {
            std::cout << it->getEvent() << std::endl;
            it = this->_events.erase(it);
            it--;
        }
    }
}

void EventManager::addEventList(const std::list<Event> &events)
{
    for (auto it = events.begin(); it != events.end(); it++) {
        this->addEvent(*it);
    }
}

EventManager::~EventManager()
{
}