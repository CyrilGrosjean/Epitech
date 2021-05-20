/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::Hunter()
{
}

Hunter::Hunter(const std::string &name, int level, std::string weapon, int strength, int stamina, int intelligence, int spirit, int agility, const std::string race, int range):
Character(name, level, strength, stamina, intelligence, spirit, agility, race, range), Warrior(name, level, weapon, strength, stamina, intelligence, spirit, agility, race, range)
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
    this->_class = "Hunter";
    std::cout << _name << " is born from a tree" << std::endl;
}

int Hunter::CloseAttack(void)
{
    int damage = 0;

    if (this->Range != RANGE) {
        if (this->_energy >= 30) {
            this->_energy -= 30;
            if (this->_weaponName == "sword") {
                damage = 20 + this->_strength;
                std::cout << _name << " strikes with his " << _weaponName << std::endl;
            }
        } else {
            std::cout << _name << " out of power" << std::endl;
        }
    }
    return (damage);
}

int Hunter::RangeAttack(void)
{
    int damage = 0;

    if (this->_energy >= 25) {
        this->_energy -= 25;
        damage = 20 + _agility;
        std::cout << _name << " uses his bow" << std::endl;
    } else {
        std::cout << _name << " out of power" << std::endl;
    }
    return (damage);
}

void Hunter::RestorePower(void)
{
    _energy = 100;
    std::cout << _name << " meditates" << std::endl;
}

void Hunter::Heal(void)
{
    return (Warrior::Heal());
}

void Hunter::TakeDamage(int damage)
{
    return (Warrior::TakeDamage(damage));
}

Hunter::~Hunter()
{
}
