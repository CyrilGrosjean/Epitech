/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>

namespace Federation
{
    namespace Starfleet
    {
        class Captain;
        class Ensign;
        class Ship;
    };
    class Ship;
};

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

class Federation::Starfleet::Captain {
    public:
        Captain(std::string name);
        std::string getName(void);
        int getAge(void);
        void setAge(int age);
        ~Captain();
    protected:
    private:
        std::string _name;
        int _age;
};

class Federation::Starfleet::Ensign {
    public:
        Ensign(std::string name);
        ~Ensign();
    protected:
    private:
        std::string _name;
};

class Federation::Starfleet::Ship {
    public:
        Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
        void promote(Captain *captain);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move(void);
        int getShield(void);
        void setShield(int shield);
        int getTorpedo(void);
        void setTorpedo(int torpedo);
        void fire(Borg::Ship *target);
        void fire(int torpedoes, Borg::Ship *target);
        ~Ship();

    protected:
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Captain *_captain;
        Destination _location;
        Destination _home;
        int _shield;
        int _photonTorpedo;
};

class Federation::Ship {
    public:
        Ship(int length, int width, std::string name);
        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move(void);
        WarpSystem::Core *getCore(void);
        ~Ship();
    protected:
    private:
        int _length;
        int _width;
        short _maxWarp;
        std::string _name;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
};

#endif /* !FEDERATION_HPP_ */
