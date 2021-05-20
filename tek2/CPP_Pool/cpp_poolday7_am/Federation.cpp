/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** Fedeation
*/

#include "Federation.hpp"

Federation::Starfleet::Captain::Captain(std::string name): _name(name)
{
    _age = 40;
}

std::string Federation::Starfleet::Captain::getName(void)
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge(void)
{
    return (_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

Federation::Starfleet::Captain::~Captain()
{
}

Federation::Starfleet::Ensign::Ensign(std::string name): _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo): _length(length), _width(width), _name(name), _maxWarp(maxWarp), _photonTorpedo(torpedo)
{
    _home = EARTH;
    _location = _home;
    _captain = nullptr;
    _shield = 100;
    if (torpedo < 0)
        _photonTorpedo = 0;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl
    << "It is " << _length << " m in length and " << _width << " m in width." <<
    std::endl << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (_photonTorpedo > 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    bool stable = _core->checkReactor()->isStable();

    if (stable) {
        std::cout << "USS " << _name << ": The core is stable at the time." <<
        std::endl;
    } else {
        std::cout << "USS " << _name << ": The core is unstable at the time." <<
        std::endl;
    }
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS"
    << " " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location &&
    _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(void)
{
    if (_core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Federation::Starfleet::Ship::getShield(void)
{
    return (_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo(void)
{
    return (_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    int targetShield = target->getShield();

    if (_photonTorpedo > 0) {
        _photonTorpedo -= 1;
        targetShield -= 50;
        target->setShield(targetShield);
        std::cout << _name << ": Firing on target. " << _photonTorpedo <<
        " torpedoes remaining." << std::endl;
        if (_photonTorpedo == 0) {
            std::cout << _name << ": No more torpedo to fire, " << _captain->getName()
            << "!" << std::endl;
        }
        return;
    }
    std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName()
    << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    int targetShield = target->getShield();

    if (_photonTorpedo >= torpedoes) {
        _photonTorpedo -= torpedoes;
        targetShield -= 50 * torpedoes;
        target->setShield(targetShield);
        std::cout << _name << ": Firing on target. " << _photonTorpedo <<
        " torpedoes remaining." << std::endl;
        if (_photonTorpedo == 0)
            std::cout << _name << ": No more torpedo to fire, " << _captain->getName()
            << "!" << std::endl;
        return;
    }
    std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName()
    << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

Federation::Ship::Ship(int length, int width, std::string name):
_length(length), _width(width), _name(name)
{
    _home = VULCAN;
    _location = _home;
    _maxWarp = 1;
    std::cout << "The independent ship " << _name << " just finished its" <<
    " construction." << std::endl << "It is " << _length << " m in length and "
    << _width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    bool stable = _core->checkReactor()->isStable();

    if (stable) {
        std::cout << _name << ": The core is stable at the time." << std::endl;
    } else {
        std::cout << _name << ": The core is unstable at the time." <<
        std::endl;
    }
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location &&
    _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(void)
{
    if (_core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

WarpSystem::Core *Federation::Ship::getCore(void)
{
    return (_core);
}

Federation::Ship::~Ship()
{
}