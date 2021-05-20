/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string file):
Toy(BUZZ, name, file)
{
    _type = BUZZ;
    _name = name;
    _file = file;
    _picture = Picture(_file);
}

Buzz::~Buzz()
{
}
