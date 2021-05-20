/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy()
{
}

AEnemy::AEnemy(int hp, const std::string &type):
_hp(hp), _type(new std::string(type))
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    _hp -= damage;
}

void AEnemy::setHp(int hp)
{
    _hp = hp;
}

AEnemy::~AEnemy()
{
    if (_type)
        delete _type;
}
