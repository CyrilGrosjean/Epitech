/*
** EPITECH PROJECT, 2021
** cpp_poolday14_am
** File description:
** Banana
*/

#include "Banana.hpp"

Banana::Banana(int vitamins): Fruit("banana", vitamins)
{
    _name = "banana";
    _vitamins = vitamins;
}

Banana::~Banana()
{
}
