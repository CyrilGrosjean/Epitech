/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior()
{
}

Warrior::Warrior(const std::string &name, int level, std::string weapon, int strength, int stamina, int intelligence, int spirit, int agility, const std::string race, int range):
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
    this->_weaponName = weapon;
    this->_class = "Warrior";
    std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack(void)
{
    int damage = 0;

    if (this->Range != RANGE) {
        if (this->_energy >= 30) {
        this->_energy -= 30;
            if (this->_weaponName == "hammer") {
                damage = 20 + this->_strength;
                std::cout << _name << " strikes with his " << _weaponName << std::endl;
            }
        } else {
        std::cout << _name << " out of power" << std::endl;
        }
    }
    return (damage);
}

int Warrior::RangeAttack(void)
{
    if (this->Range != CLOSE) {
        if (this->_energy >= 10) {
            this->_energy -= 10;
            this->Range = CLOSE;
            std::cout << _name << " intercepts" << std::endl;
        } else {
            std::cout << _name << " out of power" << std::endl;
        }
    }
    return (0);
}

Warrior::~Warrior()
{
}