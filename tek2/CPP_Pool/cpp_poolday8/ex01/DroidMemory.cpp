/*
** EPITECH PROJECT, 2021
** cpp_poolday8
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    _fingerprint = (size_t) random();
    _exp = 0;
}

size_t DroidMemory::getFingerprint(void) const
{
    return (_fingerprint);
}

size_t DroidMemory::getExp(void) const
{
    return (_exp);
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &other)
{
    _exp += other.getExp();
    _fingerprint = (_fingerprint ^ other.getFingerprint());
    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other)
{
    size_t otherExp = other.getExp();
    size_t otherFingerprint = other.getFingerprint();

    other.setExp(otherExp + _exp);
    other.setFingerprint(_fingerprint ^ otherFingerprint);
    return (other);
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &other)
{
    _exp += other.getExp();
    _fingerprint = (_fingerprint ^ other.getFingerprint());
    return (*this);
}

DroidMemory &DroidMemory::operator+=(const size_t &exp)
{
    _exp += exp;
    _fingerprint = (_fingerprint ^ exp);
    return (*this);
}

DroidMemory DroidMemory::operator+(const DroidMemory &other)
{
    DroidMemory newDroid;

    newDroid.setExp(_exp + other.getExp());
    newDroid.setFingerprint(_fingerprint ^ other.getFingerprint());
    return (newDroid);
}

DroidMemory DroidMemory::operator+(const size_t &exp)
{
    DroidMemory newDroid;

    newDroid.setExp(_exp + exp);
    newDroid.setFingerprint(_fingerprint ^ exp);
    return (newDroid);
}

DroidMemory &DroidMemory::operator=(const DroidMemory &other)
{
    _exp = other.getExp();
    _fingerprint = other.getFingerprint();
    return (*this);
}

DroidMemory::~DroidMemory()
{
}

std::ostream &operator<<(std::ostream &s, const DroidMemory &memory)
{
    s << "DroidMemory '" << memory.getFingerprint() << "', " << memory.getExp();
    return (s);
}