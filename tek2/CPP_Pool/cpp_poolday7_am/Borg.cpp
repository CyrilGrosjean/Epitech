/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    _home = UNICOMPLEX;
    _location = _home;
    _maxWarp = 9;
    _side = 300;
    _shield = 100;
    _weaponFrequency = weaponFrequency;
    if (repair <= 0)
        _repair = 3;
    else
        _repair = repair;
    std::cout << "We are the Borgs. Lower your shields and surrender " <<
    "yourselves unconditionally." << std::endl << "Your biological " <<
    "characteristics and technologies will be assimilated." << std::endl <<
    "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore(void)
{
    bool stable = _core->checkReactor()->isStable();

    if (stable) {
        std::cout << "Everything is in order." << std::endl;
    } else {
        std::cout << "Critical failure imminent." << std::endl;
    }
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location &&
    _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(void)
{
    if (_core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Borg::Ship::getShield(void)
{
    return (_shield);
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency(void)
{
    return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int weaponFrequency)
{
    _weaponFrequency = weaponFrequency;
}

short Borg::Ship::getRepair(void)
{
    return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    int targetShield = target->getShield();

    targetShield -= _weaponFrequency;
    target->setShield(targetShield);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency" << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency" << std::endl;
}

void Borg::Ship::repair(void)
{
    if (_repair > 0) {
        _shield = 100;
        _repair -= 1;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else {
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }
}

Borg::Ship::~Ship()
{
}