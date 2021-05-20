/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(const std::string &name, int apcost, int damage):
_name(new std::string(name)), _apcost(apcost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
    if (_name)
        delete _name;
}
