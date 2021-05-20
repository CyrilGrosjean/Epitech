/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name):
_name(new std::string(name)), _ap(40), _weapon(nullptr)
{
}

void Character::recoverAP(void)
{
    _ap += 10;
    if (_ap > 40)
        _ap = 40;
}

void Character::attack(AEnemy *enemy)
{
    if (_weapon) {
        if (_ap >= _weapon->getAPCost()) {
            _ap -= _weapon->getAPCost();
            std::cout << *_name << " attacks " << *enemy->getType() << " with a " << *_weapon->getName() << std::endl;
            _weapon->attack();
            enemy->takeDamage(_weapon->getDamage());
            if (enemy->getHp() <= 0)
                delete enemy;
        }
    }
}

Character::~Character()
{
}

std::ostream &operator<<(std::ostream &s, Character &charac)
{
    if (charac.getWeapon()) {
        s << *charac.getName() << " has " << charac.getAp() << " AP and wields a " << *charac.getWeapon()->getName() << std::endl;
    } else {
        s << *charac.getName() << " has " << charac.getAp() << " AP and is unarmed" << std::endl;
    }
    return (s);
}
