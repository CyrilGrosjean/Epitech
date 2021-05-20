/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string file):
Toy(WOODY, name, file)
{
    _type = WOODY;
    _name = name;
    _file = file;
    _picture = Picture(_file);
}

Woody::~Woody()
{
}
