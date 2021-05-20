/*
** EPITECH PROJECT, 2021
** cpp_poolday14_am
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon(int vitamins): Fruit("lemon", vitamins)
{
    _name = "lemon";
    _vitamins = vitamins;
}

Lemon::~Lemon()
{
}
