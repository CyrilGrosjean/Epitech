/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Peon
*/

#include "Peon.hpp"

Peon::Peon()
{
}

Peon::Peon(std::string name):
Victim(name)
{
    _name = name;
    std::cout << "Zog zog." << std::endl;
}

void Peon::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into a pink pony!" << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}
