/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim()
{
}

Victim::Victim(std::string name):
_name(name)
{
    std::cout << "Some random victim called " << _name << " just popped!" << std::endl;
}

void Victim::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

std::ostream &operator<<(std::ostream &s, Victim &victim)
{
    s << "I'm " << victim.getName() << " and I like otters!" << std::endl;
    return (s);
}
