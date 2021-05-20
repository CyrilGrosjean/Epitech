/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

namespace Borg
{
    class Ship;
};

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"

class Borg::Ship {
    public:
        Ship(int weaponFrequency = 20, short repair = 0);
        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move(void);
        int getShield(void);
        void setShield(int shield);
        int getWeaponFrequency(void);
        void setWeaponFrequency(int weaponFrequency);
        short getRepair(void);
        void setRepair(short repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair(void);
        ~Ship();
    protected:
    private:
        int _shield;
        int _weaponFrequency;
        short _repair;
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
};

#endif /* !BORG_HPP_ */
