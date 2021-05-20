/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <iostream>
#include <string>

class Event {
    public:
        Event();
        Event(unsigned int time, const std::string &event);
        Event(const Event &other);
        Event &operator=(const Event &other);
        unsigned int getTime(void) const {return (_time);}
        const std::string &getEvent(void) const {return (_event);}
        void setTime(unsigned int time);
        void setEvent(const std::string &event);
        ~Event();

    protected:
        unsigned int _time;
        std::string _event;
    private:
};

#endif /* !EVENT_HPP_ */
