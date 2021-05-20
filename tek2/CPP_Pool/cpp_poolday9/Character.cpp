/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Character
*/

#include "Character.hpp"

Character::Character()
{
}

Character::Character(const std::string &name, int level, int strength, int stamina, int intelligence, int spirit, int agility, const std::string race, int range):
Range((Character::AttackRange)range), _name(name), _level(level), _strength(strength), _stamina(stamina),
_intelligence(intelligence), _spirit(spirit), _agility(agility), _class("Character"),
_pv(100), _energy(100), _race(race)
{
    std::cout << _name << " Created" << std::endl;
}

int Character::CloseAttack(void)
{
    int damage = 0;

    if (this->Range != RANGE) {
        if (this->_energy >= 10) {
            this->_energy -= 10;
            damage = 10 + _strength;
            std::cout << _name << " strikes with a wooden stick" << std::endl;
        } else {
        std::cout << _name << " out of power" << std::endl;
        }
    }
    return (damage);
}

int Character::RangeAttack(void)
{
    int damage = 0;

    if (this->_energy >= 10) {
        this->_energy -= 10;
        damage = 5 + _strength;
        std::cout << _name << " tosses a stone" << std::endl;
    } else {
        std::cout << _name << " out of power" << std::endl;
    }
    return (damage);
}

void Character::Heal(void)
{
    this->_pv += 50;
    if (this->_pv > 100)
        this->_pv = 100;
    std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower(void)
{
    this->_energy += 100;
    if (this->_energy > 100)
        this->_energy = 100;
    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->_pv -= damage;
    if (this->_pv <= 0) {
        std::cout << _name << " out of combat" << std::endl;
    } else {
        std::cout << _name << " takes " << damage << " damage" << std::endl;
    }
}

Character::~Character()
{
}
