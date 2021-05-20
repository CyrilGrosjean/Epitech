/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest()
{
}

Priest::Priest(const std::string &name, int level, int strength, int stamina, int intelligence, int spirit, int agility, const std::string race, int range):
Character(name, level, strength, stamina, intelligence, spirit, agility, race, range), Mage(name, level, strength, stamina, intelligence, spirit, agility, race, range)
{
    _name = name;
    _level = level;
    _strength = strength;
    _stamina = stamina;
    _intelligence = intelligence;
    _spirit = spirit;
    _agility = agility;
    _race = race;
    Range = (AttackRange) range;
    this->_class = "Priest";
    std::cout << _name << " enters in the order" << std::endl;
}

int Priest::CloseAttack(void)
{
    int damage = 0;

    if (this->Range != RANGE) {
        if (this->_energy >= 10) {
            this->_energy -= 10;
            damage = 10 + _spirit;
            std::cout << _name << " uses a spirit explosion" << std::endl;
        } else {
            std::cout << _name << " out of power" << std::endl;
        }
    }
    return (damage);
}

void Priest::Heal(void)
{
    if (this->_energy >= 10) {
        this->_energy -= 10;
        this->_pv += 70;
        if (this->_pv > 100)
            this->_pv = 100;
        std::cout << _name << " casts a little heal spell" << std::endl;
    }
}

Priest::~Priest()
{
}
