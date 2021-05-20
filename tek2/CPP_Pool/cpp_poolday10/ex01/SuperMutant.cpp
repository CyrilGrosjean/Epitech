/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** SuperMutant
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant():
AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

void SuperMutant::takeDamage(int hp)
{
    int pv = this->getHp();

    hp -= 3;
    if (hp < 0)
        hp = 0;
    this->setHp(pv - hp);
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}
