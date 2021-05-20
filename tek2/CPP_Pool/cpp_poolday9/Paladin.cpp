/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin()
{
}

Paladin::Paladin(const std::string &name, int level, std::string weapon, int strength, int stamina, int intelligence, int spirit, int agility, const std::string race, int range):
Character(name, level, strength, stamina, intelligence, spirit, agility, race, range), Warrior(name, level, weapon, strength, stamina, intelligence, spirit, agility, race, range), Mage(name, level, strength, stamina, intelligence, spirit, agility, race, range), Priest(name, level, strength, stamina, intelligence, spirit, agility, race, range)
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
    _weaponName = weapon;
    _class = "Paladin";
    std::cout << "the light falls on " << _name << std::endl;
}

int Paladin::CloseAttack(void)
{
    return (Warrior::CloseAttack());
}

int Paladin::RangeAttack(void)
{
    return (Priest::RangeAttack());
}

void Paladin::Heal(void)
{
    return (Priest::Heal());
}

void Paladin::RestorePower(void)
{
    return (Warrior::RestorePower());
}

int Paladin::Intercept(void)
{
    return (Warrior::RangeAttack());
}

Paladin::~Paladin()
{
}
