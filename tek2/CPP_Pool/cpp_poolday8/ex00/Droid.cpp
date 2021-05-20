/*
** EPITECH PROJECT, 2021
** cpp_poolday8
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(const Droid &droid): _id(droid._id), _energy(droid._energy), _attack(droid._attack), _toughness(droid._toughness)
{
    if (droid._status) {
        _status = new std::string(*(droid._status));
    } else {
        _status = new std::string("Standing by");
    }
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::Droid(std::string id): _id(id), _energy(50), _attack(25), _toughness(15),
_status(new std::string("Standing by"))
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

std::string Droid::getId(void) const
{
    return (_id);
}

size_t Droid::getAttack(void) const
{
    return (_attack);
}

size_t Droid::getEnergy(void) const
{
    return (_energy);
}

std::string Droid::getStatus(void) const
{
    return (*_status);
}

size_t Droid::getToughness(void) const
{
    return (_toughness);
}

void Droid::setId(std::string id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        energy = 100;
    _energy = energy;
}

void Droid::setStatus(std::string *status)
{
    _status = status;
}

Droid &Droid::operator=(const Droid &other)
{
    _id = other._id;
    _energy = other._energy;
    if (_status)
        delete _status;
    _status = new std::string(*(other._status));
    return (*this);
}

bool Droid::operator==(const Droid &other) const
{
    if (_status->compare(*other._status) == 0 && _id == other._id &&
    _energy == other._energy) {
        return (true);
    }
    return (false);
}

bool Droid::operator!=(const Droid &other) const
{
    if (_status->compare(*other._status) != 0 || _id != other._id ||
    _energy != other._energy) {
        return (true);
    }
    return (false);
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t toAdd = 100 - _energy;

    if (energy <= 0)
        return (*this);
    if (toAdd < energy) {
        _energy = 100;
        energy -= toAdd;
    } else {
        _energy += energy;
        energy = 0;
    }
    return (*this);
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Droid &droid)
{
    s << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", "
    << droid.getEnergy();
    return (s);
}