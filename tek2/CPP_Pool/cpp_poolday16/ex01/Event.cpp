/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** Event
*/

#include "Event.hpp"

Event::Event()
{
    this->_time = 0;
    this->_event = "";
}

Event::Event(unsigned int time, const std::string &event)
{
    this->_time = time;
    this->_event = event;
}

Event::Event(const Event &other)
{
    this->_time = other._time;
    this->_event = other._event;
}

Event &Event::operator=(const Event &other)
{
    this->_time = other._time;
    this->_event = other._event;
    return (*this);
}

void Event::setTime(unsigned int time)
{
    this->_time = time;
}

void Event::setEvent(const std::string &event)
{
    this->_event = event;
}

Event::~Event()
{
}
