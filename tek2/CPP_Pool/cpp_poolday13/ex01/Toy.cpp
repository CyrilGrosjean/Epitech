/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _picture = Picture();
}

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
{
    _picture = Picture(file);
    _type = type;
    _name = name;
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return (_picture.getPictureFromFile(file));
}

Toy &Toy::operator=(const Toy &other)
{
    _picture = other._picture;
    _name = other._name;
    _type = other._type;
    return (*this);
}

Toy::~Toy()
{
}
