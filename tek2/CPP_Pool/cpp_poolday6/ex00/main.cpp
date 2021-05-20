/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** main
*/

#include "my_cat.hpp"

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (84);
    }
    get_cat(ac, av);
    return (0);
}