/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Mage
*/

#include "Mage.hpp"

Mage::Mage()
{
}

Mage::Mage(const std::string &name, int level, int strength, int stamina, int intelligence, int spirit, int agility, const std::string race, int range):
Character(name, level, strength, stamina, intelligence, spirit, agility, race, range)
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
    this->_class = "Mage";
    std::cout << _name << " teleported" << std::endl;
}

int Mage::CloseAttack(void)
{
    if (this->Range != RANGE) {
        if (this->_energy >= 10) {
            this->_energy -= 10;
            this->Range = RANGE;
            std::cout << _name << " blinks" << std::endl;
        } else {
            std::cout << _name << " out of power" << std::endl;
        }
    }
    return (0);
}

int Mage::RangeAttack(void)
{
    int damage = 0;

    if (this->_energy >= 25) {
        this->_energy -= 25;
        damage = 20 + _spirit;
        std::cout << _name << " launches a fire ball" << std::endl;
    } else {
        std::cout << _name << " out of power" << std::endl;
    }
    return (damage);
}

void Mage::RestorePower(void)
{
    this->_energy += 50 + _intelligence;
    if (this->_energy > 100)
        this->_energy = 100;
    std::cout << _name << " takes a mana potion" << std::endl;
}

Mage::~Mage()
{
}
