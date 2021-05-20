/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"

int main(int ac, const char *av[])
{
    if (ac != 2) {
        std::cout << "Usage: ./arcade ./[path to graphical shared library module]" << std::endl;
        return 84;
    }
    try {
        Core core(av[1]);
    } catch (std::logic_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}