/*
** EPITECH PROJECT, 2021
** cpp_poolday7_pm
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(std::string const &serial = "A-01", bool functionnal = true): _name(serial), _functionnal(functionnal)
{
}

bool Arms::isFunctionnal(void)
{
    return (_functionnal);
}

std::string const &Arms::serial(void)
{
    return (_name);
}

void Arms::informations(void)
{
    if (_functionnal)
        std::cout << "\t[Parts] Arms " << _name << " status : OK" << std::endl;
    else
        std::cout << "\t[Parts] Arms " << _name << " status : KO" << std::endl;
}

Arms::~Arms()
{
}

Legs::Legs(std::string const &serial = "L-01", bool functionnal = true): _name(serial), _functionnal(functionnal)
{
}

bool Legs::isFunctionnal(void)
{
    return (_functionnal);
}

std::string const &Legs::serial(void)
{
    return (_name);
}

void Legs::informations(void)
{
    if (_functionnal)
        std::cout << "\t[Parts] Legs " << _name << " status : OK" << std::endl;
    else
        std::cout << "\t[Parts] Legs " << _name << " status : KO" << std::endl;
}

Legs::~Legs()
{
}

Head::Head(std::string const &serial = "H-01", bool functionnal = true): _name(serial), _functionnal(functionnal)
{
}

bool Head::isFunctionnal(void)
{
    return (_functionnal);
}

std::string const &Head::serial(void)
{
    return (_name);
}

void Head::informations(void)
{
    if (_functionnal)
        std::cout << "\t[Parts] Head " << _name << " status : OK" << std::endl;
    else
        std::cout << "\t[Parts] Head " << _name << " status : KO" << std::endl;
}

Head::~Head()
{
}