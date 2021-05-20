/*
** EPITECH PROJECT, 2021
** cpp_poolday7_pm
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks): _name(name), _stimPaks(stimPaks)
{
}

int &Skat::stimPaks(void)
{
    return (_stimPaks);
}

void Skat::stimPaks(int stimPaks)
{
    _stimPaks = stimPaks;
}

const std::string &Skat::name()
{
    return (_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    stock += number;
    _stimPaks -= number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    }
    _stimPaks += number;
}

void Skat::useStimPaks(void)
{
    if (_stimPaks > 0) {
        _stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status(void)
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}

Skat::~Skat()
{
}
